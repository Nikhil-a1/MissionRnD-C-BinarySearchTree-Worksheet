/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inorder_recursive(struct node*, int*, int*);
void preorder_recursive(struct node*, int*, int*);
void postorder_recursive(struct node*, int*, int*);

void inorder(struct node* root, int* arr)
{
	int index = 0;
	int* ptr = &index;
	inorder_recursive(root, arr, ptr);
}
void preorder(struct node* root, int* arr)
{
	int index=0;
	int* ptr = &index;
	preorder_recursive(root, arr, ptr);
}
void postorder(struct node* root, int* arr)
{
	int index = 0;
	int* ptr = &index;
	postorder_recursive(root, arr, ptr);
}
void inorder_recursive(struct node *root, int *arr,int* ptr)
{
	if (root == NULL || arr==NULL)
		return;
	else
	{
		struct node* temp=root->left;
		inorder_recursive(temp, arr,ptr);
		arr[*ptr] = root->data;
		(*ptr)++;
		temp = root->right;
		inorder_recursive(temp, arr,ptr);
		return;
	}
}
void preorder_recursive(struct node *root, int *arr,int* ptr)
{
	if (root == NULL||arr==NULL)
		return;
	else
	{
		struct node* temp;
		arr[*ptr] = root->data;
		(*ptr)++;
		temp = root->left;
		preorder_recursive(temp, arr,ptr);
		temp = root->right;
		preorder_recursive(temp,arr,ptr);
		return;
	}
}

void postorder_recursive(struct node* root, int* arr,int* ptr)
{
	if (root == NULL||arr==NULL)
		return;

	else
	{
		struct node* temp;
		temp = root->left;
		postorder_recursive(temp, arr,ptr);
		temp = root->right;
		postorder_recursive(temp, arr,ptr);
		arr[*ptr] = root->data;
		(*ptr)++;
		return;
	}
}