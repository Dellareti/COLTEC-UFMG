public class Estatistica {
    int moda(int array[]){
        int max=0;
        int moda=0;
        for(int i=0;i<array.length;i++){
            int rep=0;
            for(int j=0;j<array.length;j++){
                if(array[i]==array[j])
                    rep++;
                if(rep>max){
                    moda = array[i];
                    max=rep;
                }
            }
        }
        return moda;
    }
    int mediana(int array[]){
        return array[array.length/2];
    }
    double media(int array[]){
        double m=0;
        for(int i=0;i<array.length;i++)
            m+=array[i];
        return (m/array.length);
    }
}
