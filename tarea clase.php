<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
      <?php
        $arreglo = [
            ["Nombre: " => "Juan",  "Edad: " => 21, "Ocupacion: " => "Desarrollador web"], 
            ["Nombre: " => "Pedro", "Edad: " => 36, "Ocupacion: " => "Vendedor"], 
            ["Nombre: " => "Diego", "Edad: " => 25, "Ocupacion: " => "Estudiante"]];
        
            foreach($arreglo as $key => $value){
            echo "<ul>";
             foreach($value as $key2 => $value2){
              print_r("<li>"."<b>".$key2."</b>".$value2."<br>"."</li>");
             }
            echo "</ul>";
            };

        ?>
</body>
</html>