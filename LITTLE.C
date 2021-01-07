#include<stdio.h>
#include<conio.h>

void main(){
	float a,t[10],T[10];
	int i,x;
	clrscr();
	printf("Enter T(n+1) to find:");
	scanf("%d",&x);
	label:
	printf("Enter Smoothing factor alpha:");
	scanf("%f",&a);
	if(a<0 || a>1){
		printf("Alpha should be 0<=Alpha<=1");
		goto label;
	}
	printf("Enter previous times t1,t2,...");
	for(i=0;i<x-1;i++){
		scanf("%f",&t[i]);
	}
	printf("Enter predicted T1:");
	scanf("%f",&T[0]);

	for(i=1;i<x;i++){
		T[i]=(a*t[i-1])+((1-a)*(T[i-1]));
		printf("T[%d]--%f",(i+1),T[i]);
	}
	printf("Predicted T%d = %f ",x,T[x-1]);
}