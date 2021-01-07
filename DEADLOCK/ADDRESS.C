#include<stdio.h>
#include<conio.h>

void main(){
	int frames[20],rem_pages;
	int ms,pfs,fno,n,i,j,k;
	int ps,np,req[10];
	int frameNo,pageNo,Offset,phyAddr,base;
	clrscr();
	printf("Enter Main Memory Size:");
	scanf("%d",&ms);
	printf("Enter Page Size/Frame Size:");
	scanf("%d",&pfs);

	fno=ms/pfs;
	printf("Main Memory is divided into %d frames\n",fno);

	printf("\nEnter No.of Process to assign:");
	scanf("%d",&n);

	for(i=0;i<fno;i++){
		frames[i]=0;
	}
	rem_pages=fno;
	for(i=0;i<n;i++){
		printf("Enter No.of pages for process %d:",i+1);
		scanf("%d",&np);

		if(np>rem_pages){
			printf("Memory is lower than asked\n");
			n++;
			continue;
		}

		printf("Give %d frames that are to be allocated:",np);
		for(j=0;j<np;j++){
			scanf("%d",&req[j]);
			if(frames[req[j]]!=0){
				printf("\tFrame %d is occupied\n",req[j]);
				n++;
				break;
			}
		}
		if(j==np){
			printf("Process %d pages are allocated",i+1);
			for(k=0;k<np;k++){
				frames[req[k]]=i+1;
			}
		}
	}
	for(i=0;i<fno;i++){
		if(frames[i]!=0){
			printf("\nFRAME %d -- PROCESS %d",i,frames[i]);
		}
		else printf("\nFRAME %d -- EMPTY",i);
	}

	printf("\n\nGive logical address(frameNo):");
	scanf("%d",&frameNo);

	printf("Enter the PageNo in process %d:",frames[frameNo]);
	scanf("%d",&pageNo);

	printf("Enter logical address(Offset):");
	scanf("%d",&Offset);

	printf("Enter Base Address of process %d in memory:",frames[frameNo]);
	scanf("%d",&base);

	phyAddr=base+(pageNo*pfs)+Offset;

	printf("Physical Address:%d",phyAddr);


}
