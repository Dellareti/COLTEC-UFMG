package interfaces;
public class ContaCorrente extends Conta implements Tributavel{
    @Override
    public void atualiza(double taxa){
        this.saldo+=this.saldo*2*taxa;
    }
    @Override
    public void depositar(double m){
        this.saldo+=m-0.1;
    }
    public double calculaTributos(){
        return 0.01*this.saldo; 
    }
}
