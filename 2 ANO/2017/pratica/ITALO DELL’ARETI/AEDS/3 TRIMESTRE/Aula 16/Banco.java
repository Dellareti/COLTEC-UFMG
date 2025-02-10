package aula16;
public class Banco {
    Conta [] contas = new Conta[3];
    int t=0;
    
    public void adiciona(Conta c){
        contas[t]=c;
        t++;
    }
    public Conta pegaConta(int x){
        return contas[x];
    }
    public int pegaTotalDeContas(){
        return t;
    }
    public static void main(String[] args) {
        ContaCorrente a = new ContaCorrente();
        ContaPoupanca b = new ContaPoupanca();
        Banco bank = new Banco();
        bank.adiciona(a);
        bank.adiciona(b);
        AtualizadorDeContas wat;
        for(int i=0;i<bank.pegaTotalDeContas();i++)
            wat = new AtualizadorDeContas(bank.pegaConta(i).saldo);
    }
}
