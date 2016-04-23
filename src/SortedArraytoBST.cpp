/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node* array_to_bst(int*, int, int);

struct node * convert_array_to_bst(int *arr, int len)
{
	if (arr==NULL || len<=0)
	return NULL;
	else
	{
		int low = 0, high = len-1;
		struct node* root;
		root = array_to_bst(arr, low, high);
		return root;
	}
}

struct node* array_to_bst(int* arr, int low_index, int high_index)
{
	if (low_index > high_index)
		return NULL;
	else
	{
		int mid = (low_index + high_index) / 2;
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		if (low_index == high_index)
		{
			temp->data = arr[low_index];
			temp->left = NULL;
			temp->right = NULL;
		}
		else
		{
			temp->data = arr[mid];
			temp->left = array_to_bst(arr, low_index, mid - 1);
			temp->right = array_to_bst(arr, mid + 1, high_index);
		}
		return temp;
	}
}

