@extends('layouts.maestro')


@section('content')
<h1>Agregar Producto</h1>
@if(Session::has('mensaje'))

<h2 style="color: red;">{{ Session::get('mensaje') }}</h2>

@endif

{{ Form::open(array('url' => 'producto/addProducto','method'=>'post')) }}
<p>
    {{Form::label('titulo', 'Nombre Producto')}} {{Form::text('Nombre Producto')}}
    {{$errors->first("Nombre Producto")}}
</p>

<p>
    {{Form::label('contenido', 'Codigo Producto')}}{{Form::text('Codigo Producto')}}
    {{$errors->first("Codigo Producto")}}
</p>
<p>
    {{Form::label('contenido', 'Precio Neto')}}{{Form::text('Precio Neto')}}
    {{$errors->first("Precio Neto")}}
</p>
<p>
    {{Form::submit('Enviar')}}
</p>
{{ Form::close() }}
@stop