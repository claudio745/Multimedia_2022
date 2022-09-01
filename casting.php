<?php

/* Casting es cuando forzamos a un tipo de dato a convertirse en otro */

$numero_string = "7"; //String
var_dump($numero_string);
echo "<br>";

$numero_float = (float) $numero_string;
var_dump($numero_float);
echo "<br>";

$dias = 5.85;
$dias = (int) $dias;        //integer
var_dump($dias);
echo "<br>";

$bandera = 0;     //Falso cuando es 0, verdadero cuando es distinto que 0
$bandera = (bool) $bandera;
var_dump($bandera);
echo "<br>";