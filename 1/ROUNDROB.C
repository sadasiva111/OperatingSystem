#include<stdio.h>
#include<conio.h>

void main(){
	int n,i,j;
	int process[10],burst[10],ts,completed[10];
	int ct=0,tat,wt;
	int burst2[10];
	float avg_tat=0,avg_wt=0;
	clrscr();
	printf("Enter No.of Processes: ");
	scanf("%d",&n);
	printf("Enter Burst times respectively: ");
	for(i=0;i<n;i++){
		scanf("%d",&burst[i]);
		process[i]=i+1;
		burst2[i]=burst[i];
		completed[i]=0;
	}
	printf("Enter Time Slice: ");
	scanf("%d",&ts);

	for(i=0;i<n;i++){

		if(burst[i]>=ts){
			ct+=ts;
			burst[i]-=ts;
		}
		else if(burst[i]<ts && burst[i]!=0){
			ct+=burst[i];
			burst[i]=0;
		}
		if(burst[i]==0 && completed[i]!=1){
			printf("\nProcess %d is completed",process[i]);
			printf("\tCompletion Time: %d\n",ct);

			tat=ct-0;
			printf("\tTurnAround Time: %d\n",tat);
			avg_tat+=tat;

			wt=tat-burst2[i];
			printf("\tWaiting Time: %d\n",wt);
			avg_wt+=wt;
			completed[i]=1;
		}
		for(j=0;j<n;j++){
			if(completed[j]==0) break;
		}
		if(j==n) break;
		if(i==n-1){
			i=-1;
		}

	}
	printf("\n\nAverage TurnAround Time: %f",avg_tat/n);
	printf("\n\nAverage Waiting Time: %f",avg_wt/n);
}