<?php
require_once('lib/nusoap.php');
$wsdl = "http://sebastian.cl/isw-ws/wsISW?wsdl";

$parametros = array();
$parametros['rut'] = $_POST['rut'];
$parametros['mensaje'] = $_POST['message'];
$cliente = new SoapClient($wsdl);
$resultado = $cliente->guardarMensaje($parametros);

echo 'Mensaje Enviado!';

?>