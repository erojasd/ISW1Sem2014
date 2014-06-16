<form method="post" action="index.php"> 
	<br> 
	<input type="submit" value="Volver"> 
	<br>
</form>

<?php
//require_once('lib/nusoap.php');
$wsdl = "http://sebastian.cl/isw-ws/wsISW?wsdl";

$parametro = array();
$parametro['rut'] = $_POST['rut'];
$cliente = new SoapClient($wsdl);
$resultado = $cliente->getAccesosPorRut($parametro);

echo "<pre>";
print_r($resultado);
echo "</pre>";
?>