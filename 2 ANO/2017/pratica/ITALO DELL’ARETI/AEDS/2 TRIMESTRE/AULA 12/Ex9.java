package aula12;
public class Ex9 {
    public static int fib(int n){
        if(n==0 || n==1)
            return n;
        return fib(n-1) + fib(n-2);
    }
    
    public static void main(String[] args){
        for(int i=1;i<12;i++)
            System.out.println(fib(i));
     }
 }
