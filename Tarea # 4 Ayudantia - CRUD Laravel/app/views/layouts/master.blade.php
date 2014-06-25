<!doctype html>
<html>
<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
    <link href="public/css/boostrap-theme.min.css" rel="stylesheet">
    <title>
        @section('titulo')
        título desde template
        @show
    </title>
    @yield('css')
    @yield('javascript')

</head>
<body>
<div id="header">encabezado del sitio web</div>
<div id="contenido">
    @yield('content')
</div>
<div id="footer">
    acá va el footer
</div>
</body>
</html>