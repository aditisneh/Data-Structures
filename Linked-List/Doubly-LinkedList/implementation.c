#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *prev;
	struct node *next;
};

struct node *head = NULL;

struct node *last = NULL;
void create();
void display();
void displayListFromEnd();

int main(){
	int n;
	printf("Enter the length of list to be created -");
	scanf("%d",&n);
	create(n);
	display();
	printf("Traversing from end \n")
	displayListFromEnd();
}

void create(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        if(head != NULL)
        {
            printf("Enter data of 1 node: ");
            scanf("%d", &data);

            head->data = data;
            head->prev = NULL;
            head->next = NULL;

            last = head;

            /*
             * Create rest of the n-1 nodes
             */
            for(i=2; i<=n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));

                if(newNode != NULL)
                {
                    printf("Enter data of %d node: ", i);
                    scanf("%d", &data);

                    newNode->data = data;
                    newNode->prev = last; 
                    newNode->next = NULL;

                    last->next = newNode; 
                    last = newNode;       
                }
                else
                {
                    printf("Unable to allocate memory.");
                    break;
                }
            }

            printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
        }
        else
        {
            printf("Unable to allocate memory");
        }
    }
}
void display(){
	struct node *temp;
	temp = head;
	int i=1;
	while(temp != NULL){
		printf("Data %d = %d\t",i,temp->data);
		temp = temp->next;
		i++;
	}
}

void displayListFromEnd()
{
    struct node * temp;
    int n = 0;

    if(last == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = last;
        printf("\n\nDATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of last-%d node = %d\n", n, temp->data);

            n++;
            
            /* Move the current pointer to previous node */
            temp = temp->prev; 
        }
    }
}
