<?php

//Arreglos

//Ejemplo 1}

$arreglo = array("Pedro", "Juan", "Diego");
echo "<pre>";
print_r($arreglo);
echo "</pre>";

//Ejemplo 2

$arreglo2 = array(
    "Juan" => "Perez",
    "Pedro" => "Gonzalez",
    "Maria" => "Lopez"
);

echo "<pre>";
print_r($arreglo2);
echo "</pre>";

// Iterar un arreglo

$arreglo3 = [
    "Nombre" => "Juan Perez",
    "Edad" => 21,
    "Ocupacion" => "Desarrollador Web"
];

foreach($arreglo3 as $value){
    echo $value . "<br>";    
}

// otra forma de hacer un foreach

/*
foreach($arreglo3 as $key => $value){
    echo $key . ": " . $value . "<br>";    
}
*/

// Arreglo de arreglos

$arreglo4 = [
    [
        "Nombre" => "Juan Perez",
        "Edad" => 21,
        "Ocupacion" => "Desarrollador Web"
    ],
    [   
        "Nombre" => "Pedro",
        "Edad" => 24,
        "Ocupacion" => "Vendedor"
    ],
    [
        "Nombre" => "Diego",
        "Edad" => 25,
        "Ocupacion" => "Informatico"
    ]
];

foreach($arreglo4 as $key => $value){
    foreach($value as $key_2 => $value_2){
        echo $key_2 . ": " . $value_2 . "<br>";
    }
    echo "<br>";
};


