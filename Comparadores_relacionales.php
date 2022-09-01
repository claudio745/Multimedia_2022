<?php

$a = 5;
$b = 5; 
$b_2 = "5";
$c = 9;

// == igual, no compara tipo de datos

var_dump($a == $b);
echo "<br>";
var_dump($a == $b_2);
echo "<br>";

// != distinto, compara tios de datos

var_dump($a != $b);
echo "<br>";
var_dump($a != $b_2);
echo "<br>";

// < menor que 

var_dump($a < $b);
echo "<br>";
var_dump($a < $c);
echo "<br>";

// <= menor o igual

var_dump($a <= $b);
echo "<br>";
var_dump($a <= $c);
echo "<br>";

// > mayor que

var_dump($a > $b);
echo "<br>";
var_dump($a > $c);
echo "<br>";

// >= mayor o igual

var_dump($a <= $b);
echo "<br>";
var_dump($a <= $c);
echo "<br>";




