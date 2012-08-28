//
//  main.cpp
//  2.4LinkedListCalculator
//
//  Created by Zewen Li on 8/20/12.
//  Copyright (c) 2012 Zewen Li. All rights reserved.
// You have two numbers represented by a linked list, where each node contains a sin- gle digit. The digits are stored in reverse order, such that the 1’s digit is at the list1 of the list. Write a function that adds the two numbers and returns the sum as a linked list.
// EXAMPLE
// Input: (3 -> 1 -> 5), (5 -> 9 -> 2) Output: 8 -> 0 -> 8

#include <iostream>
#include <sstream>
using namespace std;




struct linkedlistNode {
    int value;
    linkedlistNode *next;
};



// while loop l1 or l2 != null
// carry = 0
// if l1 and l2 not null
//      result = l1 + l2 + carry
//      if result >= 10   carry = 1  result = result%10
//      else    carry = 0
// else if l1 == null  result = carry + l2  if result >= 10   carry = 1  result = result%10
//                                          else    carry = 0
//      if l2 == null  result = carry + l1  if result >= 10   carry = 1  result = result%10
//                                          else    carry = 0



linkedlistNode *addList(linkedlistNode *list1, linkedlistNode *list2) {
    linkedlistNode *l1, *l2;
    linkedlistNode *head = NULL, *former = NULL, *latter = NULL, *result = NULL;
    l1 = list1;
    l2 = list2;
    int carry = 0;
    while ((l1 != NULL) || (l2 != NULL)) {
        
        // result linkedlist's head
        if (!head) {
            head = new linkedlistNode;
            former = latter = head;
            result = head;
        }
        
        else {
            former = latter;
            latter = new linkedlistNode;
            former->next = latter;
            result = latter;
        }
        
        if ((l1 != NULL) && (l2 != NULL)) {
            result->value = l1->value + l2->value + carry;
            if (result->value >= 10) {
                carry = 1;
                result->value = result->value % 10;
            }
            else
                carry = 0;
        
            l1 = l1->next;
            l2 = l2->next;
        }
        else {
            if (l1 == NULL) {
                result->value = carry + l2->value;
                if (result->value >= 10) {
                    result->value = result->value % 10;
                    carry = 1;
                }
                else
                    carry = 0;
                    l2 = l2->next;
            }
            if (l2 == NULL) {
                result->value = carry + l1->value;
                if (result->value >= 10) {
                    result->value = result->value % 10;
                    carry = 1;
                }
                else
                    carry = 0;
                l1 = l1->next;
            }
        }
    

    }
    //when loop over, but carry is not clear, it means that we need to extend our digit for one node 
    if (carry == 1) {
        former = latter;
        latter = new linkedlistNode;
        latter->value = 1;
        latter->next = NULL;
        former->next = latter;
    }
    
    return head;
    
}


int main(int argc, const char * argv[])
{

    // first let's create a linked list
    cout<<"input a linked list"<<endl;
    linkedlistNode *list1 = NULL;
    linkedlistNode *list2 = NULL;
    int n;
    //istream buffer;
    //INPUT list1
    string buffer;
    getline(cin, buffer);
    istringstream buffer2(buffer);
    
    while (buffer2>>n) {
        
        linkedlistNode *former, *latter;
        
        if (!list1) {
            list1 = new linkedlistNode;
            list1->value = n;
            former = list1;
            latter = former;
        }
        
        else {
            
            former = new linkedlistNode;
            former->value = n;
            former->next = NULL;
            latter->next = former;
            latter = former;
        }
        
    }
    cout<<"input another list"<<endl;
//    cin.ignore(INT_MAX, '\n');
    //input list2
  
    getline(cin, buffer);
    istringstream buffer3(buffer);
    while (buffer3>>n) {
        
        linkedlistNode *former, *latter;
        
        if (!list2) {
            list2 = new linkedlistNode;
            list2->value = n;
            former = list2;
            latter = former;
        }
        
        else {
            
            former = new linkedlistNode;
            former->value = n;
            latter->next = former;
            former->next = NULL;
            latter = former;
        }
        
    }
    
    linkedlistNode *result = addList(list1, list2);
    linkedlistNode *test = result;
    cout<<"RESULT IS ";
    while (test != NULL) {
        cout<<test->value<<" ";
        test = test->next;
    }
    cout<<endl;

    
    return 0;
}

