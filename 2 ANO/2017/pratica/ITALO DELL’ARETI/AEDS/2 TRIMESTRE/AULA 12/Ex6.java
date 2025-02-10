package aula12;
public class Ex6 {
    public static void main(String[] args){
        int fib1=1,fib2=1,aux=fib1;
        System.out.println("1");
        
        while(fib1<=100){
            System.out.println(fib1);
            aux=fib1;
            fib1+=fib2;
            fib2=aux;
        }
    }
   }
