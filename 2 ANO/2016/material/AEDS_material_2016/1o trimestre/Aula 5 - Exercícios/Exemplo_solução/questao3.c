
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista *ant;
    struct lista *prox;
} Lista;

Lista *lst_insord(Lista *l, int v);
void lst_imprime(Lista *l);
Lista *lst_limpar(Lista *l);

int main() {
    Lista *l = NULL;
    l = lst_insord(l, 1);
    l = lst_insord(l, 5);
    l = lst_insord(l, 3);
    l = lst_insord(l, 2);
    l = lst_insord(l, 4);
    lst_imprime(l);
    l = lst_limpar(l);
    printf("\nLimpa\n\n");
    l = lst_insord(l, 5);
    l = lst_insord(l, 1);
    l = lst_insord(l, 3);
    l = lst_insord(l, 2);
    l = lst_insord(l, 4);
    lst_imprime(l);
    return 0;
}

Lista *lst_insord(Lista *l, int v) {
    if(l == NULL) {
        Lista *cel = (Lista *) malloc(sizeof(Lista));
        cel->info = v;
        cel->prox = cel;
        cel->ant  = cel;
        return cel; 
    }
    Lista *pos = l, *p = l;
    do
        pos = p;
    while ((p = p->prox) != l && p->info < v);
    Lista *cel = (Lista *) malloc(sizeof(Lista));
    cel->info = v;
    if (pos == l && cel->info < pos->info) {
        cel->prox = pos;
        cel->ant  = pos->ant;
        pos->ant->prox = cel;
        pos->ant  = cel;
        return cel;
    }
    cel->prox = pos->prox;
    pos->prox->ant = cel;
    pos->prox = cel;
    cel->ant  = pos;
    return l;
}

void lst_imprime(Lista *l) {
    Lista *p = l;
    do
        printf("info %d\n", p->info);
    while ((p = p->prox) != l);
}

Lista *lst_limpar(Lista *l) {
    Lista *p = l;
    do {
        Lista *rem = p;
        p = p->prox;
        free(rem);
    } while(p != l);
    return NULL;
}
