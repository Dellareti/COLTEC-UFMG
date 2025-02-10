package interfaces;

public class Quadrado implements AreaCalculavel {
    int lado;
    public double calculaArea() {
        return this.lado * this.lado;
    }
}