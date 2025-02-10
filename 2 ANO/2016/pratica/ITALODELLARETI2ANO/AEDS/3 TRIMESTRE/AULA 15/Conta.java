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
    void deposita (double quantidade ) {
        this.saldo += quantidade ;
    }
    
    boolean saca (double valor ) {
        if (this.saldo < valor ) {
            System.out.println("Saldo insuficiente!");
            return false;
        }
        else {
            this.saldo = this.saldo - valor ;
            return true;
        }
    }   
    
    boolean transfere ( Conta destino , double valor ) {
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