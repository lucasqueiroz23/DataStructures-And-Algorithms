#include <stdlib.h>
#include <stdio.h>

// This implementation of a BST is for storage of integer types. But since the DS can be used to store any kind of data type,
// I used typedef to illustrate that it can be adapted to any other kind of data type.
typedef int DATA_TYPE;

typedef struct node
{
	DATA_TYPE data;
	struct node *left;
	struct node *right;

}node;

typedef struct binarySearchTree
{
	node *headerNode;

}binarySearchTree;

node *createNode(DATA_TYPE data)
{
	node *newNode = malloc(sizeof(node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

binarySearchTree *createBST(DATA_TYPE headerNodeData)
{
	binarySearchTree *BST = malloc(sizeof(binarySearchTree));
	BST->headerNode = createNode(headerNodeData);

	return BST;
}

void insertNode(node *thisNode,DATA_TYPE dataOfNewNode) ///header node should be parameter
{
	if(dataOfNewNode < thisNode->data)
	{
		if(thisNode->left == NULL)
		{
			thisNode->left = createNode(dataOfNewNode);
			return;
		}
		insertNode(thisNode->left,dataOfNewNode);
		return;
	}

	if(dataOfNewNode > thisNode->data)
	{
		if(thisNode->right == NULL)
		{
			thisNode->right = createNode(dataOfNewNode);
			return;
		}
		insertNode(thisNode->right,dataOfNewNode);
		return;
	}

}

void preOrderTraversal(node *tr)
{
	if(tr !=NULL)
	{
		printf("%d ",tr->data);
		preOrderTraversal(tr->left);
		preOrderTraversal(tr->right);
	}
}

void inOrderTraversal(node *tr)
{
	if(tr !=NULL)
	{
		inOrderTraversal(tr->left);
		printf("%d ",tr->data);
		inOrderTraversal(tr->right);
	}
}

void postOrderTraversal(node *tr)
{
	if(tr !=NULL)
	{
		postOrderTraversal(tr->left);
		postOrderTraversal(tr->right);
		printf("%d ",tr->data);
	}
}
