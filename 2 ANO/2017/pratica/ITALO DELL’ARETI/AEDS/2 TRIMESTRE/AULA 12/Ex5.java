package aula12;
public class Ex5 {
    public static void main(String[] args) {
        long soma=1;
        for(int i=1;i<=40;i++){
            for(int j=i;j>=1;j--)
                soma*=j;
           System.out.println(soma);
           soma=1;
        }
    }    
}
