<!DOCTYPE html>
<html>
<head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Tarea 7 de Ingenier&iacutea de Software</title>
    </head>
    <body>
	<form method="post" action="index.php"> 
		<br> 
	<input type="submit" value="Volver"> 
		<br>
	</form>

        <form method="post" action="envio_mensaje.php">
        <table>
        	<tr>
                    <td><label>Env&iacutee su mensaje</label></td>
                    <td><input type="text" name="message" required></input></td>
                    <td><label>Rut</label></td>
                    <td><input type="text" name="rut" required></input></td>
                    <td></td>
                    <td><input type="submit"></input></td>
            </tr>        
        </table>
        </form>
    </body>
</html>