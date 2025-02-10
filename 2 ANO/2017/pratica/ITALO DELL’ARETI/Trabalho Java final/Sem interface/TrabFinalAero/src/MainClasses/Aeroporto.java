package MainClasses;
public class Aeroporto {
    private String Nome;
    private String Codigo;
    private String Cidade;
 
    //Construtor padrão
    public Aeroporto(String Nome, String Codigo, String Cidade){
        this.Nome = Nome;
        this.Codigo = Codigo;
        this.Cidade = Cidade;
    }
    //Construtor vazio
    Aeroporto(){}

    public String getNome() {
        return Nome;
    }
    public void setNome(String Nome) {
        this.Nome = Nome;
    }
    public String getCodigo() {
        return Codigo;
    }
    public void setCodigo(String Codigo) {
        this.Codigo = Codigo;
    }
    public String getCidade() {
        return Cidade;
    }
    public void setCidade(String Cidade) {
        this.Cidade = Cidade;
    }
}