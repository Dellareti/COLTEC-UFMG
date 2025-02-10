package testebar;

import java.util.Date;

public class Mesa {
    private int numeroMesa;
    private Date data;
    private boolean reserva=false;
    Cliente[] clientes = new Cliente[2];
    Utils dados = new Utils();
    Comanda conta = new Comanda();
    
    public void inicializa(){
        for(int i=0;i<2;i++){
            this.clientes[i] = new Cliente();
        }
    }
    
    public int getNumeroMesa() {
        return numeroMesa;
    }

    public void setNumeroMesa(int numeroMesa) {
        this.numeroMesa = numeroMesa;
    }

    public Date getData() {
        return data;
    }

    public void setData(Date data) {
        this.data = data;
    }

    public boolean isReserva() {
        return reserva;
    }

    public void setReserva(boolean reserva) {
        this.reserva = reserva;
    }
    
    public boolean reservar(){
        if(this.reserva==true){
            System.out.println("Já reservada");
            return true;
        }
        else{
            this.reserva = true;
            return false;
        }
    }
    
     public boolean verifica_reserva(){
        if(this.reserva==true){
            return true;
        }
        else{
            this.reserva = true;
            return false;
        }
    }

    void liberar() {
        this.reserva = false;
    }
}