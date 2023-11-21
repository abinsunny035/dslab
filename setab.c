#include<stdio.h>
int u[50]={1,2,3,4,5,6,7,8,9,10};
int main(){
	int n,i;
	     int uni[10]={1,1,1,1,1,1,1,1,1,1};
     int a[10]={01,0,1,1,1,0,0,1,1};
     int b[10]={0,1,0,1,1,0,0,0,0,0};
	printf("\nEnter the size of the set");
	scanf("%d",&n);
	printf("\nEnter the elements of set A");
	for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
	printf("\nEnter the elements of set B");
	for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
		}
	
	printf("\nUnion :");
			for(i=0;i<n;i++)
		{
			u[i]=a[i]||b[i];
			printf("%d",u[i]);
		}
	return 0;
}
