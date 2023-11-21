
#include<stdio.h>
int u[10]={1,2,3,4,5,6,7,8,9,10};
void display(int *arr);
int find(int *arr);
int flag=-1;
int main()
   {
     int uni[10]={1,1,1,1,1,1,1,1,1,1};
     int a[10]={1,1,1,1,1,0,0,1,1,0};
     int b[10]={0,0,0,0,0,0,0,0,0,1};
     int a_union_b[10],i,p_a=0,p_b=0;
     printf("\n universal set is: \n");
     display(uni);
     printf("\nA is\n");
     display(a);
     printf("\n B is\n");
     display(b);
     p_a=find(a); 
     printf("\n parent of A is %d \n",p_a);      
     p_b=find(b);
     printf("\n parent of B is %d \n",p_b);
    if(p_a!=p_b)
       { 
          printf("\na union b is\n");
          for(i=0;i<10;i++)
          {
           a_union_b[i]=a[i]||b[i];
           
          }
          display(a_union_b);
       }
    else
       printf("union not possible");
     
     return 0;
   }
void display(int *arr)
  {
  int *ar=arr,i;
  for(i=0;i<10;i++)
    {
      if(*ar==1)
      printf("%d \t",u[i]);
      ar++;
    }
  }
 int find(int *arr)
 	{
 	  int *ar=arr,i;
 	  flag=flag-1;
 	  for(i=0;i<10;i++)
 	     {
 	       if(*ar==1)
               return u[i];
               ar++;
 	     }
 	  return flag;
 	}
