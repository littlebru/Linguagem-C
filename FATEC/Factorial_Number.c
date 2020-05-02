/*
  Dado um inteiro não-negativo n, determinar n!
*/

#include <stdio.h>

int main(){
  int n, fatorial=1, i;

  do{

  printf("Informe o numero:\n");
  scanf("%d", &n);

  }while(n<0);

  for(i=1; i<=n; i++){

    fatorial = fatorial * i;
  }

  printf("%d! = %d\n", n, fatorial);

  return 0;
}
