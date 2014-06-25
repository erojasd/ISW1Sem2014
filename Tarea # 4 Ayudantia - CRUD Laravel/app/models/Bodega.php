<?php
/**
 * Created by IntelliJ IDEA.
 * User: slenderman
 * Date: 23-06-14
 * Time: 09:37 PM
 */

class Bodega extends Eloquent {


    protected $primaryKey='id_b';// decirle a laravel que cambie el nombre de la clave primaria por defecto.
    protected $table = 'bodega';
    public $timestamps = false;

    public function ciudad() {
        return $this->hasMany('producto', 'fk_id_b');
    }

}