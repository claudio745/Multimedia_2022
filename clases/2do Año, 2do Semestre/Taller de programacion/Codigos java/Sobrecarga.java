/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package sobrecarga;

/**
 *
 * @author claud
 */
public class Sobrecarga {
    String nombre;
    int edad;
    String nacionalidad;

    public Sobrecarga(String nombre, int edad) {
        this.nombre = nombre;
        this.edad = edad;
    }

    public Sobrecarga(String nacionalidad) {
        this.nacionalidad = nacionalidad;
    }
    
    public void caminar()
    {
        System.out.println("soy"+nombre+", tengo"+edad+", y soy de "+nacionalidad+".");
    }
    
    public void caminar()
    {
        
    }
     
    
}
