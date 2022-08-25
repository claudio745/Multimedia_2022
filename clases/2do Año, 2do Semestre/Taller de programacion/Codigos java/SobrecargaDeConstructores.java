/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package sobrecarga.de.constructores;

/**
 *
 * @author claud
 */
public class SobrecargaDeConstructores {
    
    avion[] aviones;

    public SobrecargaDeConstructores(avion[] aviones) 
    {
        this.aviones = aviones;
    }

    public SobrecargaDeConstructores(avion avion) 
    {
        this. aviones = new avion[50];
        this.aviones[0] = avion;
    }
    
    public SobrecargaDeConstructores(avion avion, int cantidad) 
    {
        this. aviones = new avion[cantidad];
        this.aviones[0] = avion;
    }
    
    
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        
        
    }
    
}
