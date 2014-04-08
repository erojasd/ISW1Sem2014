<!DOCTYPE html>
<html lang=es>

<html>
     <head>
	     <meta charset="utf-8"/>
		 <meta description = "Desarrollo de la tarea 1"/>
		 <title>Tarea 1 Ayudantia Ingenieria de Software </title>
		 <LINK href="styles.css" rel="stylesheet" type="text/css">
		   </head>

     <body>
	             <h1><center> Ficha Tecnica </center> </h1>
				 <h2><center> Frases </center></h2>
				 <br>
				 <div id="frases">
                    <footer>
                        <p>
                          
                        <?
                        
                         
                         $vector = array(
                             1=>"”Todo lo que somos es el resultado de lo que hemos pensado; 
							 está fundado en nuestros pensamientos y está hecho de nuestros pensamientos..” Buda",
                             2=>"”Construya el algoritmo Bonivka” Ricardo 5 lucas Corbinaud",
                             3=>"”asdf”  qwerty",
                             
                         );
                         $numero = rand(1,3);
                         echo "$vector[$numero]";
                         
                         ?>
                        </p>
                        <p>

                    </footer>
            </div>
	
					<TABLE border="1" align=center id= tabla1>
											<COLGROUP>
											<COL><COL align="char" char=".">
											<THEAD>
											<TR><TH><?PHP echo"Datos"; ?> <TH> Etc
											<TBODY>
											<TR><TD><?PHP echo"Nombre";?>:  <TD>Ricardo L&#243pez N&#250&ntildeez
											<TR><TD>Carrera: <TD> Ingenier&#237a Civil en Computaci&#243n (21041)
											<TR><TD>Edad:    <TD> 24
											<TR><TD>Github:  <TD> <a href=https://github.com/rlopezn>github/rlopezn</a>
											<TR><TD>Foto:    <TD><BODY> <IMG SRC="toro.jpg" WIDTH=130 HEIGHT=101></BODY> 
						</TABLE>
						<TABLE border="1" align=center id=tabla2>
											<COLGROUP>
											<COL><COL align="char" char=".">
											<THEAD>
											<TR><TH><?PHP echo"Datos"; ?> <TH> Etc
											<TBODY>
											<TR><TD><?PHP echo"Nombre";?>:  <TD>Andr&#233s Guerrero Urbina
											<TR><TD>Carrera: <TD> Ingenier&#237a Civil en Computaci&#243n (21041)
											<TR><TD>Edad:    <TD> 23
											<TR><TD>Github:  <TD> <a href=https://github.com/famfrit>github/famfrit</a>
											<TR><TD>Foto:    <TD><BODY> <IMG SRC="bad luck.jpg" WIDTH=130 HEIGHT=101></BODY>
						</TABLE>
						<TABLE border="1" align=center id=tabla3>
											<COLGROUP>
											<COL><COL align="char" char=".">
											<THEAD>
											<TR><TH><?PHP echo"Datos"; ?> <TH> Etc
											<TBODY>
											<TR><TD><?PHP echo"Nombre";?>:  <TD>Daniel Guti&#233rrez Pizarro
											<TR><TD>Carrera: <TD> Ingenier&#237a Civil en Computaci&#243n (21041)
											<TR><TD>Edad:    <TD> 24
											<TR><TD>Github:  <TD> <a href=https://github.com/Lanceconan>github/lanceconan</a>
											<TR><TD>Foto:    <TD><BODY> <IMG SRC="fapyayin.jpg" WIDTH=130 HEIGHT=101></BODY>
						</TABLE>
						
						


					 
			
			

     </body>

</html>

 
