package MainClasses;

import java.util.ArrayList;

public class Cliente {
    private String Nome;
    private String Telefone;
    private String CPF;    
    private Endereco endereco = new Endereco(); 
    private ArrayList <ReservaDeViagem> reservasViagens = new ArrayList <>();

    //Construtor padrão
    public Cliente(String Nome, String Telefone, Endereco endereco,String CPF){
//------------------------------------        
// CHECAR FORMATO DOS DADOS NA INTERFACE
//------------------------------------        
        this.Nome=Nome;
        this.Telefone=Telefone;
        this.endereco=endereco;
        this.CPF=CPF;
    }
    //Construtor vazio
    Cliente(){}   

    public String getNome() {
        return Nome;
    }
    public void setNome(String Nome) {
        this.Nome = Nome;
    }
    public String getTelefone() {
        return Telefone;
    }
    public void setTelefone(String Telefone) {
        this.Telefone = Telefone;
    }
    public Endereco getEndereco() {
        return endereco;
    }
    public void setEndereco(Endereco endereco) {
        this.endereco = endereco;
    }
    public String getCPF() {
        return CPF;
    }
    public void setCPF(String CPF) {
        this.CPF = CPF;
    }
    public ArrayList<ReservaDeViagem> getReservasViagens() {
        return reservasViagens;
    }
    public void setReservasViagens(ArrayList<ReservaDeViagem> reservasViagens) {
        this.reservasViagens = reservasViagens;
    }
}
