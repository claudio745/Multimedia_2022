<?php

// Operadores aritmeticos

//Suma
$numero1 = 5;
$numero2 = 2;
echo "Suma: "; 
echo $numero1 + $numero2;
echo "<br>";

//Resta
echo "Resta: ";
echo $numero1 - $numero2;
echo "<br>";

//Multiplicacion
echo "Multiplicacion: ";
echo $numero1 * $numero2;
echo "<br>";

//Division
echo "Division: ";    
echo $numero1 / $numero2;
echo "<br>";

//Modulo de division
echo "Modulo de division: ";
echo $numero1 % $numero2;
echo "<br>";

//Potencia
echo "Potencia: ";
echo $numero1 ** $numero2;
echo "<br>";

//Ejercicio: Calcular Raiz Cuadrada 
//Formula: -b + raiz(b al cuadrado - 4ac)/ 2a
// a = 1 | b = -2 | c = 1

$a = 1;
$b = -2;
$c = 1;

echo "Raiz cuadrada 1:  ";
echo (-$b) + (pow($b*$b, 1/2) - 4*$a * $c) / 2*$a; 
echo "<br>";
echo "Raiz cuadrada 2:  ";
echo (-$b) - (pow($b*$b, 1/2) - 4*$a * $c) / 2*$a; 

?>