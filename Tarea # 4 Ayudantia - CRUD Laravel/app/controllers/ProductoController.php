<?php

class ProductoController extends BaseController {

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
	public function getAddProducto()
	{
        return $this->layout->content = View::make('producto.addProducto');
	}
    public function getUpdadeProducto(){
       $datos = Producto::find($id_p);
       return $this->layout->content = View::make('producto.updateProducto');
    }


}
