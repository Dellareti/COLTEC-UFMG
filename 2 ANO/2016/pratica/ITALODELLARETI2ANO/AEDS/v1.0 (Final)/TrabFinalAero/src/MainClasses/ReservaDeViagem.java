package MainClasses;
import java.util.ArrayList;

public class ReservaDeViagem {
    private ArrayList <ReservaDeVoo> reservasDeVoos = new ArrayList <>();
    int numDeViagem;
    public ArrayList<ReservaDeVoo> getReservasDeVoos() {
        return reservasDeVoos;
    }

    public void setReservasDeVoos(ArrayList<ReservaDeVoo> reservasDeVoos) {
        this.reservasDeVoos = reservasDeVoos;
    }

    public int getNumDeViagem() {
        return numDeViagem;
    }

    public void setNumDeViagem(int numDeViagem) {
        this.numDeViagem = numDeViagem;
    }

    
}