<form method="post" action="index.php"> 
	<br> 
	<input type="submit" value="Volver"> 
</form>

<?php
require_once('lib/nusoap.php');
$wsdl = "http://sebastian.cl/isw-ws/wsISW?wsdl";

$parametros = array();
$parametros['rut'] = $_POST['rut'];
$parametros['mensaje'] = $_POST['message'];
$cliente = new SoapClient($wsdl);
$resultado = $cliente->guardarMensaje($parametros);

$response = $resultado->return;

echo "<pre>";
print_r($response);
echo "</pre>";
?>