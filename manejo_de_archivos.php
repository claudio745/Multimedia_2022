<?php  


// modo de apertura de archivos
// r solo lectura
// r+ lectura y escritura
// w solo escritura, sobreescribe el archivo si existe, crea el archivo si no existe 
// w+ escitura y lectura, sobrescribe el archivo si existe, crea el archivo si no existe
//a añadido (agregar contenido), crea el archivo si no existe
// a+ añadido (agregar contenido) y lectura, cea el archivo si este no existe 


// leer archivo

$archivo = fopen("archivo.txt", "r");
while(!feof($archivo))
{
    echo fgets($archivo) . "<br>";
}

fclose($archivo);

// Escribir archivo

$archivo2 = fopen("archvios/archivo_2.txt", "w");
fwrite($archivo, "Esto es una linea de codigo" . PHP_EOF); 