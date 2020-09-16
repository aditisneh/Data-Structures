
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};
 struct node *root=NULL;
 
 void createList(int n);
 void append();
 void display();
 
 int main(){
 	int n;
 	printf("Enter the total number of nodes-");
 	scanf("%d",&n);
 	createList(n);
 	append();
 	printf("The final list becomes-\n");
 	display();
 	return 0;
 }
 
 void append(){
 	struct node *temp;
 	temp = (struct node*)malloc(sizeof(struct node));
 	
 	printf("Enter node data-"); 
 	scanf("%d",&temp->data);
 	
 	temp->link =NULL;
 	
 	if(root==NULL)
 	root=temp;
 	
 	else{
 		struct node *p;
 		p=root;
 		while(p->link!=NULL)
 		{
 			p=p->link;
		 }
		 p->link = temp;
	 }
 }
 
 void createList(int n){
 	struct node *temp,*newNode;
 	int data,i;
 	root = (struct node*)malloc(sizeof(struct node));
 	if(root==NULL){
	 printf("Unable to allocate");
	 }
	 else{
	 	printf("Enter data in node 1: ");
	 	scanf("%d",&data);
	 	
	 	root->data = data;
	 	root->link = NULL;
	 	
	 	temp = root;
	 	
	 	for(i=2;i<=n;i++){
	 		newNode = (struct node*)malloc(sizeof(struct node));
	 		if(newNode == NULL){
	 		  	 printf("Unable to allocate");
				break;	
			 }
			 else{
			 	printf("Enter data in node %d : ",i);
			 	scanf("%d",&data);
			 	newNode->data = data;
			 	newNode->link = NULL;
			 	
			 	temp->link = newNode;
			 	temp = temp->link;
			 }
			 
		 }
		 printf("Linked list created\n");
	 }
 }
 
 void display(){
 	struct node *temp;
 	if(root == NULL)
 	printf("list empty");
 	else{
 		temp = root;
 		while(root!=NULL){
 			printf("Data = %d \n", temp->data);
 			temp = temp->link;
		 }
	 }
 }
