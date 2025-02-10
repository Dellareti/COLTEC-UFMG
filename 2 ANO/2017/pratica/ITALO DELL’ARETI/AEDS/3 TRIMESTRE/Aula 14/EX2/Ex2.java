public class Ex2 {
    public static void main(String[] args) {
        int[] numeros = new int []{2,2,2,4,3,3,3,4,4,4};
        Estatistica s = new Estatistica();
        System.out.println(s.moda(numeros));
        System.out.println(s.mediana(numeros));
        System.out.println(s.media(numeros));
        
    }
}
