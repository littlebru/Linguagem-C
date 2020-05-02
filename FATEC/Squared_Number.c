/*
QUESTAO 01
Dada uma seqüência de números inteiros não-nulos, seguida por 0,
imprimir seus quadrados.

*/

#include<stdio.h>

int main(){
  int cont = 0, seq[20], nums[20], i, num = 1;

  for(i=0; i<20; i++)seq[i] = 0; //limpando os indices da sequencia
  for(i=0; i<20; i++)nums[i] = 0;

  do{
  scanf("%d",&num);

  nums[cont]= num;
  seq[cont] = num*num;

  cont++;

  }while(num!=0);

  for(i = 0; i<20; i++){

    if(seq[i] == 0)continue; //ignorando espaços que não foram preenchidos

    printf("Quadrado de %d da %d\n",nums[i],seq[i]);
  }

  return 0;
}
