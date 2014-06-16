<?php
require_once("lib/nusoap.php");

$wsdl = "http://informatica.utem.cl:8011/dirdoc-auth/ws/auth?wsdl";

$err = $cliente->getError();
if ($err) {
    echo '{"error_connect":"' . $err . '"}';
}
// Versión de "er" profe
$parametros = array();
$parametros['rut'] = $_POST['user'];
$parametros['password'] = hash('sha256', $_POST['pass']);
$cliente = new SoapClient($wsdl);
$respuesta = $cliente->autenticar($parametros);

$response = $respuesta->return;

echo "<pre>";
print_r($response);
echo "</pre>";
?>