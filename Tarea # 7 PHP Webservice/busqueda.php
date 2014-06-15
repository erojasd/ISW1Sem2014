<?php
require_once('lib/nusoap.php');
$wsdl = "http://sebastian.cl/isw-ws/wsISW?wsdl";

$parametro = array();
$parametro['rut'] = $_POST['rut'];
$cliente = new SoapClient($wsdl);
$resultado = $cliente->guardarMensaje($parametro);

echo 'Mensaje Enviado!'.$resultado;

?>