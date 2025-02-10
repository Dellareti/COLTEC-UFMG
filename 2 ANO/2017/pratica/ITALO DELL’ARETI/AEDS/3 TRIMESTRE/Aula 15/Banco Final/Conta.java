package Banco;
public class Conta {
    int numero;
    double saldo;
    double limite;
    Cliente titular;

    boolean saca(int qtd){
        if(qtd<this.saldo){
            this.saldo-=qtd;
            return true;
        }
        else
            return false;
    }
    void deposita(int qtd){
        this.saldo+=qtd;
    }
    boolean trans(Conta destino,int valor){
        boolean retirou = this.saca(valor);
        if(retirou == false){
            return false;
        }
        else{
            destino.deposita(valor);
            return true;
        }   
    }
}