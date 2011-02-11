<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:cfd="http://www.sat.gob.mx/cfd/2" >
<xsl:output method="html"/>
  <xsl:template match="/cfd:Comprobante">
    <style type="text/css">
      .top {
        text-align: center;
        border-bottom: 2px solid black;
        font-size: 12pt
      }
      table {
        font-size: 10pt;
        width: 100%;
      }
      th, td { 
        width: 50%;
      }
      td.h {
        font-weight: bold;
        text-align: left;
      }
      td.box {
        border: 1px solid black;
      }
      tr.bottom {
      }
      .center-txt {
        text-align: center;
      }
    </style>
    <span style="font-size: 8px"><br/></span>
    <div class="top">
      <xsl:apply-templates select="cfd:Emisor"/>
    </div>
    <table cellpadding="4" cellspacing="3">
      <tr class="center-txt">
        <td>
          <strong>Domicilio:</strong><br/>
          <xsl:apply-templates select="cfd:Emisor/cfd:DomicilioFiscal"/>
        </td>
        <td>
          <strong>Expedido En:</strong><br/>
          <xsl:apply-templates select="cfd:Emisor/cfd:ExpedidoEn"/>
        </td>
      </tr>
      <tr>
        <td class="box">
          <strong>Facturar a:</strong><br/>
          <xsl:apply-templates select="cfd:Receptor"/>
          <div class="center-txt">
	          <strong>Domicilio:</strong><br/>
	          <xsl:apply-templates select="cfd:Receptor/cfd:Domicilio"/>
          </div>
        </td>
        <td class="box">
          <table>
			      <tr>
			        <td class="h">FACTURA</td>
			        <td class="h"><xsl:value-of select="@folio"/></td>
			      </tr>
			      <tr>
			        <td class="h">Serie</td>
			        <td class="h"><xsl:value-of select="@serie"/></td>
			      </tr>
			      <tr>
			        <td class="l">Fecha-Hora</td>
			        <td class="r"><xsl:value-of select="@fecha"/></td>
			      </tr>
			      <tr>
			        <td class="l">No. Aprobación</td>
			        <td class="r"><xsl:value-of select="@noAprobacion"/></td>
			      </tr>
			      <tr>
			        <td class="l">Año Aprobacion</td>
			        <td class="r"><xsl:value-of select="@anoAprobacion"/></td>
			      </tr>
			      <tr>
			        <td class="l">No. Certificado</td>
			        <td class="r"><xsl:value-of select="@noCertificado"/></td>
			      </tr>
			      <tr>
		          <td class="l">Pagina</td>
		          <td class="r"></td>
		        </tr>
          </table>
        </td>
      </tr>
    </table>
	</xsl:template>

  <!--Direccion-->
  <xsl:template match="cfd:DomicilioFiscal|cfd:ExpedidoEn|cfd:Domicilio">
		<xsl:if test="@calle"><xsl:value-of select="@calle"/></xsl:if>
		<xsl:if test="@noExterior"><xsl:text> Núm. </xsl:text><xsl:value-of select="@noExterior"/></xsl:if>
		<br/>
		<xsl:if test="@colonia"><xsl:text>Col. </xsl:text><xsl:value-of select="@colonia"/></xsl:if>
		<xsl:if test="@localidad"><xsl:text> Loc. </xsl:text><xsl:value-of select="@localidad"/></xsl:if>
		<br/>
		<xsl:if test="@referencia"><xsl:value-of select="@referencia"/><br/></xsl:if>
		<xsl:if test="@municipio"><xsl:value-of select="@municipio"/><xsl:text>, </xsl:text></xsl:if>
		<xsl:if test="@estado"><xsl:value-of select="@estado"/></xsl:if>
		<br/>
		<xsl:if test="@codigoPostal"><xsl:text>C.P. </xsl:text><xsl:value-of select="@codigoPostal"/><xsl:text> </xsl:text></xsl:if>
		<xsl:value-of select="@pais"/>
  </xsl:template>

  <!--Nombre y RFC-->
  <xsl:template match="cfd:Emisor|cfd:Receptor">
    <xsl:if test="@nombre"><xsl:value-of select="@nombre"/></xsl:if>
    <br/>
    <strong>RFC: </strong><xsl:value-of select="@rfc"/>
  </xsl:template>
</xsl:stylesheet>