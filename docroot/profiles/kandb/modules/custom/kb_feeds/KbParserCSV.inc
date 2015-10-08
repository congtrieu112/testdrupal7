<?php

/**
 * Functionality to parse CSV files into a two dimensional array.
 */
class KbParserCSV extends ParserCSV{
  private $delimiter;
  private $skipFirstLine;
  private $columnNames;
  private $timeout;
  private $timeoutReached;
  private $startByte;
  private $lineLimit;
  private $lastLinePos;

  public function __construct() {
    $this->delimiter = ',';
    $this->skipFirstLine = FALSE;
    $this->columnNames = FALSE;
    $this->timeout = FALSE;
    $this->timeoutReached = FALSE;
    $this->startByte = 0;
    $this->lineLimit = 0;
    $this->lastLinePos = 0;
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
    $kb_delimiter = $this->delimiter;
    for ($lineIterator->rewind($this->startByte); $lineIterator->valid(); $lineIterator->next()) {

      $line = trim($lineIterator->current(), "\r\n");
      $line = mb_convert_encoding($line, "UTF-8", "ISO-8859-1");
      $line = str_replace("|", "" ,$line);
      $line = str_replace("¤", $kb_delimiter ,$line);
      
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
          }
          else {
            $quoted = FALSE;
            $currentIndex = $nextQuoteIndex + 1;
          }
        }
        else {
          $nextQuoteIndex = strpos($line, '"', $currentIndex);
          $nextDelimiterIndex = strpos($line, $this->delimiter, $currentIndex);

          if ($nextQuoteIndex === FALSE) {
            $nextIndex = $nextDelimiterIndex;
          }
          elseif ($nextDelimiterIndex === FALSE) {
            $nextIndex = $nextQuoteIndex;
          }
          else {
            $nextIndex = min($nextQuoteIndex, $nextDelimiterIndex);
          }

          if ($nextIndex === FALSE) {
            $currentField .= substr($line, $currentIndex);
            $fields[] = $currentField;
            break;
          }
          elseif ($line[$nextIndex] === $this->delimiter[0]) {
            $length = ($nextIndex + strlen($this->delimiter) - 1) - $currentIndex;
            $currentField .= substr($line, $currentIndex, $length);
            $fields[] = $currentField;
            $currentField = '';
            $currentIndex += $length + 1;
          }
          else {
            $quoted = TRUE;
            $currentField .= substr($line, $currentIndex, $nextIndex - $currentIndex);
            $currentIndex = $nextIndex + 1;
          }
        }
      }

      if (empty($this->columnNames)) {
        $row = $fields;
      }
      else {
        $row = array();
        foreach ($this->columnNames as $columnName) {
          $field = array_shift($fields);
          $row[$columnName] = isset($field) ? $field : '';
        }
      }
      $rows[] = $row;
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
    return $rows;
  }
}