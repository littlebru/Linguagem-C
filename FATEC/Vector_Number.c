#include <stdio.h>

int main(){
	int lancamento[37],i,n,lanca;
	
	for(i=0; i<37; i++){
		lancamento[i]=0;
	}
	scanf("%d",&n);
	
	for(i=0; i<n; i++){
		scanf("%d",&lanca);
	}
	for(i=0; i<37; i++){
		if(lancamento[i]==0) continue;
		printf("Houve %d lancamentos do numero %d\n",lancamento[i],i);
	}
	return 0;
}