package testebar;
public class Comanda {
    private String consumo;
    private double valor;
    
    double pf;
    double refri;

    public String getConsumo() {
        return consumo;
    }

    public void setConsumo(String consumo) {
        this.consumo = consumo;
    }

    public double getValor() {
        return valor;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }
    
    public void listarConsumo(){
        System.out.println("Consumo:\n");
        System.out.println("Refrescos:\t" + this.refri);
        System.out.println("Pratos feitos:\t" + this.pf);
        this.valor = this.pf*10.0 + this.refri*5.0;
        System.out.println("Total:\tR$" + this.valor);
    }

    public double calcular10porcento(){
        return this.valor+=this.valor*0.1;
    }
    
    public double dividirConta(){
        return this.valor/2;
    } 
}