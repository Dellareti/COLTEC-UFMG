package MainClasses;
public class DescricaoVoo {
    private String horarioDePartida;
    private String horarioDeChegada;
    private String numeroDoVoo;
    
    //Construtor padrão
    public DescricaoVoo(String horarioDePartida, String horarioDeChegada){
        this.horarioDePartida = horarioDePartida;
        this.horarioDeChegada = horarioDeChegada;
    }
    //Construtor vazio
    DescricaoVoo(){}

    public String getHorarioDePartida() {
        return horarioDePartida;
    }

    public void setHorarioDePartida(String horarioDePartida) {
        this.horarioDePartida = horarioDePartida;
    }

    public String getHorarioDeChegada() {
        return horarioDeChegada;
    }

    public void setHorarioDeChegada(String horarioDeChegada) {
        this.horarioDeChegada = horarioDeChegada;
    }

    public String getNumeroDoVoo() {
        return numeroDoVoo;
    }

    public void setNumeroDoVoo(String numeroDoVoo) {
        this.numeroDoVoo = numeroDoVoo;
    }
}
