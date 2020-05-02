/*
QUESTAO 08
  Dados n e dois números inteiros positivos i e j diferentes de 0, imprimir em
ordem crescente os n primeiros naturais que são múltiplos de i ou de j e ou de
ambos.
 Exemplo: Para n = 6 , i = 2 e j = 3 a saída deverá ser : 0,2,3,4,6,8.
*/

#include <stdio.h>

int main(){

  int n, i, j, p=0, cont=0;

  printf("Quantidade de multiplos: \n");
  scanf("%d", &n);

  printf("De quais numeros:\n");
  scanf("%d %d", &i, &j);

  while(cont < n)
  {
      if(p!=1)
      {
        if((p % i) == 0 || (p % j) == 0)
        {
          if((n - cont) == 1){
            printf(" %d.", p);
          }
          else{
            printf(" %d,", p);
          }
          cont++;
        }
      }
      p++;
  }


  return 0;
}
