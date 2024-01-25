/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List() { 
  // @TODO: graded in mp_lists part 1
    head_ = NULL;
    tail_ = NULL;
    length_=0;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in mp_lists part 1
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in mp_lists part 1
  return List<T>::ListIterator(NULL);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in mp_lists part 1
  ListNode * temp = head_;
  if(temp == NULL){
    return;
  }
  ListNode * temp2;
  while(temp!=NULL) {
    temp2=temp->next;
    delete temp;
    temp = temp2;
  }
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in mp_lists part 1
  ListNode * newNode = new ListNode(ndata);
  newNode -> next = head_;
  newNode -> prev = NULL;
  
  if (head_ != NULL) {
    head_ -> prev = newNode;
  } else {
    tail_ = newNode;
  }
  
  head_=newNode;
  length_++;

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in mp_lists part 1
  ListNode * newNode = new ListNode(ndata);
  newNode -> next = NULL;
  newNode -> prev = tail_;
  if (head_ == NULL) {
    head_ = newNode;
  }
  if (tail_ != NULL) {
    tail_ -> next = newNode;
  }

  tail_=newNode;
  length_++;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in mp_lists part 1
  if(start==NULL) {
    return NULL;
  }
  if(splitPoint<1) {
    return start;
  }
  if(length_<splitPoint) {
    return NULL;
  }
  ListNode * curr = start;
  for (int i = 0; i < splitPoint && curr != NULL; i++) {
    curr = curr->next;
  }
  if (curr != NULL) {
    ListNode* temp = curr->prev;
    curr->prev = NULL;
    temp->next = NULL;
    tail_ = temp;
  }
  return curr;
}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <typename T>
void List<T>::waterfall() {
  /// @todo Graded in part 1
  // if(head_==NULL || head_->next==NULL) {
  //   return;
  // }
  // ListNode * temp1 = head_;
  // ListNode * temp2 = temp1->next;
  // int a = 0;
  // while(temp1->next->next!=NULL && temp1->next!=NULL) {
  //   temp1=temp1->next;
  //   temp1->prev->next=temp1->next;
  //   temp1->next->prev =temp1->prev;
	// 	temp2 = temp1->next;
	// 	tail_->next = temp1;
	// 	temp1->prev = tail_;
	// 	temp1->next = NULL;
	// 	tail_ = temp1;
	// 	temp1 = temp2;
  // }

  if (head_ == NULL || head_->next == NULL) {
        return;
    }

    ListNode* current = head_;
    
    while (current->next != NULL && current->next->next != NULL) {
        ListNode* nodeToMove = current->next;      
        ListNode* nextNode = nodeToMove->next; 
        current->next = nextNode;
        nextNode->prev = current;
        tail_->next = nodeToMove;
        nodeToMove->prev = tail_;
        nodeToMove->next = NULL;
        tail_ = nodeToMove;
        current = nextNode;
    }
}


/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in mp_lists part 2
  if(startPoint == endPoint){
    return;
  }
  ListNode* curr;
  ListNode* temp;
  ListNode* left;
  ListNode* right;
  ListNode* start;
  ListNode* end;
  left = startPoint->prev;
  right = endPoint->next;
  start = startPoint;
  end = endPoint;

  curr = startPoint;
  temp = NULL;

  while(curr != endPoint){
    temp = curr->prev;
    curr->prev = curr->next;
    curr->next = temp;
    curr = curr->prev;
  }
  curr->next = curr->prev;
  curr->prev = left;
  startPoint->next = right;
  if(left != NULL){
    left->next = endPoint;
  }
  else{
    head_ = endPoint;
  }

  if(right != NULL){
    right->prev = startPoint;
  }
  else{
    tail_ = startPoint;
  }
  startPoint = end;
  endPoint = start;

  return;

  // if (startPoint == endPoint) {
  //       return; 
  //   }

  //   ListNode* left = startPoint->prev;
  //   ListNode* right = endPoint->next;
  //   ListNode* curr = startPoint;
  //   ListNode* prev = NULL;
  //   ListNode* temp;
  //   while (curr != right) {
  //       temp = curr->next;
  //       curr->next = prev;
  //       curr->prev = temp;
  //       prev = curr;
  //       curr = temp;
  //   }

  //   if (left) {
  //       left->next = endPoint;
  //   } else {
  //       head_ = endPoint;
  //   }

  //   if (right) {
  //       right->prev = startPoint;
  //   } else {
  //       tail_ = startPoint;
  //   }
  //   std::swap(startPoint, endPoint);

}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in mp_lists part 2
  ListNode *start;
  ListNode *blockend;
  start = head_;
  blockend = head_;

  if(n <= 1 || head_ == NULL) {
    return;
  }
  while(start != NULL){
    blockend = start;
    for(int i = 0; i < n - 1; i++){
      if(blockend->next != NULL){
        blockend = blockend->next;
      }
    }
    reverse(start, blockend);
    start = blockend->next;
  }
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in mp_lists part 2
  ListNode * temp_node = NULL;

  ListNode * result = first;

  ListNode * tempf = first;
  ListNode * temps = second;
  if(first->data < second->data) {
    result = tempf;
    tempf = tempf->next;
  } else {
    result = temps;
    temps = temps->next;
  }
  temp_node = result;

  while(temps != NULL && tempf != NULL){
    if(tempf == NULL && temps== NULL) {
      break;
    } else if (tempf == NULL || (temps->data < tempf->data && temps != NULL)) {
      temp_node->next = temps;
      temp_node->next->prev = temp_node;
      temps = temps->next;
      temp_node = temp_node->next;
    } else {
      temp_node->next = tempf;
      temp_node->next->prev = temp_node;
      tempf = tempf->next;
      temp_node = temp_node->next;
    }
  }
  if(temps == NULL) {
    temp_node->next = tempf;
    tempf->prev = temp_node;
  }
  if(tempf == NULL) {
    temp_node->next = temps;
    temps->prev = temp_node;
  }
  return result;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in mp_lists part 2
  if(chainLength == 1){
    start->prev = NULL;
    start->next = NULL;
    return start;
  } else {
    int curLength = chainLength/2;
	  ListNode * temp;
	  temp = split(start, curLength);
	  ListNode * begin = mergesort(start, curLength);
	  ListNode * end = mergesort(temp, chainLength - curLength);
	  return merge(begin, end);
  }

}
