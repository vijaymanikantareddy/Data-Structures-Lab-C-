#include<stdio.h>
#include<stdlib.h>

 struct node
 {
 	int data;
 	struct node* left, *right;
 };

 struct node* root = NULL;

 struct node *create(struct node* );
 void display(struct node* );
 struct node* delete_node(struct node*, int);
 struct node* findminvalue(struct node*);
 
 void main()
 {
 	int option, val;
	struct node* ptr;
 	do
 	{
 		printf("\n\n *** MAIN MENU ***");
 		printf("\n 1. create a BST");
 		printf("\n 2. display a BST");
 		printf("\n 3. Delete a node from a BST");
 		printf("\n 4. Quit");
 		printf("\n enter your choice: ");
 		scanf("%d",&option);
 		switch(option)
 		{
 		case 1:
 			root = create(root);
 			break;
 		case 2:
 			if(root == NULL)
			 	printf("\n NO elements in the BST ");
		 	else
 			{
 				printf("\n the elements in the BST: ");
 				display(root);
	 		}
			break;
		case 3:
	 		printf("\n enter a value to delete from a BST: ");
 			scanf("%d", &val);
 			root=delete_node(root, val);
 			break;
 		default:
		 	printf("\nenter valid option!");	
 		}
 	}while(option!=4);
 }

 struct node* create(struct node* root)
 {
 	int val;
 	printf("\n enter data (-1 to stop): ");
 	scanf("%d",&val);
 	while(val != -1)
 	{
 		struct node *ptr, *nodeptr, *parentptr;
 		ptr=(struct node*)malloc(sizeof(struct node));
 		ptr->data=val;
 		ptr->left=NULL;
 		ptr->right=NULL;
 		if(root==NULL)
 			root=ptr;
 		else
 		{
 			parentptr=NULL;
 			nodeptr=root;
 			while(nodeptr!=NULL)
 			{
 				parentptr=nodeptr;
 				if(val<nodeptr->data)
 					nodeptr=nodeptr->left;
 				else
 					nodeptr=nodeptr->right;
 			}
 			if(val<parentptr->data)
 				parentptr->left=ptr;
 			else
 				parentptr->right=ptr;
 		}
 		printf("\n enter data (-1 to stop): ");
 		scanf("%d",&val);
 	}
 	return root;
 }

 void display(struct node* root)
 {
 	if(root != NULL)
 	{
 		display(root->left);
 		printf("%4d", root->data);
 		display(root->right);
 	}
 }
 
 struct node* delete_node(struct node* root, int val)
 {
 	if(root==NULL)
 		return root;
 // If the val to be deleted is smaller than the root go to left subtree,
 	if(val<root->data)
 		root->left=delete_node(root->left, val);
 // If the val to be deleted is greater than the root go to right subtree,
 	else if(val>root->data)
 		root->right=delete_node(root->right, val);
 	else
 	{
 //a node with one child or null
 		if(root->left==NULL)
 		{
 			struct node* temp=root->right;
 			free(root);
 			return temp;
 		}
 		else if(root->right==NULL)
		{
 			struct node* temp=root->left;
 			free(root);
 			return temp;
 		}
// a node with two child
 		struct node* temp=findminvalue(root->right);
 		root->data=temp->data;
 		root->right=delete_node(root->right,temp->data);
 	}
 	return root;
 }
 struct node* findminvalue(struct node* ptr)
 {
 	struct node* current=ptr;
 	while(current->left!=NULL)
 		current = current->left;
 	return current;
 }
