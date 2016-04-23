/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct element_in_array
{
	int content;
	 int* ptr;
};
int size_of_tree(struct node*);
void convert_bst_to_array(struct node*, struct element_in_array*, int*);
void swap(int*, int*);

void fix_bst(struct node *root)
{
	int size = 0, index = 0, loop_i = 0;
	int* position1=NULL, *position2=NULL;
	int* ptr_to_aray_index = &index;
	struct element_in_array* arr;
	size = size_of_tree(root);
	arr = (struct element_in_array*)malloc(sizeof(struct element_in_array)*size);
	convert_bst_to_array(root, arr, ptr_to_aray_index);
	for (loop_i = 1; loop_i < size; loop_i++)
	{
		if (arr[loop_i - 1].content>arr[loop_i].content)
		{
			position1 = arr[loop_i - 1].ptr;
			break;
		}
	}
	loop_i = size - 1;
	for (; loop_i >= 0; loop_i--)
	{
		if (arr[loop_i - 1].content>arr[loop_i].content)
		{
			position2 = arr[loop_i].ptr;
			break;
		}
	}
	if (position1!=NULL && position2!=NULL)
	swap(position1, position2);
	return;
}

int size_of_tree(struct node* root)
{
	int size = 0;
	if (root == NULL)
		return 0;
	else
	{
		size = size_of_tree(root->left) + size_of_tree(root->right) + 1;
		return size;
	}
}

void convert_bst_to_array(struct node* root, struct element_in_array* arr, int* ptr_to_array_index)
{
	if (root == NULL)
		return;
	else
	{
		convert_bst_to_array(root->left, arr, ptr_to_array_index);
		arr[*ptr_to_array_index].content = root->data;
		arr[*ptr_to_array_index].ptr = &(root->data);
		(*ptr_to_array_index)++;
		convert_bst_to_array(root->right, arr, ptr_to_array_index);
	}
}

void swap(int* number1, int* number2)
{
	int temporary_variable = 0;
	temporary_variable = *number1;
	*number1 = *number2;
	*number2 = temporary_variable;
}