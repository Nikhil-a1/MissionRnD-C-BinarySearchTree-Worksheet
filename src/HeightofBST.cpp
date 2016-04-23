/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int get_sum(struct node*);

int BSTheight(struct node*);

int get_height(struct node *root)
{
	if (root == NULL)
		return -1;
	else
	{
		int height;
		height =BSTheight(root);
		return height;
	}
}
int BSTheight(struct node* root)
{
		int left_sub_tree_height=0 , right_sub_tree_height=0;
		if (root == NULL)
			return 0;
		else
		{
			left_sub_tree_height = BSTheight(root->left);
			right_sub_tree_height = BSTheight(root->right);
			if (left_sub_tree_height > right_sub_tree_height)
				return left_sub_tree_height + 1;
			else
				return right_sub_tree_height + 1;
		}
	
}

int get_left_subtree_sum(struct node *root)
{
	if (root==NULL)
	return -1;
	else
	{
		int sum = 0;
		struct node* temp = root;
		temp = temp->left;
		sum = get_sum(temp);
		return sum;
	}
}

int get_right_subtree_sum(struct node *root)
{
	if (root==NULL)
	return -1;
	else
	{
		int sum = 0;
		struct node* temp = root;
		temp = root->right;
		sum = get_sum(temp);
		return sum;
	}
}
int get_sum(struct node* root)
{
	if (root == NULL)
		return 0;
	else
	{
		int sum=0, left_tree , right_tree;
		left_tree= get_sum(root->left);
		right_tree = get_sum(root->right);
		return sum = left_tree+right_tree+root->data;
	}
}

