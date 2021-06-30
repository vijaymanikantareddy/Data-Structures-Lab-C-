/* c) Write a C program that uses functions to perform deletion operation on a singly linked list */
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
struct node* delete_beg(struct node*);
struct node* delete_end(struct node*);
struct node* delete_after(struct node*);

void main()
{
	int option;
	do
	{
		printf("\n\n *****MAIN MENU *****");
 		printf("\n 1: Create a list");
 		printf("\n 2: Display the list");
 		printf("\n 3: Delete a node at begining of the list");
 		printf("\n 4: Delete a node at end of the list");
 		printf("\n 5: Delete a node after a perticular node in list");
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
				start = delete_beg(start);
				printf("\n first node successfully deleted");
				break;
			case 4:
				start = delete_end(start);
				printf("\n Last node successfully deleted");
				break;
			case 5:
				start = delete_after(start);
				printf("\n Node successfully deleted");
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
	struct node * delete_beg(struct node * start)
	{
		struct node * ptr;
		ptr=start;
		start=start->next;
		free(ptr);
		return start;
	}
	struct node *delete_end(struct node *start)
{
	struct node *ptr, *preptr;
	ptr = start;
	while(ptr -> next != NULL)
	{
 		preptr = ptr;
 		ptr = ptr -> next;
	}
	preptr -> next = NULL;
	free(ptr);
	return start;
}
struct node *delete_after(struct node *start) 
{
	struct node *ptr, *preptr;
	int val;
	printf("\n Enter the value after which the node has to deleted : ");
	scanf("%d", &val);
	ptr = start;
	preptr = start;
	if(preptr->data == val) //we have to use this if we want to delete a node after a first node.
		ptr=ptr->next;
	while(preptr -> data != val)
	{
 		preptr = ptr;
 		ptr = ptr -> next;
	}
	
	preptr -> next=ptr -> next;
	free(ptr);
	return start;
}
