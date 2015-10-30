<?php

class EncodingCSVParser extends ParserCSV {

  private $delimiter;
  private $skipFirstLine;
  private $columnNames;
  private $timeout;
  private $timeoutReached;
  private $startByte;
  private $lineLimit;
  private $lastLinePos;
  private $id;

  public function __construct() {
    $this->delimiter = ',';
    $this->skipFirstLine = FALSE;
    $this->columnNames = FALSE;
    $this->timeout = FALSE;
    $this->timeoutReached = FALSE;
    $this->startByte = 0;
    $this->lineLimit = 0;
    $this->lastLinePos = 0;
    $this->id = '';
    ini_set('auto_detect_line_endings', TRUE);
  }

  public function setDelimiter($delimiter) {
    $this->delimiter = $delimiter;
  }

  public function setSkipFirstLine($skipFirstLine) {
    $this->skipFirstLine = $skipFirstLine;
  }

  public function setColumnNames($columnNames) {
    $this->columnNames = $columnNames;
  }

  public function setTimeout($timeout) {
    $this->timeout = $timeout;
  }

  public function timeoutReached() {
    return $this->timeoutReached;
  }

  public function setLineLimit($lines) {
    $this->lineLimit = $lines;
  }

  public function lastLinePos() {
    return $this->lastLinePos;
  }

  public function setId($id) {
    return $this->id = $id;
  }

  public function setStartByte($start) {
    return $this->startByte = $start;
  }

  public function parse(Iterator $lineIterator) {
    $skipLine = $this->skipFirstLine;
    $rows = array();

    $this->timeoutReached = FALSE;
    $this->lastLinePos = 0;
    $maxTime = empty($this->timeout) ? FALSE : (microtime() + $this->timeout);
    $linesParsed = 0;
    $logging = '';
    for ($lineIterator->rewind($this->startByte); $lineIterator->valid(); $lineIterator->next()) {
      $line = trim($lineIterator->current(), "\r\n");
      $line = mb_convert_encoding($line, "UTF-8", "UTF-16");
      if (empty($line)) {
        continue;
      }
      if ($skipLine) {
        $skipLine = FALSE;
        continue;
      }
      $quoted = FALSE;
      $currentIndex = 0;
      $currentField = '';
      $fields = array();
      while ($currentIndex <= strlen($line)) {
        if ($quoted) {
          $nextQuoteIndex = strpos($line, '"', $currentIndex);

          if ($nextQuoteIndex === FALSE) {
            $currentField .= substr($line, $currentIndex);
            $lineIterator->next();

            if (!$lineIterator->valid()) {
              $fields[] = $currentField;
              break;
            }
            $currentField .= "\n";
            $line = trim($lineIterator->current(), "\r\n");
            $currentIndex = 0;
            continue;
          }

          $currentField .= substr($line, $currentIndex, $nextQuoteIndex - $currentIndex);

          if (isset($line[$nextQuoteIndex + 1]) && $line[$nextQuoteIndex + 1] === '"') {
            $currentField .= '"';
            $currentIndex = $nextQuoteIndex + 2;
          } else {
            $quoted = FALSE;
            $currentIndex = $nextQuoteIndex + 1;
          }
        } else {
          $nextQuoteIndex = strpos($line, '"', $currentIndex);
          $nextDelimiterIndex = strpos($line, $this->delimiter, $currentIndex);

          if ($nextQuoteIndex === FALSE) {
            $nextIndex = $nextDelimiterIndex;
          } elseif ($nextDelimiterIndex === FALSE) {
            $nextIndex = $nextQuoteIndex;
          } else {
            $nextIndex = min($nextQuoteIndex, $nextDelimiterIndex);
          }

          if ($nextIndex === FALSE) {
            $currentField .= substr($line, $currentIndex);
            $fields[] = $currentField;
            break;
          } elseif ($line[$nextIndex] === $this->delimiter[0]) {
            $length = ($nextIndex + strlen($this->delimiter) - 1) - $currentIndex;
            $currentField .= substr($line, $currentIndex, $length);
            $fields[] = $currentField;
            $currentField = '';
            $currentIndex += $length + 1;
          } else {
            $quoted = TRUE;
            $currentField .= substr($line, $currentIndex, $nextIndex - $currentIndex);
            $currentIndex = $nextIndex + 1;
          }
        }
      }
      if ($this->id == 'migration_program_import') {
        if (is_array($fields) && 44 != count($fields)) {
          $logging .= $line;
          continue;
        }
      } else {
        if (is_array($fields) && 2 != count($fields)) {
          $logging .= $line;
          continue;
        }
      }
      if (empty($this->columnNames)) {
        $row = $fields;
      } else {
        $row = array();
        foreach ($this->columnNames as $columnName) {
          $field = array_shift($fields);
          if ($columnName == 'identifiantprogramme') {
            $field = (int) $field;
          }
          $row[$columnName] = isset($field) ? $field : '';
        }
      }
      if (!(isset($row['identifiantprogramme']) && $row['identifiantprogramme'] == 0)) {
        $rows[] = $row;
      }
      if (!empty($maxTime) && microtime() > $maxTime) {
        $this->timeoutReached = TRUE;
        $this->lastLinePos = $lineIterator->currentPos();
        break;
      }
      $linesParsed++;
      if ($this->lineLimit && $linesParsed >= $this->lineLimit) {
        $this->lastLinePos = $lineIterator->currentPos();
        break;
      }
    }

    if ($logging != '') {

      $file_log_name = '';
      if($this->id == 'migration_program_import') {
        $file_log_name = 'migration_program_import_log_' . date('Y-m-d') . '.txt';
      } else {
        $file_log_name = 'migration_program_video_import_log_' . date('Y-m-d') . '.txt';
      }

      //$file_log_name = 'migration_program_video_import_log_' . date('Y-m-d') . '.txt';
      $uri = 'private://feeds/log/';
      $prepare_file = file_prepare_directory($uri, FILE_CREATE_DIRECTORY);

      if ($prepare_file) {
        $path = drupal_realpath($uri . $file_log_name);
        $data = file_get_contents($path);
        $logging .= $data;
        drupal_chmod($uri);
        file_save_data($logging, $uri . $file_log_name, FILE_EXISTS_REPLACE);
      }
    }

    return $rows;
  }
}
