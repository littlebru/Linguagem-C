#include<stdio.h>

int main(){
//Backtracking
    float seq[50],n;
    int cont = 0;

    for(int i = 0; i<50;i++){seq[i] = 0;}

    do{
        scanf("%f",&n);
        seq[cont] = n;

        cont++;

    }while(n!=0);

    for(int i=0; i<50;i++){
        for(int j = i + 1; j<50;j++){
            if(seq[i]==seq[j]){
                seq[j] = 0;
            }
        }
        if(seq[i]!=0)
            printf("%.1f\n",seq[i]);

    }

}
