#include<stdio.h>
#include<stdlib.h>
struct node
      {
	 int data;
	 // creating a node(struct) pointer to point next element of linked list;
	 struct node *next;

      };
//creating pointer head of type node(struct) to save the starting address of the linked list .since starting there are no elements in linked list its assigned with NULL
struct node *head=NULL;
//function to insert
struct node dummy;
void ins_strt()
     {  int data;
	struct node *ptr,*temp;
	printf("\nenter the value to input : ");
	scanf("%d",&data);
	//creating a node and saving its address in temp
	temp=(struct node*)malloc(sizeof(dummy));
	//setting the data element in temp user input
	temp->data=data;
	//setting next pointer in temp with head adress of current linkedlist .To make temp as first element
	temp->next=head;
	//now temp has the adress of first element in current linkedlist.so we asign that adress to head
	head=temp;
     }
void ins_end()
     {
	int data;
	struct node *ptr,*temp;
	printf("\nenter the value to input : ");
	scanf("%d",&data);
	 temp=(struct node*)malloc(sizeof(dummy));
	  temp->data=data;
	  temp->next=NULL;
	  //if the linkedlist is empty .then temp has the adress of the first element so we asign the adress to head
	if(head==NULL)
	  {
	    head=temp;
	  }
	else
	  {
	    ptr=head;
	    //to find the last element in linked list we go trough the linked list until we find the pointer with null which indicate the last element
	    while(ptr->next!=NULL)
		{
		    ptr=ptr->next;
		}
	    //then we asign the adress of new now(temp) to the pointer of last not which means the new node is connected to last node
	    ptr->next=temp;
	  }
     }
void ins_pos()
     {
	int data,pos,i;
	struct node *ptr,*swap,*temp;
	printf("\nenter the value to input : ");
	scanf("%d",&data);
	printf("\n enter the possition");
	scanf("%d",&pos);
	temp=(struct node*)malloc(sizeof(dummy));
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
	  {
	    head=temp;
	  }
	else
	  {
	    ptr=head;

	    for(i=1;i<(pos-1)&&(ptr->next!=NULL);i++)
	       {
		 printf("%d",ptr->data);
		 ptr=ptr->next;
	       }
	    if(i==(pos-1))
	       {
		 swap=ptr->next;
		 ptr->next=temp;
		 temp->next=swap;
	       }
	     else
	       {
		 printf("invalid position");
	       }
	  }
     }
void display()
     {
	int i=1;
	struct node *ptr;
	ptr=head;
	if(ptr!=NULL)
	  {
	    while(ptr->next!=NULL)
	      {
	       printf("%d th element\t %d \n",i,ptr->data);
	       ptr=ptr->next;
	       i++;
	      }
	    printf("%d th element\t %d \n",i,ptr->data);
	  }
	else
	   {
	     printf("\n linked list is empty \n");
	   }


     }
void dlt_end()
    {
		struct node *dlt,*pre;
		pre=NULL;
		dlt=head;
		int i;
		if(dlt!=NULL)
			{

			   while(dlt->next!=NULL)
			       {
				    pre=dlt;
			     	dlt=dlt->next;
					i=i+1;
			       }
			   printf("\n delecting %d 4th element %d ",i,dlt->data);
			   if(dlt==head)
			     {head=NULL;
			      free(dlt);
				 }
				else
				  {
			        pre->next=NULL;
				  }
			}
		else 
		    printf("The Linked list is empty");		
	}
void dlt_pos()
     {
		int pos,i=1;
		struct node *dlt,*pre;
		dlt=head;
		printf("enter the postion of element to be deleted");
		scanf("%d",&pos);
		if(dlt!=NULL)
		 {
			while(dlt->next!=NULL&&i<(pos))
			  {
				i++;
				pre=dlt;
				dlt=dlt->next;
				printf("\n %d   %d",1,dlt->data);


			  }
			  if(i==pos && dlt==head)
			    {
					head=dlt->next;
					printf("head is changed");
					printf("\n the deleting elements is %d th value %d",i,dlt->data);
					free(dlt);

				}
			  else if(i==pos)
			    {
					pre->next=dlt->next;
					printf("\n the deleting elements is %d th value %d",i,dlt->data);
					free(dlt);
				}
			  else
			      printf("invalid possition");	
		 }
		else
		printf("the linked list is empty"); 


	 }	
void dlt_strt()
	{
		struct node *dlt;
		dlt=head;
		if(dlt!=NULL)
		  {
			head=dlt->next;
			printf("\n deleted element is %d \n",dlt->data);
			free(dlt);
		  }
		 else
		    printf("the linked list is empty") ;
	}		 
int main()
    {
	int choice;
	do{
	    printf("\n1.add at start\n2.add at possition\n3.add at end\n4.display\n5.delete from end\n6.Delete from start\n7.Delete at position \n10.exit");
	    printf("\n\nEnter your choice");
	    scanf("%d",&choice);
	    switch(choice)
		{
		    case 1 : ins_strt();
			     break;

		    case 2 : ins_pos();
			     break;
		    case 3 : ins_end();
			     break;
		    case 4 : display();
			     break;
			case 5 : dlt_end();
			         break;
			case 6: dlt_strt();
			         break;
			case 7: dlt_pos();
			        break;		 
		    case 10 : printf("exiting");
			     break;
		    default : printf("Invalid choice .if you want to exit pls enter 5 as choice");

		}
	}while(choice!=10);
	return 0;
    }
