#include <stdio.h>
#include <stdlib.h>

struct 
arv {char info;
struct arv ∗esq;
struct arv ∗dir;
}
typedef struct arv Arv;

Arv ∗ arv_criavazia () { // cria uma árvore vazia
  return NULL;
}

Arv ∗ arv_cria ( char c , Arv ∗sae , Arv ∗sad ){ // cria novos filhos
  Arv ∗p = (Arv ∗) malloc(sizeof (Arv));
  p−>info = c;
  p−>esq = sae;
  p−>dir = sad;
  return  p;
}

int arv_vazia (Arv ∗a) { //verifica se é vazio
  return a == NULL;
}

void arv_imprime (Arv ∗a) { //  imprime a árvore na ordem especificada
  if  (! arv_vazia(a)) {
    printf ("%c", a−>info);
    arv_imprime (a−>esq);
    arv_imprime (a−>dir);
  }
}

Arv ∗arv_libera (Arv ∗a) { // libera de um em um
  if (! arv_vazia(a)) { 
    arv_libera (a−>esq);
    arv_libera (a−>dir);
    free (a) ;
  }
  return  NULL;
}

int arv_pertence ( Arv ∗a , char c) { // verifica se uma elemento pertence a lista

  if(arv_vazia(a)) { 
    return 0;
  }
  else {
  return  a−>info == c ||   arv_pertence (a->esq, c) || arv_pertence(a->dir, c);
  }
}


