<?php
// $Id$

/**
 * @file Contains PDF creation functions based on TCPDF.
 * code is split for code reuseability in the other CFD module
 */

/**
 * Makes a PDF based on 2 XSL Template files (located in resources/cfd_*.xsl)
 * one for header, one for content and also uses SAT provided file: cadenaoriginal_2_0.xslt
 * Uses FEpdf class to define the header and footer (located in reources/FEpdf.php)
 * Custom code to word-wrap the 'cadena original' using | instead of spaces.
 * @param string $xml_string The xml string of the XML FE to convert to PDF
 * @return a TCPDF object of the converted CFD
 **/
function cfd_make_pdf($xml_string) {
  require_once libraries_get_path('tcpdf') . '/tcpdf.php';
  require_once drupal_get_path('module', 'cfde') . '/resources/FEpdf.php';
  //Apply XSLT
  $doc = new DOMDocument(); $doc->loadXML($xml_string);
  //Header
  $xsl_header_file = drupal_get_path('module', 'cfde') . '/resources/cfd_header.xsl';
  $xsl_header = new DOMDocument(); $xsl_header->load($xsl_header_file);
  $xsl = new XSLTProcessor(); $xsl->importStylesheet($xsl_header);
  $html_header = $xsl->transformToXml($doc);
  //Content
  $xsl_content_file = drupal_get_path('module', 'cfde') . '/resources/cfd_content.xsl';
  $xsl_content = new DOMDocument(); $xsl_content->load($xsl_content_file);
  $xsl = new XSLTProcessor(); $xsl->importStylesheet($xsl_content);
  $html_content = $xsl->transformToXml($doc);
  //"cadena original" or cado
  $xsl_cado_file = drupal_get_path('module', 'cfde') . '/resources/sat/cadenaoriginal_2_0.xslt';
  $xsl_cado = new DOMDocument(); $xsl_cado->load($xsl_cado_file);
  // hide warnings in @...importStylesheet because it complains about xslt version 2.0
  $xsl = new XSLTProcessor(); @$xsl->importStylesheet($xsl_cado);
  $cadena_original = $xsl->transformToXml($doc);
  
  //generate PDF
  $pdf = new FEpdf();
  $pdf->SetMargins(10, 10, 10, TRUE);
  $pdf->headerHTML($html_header);
  $pdf->AddPage();
  
  $pdf->writeHTML($html_content);

  //Cadena Original with word wrapping in |
  $pdf->SetY($pdf->getY() - 10);
  $pdf->SetFontSize(10);
  $pdf->writeHTML('<strong>Cadena Original</strong>');
  $pdf->SetFontSize(8);
  //word wrapping
  $cado = explode('|', substr($cadena_original, 2, -2));
  $pdf->SetCellPadding(0);
  $pdf->Write(0, '||');
  $margins = $pdf->getMargins();
  $line_width = $pdf->getPageWidth() - $margins['left'] - $margins['right'];
  $space_left = $line_width -  $pdf->GetStringWidth('||');
  $totalwords = count($cado);
  $i = 0;
  foreach ($cado as $word) {
    //if we are on the last word
    if ($i < $totalwords - 1) {
      $word_width = $pdf->GetStringWidth($word . '|');
    }
    else {
      $word_width = $pdf->GetStringWidth($word . '||');
    }
    
    if ($word_width > $space_left) {
      $space_left = $line_width - $word_width;
      $pdf->Ln();
    }
    else {
      $space_left -= $word_width;
    }
    $pdf->Write(0, $word . '|');
    $i++;
  }
  $pdf->Write(0, '|');
  //serve file
  $pdf->SetCreator("Drupal-CFD module with " . PDF_CREATOR);
  $pdf->SetAuthor(variable_get('site_name', 'the website'));
  return $pdf;
}
