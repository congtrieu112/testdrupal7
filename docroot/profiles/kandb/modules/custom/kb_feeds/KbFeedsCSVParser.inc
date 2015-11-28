<?php

class KbFeedsCSVParser extends FeedsCSVParser {

  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $source_config = $source->getConfigFor($this);
    $state = $source->state(FEEDS_PARSE);
    module_load_include('inc', 'kb_feeds', 'KbParserCSV');
    $parser = new KbParserCSV();
    $delimiter = $source_config['delimiter'] == 'TAB' ? "\t" : $source_config['delimiter'];
    $parser->setDelimiter($delimiter);
    $parser->setCurrentParser($this);
    $iterator = new ParserCSVIterator($fetcher_result->getFilePath());
    if (empty($source_config['no_headers'])) {
      $header = $this->parseHeader($parser, $iterator);
      if (!$header) {
        drupal_set_message(t('The CSV file is empty.'), 'warning', FALSE);
        return new FeedsParserResult();
      }
      $parser->setColumnNames($header);
    }

    $importer_id = $source->importer()->id;
    if (isset($importer_id)) {
      $file_log_name = $importer_id . '_log_' . date('Y-m-d_H-i-s') . '.txt';
      variable_set($importer_id . '_log_name', $file_log_name);

      variable_del($importer_id . '_total');
      variable_del($importer_id . '_rejected');
      variable_del($importer_id . '_created');
      variable_del($importer_id . '_updated');
      variable_del($importer_id . '_counted');
    }

    $start = $state->pointer ? $state->pointer : $parser->lastLinePos();
    $limit = $source->importer->getLimit();
    $rows = $this->parseItems($parser, $iterator, $start, $limit);
    $state->total = filesize($fetcher_result->getFilePath());
    $state->pointer = $parser->lastLinePos();
    $progress = $parser->lastLinePos() ? $parser->lastLinePos() : $state->total;
    $state->progress($state->total, $progress);
    return new FeedsParserResult($rows, $source->feed_nid);
  }

  protected function parseHeader(ParserCSV $parser, ParserCSVIterator $iterator) {
    $parser->setLineLimit(1);
    $rows = $parser->parse($iterator);
    if (!count($rows)) {
      return FALSE;
    }
    $header = array_shift($rows);
    foreach ($header as $i => $title) {
      $header[$i] = trim(drupal_strtolower($title));
    }
    return $header;
  }

  protected function parseItems(ParserCSV $parser, ParserCSVIterator $iterator, $start = 0, $limit = 0) {
    $parser->setLineLimit($limit);
    $parser->setStartByte($start);
    $rows = $parser->parse($iterator);
    return $rows;
  }

  public function getMappingSources() {
    return FALSE;
  }

  public function getSourceElement(FeedsSource $source, FeedsParserResult $result, $element_key) {
    return parent::getSourceElement($source, $result, drupal_strtolower($element_key));
  }

  public function sourceDefaults() {
    return array(
      'delimiter' => $this->config['delimiter'],
      'no_headers' => $this->config['no_headers'],
      'total_column' => $this->config['total_column'],
    );
  }
  public function sourceForm($source_config) {
    $form = array();
    $form['#weight'] = -10;

    $mappings = feeds_importer($this->id)->processor->config['mappings'];
    $sources = $uniques = array();
    foreach ($mappings as $mapping) {
      $sources[] = check_plain($mapping['source']);
      if (!empty($mapping['unique'])) {
        $uniques[] = check_plain($mapping['source']);
      }
    }
    $sources = array_unique($sources);

    $output = t('Import !csv_files with one or more of these columns: !columns.', array('!csv_files' => l(t('CSV files'), 'http://en.wikipedia.org/wiki/Comma-separated_values'), '!columns' => implode(', ', $sources)));
    $items = array();
    $items[] = format_plural(count($uniques), 'Column <strong>!columns</strong> is mandatory and considered unique: only one item per !columns value will be created.', 'Columns <strong>!columns</strong> are mandatory and values in these columns are considered unique: only one entry per value in one of these column will be created.', array('!columns' => implode(', ', $uniques)));
    $items[] = l(t('Download a template'), 'import/' . $this->id . '/template');
    $form['help'] = array(
      '#prefix' => '<div class="help">',
      '#suffix' => '</div>',
      'description' => array(
        '#prefix' => '<p>',
        '#markup' => $output,
        '#suffix' => '</p>',
      ),
      'list' => array(
        '#theme' => 'item_list',
        '#items' => $items,
      ),
    );
    $form['delimiter'] = array(
      '#type' => 'select',
      '#title' => t('Delimiter'),
      '#description' => t('The character that delimits fields in the CSV file.'),
      '#options'  => array(
        '|' => 'KB delimiter',
      ),
      '#default_value' => isset($source_config['delimiter']) ? $source_config['delimiter'] : ',',
    );
    $form['no_headers'] = array(
      '#type' => 'checkbox',
      '#title' => t('No Headers'),
      '#description' => t('Check if the imported CSV file does not start with a header row. If checked, mapping sources must be named \'0\', \'1\', \'2\' etc.'),
      '#default_value' => isset($source_config['no_headers']) ? $source_config['no_headers'] : 0,
    );
    $form['total_column'] = array(
      '#type' => 'textfield',
      '#title' => t('Total columns'),
      '#description' => t('Total columns in a validated row.'),
      '#default_value' => $this->config['total_column'],
    );
    return $form;
  }

  public function configDefaults() {
    return array(
      'delimiter' => '|',
      'no_headers' => 1,
      'total_column' => 1,
    );
  }

  public function configForm(&$form_state) {
    $form = array();
    $form['delimiter'] = array(
      '#type' => 'select',
      '#title' => t('Default delimiter'),
      '#description' => t('Default field delimiter.'),
      '#options' => array(
        '|' => 'KB delimiter',
      ),
      '#default_value' => $this->config['delimiter'],
    );
    $form['no_headers'] = array(
      '#type' => 'checkbox',
      '#title' => t('No headers'),
      '#description' => t('Check if the imported CSV file does not start with a header row. If checked, mapping sources must be named \'0\', \'1\', \'2\' etc.'),
      '#default_value' => $this->config['no_headers'],
    );
    $form['total_column'] = array(
      '#type' => 'textfield',
      '#title' => t('Total columns'),
      '#description' => t('Total columns in a validated row.'),
      '#default_value' => $this->config['total_column'],
    );
    return $form;
  }

  public function getTemplate() {
    $mappings = feeds_importer($this->id)->processor->config['mappings'];
    $sources = $uniques = array();
    foreach ($mappings as $mapping) {
      if (in_array(check_plain($mapping['source']), $uniques) || in_array(check_plain($mapping['source']), $sources)) {
        continue;
      }

      if (!empty($mapping['unique'])) {
        $uniques[] = check_plain($mapping['source']);
      }
      else {
        $sources[] = check_plain($mapping['source']);
      }
    }
    $sep = $this->config['delimiter'];
    $columns = array();
    foreach (array_merge($uniques, $sources) as $col) {
      if (strpos($col, $sep) !== FALSE) {
        $col = '"' . str_replace('"', '""', $col) . '"';
      }
      $columns[] = $col;
    }
    drupal_add_http_header('Cache-Control', 'max-age=60, must-revalidate');
    drupal_add_http_header('Content-Disposition', 'attachment; filename="' . $this->id . '_template.csv"');
    drupal_add_http_header('Content-type', 'text/csv; charset=utf-8');
    print implode($sep, $columns);
    return;
  }
}
