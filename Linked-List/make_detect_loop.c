#include<stdio.h>
#include<stdlib.h>
void create(int n);
void detect();
void display();
void make_loop(int k);
struct node {
	int data;
	struct node *link;
};
struct node *root = NULL;
void make_loop(int k){
	struct node *temp = root;
	int count = 1,x;
	while(count<k){
		temp = temp->link;
		count++;
	}
	
	struct node *joint_point = temp;
	
	while(temp->link != NULL){
		temp = temp->link;
	}
	temp->link = joint_point;
	printf("Loop made! Enter 2 if you wanna cross check it - ");
	scanf("%d",&x);
	if(x==2)
	detect();
}

void detect(){
	struct node *slow_ptr,*fast_ptr;
    	slow_ptr =fast_ptr=root;
    	
    	while(slow_ptr !=NULL && fast_ptr != NULL && fast_ptr->link!= NULL){
    		slow_ptr = slow_ptr->link;
    		fast_ptr = fast_ptr->link->link;
    		if(slow_ptr == fast_ptr){
    			printf("\n Loop Detected");
    			exit(0);
			}
		}
		   display();
}
 
int main(){
	int n,k,x;
	printf("Enter the length of the list - ");
    scanf("%d",&n);
    create(n);
    printf("If you want to make a loop enter 1\nIf you want to detect a loop enter 2-");
    scanf("%d",&x);
    if(x==1){
	
    printf("Enter the position at which you wanna make a loop-");
    scanf("%d",&k);
    make_loop(k);
    }
    else if(x==2){
    	detect();
}
}
void create(int n){
		struct node *temp, *newNode;
	    int data,i;
	
	   root = (struct node*)malloc(sizeof(struct node));
	    if(root==NULL){
		printf("Unable to allocate memory");
	}
	else{
		printf("Enter data in node 1 -");
		scanf("%d",&data);
		root->data = data;
		root->link = NULL;
		
		temp = root;
		
		for(i=2;i<=n;i++){
			newNode = (struct node*)malloc(sizeof(struct node));
			
			if(newNode==NULL){
			printf("Unable to allocate memory");
			break;}
			
			else{
				printf("Enter the data in node %d -",i);
				scanf("%d",&data);
				
				newNode->data = data;
				newNode->link = NULL;
				
				temp->link = newNode;
				temp = temp->link;
			}
		}
		printf("List created successfully\n");
	}
}

void display(){
	struct node *temp;
	if(root==NULL)
	printf("list empty");
	else{
		temp =root;
		while(temp!=NULL){
			printf("Data = %d \n",temp->data);
			temp = temp->link;
		}
	}
}
