#include<stdio.h>
#include<conio.h>

void swap(int * a ,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void main(){
	int n,i,j;
	int process[10],burst[10];
	int ct=0,tat,wt;
	float avg_tat=0,avg_wt=0;
	clrscr();
	printf("Enter No.of Processes: ");
	scanf("%d",&n);
	printf("Enter Burst times respectively: ");
	for(i=0;i<n;i++){
		scanf("%d",&burst[i]);
		process[i]=i+1;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(burst[j]>burst[j+1]){
				swap(&burst[j],&burst[j+1]);
				swap(&process[j],&process[j+1]);
			}
		}
	}
	for(i=0;i<n;i++){
		printf("Process %d is executed\n",process[i]);
		ct+=burst[i];
		printf("\tCompletion Time: %d\n",ct);

		tat=ct-0;
		printf("\tTurnAround Time: %d\n",tat);
		avg_tat+=tat;

		wt=tat-burst[i];
		printf("\tWaiting Time: %d\n",wt);
		avg_wt+=wt;
	}
	printf("\n\nAverage TurnAround Time: %f",avg_tat/n);
	printf("\n\nAverage Waiting Time: %f",avg_wt/n);
}