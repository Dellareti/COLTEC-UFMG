package projeto;

import java.util.Scanner;

public class Agenda {
    Pessoa[] pessoas;
    int qtd_amigos=0;
    int qtd_conhecidos=0;

    Agenda(int qtd){
        pessoas = new Pessoa[qtd];
        
        for(int i=0;i<qtd;i++){
            pessoas[i] = new Pessoa();
        }
        int x;
        for(int i=0;i<qtd;i++){
            x = 1+(int)(Math.random()*2);
            
            if(x==1){//amigo
                Amigo amigos = new Amigo();
                pessoas[i] = amigos;
                this.qtd_amigos++;
            }
            else{//conhecido
                Conhecido conhecidos = new Conhecido();
                pessoas[i] = conhecidos;
                this.qtd_conhecidos++;
            }
            
        }
        
        
    }
    
    public void addinformacoes(){
        Amigo aux;
        Conhecido auxx;
        for(int i=0;i<this.qtd_amigos+this.qtd_conhecidos;i++){
            if(this.pessoas[i] instanceof Amigo){//amigo
                aux = new Amigo();
                System.out.println("Digite o nome:");
                aux.setNome(new Scanner(System.in).next());
                System.out.println("Digite sua idade:");
                aux.setIdade (new Scanner(System.in).nextInt());
                System.out.println("Digite seu aniversario:");
                aux.setAniversario(new Scanner(System.in).next());
                this.pessoas[i] = aux;
            }
            else{//conhecido
                auxx = new Conhecido();
                System.out.println("Digite seu nome:");
                auxx.setNome(new Scanner(System.in).next());
                System.out.println("Digite sua idade:");
                auxx.setIdade(new Scanner(System.in).nextInt());
                System.out.println("Digite seu email:");
                auxx.setEmail(new Scanner(System.in).next());
                this.pessoas[i] = auxx;
            }
        }
    }
    
    public void imprimeAniversarios(){
        Amigo aux;
        for(int i=0;i<this.qtd_amigos+this.qtd_conhecidos;i++){
            if(this.pessoas[i] instanceof Amigo){//amigo
                aux = new Amigo();
                aux = (Amigo) this.pessoas[i];
                System.out.println("A data de aniverssário:\t" + aux.aniversario);
            }
        }
    }

    public void imprimeEmail(){
        Conhecido aux;
        for(int i=0;i<this.qtd_amigos+this.qtd_conhecidos;i++){
            if(this.pessoas[i] instanceof Conhecido){//amigo
                aux = new Conhecido();
                aux = (Conhecido) this.pessoas[i];
                System.out.println("O email é:\t" + aux.email);                
            }
        }
    }
    
    public Pessoa[] getPessoas() {
        return pessoas;
    }

    public void setPessoas(Pessoa[] pessoas) {
        this.pessoas = pessoas;
    }

    public int getQtd_amigos() {
        return qtd_amigos;
    }

    public void setQtd_amigos(int qtd_amigos) {
        this.qtd_amigos = qtd_amigos;
    }

    public int getQtd_conhecidos() {
        return qtd_conhecidos;
    }

    public void setQtd_conhecidos(int qtd_conhecidos) {
        this.qtd_conhecidos = qtd_conhecidos;
    }
    
}