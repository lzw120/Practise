//
//  main.cpp
//  2.5FindCircularinLinkedList
//
//  Created by Zewen Li on 8/21/12.
//  Copyright (c) 2012 Zewen Li. All rights reserved.
//
//Given a circular linked list, implement an algorithm which returns node at the begin- ning of the loop.
//DEFINITION
//Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node, so as to make a loop in the linked list.
// EXAMPLE
// Input: A -> B -> C -> D -> E -> C [the same C as earlier] Output: C


// Method: Use hash table. Scan every node, we could derive a hash table like
//      key('A')  value(pointer)
// for every node T:
//      if hashtable[T->value] not exist
//         hashtable[T->value] = &T
//      else
//         return hashtable[T->value]

// Method: Floyd's cycle-finding algorithm
// Proof: let's say a linked list has a total length of L
// e.g.  1, 2, 3, 4, 5, 3 (L = 6)
// and suppose the entry node of circle(in our example it is 3) is at position a;
// and there are two poiners: slow and fast, slow walks by one step while fast by two.
// both start from head, sooner or later they will meet, otherwise there is no circle.
// The so called meeting node must be somewhere in the circle, say T.
// let x: distance from entry node to node T
//     r: length of circle
//   &we know that
//     a: distance from head to circle entry node
//     L: total length of linkedlist

// When the first time slow and fast meet:
// a + x = n * r (n times of circling, no need to care)
// a + r = L
// so we can know that
// a = n * r - x = (n-1) * r +r - x
//   = (n-1) * r + (L-a) - x
// which means
// a = (n-1) * r + (L-a-x)
// See this equation:
// it means if we had another pair of pointer: p1, p2 both walk by one step.
// and p1 starts from head, p2 starts from the meeting node T.
// when p1 reaches entry node(after a steps), at the same time, p2 walks by
// (n - 1)*r + (L-a-x) steps, this means, besides the n-1 times circulation, actually, p2 just walks forward by L-a-x steps, and thus it reaching entry node.
// and we found it !
// Code :
// slow = fast = head;
// while loop:
// if fast == null
//      then no circle
// else
//      if slow == fast
//          pointer T = fast
//          pointer p1 = head
//          pointer p2 = T
//          while (p1 != p2)
//              {p1++
//               p2++   }
///         return p1 or p2
//      else
//          slow + 1
//          fast + 2

#include <iostream>
#include <sstream>
#include <hash_map.h>
using namespace std;

struct linkedlistNode {
    char value;
    linkedlistNode *next;
};




__gnu_cxx::hash_map<char, linkedlistNode*> Table;




linkedlistNode *findCircular(linkedlistNode *head) {
    linkedlistNode *T = head;
    while (T) {
        if (Table.find(T->value) == Table.end()) {
            Table[T->value] = T;
        }
        else {
            return Table[T->value];
        }
        T = T->next;
    }
    cout<<"Circular does not exist"<<endl;
    return 0;
}


linkedlistNode *findCircular2( linkedlistNode *head) {
    linkedlistNode *slow = NULL, *fast = NULL;
    slow = fast = head;
    // while fast and slow both not null
    while ((fast != NULL) & (slow != NULL)) {
        if ((slow == fast) & (slow != head)) {
            linkedlistNode *p1 = NULL, *p2 = NULL;
            p1 = head;
            p2 = fast;
            while (p1 != p2) {
                p1 = p1->next;
                p2 = p2->next;
            }
            return p1;
        }
        else {
            slow = slow->next;
            fast = fast->next;
            //if (fast != NULL)
            fast = fast->next;
        }
    }
    // if fast == null, no circle
    if (!fast) {
        cout<<"no circle"<<endl;
        return NULL;
    }
    
}


int main(int argc, const char * argv[])
{
    string str, n;
    cout<<"Input samles:"<<endl;
    getline(cin, str);
    stringstream buffer(str);
    linkedlistNode *head = NULL;
    linkedlistNode *former = NULL, *latter = NULL;
    //Input 
    while (buffer>>n) {
     
                
        if (!head) {
            head = new linkedlistNode;
            head->value = n[0];
            former = head;
            latter = former;
        }
        
        else {
            
            former = new linkedlistNode;
            former->value = n[0];
            former->next = NULL;
            latter->next = former;
            latter = former;
            former->next = head->next->next;
        }
        
    }
    
    
    //linkedlistNode *result = findCircular(head);
    linkedlistNode *result = findCircular2(head);
    cout<<"circular head is: "<<result->value<<endl;
    
    return 0;
}

