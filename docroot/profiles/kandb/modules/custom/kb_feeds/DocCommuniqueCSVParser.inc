<?php

class DocCommuniqueCSVParser extends ParserCSV{
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
    $this->id = '';
    ini_set('auto_detect_line_endings', TRUE);
  }

  /**
   * Set the column delimiter string.
   * By default, the comma (',') is used as delimiter.
   */
  public function setDelimiter($delimiter) {
    $this->delimiter = $delimiter;
  }

  /**
   * Set this to TRUE if the parser should skip the first line of the CSV text,
   * which might be desired if the first line contains the column names.
   * By default, this is set to FALSE and the first line is not skipped.
   */
  public function setSkipFirstLine($skipFirstLine) {
    $this->skipFirstLine = $skipFirstLine;
  }

  /**
   * Specify an array of column names if you know them in advance, or FALSE
   * (which is the default) to unset any prior column names. If no column names
   * are set, the parser will put each row into a simple numerically indexed
   * array. If column names are given, the parser will create arrays with
   * these column names as array keys instead.
   */
  public function setColumnNames($columnNames) {
    $this->columnNames = $columnNames;
  }

  /**
   * Define the time (in milliseconds) after which the parser stops parsing,
   * even if it has not yet finished processing the CSV data. If the timeout
   * has been reached before parsing is done, the parse() method will return
   * an incomplete list of rows - a single row will never be cut off in the
   * middle, though. By default, no timeout (@p $timeout == FALSE) is defined.
   *
   * You can check if the timeout has been reached by calling the
   * timeoutReached() method after parse() has been called.
   */
  public function setTimeout($timeout) {
    $this->timeout = $timeout;
  }

  /**
   * After calling the parse() method, determine if the timeout (set by the
   * setTimeout() method) has been reached.
   *
   * @deprecated Use lastLinePos() instead to determine whether a file has
   *   finished parsing.
   */
  public function timeoutReached() {
    return $this->timeoutReached;
  }

  /**
   * Define the number of lines to parse in one parsing operation.
   *
   * By default, all lines of a file are being parsed.
   */
  public function setLineLimit($lines) {
    $this->lineLimit = $lines;
  }

  /**
   * Get the byte number where the parser left off after last parse() call.
   *
   * @return
   *  0 if all lines or no line has been parsed, the byte position of where a
   *  timeout or the line limit has been reached otherwise. This position can be
   *  used to set the start byte for the next iteration after parse() has
   *  reached the timeout set with setTimeout() or the line limit set with
   *  setLineLimit().
   *
   * @see ParserCSV::setStartByte()
   */
  public function lastLinePos() {
    return $this->lastLinePos;
  }

  public function setId($id) {
    return $this->id = $id;
  }

  /**
   * Set the byte where file should be started to read.
   *
   * Useful when parsing a file in batches.
   */
  public function setStartByte($start) {
    return $this->startByte = $start;
  }

  /**
   * Parse CSV files into a two dimensional array.
   *
   * @param Iterator $lineIterator
   *   An Iterator object that yields line strings, e.g. ParserCSVIterator.
   * @param $start
   *   The byte number from where to start parsing the file.
   * @param $lines
   *   The number of lines to parse, 0 for all lines.
   * @return
   *   Two dimensional array that contains the data in the CSV file.
   */
  public function parse(Iterator $lineIterator) {
    $skipLine = $this->skipFirstLine;
    $rows = array();

    $this->timeoutReached = FALSE;
    $this->lastLinePos = 0;
    $maxTime = empty($this->timeout) ? FALSE : (microtime() + $this->timeout);
    $linesParsed = 0;
    $mylinesParsed = 0;
    $log_text = '';
    $is_log = FALSE;
    for ($lineIterator->rewind($this->startByte); $lineIterator->valid(); $lineIterator->next()) {

      // Make really sure we've got lines without trailing newlines.
      $line = trim($lineIterator->current(), "\r\n");
      $line = mb_convert_encoding($line, "UTF-8", "UTF-16");
      // Skip empty lines.
      if (empty($line)) {
        continue;
      }
      // If the first line contains column names, skip it.
      if ($skipLine) {
        $skipLine = FALSE;
        continue;
      }
      $lines = explode('|', $line);
      if($this->id == 'document_import_communique_de_presse') {
        $lines = explode('|', $line);
        if(count($lines) < 14) {
          $concat_string .= $line;
          if(count(explode('|', $concat_string)) == 14) {
            $line = $concat_string;
            $concat_string = '';
          } else {
            continue;
          }
        }
      }



      // The actual parser. explode() is unfortunately not suitable because the
      // delimiter might be located inside a quoted field, and that would break
      // the field and/or require additional effort to re-join the fields.
      $quoted = FALSE;
      $currentIndex = 0;
      $currentField = '';
      $fields = array();

      // We must use strlen() as we're parsing byte by byte using strpos(), so
      // drupal_strlen() will not work properly.
      while ($currentIndex <= strlen($line)) {
        if ($quoted) {
          $nextQuoteIndex = strpos($line, '"', $currentIndex);

          if ($nextQuoteIndex === FALSE) {
            // There's a line break before the quote is closed, so fetch the
            // next line and start from there.
            $currentField .= substr($line, $currentIndex);
            $lineIterator->next();

            if (!$lineIterator->valid()) {
              // Whoa, an unclosed quote! Well whatever, let's just ignore
              // that shortcoming and record it nevertheless.
              $fields[] = $currentField;
              break;
            }
            // Ok, so, on with fetching the next line, as mentioned above.
            $currentField .= "\n";
            $line = trim($lineIterator->current(), "\r\n");
            $currentIndex = 0;
            continue;
          }

          // There's actually another quote in this line...
          // find out whether it's escaped or not.
          $currentField .= substr($line, $currentIndex, $nextQuoteIndex - $currentIndex);

          if (isset($line[$nextQuoteIndex + 1]) && $line[$nextQuoteIndex + 1] === '"') {
            // Escaped quote, add a single one to the field and proceed quoted.
            $currentField .= '"';
            $currentIndex = $nextQuoteIndex + 2;
          }
          else {
            // End of the quoted section, close the quote and let the
            // $quoted == FALSE block finalize the field.
            $quoted = FALSE;
            $currentIndex = $nextQuoteIndex + 1;
          }
        }
        else { // $quoted == FALSE
          // First, let's find out where the next character of interest is.
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
            // This line is done, add the rest of it as last field.
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
            // Continue with the next field.
          }
          else { // $line[$nextIndex] == '"'
            $quoted = TRUE;
            $currentField .= substr($line, $currentIndex, $nextIndex - $currentIndex);
            $currentIndex = $nextIndex + 1;
            // Continue this field in the $quoted == TRUE block.
          }
        }
      }
      // End of CSV parser. We've now got all the fields of the line as strings
      // in the $fields array.

//      if(is_array($fields) && 14 != count($fields)){
//          $is_log = TRUE;
//          $log_text .= $line;
//          continue;
//      }
      $columnNamesStatus = 0;
      if (empty($this->columnNames)) {
        $row = $fields;
      }
      else {
        $doc_sticky = 0;
        $row = array();
        $columnNamesStatus = 1;
        foreach ($this->columnNames as $columnName) {
          $field = array_shift($fields);
          if($columnName == 'identifiantcommunique'){
              $field = (int)$field;
          }
          if ($columnName == 'contact1affichagepardefaut' || $columnName == 'contact2affichagepardefaut') {
              $field = (bool)$field;
          }
          if($columnName == 'contenulientxt') {
              $field = trim($field);
              if($field != '') {
                $txt_uri = '';
                if ($this->id == 'document_import_communique_de_presse') {
                  $txt_file_name = substr($field, strrpos($field, '/') + 1);
                  $txt_uri = 'public://import/pdf_migration_folder/' . $txt_file_name;
                }
                elseif ($this->id == 'document_import_communique_de_presse_uk') {
                  $txt_uri = 'public:/' . $field;
                }
                $txt_file_prepare = file_prepare_directory($txt_uri, FILE_MODIFY_PERMISSIONS);
                $txt_path = drupal_realpath($txt_uri);
                if(!file_exists($txt_path)) {
                    $is_log = TRUE;
                    $field = '';
                } 
                else {
                  $txt_data = file_get_contents($txt_path);
                  $encoding = mb_detect_encoding($txt_data, "UTF-8,ISO-8859-15,UTF-16");
                  if ($txt_data) {
                    if($encoding != 'UTF-8') {
                        $txt_data = mb_convert_encoding($txt_data, "UTF-8", $encoding);
                    }
                    $field = $txt_data;
                  }
                  else {
                    $field = '';
                  }
                }
              }
          }
//          if($columnName == 'lienfichier') {
//              if(trim($field) != '') {
//                if ($this->id == 'document_import_communique_de_presse') {
//                  $pdf_file_name = substr($field, strrpos($field, '/') + 1);
//                  $pdf_uri = 'public://import/pdf_migration_folder/' . $pdf_file_name;
//                }
//                elseif ($this->id == 'document_import_communique_de_presse_uk') {
//                  $pdf_uri = $field;
//                }
//                file_prepare_directory($pdf_uri, FILE_MODIFY_PERMISSIONS);
//                $pdf_path = drupal_realpath($pdf_uri);
//                if(!file_exists($pdf_path)) {
//                    $is_log = TRUE;
//                    $field = '';
//                }
//              }
//          }
          if($columnName == 'statut') {
              if (trim($field) == 'On line') {
                 $field = 1;
              }
              elseif (trim($field) == 'Off line') {
                  $field = 0;
              }
              elseif (trim($field) == 'On line + mise en avant') {
                  $field = 1;
                  $doc_sticky = 1;
              }
          }

          $row[$columnName] = isset($field) ? $field : '';
        }
        $row['sticky'] = $doc_sticky;
        $row['categorie'] = '';
      }
      if($is_log) {
          $is_log = FALSE;
          $log_text .= $line;
      }
      if(!(isset($row['identifiantcommunique']) && $row['identifiantcommunique'] == 0)){
        $mylinesParsed++;
        $rows[] = $row;
      }

      if($columnNamesStatus == 0) {
        $mylinesParsed--;
      }

      // Quit parsing if timeout has been reached or requested lines have been
      // reached.
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

    $total = variable_get($this->id . '_total', 0);
    if($mylinesParsed > 0) {
      variable_set($this->id . '_total', $mylinesParsed + $total);
    }

    return $rows;
  }
}
