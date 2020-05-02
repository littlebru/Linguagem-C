#include<stdio.h>

int main(){
//Backtracking
    char seq[5],n;
    int cont = 0;

    for(int i = 0; i<5;i++){seq[i] = 0;}

    do{
        scanf("%c",&n);
        seq[cont] = n;

        cont++;

    }while(n!= ']');

    for(int i=0; i<5;i++){
        for(int j = i + 1; j<5;j++){
            if(seq[i]==seq[j]){
                seq[j] = ']';
            }
        }
        if(seq[i]!=']')
            printf("%c\n",seq[i]);
        }
    }


