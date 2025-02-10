package MainClasses;
import java.util.ArrayList;

public class ReservaDeViagem {
    private ArrayList <ReservaDeVoo> reservasDeVoos = new ArrayList <>();

    public ArrayList<ReservaDeVoo> getReservasDeVoos() {
        return reservasDeVoos;
    }

    public void setReservasDeVoos(ArrayList<ReservaDeVoo> reservasDeVoos) {
        this.reservasDeVoos = reservasDeVoos;
    }

}