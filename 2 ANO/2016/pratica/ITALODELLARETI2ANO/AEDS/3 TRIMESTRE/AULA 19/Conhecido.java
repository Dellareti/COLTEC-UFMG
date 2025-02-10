package projeto;
public class Conhecido extends Pessoa{
    String email;
    
    Conhecido(){
        this.email = "indefinido";
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }
    
}