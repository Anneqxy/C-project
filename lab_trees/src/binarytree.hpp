/**
 * @file binarytree.hpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "InorderTraversal.h"
#include <iostream>

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + std::max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    std::cout << std::endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    std::cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
    template <typename T>
void BinaryTree<T>::mirror()
{
    //your code here
    mirror(root);
}

template <typename T>
void BinaryTree<T>::mirror(Node* subRoot) {
	if (subRoot == NULL) {
		return;
	}
	Node * middle = subRoot->left;
	subRoot->left = subRoot->right;
	subRoot->right = middle;
	mirror(subRoot->left);
	mirror(subRoot->right);
}


/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedIterative() const
{
    // your code here
    if(root == NULL) {
        return true;
    }
    std::stack<T> soutput;
	int larger_value = 0;
	InorderTraversal<int> iot(this->getRoot());
	for (TreeTraversal<int>::Iterator it = iot.begin(); it != iot.end(); ++it) {
		soutput.push((*it)->elem);
	}
	if (!soutput.empty()){ 
		larger_value = soutput.top();
		soutput.pop();
	}
	while (!soutput.empty()) {
		if (larger_value < soutput.top()) {
			return false;
		}
		larger_value = soutput.top();
		soutput.pop();
	}
    return true;
}

/**
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{
    Node * Root = root;
    T * temp = NULL;
    bool judge = true;
	helper(Root, temp, judge);
	return judge;
}

template <typename T>
void BinaryTree<T>::helper(Node *& Root, T * &temp, bool & judge) const {
    if(Root == NULL){
        return;
    }
    helper(Root -> left, temp, judge);
    if(temp == NULL){
    	temp = new T(Root -> elem);
    }else{
    	if(* temp > Root -> elem){
    		judge = false;
    	}
    	*temp = Root -> elem;
    }
    helper(Root -> right, temp, judge);
}
