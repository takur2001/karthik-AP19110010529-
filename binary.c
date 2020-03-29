#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct Binary_tree
{
	struct Binary_tree *left;
	int data;
	struct Binary_tree *right;
}node;

void crbtree(node *,int);
void preorder(node *);
void inorder(node *);
void postorder(node *);

void main()
{
	node *root=NULL;
	int e,ch;
	do
	{
		printf("\n....Binary Tree Traversals....");
		printf("\n1.Create\n2.Preorder\n3.Inorder\n4.Postorder\n5.Exit");
		printf("\nEnter ur Choice:");
		scanf("%d",&ch);

		if(ch==5)
		{
			free(root);
			exit(0);
		}

		switch(ch)
		{
			case 1: printf("\nEnter Elements into Binary Tree:");
				scanf("%d",&e);
				root=(node *)malloc(sizeof(node));
				crbtree(root,e);
			break;
			case 2: preorder(root);
			break;
			case 3: inorder(root);
			break;
			case 4: postorder(root);
			break;
			default:printf("\nYour Choice is Out of Range");
		}
	}while(1);
}

void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%3d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%3d",root->data);
		inorder(root->right);
	}
}

void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%3d",root->data);
	}
}

void crbtree(node *root,int e)
{
	char ch;
	if(root!=NULL)
	{
		root->data=e;
		printf("\nDo you want add as a Left Child(Y/N):");
		scanf("%c",&ch);
		if(ch=='y'||ch=='Y')
		{
			root->left=(node *)malloc(sizeof(node));
			printf("\nEnter Element:");
			scanf("%d",&e);
			crbtree(root->left,e);
		}
		else
		{
		      root->left=NULL;
		}
		printf("\nDo you want add as a Right Child(Y/N):");
		scanf("%c",&ch);
		if(ch=='y'||ch=='Y')
		{
			root->right=(node *)malloc(sizeof(node));
			printf("\nEnter Element:");
			scanf("%d",&e);
			crbtree(root->right,e);
		}
		else
		{
		      root->right=NULL;
		}
	}
}