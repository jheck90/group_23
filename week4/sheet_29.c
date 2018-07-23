
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#define TYPE int
struct Node {
	TYPE value;
	struct Node * left;
	struct Node * right;
};
struct BinarySearchTree {
	struct Node *root;
	int size;
};
void initBST(struct BinarySearchTree *tree) 
{ 
	tree->size = 0;
	tree->root = 0;
}

int sizeBST(struct BinarySearchTree *tree) 
{
	return tree->size; 
}
struct Node * _nodeAddBST(struct Node *current, TYPE newValue) {

	struct Node* tempPtr = NULL;
	if (current == NULL)
	{
		tempPtr = (struct Node *)malloc(sizeof(struct Node));
		tempPtr->left = NULL;
		tempPtr->right = NULL;
		tempPtr->value = newValue;
		return tempPtr;
	}
	if (newValue < current->value)
		current->left = _nodeAddBST(current->left, newValue);
	else
		current->right = _nodeAddBST(current->right, newValue);
	return current;
}
void addBST(struct BinarySearchTree *tree, TYPE newValue) {
	tree->root = _nodeAddBST(tree->root, newValue);
	tree->size++;
}
int containsBST(struct BinarySearchTree *tree, TYPE d) {
	
	struct Node *tempPtr = tree->root;

	while (tempPtr != NULL && tempPtr->value != d)
	{
		if (d < tempPtr->value)
			tempPtr = tempPtr->left;
		else
			tempPtr = tempPtr->right; 
	}

	if (tempPtr == NULL)
		return 0;

	return 1;
}

TYPE  _leftMostChild(struct Node * current) {
	TYPE smallest = current->value;
	while (current->left != NULL)
	{
		smallest = current->left->value;
		current = current->left;
	}
	return smallest;
}
struct Node * _removeLeftmostChild(struct Node *current) {

	//When found,return the right child(which could possibly be null)
	if (current->left == NULL)
		return current->right;
	else
	{
		//Otherwise make a recursive call and set the left child to the value returned by the recursive call, and return the current Node.
		current->left = _removeLeftmostChild(current);
		return current;
	}
}
struct Node * _nodeRemoveBST(struct Node * current, TYPE d) {
	
	if (d == current->value)//if start.value is the value we seek
	{	//decrease the value of dataSize
		if (current->right == NULL)//if right child is null
			return current->left;//return left child
		else //	otherwise
		{	//replace value of node with leftmost child of right child
			current->value = _leftMostChild(current->right);
			current->right = _removeLeftmostChild(current->right);//set right child to be removeLeftmost(right child)
		}
	}
	else if (d < current->value)
	{ //otherwise if testValue is smaller than start.value
		//set left child to remove(left child, testValue)
		current->left = _nodeRemoveBST(current->left, d);
	}
	else//otherwise
	{
		//set right child to remove(right child, testValue)
		current->right = _nodeRemoveBST(current->right, d);
	}		
	return current;
}
void removeBST(struct BinarySearchTree *tree, TYPE d) {
	if (containsBST(tree, d) )
	{
		tree->root = _nodeRemoveBST(tree->root, d);
		tree->size--;
	}
}
void print(struct Node * current)
{
	if (current != NULL)
	{
		print(current->left);
		printf("%d, ", current->value);
		print(current->right);
	}
}
void inOrder(struct BinarySearchTree *tree)
{
	if (tree != NULL)
	{
		print(tree->root);
	}
}

int main()
{
	struct BinarySearchTree *tree = (struct BinarySearchTree *)malloc(sizeof (struct BinarySearchTree));
	initBST(tree);
	addBST(tree, 1);
	addBST(tree, 2);
	addBST(tree, 3);
	addBST(tree, 4);
	addBST(tree, 5);
	addBST(tree, 6);
	inOrder(tree);
	printf("\n");
	removeBST(tree,4);
	inOrder(tree);
	printf("\n");
	return 0;
}

