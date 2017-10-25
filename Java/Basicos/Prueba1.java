import java.util.Scanner;

public class Prueba1 {

    protected int edad;
    protected String nombre;

    public Prueba1(int edad, String nombre){
        this.edad = edad;
        this.nombre = nombre;
    }

    public int getEdad(){
        return edad;
    }
    protected void printName(){
        System.out.println("Nombre: " + nombre);
    }
    public static void main(String [] args){
        System.out.println("Cual es tu nombre?");
        Scanner s = new Scanner(System.in);
        String nombre = s.nextLine();
        System.out.println("Cual es tu edad?");
        int edad = s.nextInt();
        Prueba1 p = new Prueba1(edad, nombre);
        p.printName();
        System.out.println("Edad: " + p.getEdad());
    }
}
