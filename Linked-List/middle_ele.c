#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};
struct node *root=NULL;

void create();
void middle_element();

int main(){
	int data,i,n;
	printf("Enter the length of the string-");
	scanf("%d",&n);
	create(n);
	middle_element();
	return 0;
}

void create(int n){
	struct node *temp, *newNode;
	int data,i;
	root = (struct node*)malloc(sizeof(struct node));
	if(root==NULL)
	printf("Unable to allocate");
	else{
	
	printf("Enter the string, first element-");
	scanf("%d",&data);
    root->data = data;
	root->link = NULL;
	
	temp=root;
	
	for(i=2;i<=n;i++){
		newNode = (struct node*)malloc(sizeof(struct node));
			if(newNode==NULL){
			printf("Unable to allocate memory");
			break;}
			else{
			 printf("Enter data %d-",i);
		     scanf("%d",&data);
		     newNode->data = data;
		     newNode->link = NULL;
		     
		     temp->link = newNode;
		     temp = temp->link;
	}

	}
		printf("String of number created successfully\n");
}
}

void middle_element(){
	struct node *slow, *fast;
        if(root->link==NULL){
	
                printf("The middle element is [%d]\n\n",root->data);
                return;
            }
        slow=fast=root;
 
        
        while(fast->link!=NULL && fast->link->link!=NULL)
        {
                slow=slow->link;
                fast=fast->link->link;
        }
        printf("The middle element is [%d]\n\n", slow->data);  
    }  
 



