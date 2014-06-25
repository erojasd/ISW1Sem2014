@extends('layouts.maestro')



@section('content')
<h1>Editar Ciudad</h1>
@if(Session::has('mensaje'))

<h2 style="color: red;">{{ Session::get('mensaje') }}</h2>

@endif

{{ Form::open(array('url' => 'producto/updateProducto/','method'=>'post')) }}
<p>
    {{Form::label('titulo', 'Producto')}} {{Form::text('Nombre Producto',$datos['Nombre Producto'])}}
    {{$errors->first("Nombre")}}
</p>
<p>
    {{Form::label('contenido', 'Pais')}}{{ Form::select('pais', Paises::lists('nombre', 'id'),$datos['fk_pais_id'])}}
    {{$errors->first("pais")}}
</p>
<p>
    {{Form::hidden('id',$datos['id'])}}
    {{Form::submit('Actualizar')}}
</p>
{{ Form::close() }}
@stop