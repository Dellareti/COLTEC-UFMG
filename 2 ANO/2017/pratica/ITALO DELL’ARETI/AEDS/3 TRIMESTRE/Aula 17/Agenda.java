package aula17;

import static com.sun.org.apache.bcel.internal.Repository.instanceOf;
import java.util.Scanner;

public class Agenda {
    Pessoa []p;
    int qtda=0;
    int qtdc=0;
    
    Agenda(int i){
        this.p = new Pessoa[i];
        for(int j=0;j<i;j++){
            if((1+(int)(Math.random()*2))==1){
               this.p[j]=new Amigo();
               qtda++;
            }
            else{
               this.p[j]=new Conhecido();
               qtdc++;
            }
        }
    }
    
    public void addInformacoes(){
        for(int i=0;i<this.qtda+this.qtdc;i++){
                p[i].setIdade(new Scanner(System.in).nextInt());
                p[i].setNome(new Scanner(System.in).next());
        }
    }
    public void imprimeAniversarios(){
        for(int i=0;i<this.qtda+this.qtdc;i++){
            if(p[i] instanceof Amigo){
            Amigo a = (Amigo) p[i];
            System.out.println(a.getAniversario());
            }
        }
    }
    public void imprimeEmail(){
        for(int i=0;i<this.qtda+this.qtdc;i++){
            if(p[i] instanceof Conhecido){
            Conhecido a = (Conhecido) p[i];
            System.out.println(a.getEmail());
            }
        }
    }
    
    public Pessoa[] getP() {
        return p;
    }

    public void setP(Pessoa[] p) {
        this.p = p;
    }

    public int getQtda() {
        return qtda;
    }

    public void setQtda(int qtda) {
        this.qtda = qtda;
    }

    public int getQtdc() {
        return qtdc;
    }

    public void setQtdc(int qtdc) {
        this.qtdc = qtdc;
    }
    public static void main(String[] args) {
        Agenda a = new Agenda(new Scanner(System.in).nextInt());
        System.out.println(a.getQtda());
        System.out.println(a.getQtdc());
        a.addInformacoes();
        a.imprimeAniversarios();
        a.imprimeEmail();
    }
}
