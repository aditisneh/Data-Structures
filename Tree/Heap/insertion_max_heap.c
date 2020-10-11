#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
	int data;
	struct node *right;
	struct node *left;
};

struct node *root = NULL;

void insert(int *A, int n, int x );
struct node* create();
void swap(int a,int b);


void swap(int a,int b){
	int temp;
	a=temp;
	a=b;
	b=temp;
}
int main(){
	int x;
	root = create();
	printf("\nTree created \n");

	int h;
	h=maxDepth(root);
	printf("height of the tree is %d",h);
	int n;
	n = pow(2,h);
	printf("\nnodes %d\n",n);
	int *A;
	A = (int*)malloc(n*sizeof(int));
		printf("Enter data to be inserted in the heap-");
	scanf("%d", &x);
	insert(A,n,x);
	int i;
	for(i=0;i<n;i++){
		printf("%d  ",A[i]);
	}
}

void insert(int *A, int n, int x ){
	n = n+1;
	A[n] = x;
	int i;
	i= n;
	int parent;
	while(i>1){
		parent = i/2;

	if(A[parent] <A[i]){
		swap(A[parent],A[i]);
		i=parent;
	}
	else
	return;
}
}
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
int maxDepth(struct node* node)  
{ 
   if (node==NULL)  
       return 0; 
   else 
   { 
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left); 
       int rDepth = maxDepth(node->right); 
  
       /* use the larger one */
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   }
}
