#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left, *right;
};
struct node *root = NULL;

void insert(int data);
struct node *Get_node(int data);
struct node *Insert(int data);
void InOrder(struct node *root);

struct node *Get_node(int data){
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	
	new_node->data  = data;
	new_node->left = NULL;
	new_node->right = NULL;
}

struct node *Insert(int data){
	if(root == NULL){
		root = Get_node(data);
		return root;
	}
	else if(data<= root->data)
	root->left = Insert(data);
	
	else
	root->right = Insert(data);
	
	return root;
}

int main(){
	root = insert(root, 50); 
	root = Insert(15);
	root = Insert(5);
	root = Insert(13);
	root = Insert(17);
	root = Insert(3);
    InOrder(root);	
}

void InOrder(struct node *root){

   if(root == NULL)
   return;
   
   InOrder(root->left);
   printf("%d  -> ",root->data);
   InOrder(root->right);
}
