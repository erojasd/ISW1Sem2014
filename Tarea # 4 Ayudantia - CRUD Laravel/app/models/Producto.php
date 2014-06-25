<?php
class Ciudad extends Eloquent {

protected $table = 'Producto';
public $timestamps = false;

public function pais(){
return $this->belongsTo('Bodega');
}
}