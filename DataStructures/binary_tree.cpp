#include <stdio.h>
#include <stdlib.h>

#define BT binary_tree

#define elif else if
#define out(value) printf("%f\n", value)

typedef struct tree2
{
	double self;
	bool isset;
	tree2* left_tree;
	tree2* right_tree;
} binary_tree;

void init_tree(BT *tree, double initial)
{
	tree->self = initial;
	tree->left_tree = NULL;
	tree->right_tree = NULL;
	return;
}

void print_sorted(BT tree)
{
	if(tree.isset == false)
		return;
	else
	{
		if(tree.left_tree != NULL)
			print_sorted(*tree.left_tree);
		printf("%f ", tree.self);
		if(tree.right_tree != NULL)
			print_sorted(*tree.right_tree);
		return;
	}
}

void insert_into_tree(BT *tree, double value)
{
	if(tree->isset == false) // Если текущий элемент неопределён
	{
		init_tree(tree, value);
		tree->isset = true;
		return;
	}
	else if(tree->self == value) // Если определён, но уже есть в дереве
		return;
	else if(value < tree->self) // Если определён и меньше вставляемого
	{
		if(tree->left_tree == NULL)
			tree->left_tree = (BT*)malloc(sizeof(BT));
		insert_into_tree(tree->left_tree, value);
	}
	else // Если определён и больше вставляемого
	{
		if(tree->right_tree == NULL)
			tree->right_tree = (BT*)malloc(sizeof(BT));
		insert_into_tree(tree->right_tree, value);
	}
	return;
}

int main(void)
{
	double A[] = {13,12,15,16,17,51,24,39,48,24};
	int N = 10;
	BT my = {0, false, NULL, NULL};
	for(int i = 0; i < 10; i++)
	{
		insert_into_tree(&my, A[i]);
	}
	print_sorted(my);
	printf("\n");
	return 0;
}
