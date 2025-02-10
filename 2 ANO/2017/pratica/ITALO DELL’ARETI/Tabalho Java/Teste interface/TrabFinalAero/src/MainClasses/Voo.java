package MainClasses;
public class Voo {
    private String dataDePartida;
    private int numVagas;
    private DescricaoVoo descVoo = new DescricaoVoo(); 
    private Aviao av = new Aviao();
    //Construtor padrão
    public Voo(String dataDePartida, int numVagas,DescricaoVoo d,Aviao a){
        this.dataDePartida = dataDePartida;
        this.numVagas = numVagas;
        this.descVoo = d;
        this.av = a;
    }
    //Construtor vazio
    Voo(){}

    public Aviao getAv() {
        return av;
    }

    public void setAv(Aviao av) {
        this.av = av;
    }

    public String getDataDePartida() {
        return dataDePartida;
    }
    public void setDataDePartida(String dataDePartida) {
        this.dataDePartida = dataDePartida;
    }
    public String getSNumVagas() {
        return Integer.toString(numVagas);
    }
    public int getNumVagas() {
        return numVagas;
    }
    public void setSNumVagas(String n){
        this.numVagas=Integer.parseInt(n);
    }
    public void setNumVagas(int numVagas) {
        this.numVagas = numVagas;
    }

    public DescricaoVoo getDescVoo() {
        return descVoo;
    }

    public void setDescVoo(DescricaoVoo descVoo) {
        this.descVoo = descVoo;
    }
    
}