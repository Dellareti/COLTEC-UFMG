#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "contato.h"
 
int main()
{
	Hash* h = hash_criar();
	hash_inserir(h, 2, contato_criar(2, "Saulo", "99990000", "saulopz@gmail.com"));
	hash_inserir(h, 6, contato_criar(6, "Joao", "99009900", "joao@gmail.com"));
	hash_inserir(h, 13, contato_criar(13, "Marta", "99778877", "marta@gmail.com"));
	hash_inserir(h, 12, contato_criar(12, "Roberta", "87872222", "roberta@gmail.com"));
	hash_inserir(h, 7, contato_criar(7, "Marta", "77887777", "marta@gmail.com"));
	int i;
	for (i = 0; i < 20; i++)
	{
		Contato *c = (Contato*)hash_buscar(h, i);
		if (c != NULL)
		{
			printf("%d - %d: %s - %s\n", i % 4, i, contato_getNome(c), contato_getEmail(c));
		}
	}
	hash_destruir(h);
	return 0;
}