#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left, *right;
};

// Create a node
struct node * newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data= item;
  temp->left = temp->right = NULL;
  return temp;
}
void inorder(struct node *root)
    {
        if(root!=NULL)
            {
                //left sub tree
                inorder(root->left);
                //printing root
                printf("\n %d \n",root->data);
                //inordering rigth sub tree
                inorder(root->right);

            }
    }
struct node * insert(struct node *root,int item)
      {
        if(root==NULL)
          {
            return newNode(item);
          }
        if(item<root->data)
            {
                root->left=insert(root->left,item);
            }  
        else
            {
               root->right=insert(root->right,item); 
            }
        return root;
      }
//preorder traversal
void preorder(struct node *root)
    {
        if(root!=NULL)
            {
                 //printing root
                printf("\n %d \n",root->data);
                //left sub tree
                preorder(root->left);
               
                //preordering rigth sub tree
                preorder(root->right);

            }
    }
//postorder traversal code
void postorder(struct node *root)
    {
        if(root!=NULL)
            {
                //left sub tree
                postorder(root->left);
               
                //postordering rigth sub tree
                postorder(root->right);
                 //printing root
                printf("\n %d \n",root->data);

            }
    }
int main()
    {
        struct node *start=NULL;
        int choice,item;
        do{
            printf("\n1.Insert \n2.Inorder traversel\n3.Preorder traversal\n4.Postorder teaversal \n5.Exit");
            printf("Enter your choice");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:   printf("Enter the value to be inserted");
                          scanf("%d",&item);
                          start=insert(start,item);
                          break;
                case 2: inorder(start);
                        break;
                case 3: preorder(start);
                        break;
                case 4: postorder(start);
                        break;                  
            }
        }while(choice!=5);

    }
