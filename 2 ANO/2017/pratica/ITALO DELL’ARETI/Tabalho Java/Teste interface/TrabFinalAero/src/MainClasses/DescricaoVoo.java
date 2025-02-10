package MainClasses;
public class DescricaoVoo {
    private String horarioDePartida;
    private String horarioDeChegada;
    private String numeroDoVoo;
    private String aeroPartida;
    private String aeroChegada;

    public String getAeroPartida() {
        return aeroPartida;
    }

    public void setAeroPartida(String aeroPartida) {
        this.aeroPartida = aeroPartida;
    }

    public String getAeroChegada() {
        return aeroChegada;
    }

    public void setAeroChegada(String aeroChegada) {
        this.aeroChegada = aeroChegada;
    }

    
    //Construtor padrão
    public DescricaoVoo(String horarioDePartida, String horarioDeChegada, String aeroPartida, String aeroChegada){
        this.horarioDePartida = horarioDePartida;
        this.horarioDeChegada = horarioDeChegada;
        this.aeroPartida = aeroPartida;
        this.aeroChegada = aeroChegada;
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
