/**
 * @file bst.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V BST<K, V>::find(const K& key)
{
    // your code here

    Node* resultNode = find(root, key);

    // if (resultNode != nullptr) {
    //     return resultNode->value;
    // }
    return resultNode->value;

}

template <class K, class V>
struct BST<K, V>::Node* & BST<K, V>::find(Node* & subtree, const K& key)
{
    // Your code here
    if (subtree == nullptr || key == subtree->key) {
        return subtree;
    }

    if (key < subtree->key) {
        return find(subtree->left, key);
    } else {
        return find(subtree->right, key);
    }
}

template <class K, class V>
void BST<K, V>::insert(const K & key, const V & value)
{
    // your code here
    insert(root, key, value);
}

template <class K, class V>
void BST<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if (subtree == nullptr) {
        subtree = new Node(key, value);
    } else if (key < subtree->key) {
        insert(subtree->left, key, value);
    } else if (key > subtree->key) {
        insert(subtree->right, key, value);
    }
}

template <class K, class V>
void BST<K, V>::swap(Node*& first, Node*& second)
{
    // your code here
    std::swap(first->key, second->key);
    std::swap(first->value, second->value);
}

template <class K, class V>
void BST<K, V>::remove(const K& key)
{
    // your code here
    remove(root, key);
}

template <class K, class V>
void BST<K, V>::remove(Node*& subtree, const K& key)
{
    // your code here
    if (subtree == nullptr) {
        return;
    }
    if (subtree->key == key) {
        if (subtree->left == nullptr && subtree->right == nullptr) {
            delete subtree;
            subtree = nullptr;
        } else if(subtree->left == nullptr) {
            // swap(subtree->right, subtree);
            // delete subtree;
            Node* temp = subtree;
            subtree = subtree->right;
            delete temp;
        } else if (subtree->right == nullptr) {
            // swap(subtree->left, subtree);
            // delete subtree;
            Node* temp = subtree;
            subtree = subtree->left;
            delete temp;
        } else {
            Node* iop = subtree->left;
            while (iop->right != nullptr) {
                iop = iop->right;
            }
            swap(subtree, iop);
            // delete subtree;
            remove(subtree->left, key);
        }
    } else if (key < subtree->key) {
        remove(subtree->left, key);
    } else if (key > subtree->key) {
        remove(subtree->right, key);
    } 
}

template <class K, class V>
BST<K, V> listBuild(std::vector<std::pair<K, V>> inList){
    // your code here
    BST<K, V> bst;
    for (const auto& pair : inList) {
        bst.insert(pair.first, pair.second);
    }
    return bst;
}

template <class K, class V>
std::vector<int> allBuild(std::vector<std::pair<K, V>> inList){
    // your code here
    // std::vector<int> histogram = {};

    // // Sort the input list to start with the smallest possible configuration
    // std::sort(inList.begin(), inList.end());

    // do {
    //     BST<K, V> bst; 
    //     for (const auto& pair : inList) {
    //         bst.insert(pair.first, pair.second);
    //     }

    //     int height = bst.height();
    //     int y = histogram.size();
    //     if (height >= y) histogram.resize(height + 1);
    //     histogram.at(height)++;
    //     ++histogram[height];
    // } while (std::next_permutation(inList.begin(), inList.end()));

    // return histogram;

    std::vector<int> output = {};
    std::sort(inList.begin(), inList.end());
    do {
        BST<K, V> check;
        for (std::pair<K, V> it : inList) {
            check.insert(it.first, it.second);
        }
        int h = check.height();
        int y = output.size();
        if (h >= y) output.resize(h + 1);
        output.at(h)++;
    } while (std::next_permutation(inList.begin(),inList.end()));
    return output;

}