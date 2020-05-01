#include<stdio.h>


int main(){
  int X[10],i,n;

  for(i=0; i<10; i++) X[i]=0;

  for(i=0; i<10; i++){

    scanf("%d",&X[i]);

    if(X[i]<=0) X[i]=1;
  }

  for(i=0; i<10; i++)
    printf("X[%d] = %d\n",i,X[i]);

  return 0;
}
