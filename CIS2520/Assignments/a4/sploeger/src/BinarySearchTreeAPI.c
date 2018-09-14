#include "BinarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef BST_GUARD
#define BST_GUARD

/**************************************
Interface for a Binary Tree ADT

Author:  Judi McCuaig
October, 2012
Modfied: James Fraser (Nov 2017)
Modified: Spencer Ploeger (Nov 2017)
**************************************/

/**
 * Creates a TreeNode. TreeNode children are set to NULL and data is set to the passed in data.
 * @param data - the data to be stored within the Node. 
 * @return Newly created TreeNode
 *
 */
 TreeNode* createTreeNode(TreeDataPtr data)
 {
 	TreeNode newNode = malloc(sizeof(TreeNode));
 	newNode->data = data;
 	newNode->left = NULL;
 	newNode->right = NULL;

 }

/**
 * createBinTree allocates memory for Tree and assigned function pointers
 * @param  compare [Function pointer to Compare data in tree nodes]
 * @param  del     [Function pointer to delete data from node]
 * @return Newly created Tree
 */
 Tree * createBinTree(CompareFunc compare, DeleteFunc del)
 {
 	Tree tempTree = malloc(sizeof(Tree));
 	tempTree->root = NULL;
 	tempTree->CompareFunc = compare;
 	tempTree->DeleteFunc = del;

 }

/**
 * destroyBinTree - remove all items and free memory
 * @param  toDestroy - the tree
 * @return
 */
 void  destroyBinTree(Tree * toDestroy)
 {
 	if(toDestroy == NULL)
 	{
 		return;
 	}
 	else{
 		destroyTheBinTree(toDestroy->root, toDestroy->DeleteFunc);
 	}
 	free(toDestroy);
 }
 void  destroyTheBinTree(TreeNode * theNode, DeleteFunc del)
 {
 	if(theNode == NULL)
 	{
 		return;
 	}
 	destroyTheBinTree(theNode->left);
 	destroyTheBinTree(theNode->right);
 	if(del != NULL)
 	{
 		del(theNode);
 	}
 	free(theNode)
 }

/**
 * Add data to a tree
 * @param theTree 
 * @param data    
 */
 void addToTree(Tree * theTree, TreeDataPtr data)
 {
 	if(theTree == NULL)
 	{
 		return;
 	}
 	addToTheTree(theTree->root, data, theTee->CompareFunc);
 }
void addToTheTree(TreeNode * theNode, TreeDataPtr data, CompareFunc comp)
{
	if(comp(theNode->data, data) > 0)
	{
		if(theNode->left == NULL)
		{
			theNode->left = createTreeNode(data);
			return;
		}
		addToTheTree(theNode->left, data, comp);
	}

	if(comp(theNode->data, data) < 0)
	{
		if(theNode->right == NULL)
		{
			theNode->right = createTreeNode(data);
			return;
		}
		addToTheTree(theNode->right, data, comp);
	}

	if(comp(theNode->data, data) == 0)
	{
		printf("this data already exists\n");
			return;
	}
}

/**
 * Remove data from the tree
 * @param theTree 
 * @param data    
 */
 void removeFromTree(Tree * theTree, TreeDataPtr data)
 {
 	if(theTree == NULL)
 	{
 		return;
 	}
 	int numChildren = numberOfChildren(findInTree(theTree, data)); /*find the node that is has the data to be deleted, and see how many children it has*/
 	
 	if (numChildren == 0)
 	{
 		removeWithOneChild();
 	}
 	if (numChildren == 1)
 	{
 		removeWithTwoChildren();
 	}
 	if (numChildren == 2)
 	{
 		removeWithNoChildren(findInTree(theTree, data), theTree->DeleteFunc);
 	}
 }

/*add function to .h, update parameters when called in remove*/
void removeWithOneChild()
{

}
/*add function to .h, update parameters when called in remove*/
void removeWithTwoChildren()
{

}
/*add function to .h, update parameters when called in remove*/
void removeWithNoChildren(TreeNode * toDelelete, DeleteFunc del)
{
	del(TreeNode->data);
	TreeNode = NULL;
}

