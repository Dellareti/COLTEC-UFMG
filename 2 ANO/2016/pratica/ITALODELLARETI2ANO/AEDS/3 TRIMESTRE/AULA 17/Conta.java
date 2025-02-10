package programa;
class Conta {
    int numero ;
    Cliente titular;
    double saldo ;
    double limite ;
/*
    void saca (double quantidade ) {
        double novoSaldo = this.saldo - quantidade ;
        this.saldo = novoSaldo ;
    }
*/
    public void deposita (double quantidade ) {
        this.saldo += quantidade ;
    }
     
    public boolean saca (double valor ) {
        if (this.saldo < valor ) {
            System.out.println("Saldo insuficiente!");
            return false;
        }
        else {
            this.saldo = this.saldo - valor ;
            return true;
        }
    }   
     
    public boolean transfere ( Conta destino , double valor ) {
        boolean retirou = this. saca ( valor );
        if (retirou == false) {
            // não deu pra sacar!
            return false;
        }
        else {
            destino.deposita ( valor );
            return true;
        }
    }
}