#include <stdio.h>
 
int main() {
 
   float A, B, C, MEDIA = 0;

  scanf("%f", &A);
  scanf("%f", &B);
  scanf("%f", &C);

  MEDIA = (A*2 + B*3 + C*5)/10.0;

  printf("MEDIA = %.1f\n",MEDIA);

return 0;
}
