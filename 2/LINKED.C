#include<stdio.h>
#include<conio.h>

void main(){
	int n,i,j,k,disk[128];
	char fileName[10];
	int nb,reqb[10];
	clrscr();
	for(i=0;i<128;i++){
		disk[i]=0;
	}

	printf("Enter No.of Files you want to allocate: ");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		printf("Enter FileName: ");
		scanf("%s",fileName);

		printf("Enter No.of Blocks required: ");
		scanf("%d",&nb);
		printf("Enter %d blocks: ",nb);
		for(j=0;j<nb;j++){
			scanf("%d",&reqb[j]);
		}
		for(j=0;j<nb;j++){
			if(disk[reqb[j]]==1){
				printf("\tBlock %d is occupied\n",reqb[j]);
				n++;
				break;
			}
		}
		if(j==nb){
			printf("\tFile %s is allocated\n",fileName);
			for(k=0;k<nb;k++){
				disk[reqb[k]]=1;
				printf("%d->",reqb[k]);
			}
		}
	}
}