/* Variaveis em escopos diferentes */

#include<stdio.h>
#include<stdlib.h>

void reajusta20(float *preco, float *reajuste);      /*protótipo da função*/

int main(){
  float val_preco, val_reaj;

  do{
	// Recebendo entrada do usuario
    printf("\nInsira o preco atual: ");
    scanf("%f", &val_preco);
	
    reajusta20(&val_preco, &val_reaj);

	/*Enviando endereços das variaveis*/
    printf("\nO preco novo e = %.2f", val_preco);
    printf("\nO aumento foi de = %.2f\n", val_reaj);


  }while(val_preco != 0);

  return 0;
}

/* reajusta20() */
/* Reajusta o preço em 20% */
void reajusta20(float *preco, float *reajuste){
*reajuste = *preco * 0.2;
*preco = *preco * 1.2;
}
