/*
QUESTAO 06
Dados n e uma seqüência de n números inteiros, determinar a soma dos números pares.

*/

#include<stdio.h>

int main(){
  int n, numero, somaPar=0, i;

  printf("Quantidade de numeros:\n");
  scanf("%d", &n);

  for(i=0; i<n; i++){

    printf("Informe o numero:\n");
    scanf("%d", &numero);

    if(numero % 2 == 0){
      somaPar = somaPar + numero;
    }
  }

  printf("A soma dos numeros pares deu %d", somaPar);
  printf("\n");

  return 0;
}
