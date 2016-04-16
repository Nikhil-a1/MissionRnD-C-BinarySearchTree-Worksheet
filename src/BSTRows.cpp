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

int copying_elements_into_array(struct node*, struct node*,int*,int);

int* BSTRighttoLeftRows(struct node* root)
{
	int* arr,index=0;
	if (root == NULL)
	{
		return NULL;
	}
	else
	{
		arr = (int*)calloc(20,sizeof(int));
		struct node* root_node = root,*prev_node=NULL;
		arr[index] = root->data;
		index++;
		while (root_node != NULL)
		{
			index=copying_elements_into_array(root_node, prev_node, arr,index);
			prev_node = root_node->left;
			root_node = root_node->right;
		}
		arr = (int*)realloc(arr, (index));
		return arr;
	}
}

int copying_elements_into_array(struct node* root_node, struct node* prev_node, int* arr,int index)
{
	if (root_node == NULL)
		return index;
	else
	{
		struct node* temp1, *temp2;
		temp1 = root_node->right;
		temp2 = root_node->left;
		if (temp1 != NULL)
		{
			arr[index] = temp1->data;
			index++;
		}
		if (temp2 != NULL)
		{
			arr[index] = temp2->data;
			index++;
		}
		if (prev_node != NULL)
		index = copying_elements_into_array(prev_node, NULL, arr, index);
		return index;
	}
}

