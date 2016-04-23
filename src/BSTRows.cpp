/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order here is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
int number_of_nodes(struct node*);

int search_for_node(struct node*,int, int*, int);

int number_of_nodes(struct node* root)
{
		int count=0;
		if (root == NULL)
			return 0;
		else
		{
		count = 1 + number_of_nodes(root->left) + number_of_nodes(root->right); 
		return count;
	}
}

int* BSTRighttoLeftRows(struct node* root)
{
	int* arr, index = 0, size = 0,next_node_to_search=0;
	if (root == NULL)
	{
		return NULL;
	}
	else
	{
		size = number_of_nodes(root);
		arr = (int*)malloc(sizeof(int)*size);
		arr[index] = root->data;
		index++;
		for (; next_node_to_search < size; next_node_to_search++)
		{
			index = search_for_node(root,arr[next_node_to_search], arr, index);
		}
		return arr;
	}
}
int search_for_node(struct node* root, int node_value, int* arr, int index)
{
	if (root != NULL)
	{
		if (node_value == root->data)
		{
			if (root->right != NULL)
			{
				arr[index] = root->right->data;
				index++;
			}
			if (root->left != NULL)
			{
				arr[index] = root->left->data;
				index++;
			}
			return index;
		}
		else if (root->data > node_value)
		{
			root = root->left;
			return index=search_for_node(root, node_value, arr, index);
		}
		else if (root->data < node_value)
		{
			root = root->right;
			return index= search_for_node(root, node_value, arr, index);
		}
	}
	else
		return 0;
}