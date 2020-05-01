/* Mostra ponteiros constantes */

#include<stdio.h>
#include<stdlib.h>

int main(){
  int i, j, k;

  printf("Imprimindo o endereco das variaveis na memoria\n");
  printf("Endereco de i: %p\n", &i);
  
  /* O código especial %p é utilizado para imprimir ponteiros*/
  printf("Endereco de j: %p\n", &j);
  printf("Endereco de k: %p\n", &k);

  return 0;
}
