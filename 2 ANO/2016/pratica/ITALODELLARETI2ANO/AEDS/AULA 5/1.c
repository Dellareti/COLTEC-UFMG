#include<stdio.h>
#include<arvores.h>
#include<stdlib>

int main(){

void imprime_ordenada (link h) { 
    if (h == NULL) return;
    printf("%d\n", h->item); 
    imprime(h->l);
    imprime(h->r);
}

void imprime_simetrica (link h) { 

    if (h == NULL) return;
    imprime(h->l);
    printf("%d\n", h->item); 
    imprime(h->r);
}

void imprime_pos_ordem (link h) { 
    if (h == NULL) return;
    printf("%d\n", h->item); 
    imprime(h->l);
    imprime(h->r);
    printf("%d\n", h->item);
}


return 0;
}
