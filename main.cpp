#include <iostream>
using namespace std;

// There are two problems

// 1. Given the head of a Singly LinkedList, write a function to determine if
// the LinkedList has a cycle in it or not.

class Linkedlist {
public:
  int value;
  Linkedlist *next;

  Linkedlist(int val) : value(val), next(nullptr) {}
};

// NOTE: pass pointer or reference
//       hasCycle(Linkedlist &list) w hasCycle(head) compilation error
//       hasCycle(Linkedlist *list) w hasCycle(head) compiled
//       head is pointer to Linkedlist,
//       passing reference an object is different than pointer to the obj.
//       &head  = *head

bool hasCycle(Linkedlist *head) {
  Linkedlist *slowptr = head;
  Linkedlist *fastptr = head;
  while (fastptr->next != nullptr && fastptr->next->next != nullptr) {
    fastptr = fastptr->next->next;
    slowptr = slowptr->next;
    // This test at the begining of the this block is always true
    // since both pointer start from same location.
    if (slowptr->value == fastptr->value)
      return true;
  }
  return false;
}

// 2. Find the length of cycle.


int calculateLength(Linkedlist *slow) {
  Linkedlist *current = slow;
  int cycleLength =0;
  int length = 0;
  // calculate the circle: starts from slow ptr walk through to get back to slow ptr.
  do {
    current = current->next;
    cycleLength++;
  } while(current != slow);
  return cycleLength;
}


int cycleLength3(Linkedlist *head) {
  Linkedlist *slowptr = head;
  Linkedlist *fastptr = head;
  while (fastptr->next != nullptr && fastptr->next->next != nullptr) {
    fastptr = fastptr->next->next;
    slowptr = slowptr->next;
  
    // This test at the begining of the this block is always true
    // since both pointer start from same location.
    if (slowptr->value == fastptr->value) {
      return calculateLength(slowptr);
    }
  }
  return -1;
}


// 3. Given the head of a Singly LinkedList that contains a cycle, write a function to find the starting node of the cycle.
/*
If we know the length of the LinkedList cycle, we can find the start of the cycle through the following steps:

Take two pointers. Let’s call them pointer1 and pointer2.
Initialize both pointers to point to the start of the LinkedList.
We can find the length of the LinkedList cycle using the approach discussed in LinkedList Cycle. Let’s assume that the length of the cycle is ‘K’ nodes.
Move pointer2 ahead by ‘K’ nodes.
Now, keep incrementing pointer1 and pointer2 until they both meet.
As pointer2 is ‘K’ nodes ahead of pointer1, which means, pointer2 must have completed one loop in the cycle when both pointers meet. Their meeting point will be the start of the cycle.
*/

Linkedlist* startCycle(Linkedlist *head){
  Linkedlist* ptr1 = head;
  Linkedlist* ptr2 = head;
  int cycleLen = cycleLength3(head);
  //cout<<"HHH "<<cycleLen<<endl;
  while(cycleLen > 0) {
    ptr2 = ptr2->next;
    cycleLen--;
    }
  while (ptr1 != ptr2){
    cout<<"kk "<<ptr1->value<<" "<<ptr2->value<<endl;
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  cout<<"uu "<<ptr1->value<<endl;
  return ptr1;
}

int main() {
  std::cout << "Hello World!\n";
  Linkedlist *head = new Linkedlist(1);
  head->next = new Linkedlist(2);
  head->next->next = new Linkedlist(3);
  head->next->next->next = new Linkedlist(4);
  head->next->next->next->next = new Linkedlist(5);
  head->next->next->next->next->next = new Linkedlist(6);

  cout << hasCycle(head) << endl;
  //cout<<cycleLength(head)<<endl;
  head->next->next->next->next->next = head->next->next;
  cout << hasCycle(head) << endl;
  //cout<<cycleLength(head)<<endl;
  cout<<cycleLength3(head)<<endl;
  // Note: Chaining
  cout<<startCycle(head)->value<<endl;
  

  }