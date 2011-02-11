<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:cfd="http://www.sat.gob.mx/cfd/2" >
  <xsl:output method="html"/>
  <xsl:template match="/cfd:Comprobante">
    <style type="text/css">
      table {
        width: 100%;
        font-size: 10pt;
      }
      th, td { 
        text-align: center;
      }
      td.h {
        font-weight: bold;
      }
      td.l {
        text-align: left;
      }
      td.r {
        text-align: right;
      }
      .box {
        border: 1px solid black;
      }
    </style>
    <table cellspacing="0" cellpadding="2" border="1" nobr="true">
      <tr style="font-weight: bold;">
        <th width="8%">Id.</th>
        <th width="57%">Descripcion</th>
        <th width="9%">Cantidad</th>
        <th width="8%">Unidad</th>
        <th width="8%">Valor Unitario</th>
        <th width="10%">Importe</th>
      </tr>
      <xsl:for-each select="cfd:Conceptos/cfd:Concepto">
        <tr>
          <td><xsl:if test="@noIdentificacion"><xsl:value-of select="@noIdentificacion"/></xsl:if></td>
          <td style="text-align: left"><xsl:value-of select="@descripcion"/></td>
          <td><xsl:value-of select="@cantidad"/></td>
          <td><xsl:if test="@unidad"><xsl:value-of select="@unidad"/></xsl:if></td>
          <td><xsl:value-of select="@valorUnitario"/></td>
          <td><xsl:value-of select="@importe"/></td>
        </tr>
      </xsl:for-each>
    </table>
    <span style="font-size: 6pt"><br/></span>
    <table cellspacing="0" cellpadding="2">
      <tr>
        <td width="60%"  style="vertical-align:middle">
          <br/><br/>
          <strong><xsl:value-of select="@formaDePago"></xsl:value-of></strong>
        </td>
        <td width="40%">
          <table class="box">
            <tr>
              <td class="l h">Subtotal</td>
              <td class="r h"><xsl:value-of select="@subTotal"/></td>
            </tr>
            <tr>
              <td class="l h">Descuento global</td>
              <td class="r h"><xsl:value-of select="@descuento"/></td>
            </tr>
            <tr>
              <td class="l h"><xsl:value-of select="cfd:Impuestos/cfd:Traslados/cfd:Traslado/@impuesto"/><xsl:text> </xsl:text><xsl:value-of select="cfd:Impuestos/cfd:Traslados/cfd:Traslado/@tasa"/>%</td>
              <td class="r h"><xsl:value-of select="cfd:Impuestos/@totalImpuestosTrasladados"/></td>
            </tr>
            <tr style="font-size: 12pt">
              <td class="l h">TOTAL</td>
              <td class="r h"><xsl:value-of select="@total"/></td>
            </tr>
          </table>
        </td>
      </tr>
      <tr></tr><tr></tr>
      <tr>
        <td class="l" colspan="2">
          <strong>Sello</strong><br/>
          <xsl:value-of select="@sello"/><br/>
        </td>
      </tr>
    </table>
	</xsl:template>
</xsl:stylesheet>