/**
* Returns the number of chilren of a node
* @param a node
* @return the number of children
*/
int numberOfChildren(TreeNode theNode)
 {
 	if(theNode->left == NULL && theNode->right == NULL) //if both left and right ar null, no children
 	{
 		return 0;
 	}
 	if((theNode->right == NULL && theNode->left != NULL) || (theNode->right != NULL && theNode->left == NULL))
 	{
 		return 1;
 	}
 	return 2;
 }



/**
 * This function searches the tree for the target data
 * @param  theTree 
 * @param  data    
 * @return         NULL if fail, otherwise return data
 */
 TreeDataPtr findInTree( Tree* theTree, TreeDataPtr data )
 {
 	if(theTree == NULL)
 	{
 		return NULL;
 	}
 	TreeNode * temp = findInTheTree(theTree->root, data, theTree->CompareFunc);
 	if(temp == NULL)
 	{
 		return NULL:
 	}
 	return temp->data;
 }
 TreeNode * findInTheTree(TreeNode * theNode, TreeDataPtr theData, CompareFunc comp)
{
	if(theNode == NULL)
	{
		return NULL;
	}
	if(comp(theNode->data, data) == 0)
	{
		return theNode->data;
	}
	else if(comp(theNode->data, data) > 0)
	{
		return findInTheTree(theNode->left, data, comp);
	}
	else
	{
		return findInTheTree(theNode->right, data, comp);	
	}
	return NULL;
}

/**
 * Get data from the root of the Tree if it exists.
 * @param  theTree 
 * @return NULL if tree is empty, otherwise return root
 */
 TreeDataPtr getRootData(Tree * theTree)
 {
 	return tree->root->data;
 }

 void printInOrder(Tree * theTree, PrintFunc printData)
 {
 	if(theTree == NULL)
 	{
 		return;
 	}
 	
 	printTheOrder(theTree->root, printData);
 }

 void printTheOrder(TreeNode * theNode, PrintFunc printData)
 {
 	if(theNode->left != NULL)
 	{
 		printTheOrder(theNode->left, printData);
 	}

 	PrintFunc(theNode->data);

 	if(theNode->right != NULL)
 	{
 		printTheOrder(theNode->right, printData);
 	}

 }

/**
 * [printPreOrder This function prints the tree using an preOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
 void printPreOrder(Tree * theTree, PrintFunc printData)
 {
 	if(theTree == NULL)
 	{
 		return;
 	}
 	printThePreOrder(theTree->root, printData);

 }

 void printThePreOrder(TreeNode * theNode, PrintFunc printData)
 {

 	PrintFunc(theNode->data);

 	if(theNode->left != NULL)
 	{
 		printThePreOrder(theNode->left, printData);
 	}

 	if(theNode->right != NULL)
 	{
 		printThePreOrder(theNode->right, printData);
 	}
 }

/**
 * [printPostOrder This function prints the tree using an postOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
 void printPostOrder(Tree * theTree, PrintFunc printData)
 {
 	if(theTree == NULL)
 	{
 		return;
 	}
 	printThePostOrder(theTree->root, printData);
 }

 void printThePostOrder(TreeNode * theNode, PrintFunc printData)
 {

 	if(theNode->left != NULL)
 	{
 		printThePostOrder(theNode->left, printData);
 	}

 	if(theNode->right != NULL)
 	{
 		printThePostOrder(theNode->right, printData);
 	}

 	PrintFunc(theNode->data);
 }

/**
 * Checks if a tree is empty
 * @param  theTee [description]
 * @return        0 if false, 1 otherwise
 */
 int isTreeEmpty(Tree* theTee)
 {
 	if(tree-> == NULL)
 	{
 		return 1;
 	}
 	else
 	{
 		return 0;
 	}
 }


/**
 * Helper function for checking if a single node is a leaf (no children)
 * @param  treeNode [description]
 * @return          0 if false, 1 otherwise
 */
 int isLeaf( TreeNode * treeNode)
 {

 }

/**
 * Helper funciton for checking if a single node has two children.
 * @param  treeNode [description]
 * @return         0 if false, 1 otherwise
 */
 int hasTwoChildren( TreeNode *treeNode)
 {

 }

/**
 * Helper funciton Get the height of a particulat Node in the tree. 
 * @param  treeNode [description]
 * @return    (1-Based) heigh for the tree. 
 */
 int getHeight( TreeNode* treeNode )
 {

 }


/**
 * You may add additional API functions below this comment if you want to extend the funcitonality.
 */


#endif
