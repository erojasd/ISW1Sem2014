@extends('layouts.maestro')


@section('content')
<h1>Actualizar Bodega</h1>


{{ Form::open(array('url' => 'bodega/updatebodega','method'=>'post')) }}
<p>
    {{Form::label('titulo', 'Nombre Bodega')}} {{Form::text('Nombre Bodega',$datosBodegas['nombre_bodega'])}}
    {{$errors->first("Nombre bodega")}}
</p>

<p>
    {{Form::label('contenido', 'Codigo Bodega')}} {{Form::text('Codigo Bodega',$datosBodegas['codigo_bodega'])}}
      {{$errors->first("Codigo Bodega")}}
</p>
<p>
    {{Form::hidden('id',$datosBodegas['id'])}}
    {{Form::submit('Actualizar')}}
</p>
{{ Form::close() }}
@stop