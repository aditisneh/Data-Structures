#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	int *left, *right;
};
void InOrder();
struct node *create();

struct node *create(){
	int x;
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	printf("Enter data (-1 for null node):");
	scanf("%d",&x);
	if(x==-1)
	return 0;
	
	newNode->data = x;
	printf("Enter the left Child of %d - \n",x);
	newNode->left  = create();
	printf("Enter the right Child of %d - \n",x);
	newNode->right  =create();
	 
	return newNode;
}

void main(){
	struct node *root;
	root = create();
	printf("\nTree created");
	 printf("\nDisplaying elements in InOrder-\n");
	InOrder(root);
}

void InOrder(struct node *root){

   if(root == NULL)
   return;
   
   InOrder(root->left);
   printf("%d  -> ",root->data);
   InOrder(root->right);
}
