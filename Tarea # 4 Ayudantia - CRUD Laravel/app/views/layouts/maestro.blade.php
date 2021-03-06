<!DOCTYPE html>
<html>
<head>
    <title>@yield('title', 'Aprendiendo Laravel')</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <!-- Bootstrap -->
    {{ HTML::style('assets/css/bootstrap.min.css', array('media' => 'screen')) }}
    @yield('css')
    @yield('javascript')

</head>
<body>
<div id="wrap">
    <div class="contenido">
        @yield('content')
    </div>
</div>
<!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
<script src="//code.jquery.com/jquery.js"></script>
<!-- Include all compiled plugins (below), or include individual files as needed -->
<script src="{{ assets(‘assets/js/bootstrap.min.js’) }}"></script>
</body>
</html>