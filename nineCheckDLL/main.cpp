#include "dlist.h"

int main()
{
    dlist object;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    //node* head = object.getHead();
    object.nineCheck();

    object.display();
    
    return 0;
}

void dlist::nineCheck() {
  if (head->data > 9) { //edge case, if head is greater than 9
    node* temp = head->next;
    temp->previous = nullptr;
    delete head;
    head = temp;
    nineCheck(); //incase after youve deleted head
  }
  if (tail->data > 9) { //edge case, if tail is greater than 9
    node* temp = tail->previous;
    temp->next = nullptr;
    delete tail;
    tail = temp;
    nineCheck();
  }
  //recursively process middle nodes
  checkHelper(head);
}

void dlist::checkHelper(node* current) {
  node* next = current->next;
  if (current == tail) { //base case, if the node you are looking at is tail
    return;
  }
  if (current->data > 9) {
    node* temp = current->previous;
    node* temp2 = current->next;
    temp->next = temp2;
    temp2->previous = temp;
    delete current;
  }
  checkHelper(next);
}


/*node* dlist::getHead() {
  return head;
  } */
