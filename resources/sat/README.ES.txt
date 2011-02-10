$Id$

El modulo require 2 archivos en este directorio: 

cfdv2.xsd .................. [1]
cadenaoriginal_2_0.xslt  ... [2]

Disponibles en:
[1] http://www.sat.gob.mx/sitio_internet/cfd/2/cfdv2.xsd 
[2] http://www.sat.gob.mx/sitio_internet/cfd/2/cadenaoriginal_2_0/cadenaoriginal_2_0.xslt

NOTA:
Es posible obenter los archivos incluidos en [2]; por ejemplo: 
<xsl:include href="http://www.sat.gob.mx/sitio_internet/cfd/2/cadenaoriginal_2_0/utilerias.xslt"/>

Al obtener este archivo se pude poner en el mismo directorio y modificar [2]
para que busque los archivos localmente; por ejemplo al copiar utilerias.xslt a
este directorio (resources/sat/) quedaria así:
<xsl:include href="utilerias.xslt"/>
