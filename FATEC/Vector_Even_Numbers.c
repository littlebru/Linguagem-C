/*
QUESTAO 06
Dados n e uma seqüência de n números inteiros, determinar a soma dos números pares.
(Utilizando Vetor)
*/

#include<stdio.h>

int main(){
  int n, sequencia[20], somaPar=0, i;

  for(i=0; i<20; i++){
      sequencia[i]=0; //zerando os indices do vetor
  }

  printf("Quantidade de numeros:\n");
  scanf("%d", &n);

  for(i=0; i<n; i++){

    printf("Informe o numero:\n");
    scanf("%d", &sequencia[i]);

    if(sequencia[i] % 2 == 0){
      somaPar = somaPar + sequencia[i];
    }
  }

  printf("A soma dos numeros pares deu %d", somaPar);
  printf("\n");

  return 0;
}

