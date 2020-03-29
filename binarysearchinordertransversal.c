#include<stdio.h>
#include<stdlib.h>
struct node {
int a;
struct node* left;
struct node* right;
};
struct node *newNode(int item) {
struct node*temp = (struct node*)malloc(sizeof(struct node));
temp->a = item;
temp->left = temp->right = NULL;
return temp;
}
struct node* insert(struct node *node, int value){
if (node==NULL)return newNode(value);
if (value<node->a)
node->left = insert(node->left, value);
else if(value>node->a)
node->right = insert(node->right, value);
return node;
}
void inorder (struct node* root) {
if(root == NULL) return;
inorder(root->left);
printf("%d->", root->a);
inorder(root->right);
}
void main () {
struct node* root = NULL;
root = insert(root, 52);
insert(root, 35);
insert(root, 11);
insert(root, 45);
insert(root, 78);
insert(root, 89);
insert(root, 66);
printf("\n inorder traversal \n");
inorder(root);
}
