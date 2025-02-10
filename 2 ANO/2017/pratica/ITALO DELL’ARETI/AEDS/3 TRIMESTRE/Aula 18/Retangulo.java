package interfaces;

public class Retangulo implements AreaCalculavel {
    int ladoA;
    int ladoB;

    public double calculaArea() {
        return this.ladoA * this.ladoB;
    }
}