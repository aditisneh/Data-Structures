#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
 struct node *root;
 
void create(int n);
void display();
void delete(int data, int position);


int main(){
	int n;
	printf("Enter the length of list-");
	scanf("%d",&n);
	create(n);
	printf("Enter the data you want to delete")
}

void delete(int position){
	
}
