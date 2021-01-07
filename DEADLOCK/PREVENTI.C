
#include<stdio.h>
#include<conio.h>

void main(){
	int pro,res,i,j,k,count=0,flag[5];
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


	printf("\n\nSAFE SEQUENCE--");

	label:
	count=0;
	for(i=0;i<pro;i++){
		for(j=0;j<res;j++){
			if(needed[i][j]>res_avail[j]||flag[i]==1){
				count++;
				break;
			}
		}
		if(j==res){
		    printf("  P%d",i);
		    flag[i]=1;
		    for(k=0;k<res;k++){
			res_avail[k]+=alloc[i][k];
		    }
		    goto label;
		}
		}
		if(count==pro){
			printf("\nNO SAFE STATE IS POSSIBLE");

	}

}