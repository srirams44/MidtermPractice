#include "clist.h"
#include <iostream>


int main()
{
    clist object;
    object.build();		//builds a circular LL
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    object.evenSum();
    
    object.display(); //resulting list after your function call!
    
    return 0;
}



void clist::evenSum() {
  if (!rear) { //if no list, exit
    cout << "List does not exist. " << endl;
    return;
  }
  if (rear->next == rear) { //If the list has just one node
    if (rear->data % 2 == 0) {
      cout << "Sum: " << rear->data << endl;
    } else {
      cout << "No even nodes." << endl;
    }
  }
  cout << "Sum: " << evenCheck(rear->next) << endl;
}
    

int clist::evenCheck(node* current) {
  if (current == rear) { //base case, if you are back to rear, process it and quit
    if (current->data % 2 == 0) { //if rear is even, return the value
      return current->data;
    }
    else { //if its odd, quit
      return 0;
    }
  }
  if (current->data % 2 == 0) { //if the current node is even, return the value and add it to the next check
    return current->data + evenCheck(current->next);
  }
  else { //if its odd, just move onto the nect check
    return evenCheck(current->next);
  }
}
  
    

