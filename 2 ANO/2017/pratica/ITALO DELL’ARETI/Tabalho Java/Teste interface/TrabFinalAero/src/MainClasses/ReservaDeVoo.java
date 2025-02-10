package MainClasses;
import java.util.ArrayList;

public class ReservaDeVoo {
    private Voo voo = new Voo();

    public ReservaDeVoo(Voo v){
        this.voo=v;
    }
    public ReservaDeVoo(){}
    
    public Voo getVoo() {
        return voo;
    }
    public void setVoo(Voo voo) {
        this.voo = voo;
    }
}
