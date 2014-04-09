<!DOCTYPE html>
<html lang=es>


<body background="F2.JPG" style="background-attachment: fixed">
<html>
     <head>
	     <meta charset="utf-8"/>
		 <meta description = "Desarrollo de la tarea 1"/>
		 <title>Tarea 1 Ayudantia Ingenieria de Software </title>		 
		 <LINK href="styles.css" rel="stylesheet" type="text/css">
		 <link rel="shortcut icon" href="ICONO.ico"/>
		   </head>

     <body>
				 <div><IMG src="ban.png" WIDTH=100% HEIGHT=100% position: relative></div>
				 <br>
				 
				 <div> 
				 <div id="frases">
				 <TABLE border="8" WIDTH="1000" HEIGHT = "80" align=center id= tabla0> 
				        <TH><?php
                        
                         
                         $vector = array(
                             1=>"BUDA: Todo lo que somos es el resultado de lo que hemos pensado está fundado en nuestros pensamientos y está hecho de nuestros pensamientos",
                             2=>"JAVIER IMBRODA: El talento sin esfuerzo solo sirve para divertirse",
                             3=>"GABRIEL ALEMANY: La actitud positiva debe ser un hábito, trabajado todos los días sobre todo en las situaciones adversas",
							 4=> "CAROLINA HERRERA: La educación es el principal vestido para la fiesta de la vida.",
							 5=> "H. ROSS PEROT: La mayoría de las personas abandona justo cuando está a punto de conseguir el éxito. Lo deja a un metro de la meta. Lo deja en el último momento del partido, a un punto de la victoria",
							 6=> "JOSEF AJRAM: Avanzar, conseguir lo que te propones supone esfuerzo, entrenamiento, sufrimiento...¿Existe la suerte? No lo sabemos...pero lo que sí que sabemos es que todo está en nuestras manos...Un nuevo día, un nuevo reto.   "
                             
                         );
                         $numero = rand(1,6);
                         echo "$vector[$numero]";                         
                         ?><TR> 
				 
				 
				 <b>
				 </div>                   
	             
					<TABLE border="3" WIDTH="700" align=center id= tabla1>
											<COLGROUP>
											<COL><COL align="char" char=".">
											<THEAD>
											<TR><TH><center><b> <?PHP echo"Datos"; ?> <TH> 
											<TBODY>
											<TR><TD> <center><b><?PHP echo"Nombre";?><TD><b> <center>Ricardo L&#243pez N&#250&ntildeez
											<TR><TD><center><b>Carrera<TD> <center><b> Ingenier&#237a Civil en Computaci&#243n (21041)
											<TR><TD><center><b>Edad<TD> <center><b>24 años
											<TR><TD><center><b>Github<TD><center> <b><a href=https://github.com/rlopezn>github/rlopezn</a>
											<TR><TD><center><b>Avatar<TD><BODY><center><IMG SRC="toro.jpg" WIDTH=180 HEIGHT=130></BODY> 
						</TABLE>
						<TABLE border="3" WIDTH="700" align=center id=tabla2>
											<COLGROUP>
											<COL><COL align="char" char=".">
											<THEAD>
											<TR><TH><center><?PHP echo"Datos"; ?> <TH> 
											<TBODY>
											<TR><TD><center><?PHP echo"Nombre";?><TD><center>Andr&#233s Guerrero Urbina
											<TR><TD><center>Carrera<TD><center> Ingenier&#237a Civil en Computaci&#243n (21041)
											<TR><TD><center>Edad<TD> <center>23 años
											<TR><TD><center>Github<TD><center> <a href=https://github.com/famfrit>github/famfrit</a>
											<TR><TD><center>Avatar<TD><BODY><center><IMG SRC="bad luck.jpg" WIDTH=180 HEIGHT=160></BODY>
						</TABLE>
						<TABLE border="3" WIDTH="700" align=center id=tabla3>
											<COLGROUP>
											<COL><COL align="char" char=".">
											<THEAD>
											<TR><TH><center><?PHP echo"Datos"; ?> <TH> 
											<TBODY>
											<TR><TD><center><?PHP echo"Nombre";?><TD><center>Daniel Guti&#233rrez Pizarro
											<TR><TD><center>Carrera<TD><center> Ingenier&#237a Civil en Computaci&#243n (21041)
											<TR><TD><center>Edad<TD> <center>24 años
											<TR><TD><center>Github<TD> <center><a href=https://github.com/Lanceconan>github/lanceconan</a>
											<TR><TD><center>Avatar<TD><BODY> <center><IMG SRC="fapyayin.jpg" align=center WIDTH=180 HEIGHT=130></BODY>
						</TABLE>
     </body>

</html>

 