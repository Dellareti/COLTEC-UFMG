package projeto;
public class Amigo extends Pessoa {
    String aniversario;

    Amigo(){
        this.aniversario = "indefinido";
    }
    
    public String getAniversario() {
        return aniversario;
    }

    public void setAniversario(String aniversario) {
        this.aniversario = aniversario;
    }
    
}