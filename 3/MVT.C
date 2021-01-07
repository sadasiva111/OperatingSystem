#include<stdio.h>
#include<conio.h>

void main(){
	int ms,os,i;
	int nf,req,c;
	clrscr();
	printf("Enter Memory Size: ");
	scanf("%d",&ms);
	printf("Enter OS Size: ");
	scanf("%d",&os);
	ms=ms-os;

	for(i=0;ms>0;i++){
		printf("\tMemory Required for Task %d: ",i+1);
		scanf("%d",&req);
		if(req>ms){
			printf("\tmemory cannot be assigned for task %d\n",i+1);
			i--;
		}
		else{
			ms=ms-req;
			printf("\tmemory is assigned for task %d\n",i+1);
		}
		printf("Do you want to assign more tasks? Y(1) or N(0):");
		scanf("%d",&c);
		if(c==1){
			continue;
		}else break;
	}
	printf("\n\nExternal Fragementation=%d",ms);
	getch();
}