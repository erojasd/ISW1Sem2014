@extends('layouts.maestro')


@section('content')
<h1>Agregar Bodega</h1>
@if(Session::has('mensaje'))

<h2 style="color: red;">{{ Session::get('mensaje') }}</h2>

@endif

{{ Form::open(array('url' => 'bodega/addBodega','method'=>'post')) }}
<p>
    {{Form::label('titulo', 'Nombre Bodega')}} {{Form::text('Nombre Bodega')}}
    {{$errors->first("Nombre bodega")}}
</p>

<p>
    {{Form::label('contenido', 'Codigo Bodega')}}{{Form::text('Codigo bodega')}}
    {{$errors->first("Codigo Bodega")}}
</p>
<p>
    {{Form::submit('Enviar')}}
</p>
{{ Form::close() }}
@stop