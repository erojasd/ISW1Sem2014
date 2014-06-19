<!doctype html>
<html>
<head>
	<meta charset="UTF-8" />
	<title>
		@section('titulo')
		@show
	</title>
	@yield('css')
	@yield('javascript')
</head>
	<body>
			<div id="container">
			@yield('content')
		</div>
	</body>
</html>