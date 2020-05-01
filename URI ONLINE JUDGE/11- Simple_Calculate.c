#include <stdio.h>
 
int main() {
 
float CodeP1,NumP1, CodeP2, NumP2, PriceP1, PriceP2, toPay;

  scanf("%f %f %f", &CodeP1, &NumP1, &PriceP1);
  scanf("%f %f %f", &CodeP2, &NumP2, &PriceP2);

  toPay = (NumP1 * PriceP1) + (NumP2 * PriceP2);

  printf("VALOR A PAGAR: R$ %.2f\n", toPay);

return 0 ;
}
