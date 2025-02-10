#include <stdio.h>
#include <stdlib.h>
   
float **Alocar_matriz_real (int m, int n){
    float **mat;
    int   i;   
   
    if (m < 1 || n < 1) { 
        printf ("\n\n ** Erro: Parametro invalido **\n\n");
        exit(-1);
    }
       
    else{
   
        mat = (float **) calloc (m,sizeof(float *));
     
        for ( i = 0; i < m; i++ ) {
            mat[i] = (float*) calloc (n,sizeof(float));
        }
       
        return mat; 
    }
}
   
void lerMatriz(float **matriz , int m , int n){
   
    int i, k;
   
    for (i=0 ; i<m ; i++){
        for (k=0 ; k<n ; k++){
            scanf ("%f", &matriz[i][k]);
        }
    }
   
}
   
void produtoMatriz(float **mat1 , float **mat2 , float **mat , int La , int Ca, int Lb, int Cb){
    int i, k, j;
   
    for (i=0; i<La ; i++){
        for (j=0 ; j<Cb ; j++){
            for (k=0 ; k<Ca ; k++){
                mat[i][j] = mat[i][j] + mat1[i][k] * mat2[k][j];
            }
        }
    }
      
    printf("\n A nova matriz sera :  \n\n");
      
    for (i=0 ; i<La ; i++){
        printf("Linha %d\n", i);
        for (j=0 ; j<Cb ;j++){
            printf("%.1f\t", mat[i][j]);
        }
        printf("\n\n");
    }
   
}
   
int main (){
   
    float **mat1, **mat2, **mat;
    int l1, c1, l2, c2, i;
  
    printf ("\n\n Digite o numero de linhas e colunas para a primeira matriz \n\n");
    scanf ("%d %d" , &l1, &c1);
    
    mat1=Alocar_matriz_real(l1,c1);
  
    printf("\n\n Digite o numero de linhas e colunas para a segunda matriz\n\n");
    scanf ("%d %d" , &l2, &c2);
   
    mat2=Alocar_matriz_real(l2,c2);
  
    if(c1==l2){
         
        mat=Alocar_matriz_real(l1,c2);
  
        printf("\n\n Digite elementos para a primeira matriz %d * %d\n\n", l1 ,c1);
        lerMatriz(mat1,l1,c1);
   
   
        printf("\n\n Digite elementos para a segunda matriz %d * %d\n\n", l2 ,c2);
        lerMatriz(mat2,l2,c2);
   
        produtoMatriz(mat1,mat2,mat,l1,c1,l2,c2);
   
        for (i=0 ; i<l1 ; i++) free (mat[i]);
  
        free (mat);
      
    }
  
    printf("\n\n");
      
    return 0;
   
}