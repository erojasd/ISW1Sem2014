<?php

class BodegaController extends BaseController {

	/*
	|--------------------------------------------------------------------------
	| Default Home Controller
	|--------------------------------------------------------------------------
	|
	| You may wish to use controllers instead of, or in addition to, Closure
	| based routes. That's great! Here is an example controller method to
	| get you started. To route to this controller, just add the route:
	|
	|	Route::get('/', 'HomeController@showWelcome');
	|
	*/
    protected $layout = 'layouts.maestro';
	public function getIndex()
	{
        return $this->layout->content = View::make('bodega.addBodega');

	}
    public function getBodegas(){
        $datosBodegas = Bodega::all();
        return $this->layout->content=View::make('bodega.listarBodega',compact("datosBodegas"));
    }
    public function getUpdatebodega($id_b =null){
        $datosBodegas = Bodega::find($id_b);
        return $this->layout->content = View::make('bodega.updateBodega', compact("datosBodegas"));

    }
    public function postupdatebodega(){
        $inputs=Input::all();
        $reglas=array(
            'Nombre Bodega' =>'required|min:4',
            'Codigo Bodega' => 'required|min3'
        );
        $mensajes=array(
            "required"=>"este campo es Obligatorio",
            "min"=>"debe tener un minimo de %s caracteres"
        );
        $validar=Validator::make($inputs,$reglas,$mensajes);
        if ($validar->fails()) {
            return Redirect::back()->withErrors($validar);
        } else {

        }

    }

}
