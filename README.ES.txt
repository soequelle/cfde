$Id$

INTRODUCIÓN
-----------

La intención de éste modulo es la distribución de facturas electrónicas
emitidas. Por eso el nombre cfde = comprobante fiscal digital emitido.

INFORMACIÓN
-----------

El modulo necesita que los usuarios se registren con su RFC como nombre de
usuario. Esto permite que se les puede dar acceso únicamente a sus CFDs o FEs.
El usuario administrador (uid 1) tiene acceso a todas las facturas.
La sección NOTAS tiene información sobre como validar los nombres de usuario.

Este modulo utiliza el modulo 'Rules' para enviar notificaciones a los usuarios
cuando se crea una nueva Factura asignada al cliente.

El modulo no contempla al Comprobante Fiscal Digital por Internet por ahora.

INSTALACIÓN
-----------

El modulo requiere que TCPDF (http://www.tcpdf.org/) esté
 en 'sites/all/libraries' (queda como: 'sites/all/libraries/tcpdf')
  
También son necesarios algunos archivos del SAT (Servicio de Administración
 Tributaria), el archivo 'resources/sat/README.ES.txt' contiene detalles.

NOTAS
-----

La expresión regular para validar el RFC usando el modulo 
 'custom_username_validation' es:

  - Todo en mayúsculas:
/^(([A-Z]){3,4})([0-9]{6})((([A-Z]|[0-9]){3}))$/
  
  - O permitiendo minúsculas:
/^(([A-Z]|[a-z]){3,4})([0-9]{6})((([A-Z]|[a-z]|[0-9]){3}))$/

 Como los nombres usuario no distingen entre mayúsculas y minúsculas esto no es
 muy importante.