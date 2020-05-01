#include <stdio.h>
 
int main() {
 
  char Nome;
  double SalarioFixo, TotalVenda, Salario;

  scanf("%s", &Nome);
  scanf("%lf", &SalarioFixo);
  scanf("%lf", &TotalVenda);

  Salario = SalarioFixo + (TotalVenda * 0.15);

  printf("TOTAL = R$ %.2lf\n",Salario);
  
return 0 ;
}
