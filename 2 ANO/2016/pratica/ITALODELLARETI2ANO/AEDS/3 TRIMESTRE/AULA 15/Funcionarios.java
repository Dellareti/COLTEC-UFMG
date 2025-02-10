package Empresa;

public class Funcionarios {

     String Nome;
     String Depart;
     String Salario;
     String DataDeEntrada;
     String Rg;
    
    
    public void preenche(String Nome, String Depart, String Salario, String DataDeEntrada, String Rg) {
        this.Nome = Nome;
        this.Depart = Depart;
        this.Salario = Salario;
        this.DataDeEntrada = DataDeEntrada;
        this.Rg = Rg;
    } 
    
    
    public String getNome() {
        return Nome;
    }

    public void setNome(String Nome) {
        this.Nome = Nome;
    }

    public String getDepart() {
        return Depart;
    }

    public void setDepart(String Depart) {
        this.Depart = Depart;
    }

    public String getSalario() {
        return Salario;
    }

    public void setSalario(String Salario) {
        this.Salario = Salario;
    }

    public String getDataDeEntrada() {
        return DataDeEntrada;
    }

    public void setDataDeEntrada(String DataDeEntrada) {
        this.DataDeEntrada = DataDeEntrada;
    }

    public String getRg() {
        return Rg;
    }

    public void setRg(String Rg) {
        this.Rg = Rg;
    }

    public void mostrar() {
     
        System.out.println("\n");
        System.out.println("Nome :" + Nome);
        System.out.println("Departamento :" + Depart);
        System.out.println("Salario :" + Salario);
        System.out.println("Data de entrada " + DataDeEntrada);
        System.out.println("RG :" + Rg);
    }

}
