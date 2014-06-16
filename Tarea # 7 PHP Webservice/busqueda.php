<?php
//require_once('lib/nusoap.php');
$wsdl = "http://sebastian.cl/isw-ws/wsISW?wsdl";

$parametro = array();
$parametro['rut'] = $_POST['rut'];
$cliente = new SoapClient($wsdl);
$resultado = $cliente->getMensajesPorRut($parametro);

echo "<pre>";
print_r($resultado);
echo "</pre>";
?>