public class Casa {
    String cor;
    int totalDePortas;
    Porta[] portas = new Porta[10];
    void pinta(String cor){
            this.cor=cor;
    }
    void abre(int x){
        this.portas[x].aberta++;
    }
    int portasAbertas(){
        int t=0;
        for(int i=0;i<totalDePortas;i++)
            if(portas[i].aberta==1)
                t++;
        return t;
    }
    void add(Porta p){
        portas[totalDePortas] = p;
        totalDePortas++;
    }
    int total(){
        return totalDePortas;
    }
}
