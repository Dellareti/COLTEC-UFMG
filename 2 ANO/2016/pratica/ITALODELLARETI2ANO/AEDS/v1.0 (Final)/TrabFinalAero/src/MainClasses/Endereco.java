package MainClasses;
public class Endereco {
    private String rua;
    private String num;
    private String bairro;
    private String cidade;    
    
    public Endereco(String rua,String num,String bairro,String cidade){
        this.rua=rua;
        this.num=num;
        this.bairro=bairro;
        this.cidade=cidade;
    }
    public Endereco(){}
    
    public String getRua() {
        return rua;
    }

    public void setRua(String rua) {
        this.rua = rua;
    }

    public String getNum() {
        return num;
    }

    public void setNum(String num) {
        this.num = num;
    }

    public String getBairro() {
        return bairro;
    }

    public void setBairro(String bairro) {
        this.bairro = bairro;
    }

    public String getCidade() {
        return cidade;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }
}
