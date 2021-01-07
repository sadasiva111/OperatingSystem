#include<stdio.h>
#include<conio.h>

void main(){
	int pro,res,i,j,x;
	int res_vector[5],res_avail[5],res_alloc[5];
	int max[5][5],alloc[5][5],needed[5][5];
	clrscr();
	printf("Enter No.of processes: ");
	scanf("%d",&pro);
	printf("Enter No.of resources: ");
	scanf("%d",&res);
	printf("Enter Resource Vector:");
	for(i=0;i<res;i++){
		scanf("%d",&res_vector[i]);
		res_alloc[i]=0;
		res_avail[i]=0;
	}
	printf("Enter Max Requirement Matrix:\n");
	for(i=0;i<pro;i++){
		for(j=0;j<res;j++){
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter Allocated Matrix:\n");
	for(i=0;i<pro;i++){
		for(j=0;j<res;j++){
			scanf("%d",&alloc[i][j]);
		}
	}

	for(i=0;i<pro;i++){
		for(j=0;j<res;j++){
			needed[i][j]=max[i][j]-alloc[i][j];
		}
	}
	for(i=0;i<res;i++){
		for(j=0;j<pro;j++){
			res_alloc[i]+=alloc[j][i];
		}
		res_avail[i]=res_vector[i]-res_alloc[i];
	}


	while(pro>0){
		printf("Enter the process to be executed:");
		scanf("%d",&x);
		for(i=0;i<res;i++){
			if(needed[x][i]>res_avail[i]){
				printf("Process cannot be executed\n");
				printf("UNSAFE STATE-DEADLOCK AVOIDANCE");
				exit(0);
			}
		}
		if(i==res){
			printf("Process %d is executed\n",x);
			for(j=0;j<res;j++){
				res_avail[j]+=alloc[x][j];
			}
		}
		pro--;
	}
	if(pro==0) printf("\nIT IS A SAFE STATE");

}