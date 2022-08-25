<?php
    echo "Hola Mundo";
    echo "<br>";
    // Variables

    $nombre = "Juan";
    $apellido = "Perez";

    // Concatenar
    // 1ra forma
    echo "Hola " . $nombre . " " . $apellido; 

    // 2da forma

    echo "<br>";
    echo "Hola $nombre $apellido <br>";

    // Comentarios

    #comentario con el gato

    /* comentario multilinea */



    // Debuggin

    $nombre1 = "Juan";

    // opcion mas legible

    print_r($nombre1);

    // Más completa

    var_dump($nombre1);


    // averiguar los siguientes tipos de datos: 

    $numero_1 = 10; //int
    $numero_2 = 10.5; //float 
    $letra = "a"; // string
    $verdadero = true;  // bool

    echo "<br>";
    var_dump($verdadero);
    echo "<br>";
    var_dump($numero_1);
    echo "<br>";
    var_dump($numero_2);
    echo "<br>";
    var_dump($letra); 
    echo "<br>";


    //variables y constantes

    // variables se inician con un signo de dolar = $
    /* Reglas para nombres de variables:
        1- Signo de dolar.
        2- Nombre de variable.
        3- Nombre de variable no puede empezar con un número.".
        4- Los nombres de las variables no pueden contener espacios. 
        5- Nombre no puede contener caracteres especiales.
        6- El nombre de la variable puede contener guiones bajos _ .
        7- El nombre de la variable no puede contener acentos.
        8- El nombre de la variable debe ser lo más descritivo posible.
        9- Una buena práctica, es que el nombre de la variable este en minúsculas.

        //Constantes en mayusculas y sin signo de dolar
    */

    /* Constantes:
    1- Valor no puede cambiar.
    2- Se escriben con una funcion : 
        define ("Nombre de constante", Valor de constante);
    3-  

?>