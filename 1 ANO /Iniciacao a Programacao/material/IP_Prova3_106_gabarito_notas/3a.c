#include <stdio.h>

int ack(int m, int n) {
  if (m == 0) return n+1;
  else if (m > 0 && n == 0) return ack(m-1, 1);
  else return ack(m-1, ack(m,n-1));
}


int main() {

  int m, n;
  do{
    printf("Digite os valores de m e n, respectivamente:\n");
    scanf("%d %d", &m, &n);
    printf("%d\n", ack(m, n));
  } while (m != 0 && n != 0);
  return 0;
}
