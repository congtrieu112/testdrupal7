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
  private $currentParser;

  public function __construct() {
    $this->delimiter = ',';
    $this->skipFirstLine = FALSE;
    $this->columnNames = FALSE;
    $this->timeout = FALSE;
    $this->timeoutReached = FALSE;
    $this->startByte = 0;
    $this->lineLimit = 0;
    $this->lastLinePos = 0;
    $this->currentParser = NULL;
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
  public function setCurrentParser($current_parser) {
    return $this->currentParser = $current_parser;
  }

  public function parse(Iterator $lineIterator) {
    $skipLine = $this->skipFirstLine;
    $rows = array();

    $this->timeoutReached = FALSE;
    $this->lastLinePos = 0;
    $maxTime = empty($this->timeout) ? FALSE : (microtime() + $this->timeout);
    $linesParsed = 0;
    $kb_delimiter = $this->delimiter;
    $total_column = $this->currentParser->config['total_column'];
    $logging = '';
    $stored_line = '';
    for ($lineIterator->rewind($this->startByte); $lineIterator->valid(); $lineIterator->next()) {
      $line = $ori_line = $lineIterator->current();
      $line = mb_convert_encoding($line, "UTF-8", "ISO-8859-1");
      if (empty($line)) {
        continue;
      }
      if ($skipLine) {
        $skipLine = FALSE;
        continue;
      }
      if (strpos($line, '|') > 0) {
          $line = trim($line, "\r\n");
          $line = str_replace("|", "" ,$line);
          $line = str_replace("¤", $kb_delimiter ,$line);
          $line = $stored_line . $line;
          $stored_line = '';
      }
      else {
          $line = str_replace("¤", $kb_delimiter ,$line);
          $stored_line .= $line;
          continue;
      }
      $fields = str_getcsv($line, $this->delimiter, '','\\');
      if(is_array($fields) && $total_column != count($fields)){
          $log_line = mb_convert_encoding($ori_line, "UTF-8", "ISO-8859-1");
          $logging .= str_replace('¤', '€' ,$log_line);;
          continue;
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
    if($logging != ''){
        $file_log_name = $this->currentParser->id . '_log_' . date('Y-m-d') . '.txt';
        $uri = 'private://feeds/log/';
        $prepare_file = file_prepare_directory($uri, FILE_CREATE_DIRECTORY);
        if($prepare_file){
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