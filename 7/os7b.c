#include<stdio.h>
void main(){
	int rs[25], m[10], count[10], flag[25], n, f, pf=0,i, j , k, min,next=1;
	printf("Enter the length of reference string:");
	scanf("%d",&n);
	printf("Enter the reference string:");
	for(i=0;i<n;i++){
		scanf("%d",&rs[i]);
		flag[i]=0;
	}
	printf("Enter the number of frames:");
	scanf("%d",&f);
	for(i=0;i<f;i++){
		count[i]=0;
		m[i]=-1;
	}
	printf("The Page Replacement process is\n");
	for(i=0;i<n;i++){
		for(k=0;k<f;k++){
			if(m[k]==rs[i]){
				count[k]=next++;
				break;
			}
		}
		if(k==f){
			if(i<f){
				m[i]=rs[i];
				count[i]=next++;
			}
			else{
				min=0;
				for(j=1;j<f;j++)
					if(count[min] > count[j])
						min=j;
				m[min]=rs[i];
				count[min]=next++;
			}
			pf++;
		}
		for(j=0;j<f;j++)
			printf("%d\t", m[j]);
		if(k==f)
			printf("PF No.%d\n" , pf);
	}
	printf("\nThe number of page faults using LRU are %d",pf);
}
