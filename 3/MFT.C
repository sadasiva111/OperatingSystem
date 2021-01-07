#include<stdio.h>
#include<conio.h>

void main(){
	int ms,os,fs,i;
	int nf,n,req;
	int extfrag=0,intfrag=0;
	clrscr();
	printf("Enter Memory Size: ");
	scanf("%d",&ms);
	printf("Enter OS Size: ");
	scanf("%d",&os);
	ms=ms-os;
	printf("Enter Frame Size: ");
	scanf("%d",&fs);

	nf=ms/fs;
	if(ms%fs!=0){
		extfrag=ms-(nf*fs);
	}

	printf("Enter No.of Tasks:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\tMemory Required for Task %d: ",i+1);
		scanf("%d",&req);
		if(req>fs){
			printf("\tmemory cannot be assigned for task %d\n",i+1);
			//n++;
			continue;
		}
		else{
			intfrag+=fs-req;
			printf("\tmemory is assigned for task %d\n",i+1);
		}
	}
	printf("\n\nExternal Fragementation=%d",extfrag);
	printf("\nInternal Fragementation=%d",intfrag);

}