#include<stdio.h>
#include<conio.h>

void main(){
	int n,i,j,k,disk[128];
	char fileName[10];
	int sb,nb;
	clrscr();
	for(i=0;i<128;i++){
		disk[i]=0;
	}

	printf("Enter No.of Files you want to allocate: ");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		printf("Enter FileName: ");
		scanf("%s",fileName);
		printf("Enter the Starting Block: ");
		scanf("%d",&sb);
		if(disk[sb]==1){
			printf("\tBlock %d is occupied\n",sb);
			n++;
			continue;
		}
		printf("Enter No.of Blocks required: ");
		scanf("%d",&nb);
		for(j=sb;j<sb+nb;j++){
			if(disk[j]==1){
				printf("Block %d is occupied\n",j);
				n++;
				break;
			}
		}
		if(j==sb+nb){
			for(k=sb;k<sb+nb;k++){
				disk[k]=1;
			}
			printf("\tFile %s is allocated\n",fileName);
		}
	}
}