package interfaces;
public class Teste {
    public static void main(String[] args) {
        Quadrado a = new Quadrado();
        a.lado = 2;
        System.out.println(a.calculaArea());
        Retangulo b = new Retangulo();
        b.ladoA = 2; b.ladoB = 3;
        System.out.println(b.calculaArea());
        Circulo c = new Circulo();
        c.raio = 2;
        System.out.println(c.calculaArea());
    }    
}
