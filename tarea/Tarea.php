<?php

require_once('conexion.php');
if (empty($_POST['Nombre']) || empty($_POST['Apellido'])){
    echo "Por favor llene los campos correspondientes";
}else{
    $nombre = $_POST['Nombre'];
    $apellido = $_POST['Apellido'];
    $imagen = addslashes(file_get_contents($_FILES['imagen']['tmp_name']));
    $query = "INSERT INTO  usuarios (nombre, apellido, imagen) VALUES ('$nombre', '$apellido', '$imagen')";
    $resultado = $conexion->query($query);

    if($resultado){
        echo "Se han insertado los datos correctamente";
    }else{
        echo "No se an guardado los datos";
    }
}
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <link rel="stylesheet" type="text/css" href = style.css> 
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1>Ingrese sus datos </h1>
    <form  method= "POST" enctype = "multipart/form-data"> 
            <label for="Nombre"> Nombre: </label>
            <input type="text" name="Nombre" id="Nombre">
            <br><br>
            <label for="Apellido"> Apellido: </label>
            <input type="text" name="Apellido" id="Apellido">
            <br><br>
            <label> Foto: </label>
            <input type = "file" name = "imagen"><br><br>
            <input type="submit" value="Enviar formulario">
        </form>
</body>
</html>