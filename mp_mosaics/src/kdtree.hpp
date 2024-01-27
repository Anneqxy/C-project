/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;

template <int Dim>
bool smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim)
{
    /**
     * @todo Implement this function!
     */
    if (first[curDim] < second[curDim]) {
      return true;
    } else if (first[curDim] > second[curDim]) {
      return false;
    } else {
      return first<second;
    }
}

template <int Dim>
bool shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential)
{
    /**
     * @todo Implement this function!
     */
    double cur_dis = 0.0;
    double pos_dis = 0.0;
    for (int i = 0; i < Dim; i++) {
      cur_dis = cur_dis + (target[i] - currentBest[i])*(target[i] - currentBest[i]);
      pos_dis = pos_dis + (target[i] - potential[i])*(target[i] - potential[i]);
    } 
    if (pos_dis < cur_dis) {
      return true;
    } else if (cur_dis < pos_dis) {
      return false;
    } else {
      return potential < currentBest;
    }
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */

  if(newPoints.empty()){
		root=NULL;
	} 
	vector<Point<Dim>> copy;
	for(unsigned int i=0;i<newPoints.size();i++){
		copy.push_back(newPoints[i]);
	}
  root=KDTree_helper(copy,0,newPoints.size()-1,0);
  // constructKDTree(copy,0, root);
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::KDTree_helper(vector<Point<Dim>>& input, int left, int right, int dim) {
  if (left > right) {
    return nullptr;
  } else if (left ==right) {
    return new KDTreeNode(input[left]);
  } else {
    int med = (left+right)/2;
    auto cmp = [dim](const Point<Dim>& p1, const Point<Dim>& p2){return smallerDimVal(p1, p2, dim);};
    select(input.begin() + left, input.begin() + right + 1, input.begin() + med, cmp);
    KDTreeNode* newnode = new KDTreeNode(input[med]);
    dim = (dim + 1) % Dim;
    newnode->left = KDTree_helper(input, left, med - 1, dim);
    newnode->right = KDTree_helper(input, med + 1, right, dim);
    return newnode;
  }
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
  root = nullptr;
  root = copyTree(other.root);
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::copyTree(KDTreeNode* otherNode) {
  if(otherNode==NULL){
		return NULL;
	}
	KDTreeNode* new_root= new KDTreeNode(otherNode->point);
	new_root->left=copyTree(otherNode->left);
	new_root->right=copyTree(otherNode->right);
	return new_root;
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
  if (this == &rhs) {
    return *this;
  }
  destroy(root);
  root = copyTree(rhs.root);
  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
   destroy(root);
}

template <int Dim>
void KDTree<Dim>::destroy(KDTreeNode* currentNode) {
  if (currentNode == nullptr) {
    return;
  }
  destroy(currentNode->left);
  destroy(currentNode->right);
  delete currentNode;
}


template<int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim> &query) const {
  return findNearestNeighborHelper(query,root, 0);
}


template<int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighborHelper(const Point<Dim> &query, KDTreeNode *current, int currentDimension) const {
    if (current->left == nullptr && current->right == nullptr) {
        return current->point;
    }

    Point<Dim> currentBest = current->point;
    Point<Dim> temporaryBest = findNearestNeighborRecursive(query, current, currentDimension);

    if (shouldReplace(query, currentBest, temporaryBest)) {
        currentBest = temporaryBest;
    }

    return currentBest;
}

template<int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighborRecursive(const Point<Dim> &query, KDTreeNode *current, int currentDimension) const {
    if (current == nullptr) {
        return Point<Dim>();
    }

    int nextDimension = (currentDimension + 1) % Dim;
    Point<Dim> recursiveBest = current->point;
    Point<Dim> temporaryBest = recursiveBest;
    bool isLeftDirection = smallerDimVal(query, recursiveBest, currentDimension);

    if ((isLeftDirection && current->left != nullptr)) {
        temporaryBest = findNearestNeighborRecursive(query, current->left, nextDimension);
    } else if ((!isLeftDirection && current->right != nullptr)) {
        temporaryBest = findNearestNeighborRecursive(query, current->right, nextDimension);
    }

    if (shouldReplace(query, recursiveBest, temporaryBest)) {
        recursiveBest = temporaryBest;
    }

    int euclideanDistance = 0;
    for (int i = 0; i < Dim; i++) {
        euclideanDistance += pow(query[i] - recursiveBest[i], 2);
    }

    int dimensionDistance = pow(current->point[currentDimension] - query[currentDimension], 2);

    if (dimensionDistance <= euclideanDistance) {
        if (isLeftDirection && current->right != nullptr) {
            temporaryBest = findNearestNeighborRecursive(query, current->right, nextDimension);
            if (shouldReplace(query, recursiveBest, temporaryBest)) {
                recursiveBest = temporaryBest;
            }
        } else if (!isLeftDirection && current->left != nullptr) {
            temporaryBest = findNearestNeighborRecursive(query, current->left, nextDimension);
            if (shouldReplace(query, recursiveBest, temporaryBest)) {
                recursiveBest = temporaryBest;
            }
        }
    }

    return recursiveBest;
}


template<typename RandIter, typename Comparator>
void select(RandIter start, RandIter end, RandIter k, Comparator cmp) {
    if (start == end) {
      return;
    }
    RandIter pivot = start;
    RandIter i = start + 1;
    RandIter j = end - 1;
    while (i <= j) {
        while (i <= j && cmp(*i, *pivot)) ++i;
        while (i <= j && !cmp(*j, *pivot)) --j;
        if (i < j) {
            std::swap(*i, *j);
        }
    }
    std::swap(*pivot, *(i-1));
    pivot = i - 1;
    if (k == pivot) {
      return;
    }
    else if (k < pivot) select(start, pivot, k, cmp);
    else select(pivot+1, end, k, cmp);
}

