@extends('layouts.maestro')




@section('content')
<h1>Listado de Bodegas</h1>
<ul>
    @foreach($datosBodegas as $datoBodega)
    <li>
        <?php echo $datoBodega->nombre_bodega . " " . HTML::link("bodega/updatebodega/" . $datoBodega->id_b, 'Actualizar') . " " ?>
    </li>
    @endforeach
</ul>
@stop