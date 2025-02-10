package MainClasses;
public class Aviao {
    private String nomeDoFabricante;
    private String numModelo;
    private String numAssentos;

    //Construtor padrão
   public Aviao(String nomeDoFabricante, String numModelo, String numAssentos){
        this.nomeDoFabricante = nomeDoFabricante;
        this.numModelo = numModelo;
        this.numAssentos = numAssentos;
    }
    //Construtor vazio
    Aviao(){}

    public String getNomeDoFabricante() {
        return nomeDoFabricante;
    }

    public void setNomeDoFabricante(String nomeDoFabricante) {
        this.nomeDoFabricante = nomeDoFabricante;
    }

    public String getNumModelo() {
        return numModelo;
    }

    public void setNumModelo(String numModelo) {
        this.numModelo = numModelo;
    }

    public String getNumAssentos() {
        return numAssentos;
    }

    public void setNumAssentos(String numAssentos) {
        this.numAssentos = numAssentos;
    }
}
