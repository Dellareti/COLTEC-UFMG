#include <stdio.h>
#include <stdlib.h>

void imprime ( int n )
{
int i = 1;	
while( i < n + 1 )
{
printf( "%d ", i );
i = i + 1;
}
}

int main()
{
int num = 10; 
imprime( num );
getchar();
return 0; 
}