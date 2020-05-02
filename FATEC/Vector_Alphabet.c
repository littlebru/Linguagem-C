#include <stdio.h>

int main()
{
    int lancamento[100], n, i;
    char lanca;
    for(i=65; i<91;i++) lancamento[i]=0;

    scanf("%d", &n);
    for (i=0;i<n;i++){
        scanf("%c",&lanca);
        if ((lanca = getchar())!=10)
         ++ lancamento[lanca];
        printf("valor ==== %d\n",i);
        printf("letra ==== %c\n",lanca);
        }
    for (i=65; i<91;i++){
        if (lancamento[i]==0) continue;
        printf("Houve %d lancamentos do n %c\n",lancamento[i],i);
        }
        return 0;
}
