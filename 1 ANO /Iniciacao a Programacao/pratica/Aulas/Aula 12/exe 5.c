#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void  quickSort ( int a [], int l , int r ){


	int  j ;
	if (l < r){
	j = partition ( a ,l , r ) ;
	quickSort ( a, l , j1) ;
	quickSort (a,j +1, r) ;
  }
}

 void bubbleSort(int*p){
        
        boolean troca = true;
        int aux;
        while (troca) {
            troca = false;
            for (int i = 0; i < vetor.length - 1; i++) {
                if (vetor[i] > vetor[i + 1]) {
                    aux = vetor[i];
                    vetor[i] = vetor[i + 1];
                    vetor[i + 1] = aux;
                    troca = true;
                }
            }
        }
    }

	void MergeSort(int a(),int low,int high){
		
		int mid;
		if(low < high){;
			mid=(low + high)/2;
		   	MergeSort(a,low,mid);
			MergeSort(a,mid+1,high);
			MergeSort(a,low,high,mid);	
		}
	}	
	
     int partition(int a(),int l,int r){
		 int pivot,i,j,ti;
		 pivot=a(l);
		 i = l;  j =r+1;
		 
		 while(1){
			do i++;  while ( a [i]<= pivot && i<= r ) ;
			do --j ;  while ( a [j ]>pivot  ) ;
			
			if (i > = j)  break ;
			t1 = a [i] ; a [i] = a [j] ; a [j] = t1 ;
			
			t1 = a [l] ; a [l] = a [j] ; a [j] = t1 ;
			return  j ;
		 }
			
			void  quickSort (  int  a [] ,int l , int  r ){
			
			int  j ;
			
			if ( l < r  ){
			j = partition ( a ,  l ,  r ) ;
			quickSort ( a ,  l ,  j-1) ;
			quickSort ( a ,  j +1,  r ) ;
			
      }
  }
			void  geraVetor (int  *vetor ){
			int  i ;
			printf ("\n\n Criando  vetor  aleatorio  com  valores  de 0 a 1000 \n\n") ;
			for  ( i = 0;  i<t ;  i++)
			vetor [i] = rand () % 1001;
	
	
		int  main (){
			
		int vetor[t];
		srand(time(NULL));
		
		geraVetor(vetor);	
		
		printf("\n\n ordenando vetor com bubbleSort \n\n");
		bubbleSort(vetor);
			
		geraVetor(vetor);	
		printf("\n\n Ordenando com MergeSort \n\n");
		MergeSort(vetor, 0 ,t);
		
		geraVetor(vetor);
		printf("\n\n Ordenando em QuickSort \n\n");	
		quickSort(vetor, 0, t);	
			
			
		return 0;	
		}
		 
		 
	 


