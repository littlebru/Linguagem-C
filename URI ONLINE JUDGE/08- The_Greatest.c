#include <stdio.h>
#include <stdlib.h>

int main(){
  int a,b,s,maiorAB = 0;

  scanf("%d %d %d",&a,&b,&s);

  maiorAB = (a + b + abs(a-b))/2;

  maiorAB = (maiorAB + s + abs(maiorAB-s))/2;

  printf("%d eh o maior\n",maiorAB);

  return 0;
}
