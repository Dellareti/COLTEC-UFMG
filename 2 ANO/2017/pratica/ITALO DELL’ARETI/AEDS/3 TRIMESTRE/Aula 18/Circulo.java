package interfaces;

public class Circulo implements AreaCalculavel {
    int raio;
    public double calculaArea() {
        return this.raio * this.raio * 3.14159326;
    }
}
