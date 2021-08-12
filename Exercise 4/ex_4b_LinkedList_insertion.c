/* b) Write a C program that uses functions to perform insertion operation on a singly linked list */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* start = NULL;
struct node* createll(struct node *);
void display(struct node *);
struct node* insert_beg(struct node*);
struct node* insert_end(struct node*);
struct node* insert_after(struct node*);
void main()
{
	int option;
	do
	{
		printf("\n\n *****MAIN MENU *****");
 		printf("\n 1: Create a list");
 		printf("\n 2: Display the list");
 		printf("\n 3: inserting a node at begining of the list");
 		printf("\n 4: insert a node at the end of the list");
 		printf("\n 5: insert a node after a perticular node in the list");
		printf("\n 6: Exit");
		printf("\nenter your option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				start = createll(start);
				printf("\n linked list is created");
				break;
			case 2:
				display (start);
				break;
			case 3:
				start = insert_beg(start);
				break;
			case 4:
				start= insert_end(start);
				break;
			case 5:
				start = insert_after(start);
				break;
		}
	}while(option != 6);
}
struct node* createll(struct node* start)
{
	struct node *newnode; 
	struct node *ptr;
	int num;
	printf("\n enter the data or -1 to end: ");
	scanf("%d",&num);
	while(num!= -1)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->data=num;
		if(start == NULL)
		{
			newnode->next=NULL;
			start=newnode;
		}
		else
		{
			ptr = start;
			while(ptr->next != NULL)
			{
				ptr = ptr->next;
				}	
			ptr->next = newnode;
			newnode->next=NULL;
	    }
	    printf("\n enter the data: ");
	    scanf("%d",&num); 
	   }
	   return start;
	}
	void display(struct node* start)
	{
		struct node * ptr;
		ptr=start;
		while (ptr != NULL)
		{
			printf("%d\t ", ptr->data);
			ptr=ptr->next;
		}
	}
	struct node * insert_beg(struct node * start)
	{
		struct node * newnode;
		int num;
		printf("\n enter the data: ");
		scanf("%d",&num);
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=num;
		newnode->next=start;
		start=newnode;
		return start;
	}
	struct node* insert_end(struct node * start)
	{
		int num;
		printf("\n enter the data: ");
		scanf("%d",&num);
		struct node* new_node, *ptr;
		new_node= (struct node*)malloc(sizeof(struct node));
		new_node->data=num;
		new_node->	next= NULL;
		ptr=start;
		while(ptr->next!=NULL)
			ptr= ptr->next;
		ptr->next=new_node;
		return start;	
	}
	struct node* insert_after(struct node * start)
	{
		int num, val;
		printf("\n enter the data: ");
		scanf("%d",&num);
		printf("\n enter a value after which the new node is inserted: ");
		scanf("%d",&val);
		struct node* new_node, *ptr, *preptr;
		new_node= (struct node*)malloc(sizeof(struct node));
		new_node->data=num;
		ptr=start;
		preptr=ptr;
		while(preptr->data!=val)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=new_node;
		new_node->next=ptr;
		return start;
		
	 }
