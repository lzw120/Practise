//
//  main.cpp
//  2.3RemoveNodeinLinkedList
//
//  Created by Zewen Li on 8/16/12.
//  Copyright (c) 2012 Zewen Li. All rights reserved.
//Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.
/*
EXAMPLE
Input: the node ‘c’ from the linked list a->b->c->d->e
Result: nothing is returned, but the new linked list looks like a->b->d->e
*/
 
// My question is : what kind of this linkedlist could be?
// and integer?

// If it is bidirectional linkedlist, then its very easy.
//      Node it;
//      it->pre->next = it->next;
//      it->next->pre = it->pre;
//      delete it; it = NULL;

// However, when it's not, original idea could be:
// from head to it:
//     if next is it:
//          then we redirect next to it->next;
//          delete it
//          break;
//      else continue
// No interest
// The solution to this is to simply copy the data from the next node into this node and then delete the next node.


#include <iostream>
using namespace std;


struct linkedlistNode {
    int value;
    linkedlistNode *next;
};

int main(int argc, const char * argv[])
{
    // first let's create a linked list
    cout<<"input a linked list"<<endl;
    linkedlistNode *head = NULL;
    int length = 0;
    int n;
    while (cin>>n) {
        
        linkedlistNode *former, *latter;
        
        if (!head) {
            head = new linkedlistNode;
            head->value = n;
            former = head;
            latter = former;
            length = 1;
        }
        
        else {
            
            former = new linkedlistNode;
            former->value = n;
            latter->next = former;
            latter = former;
            length++;
        }
        
    }

    int k = rand()%length;
    linkedlistNode *p = head;
    // set p
    for (int i = 0; i < k; i++) {
        p = p->next;
    }
 
    cout<<"delete the "<<k<<"th node"<<endl;
    
    //if p is the tail then we have no choice
    if (!p->next) {
        cout<<"no tricky way"<<endl;
        exit(0);
    }
    
    //start from p copy p->next to p
    linkedlistNode *temp = NULL;
    while (p->next != NULL) {
        p->value = p->next->value;
        temp = p;
        p = p->next;
    }
    // when p reach the end, delete it
    temp->next = NULL;
    delete p;
    p = NULL;
    
    // verify result
    temp = head;
    cout<<"result is: "<<endl;
    while (temp) {
        cout<<temp->value<<" "<<endl;
        temp = temp->next;
    }
    
    
    
    return 0;
}

