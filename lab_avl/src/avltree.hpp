/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    Node *newRoot = t->right;
    Node *subtree = newRoot->left;
    newRoot->left = t;
    t->right = subtree;
    t->height = std::max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;
    newRoot->height = std::max(heightOrNeg1(newRoot->left), heightOrNeg1(newRoot->right)) + 1;
    t = newRoot;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
    Node * left = t->left;
    Node * temp = left->right;
    t->left = temp;
    left ->right = t;
    t->height=std::max(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;
    t =left;
    t->height=std::max(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    if (!subtree) {
        return;
    }

    int balanceFactor = heightOrNeg1(subtree->left) - heightOrNeg1(subtree->right);

    if (balanceFactor > 1) { 
        if (heightOrNeg1(subtree->left->left) >= heightOrNeg1(subtree->left->right)) {
            rotateRight(subtree);
        } else {
            rotateLeftRight(subtree);
        }
    } else if (balanceFactor < -1) { 
        if (heightOrNeg1(subtree->right->left) <= heightOrNeg1(subtree->right->right)) {
            rotateLeft(subtree);
        } else {
            rotateRightLeft(subtree);
        }
    }
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if (subtree == nullptr) {
        subtree = new Node(key, value);
    }
    else if (subtree->key < key) {
        insert(subtree->right, key, value);
        rebalance(subtree);
    }
    else if (subtree->key > key) {
        insert(subtree->left, key, value);
        rebalance(subtree);
    }
    else if (subtree->key == key) {
        return;
    }
    subtree->height = std::max(heightOrNeg1(subtree->right), heightOrNeg1(subtree->left)) + 1;
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        remove(subtree->left,key);
        rebalance(subtree);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right,key);
        rebalance(subtree);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            delete subtree; 
            subtree = nullptr;
            return;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node *prede = subtree->left;
            while (prede->right != nullptr) {
                prede = prede->right;
            }
            subtree->key = prede->key;
            subtree->value = prede->value;
            remove (subtree->left, prede->key);
        } else {
            /* one-child remove */
            // your code here
            Node *temp = (subtree->right == nullptr) ? subtree->left : subtree->right;
            *subtree = *temp;
            delete temp;    temp = nullptr;
        }
        // your code here
    }
    subtree->height = std::max(heightOrNeg1(subtree->right), heightOrNeg1(subtree->left)) + 1;
    rebalance(subtree);
}
