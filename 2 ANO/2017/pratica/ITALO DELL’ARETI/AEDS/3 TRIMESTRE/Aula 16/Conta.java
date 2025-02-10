package aula16;
abstract public class Conta {
    protected double saldo;
    public double getSaldo(){
        return saldo;
    }
    public void sacar(double m){
        this.saldo-=m;
    }
    public void depositar(double m){
        this.saldo+=m;
    }
    abstract public void atualiza(double taxa);
    
    public static void main(String[] args) {
        ContaCorrente conta= new ContaCorrente();
        conta.depositar(10);
        System.out.println(conta.getSaldo());
    }
}
