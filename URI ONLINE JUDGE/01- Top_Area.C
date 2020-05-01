#include<stdio.h>

int main(){
  char O;
  double M[12][12], resulta=0.0;
  int i, j,l1=0,l2=12;

  for(i=0; i<12; i++){
  for(j=0; j<12; j++){
        M[j][i]=0;
    }
  }
scanf("%c",&O);

for(i=0; i<12; i++){
   for(j=0; j<12; j++){
     scanf("%lf",&M[j][i]);
   }
}
if(O == 'S'){
    for(i=0; i<12; i++)
    {
       l1++;
       l2--;
       if(l1 > 5)break;
       for(j=l1; j<l2; j++){
           resulta += M[j][i];
        }
    }
  }
if(O == 'M'){
    for(i=0; i<12; i++)
    {
       l1++;
       l2--;
       if(l1 > 5)break;
       for(j=l1; j<l2; j++){
           resulta += M[j][i];
        }
    }
      resulta = resulta/30;
  }
printf("%.1lf\n",resulta);

  return 0;
}
