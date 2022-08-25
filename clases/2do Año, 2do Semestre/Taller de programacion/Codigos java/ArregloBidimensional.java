/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package taler.progra.pkg2021;

import static java.time.Clock.system;
import java.util.Scanner;
import javax.swing.JOptionPane;

/**
 *
 * @author claud
 */
public class ArregloBidimensional {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Scanner entrada = new Scanner(System.in);
        
        int nFilas = Integer.parseInt(JOptionPane.showInputDialog("Digite numero de filas:"));
        int nColum = Integer.parseInt(JOptionPane.showInputDialog("Digite numero de columnas:"));
        
        int[][] matriz = new int[nFilas][nColum];
        
        
        System.out.println("Digite la matriz: ");
        for(int i=0;i<nFilas; i++)
        {
            for (int j=0; j<nColum; j++)
            {
                System.out.print(" Matriz ["+i+"]["+j+"]:");
                matriz[i][j] = entrada.nextInt();
            }
        }
        
        System.out.println("\n La matriz es: ");
        for (int i = 0;i<nFilas;i++)
        {
            for (int j = 0; j<nColum; j++)
            {
                System.out.print(matriz[i][j]);
            }
            System.out.println("");
        }         
    }

}
