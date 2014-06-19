<?php

class TestController extends BaseController {

	protected $layout = 'layouts.master';

	public function getIndex()
	{
		$nombre="Algo";
		return $this->layout->content = View::make('test.index', compact("nombre"));
	}

}
