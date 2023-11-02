#include<stdio.h>
int u[10]={1,2,3,4,5,6,7,8,9,10};
void display(int *arr);
int main()
   {
     int uni[10]={1,1,1,1,1,1,1,1,1,1};
     int a[10]={1,0,1,1,1,0,0,1,1,0};
     int b[10]={0,1,0,1,1,0,0,0,0,0};
     int a_union_b[10],a_inter_b[10],a_diff_b[10],b_diff_a[10],i;
     printf("\n universal set is: \n");
     display(uni);
     printf("\nA is\n");
     display(a);
     printf("\n B is\n");
     display(b);
     
     
     printf("\na union b is\n");
     for(i=0;i<10;i++)
        {
         a_union_b[i]=a[i]||b[i];
        }
     display(a_union_b);
     printf("\n A intersection B is\n");
     for(i=0;i<10;i++)
        {
         a_inter_b[i]=a[i]&&b[i];
        }
     display(a_inter_b);
     printf("\n A-B is \n");
     for(i=0;i<10;i++)
        {
        if(a[i]>=b[i])
         a_diff_b[i]=a[i]-b[i];
        }
     display(a_diff_b);
     printf("\n B-A is \n");
     for(i=0;i<10;i++)
        {
        if(b[i]>=a[i])
         b_diff_a[i]=b[i]-a[i];
        }
     display(b_diff_a);
     
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
