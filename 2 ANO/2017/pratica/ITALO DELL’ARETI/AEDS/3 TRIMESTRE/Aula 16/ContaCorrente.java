package aula16;
public class ContaCorrente extends Conta{
    @Override
    public void atualiza(double taxa){
        this.saldo+=this.saldo*2*taxa;
    }
    @Override
    public void depositar(double m){
        this.saldo+=m-0.1;
    }
        
}
