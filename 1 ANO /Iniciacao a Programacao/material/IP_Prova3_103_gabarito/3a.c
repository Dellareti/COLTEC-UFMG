#include <stdio.h>

int comb(int n, int k) {
  if (k == 1) {
    return n;
  } else if (k == n) {
    return 1;
  } else if (k > 1 && n > k) {
    return comb(n - 1, k - 1) + comb(n - 1, k);
  } else {
    return 0;
  }
}


int main() {

  int k, n;

  printf("Digite os valores de n e k, respectivamente:\n");
  scanf("%d %d", &n, &k);

  printf("%d\n", comb(n, k));
  return 0;
}
