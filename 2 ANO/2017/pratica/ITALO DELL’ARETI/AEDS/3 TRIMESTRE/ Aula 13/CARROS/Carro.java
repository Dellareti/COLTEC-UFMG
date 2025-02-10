package fabrica;
public class Carro {
    String cor ;
    String modelo ;
    double velocidadeAtual ;
    double velocidadeMaxima ;

    void liga () {
        System . out . println ("O carro está ligado");
    }
    void acelera(double quantidade){
        this. velocidadeAtual = this.velocidadeAtual + quantidade;
    }
    int pegaMarcha () {
        if (this. velocidadeAtual< 0){
            return -1;
        }
        else if (this. velocidadeAtual>= 0 && this.velocidadeAtual < 40){
            return 1;
        }
        else if (this. velocidadeAtual>= 40 && this.velocidadeAtual < 80){
            return 2;
        }
    return 3;
    }
}