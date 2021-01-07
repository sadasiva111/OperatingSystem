#include<stdio.h>
#include<conio.h>

/*
void swap(int* a,int* b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
} */
void main(){
	int n,i,j;
	int process[10],burst[10];
	int tat,wt,ct=0;
	float avg_wt=0,avg_tat=0;
	clrscr();
	printf("Enter No.of processes: ");
	scanf("%d",&n);
	printf("Enter burst times respectively: ");
	for(i=0;i<n;i++){
		scanf("%d",&burst[i]);
		process[i]=i+1;
	}
	for(i=0;i<n;i++){
		printf("Process %d is executed\n",process[i]);
		ct+=burst[i];
		printf("\tCompletion Time: %d\n",ct);

		tat=ct-0;//since tat=ct-at and here at is 0 for all
		printf("\tTurnAround Time: %d\n",tat);
		avg_tat+=tat;

		wt=tat-burst[i];
		printf("\tWaiting Time: %d\n",wt);
		avg_wt+=wt;
	}
	printf("\n\nAverage TurnAround Time: %f ",(avg_tat/n));
	printf("\n\nAverage Waiting Time: %f ",(avg_wt/n));
}