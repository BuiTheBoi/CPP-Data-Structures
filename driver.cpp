// ====================================================PROJECT INFORMATION==============================================================
// Program Name: Data Structure Implementations
// Programming Language: C++
// Project Start Date: 25 December, 2020
// 
// General Purpose: In this personal project, I demonstrate my knowledge in data structures
//                  by implementing all of the structures I know using the C++ language. 
// 
// Moldule Description: In the driver file, I instantiate objects from each data structure
//                      class and call their functions to test out how each class operates
// 
// Compile: g++ driver.cpp
// Execute: ./a.out 
// =====================================================================================================================================
// 
// 
// =====================================================ABOUT THE AUTHOR================================================================
// Author: Justin Bui
// Email: jbui3493@gmail.com
// Institution: California State University, Fullerton
// =====================================================================================================================================
// 
// 
// ======================================================COPYRIGHT/LICENSING============================================================
// Copyright (C) 2020 Justin Bui
// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
// version 3 as published by the Free Software Foundation.
// This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// Warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
// A copy of the GNU General Public License v3 is available here:  <https://www.gnu.org/licenses/>.
// =====================================================================================================================================

// ==========================================================START OF MODULE============================================================

#include<iostream>
#include<iomanip>
#include<string>

//Includes for data structures I implemented
#include "moveOn.hpp"
#include "singlyLinked.hpp"
#include "doublyLinked.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "binarySearchTree.hpp"

using namespace std;

void moveOn();

int main(){
    //************************
    // SINGLY LINKED LIST    
    //************************
    cout << "Welcome to the Singly Linked List Implementation" << endl; 
    singlyLinkedList<int> mySingly;
    
    cout << "Contents after appending: " << endl; 
    mySingly.append(10);
    mySingly.append(12);
    mySingly.append(2);
    mySingly.append(99);
    mySingly.printData();

    cout << "Contents after prepending: " << endl; 
    mySingly.prepend(23);
    mySingly.prepend(1);
    mySingly.prepend(0);
    mySingly.printData();

    cout << "Current size of list: " << endl;
    cout << mySingly.size() << endl;

    cout << "Contents after popping front: " << endl;
    mySingly.popFront();
    mySingly.popFront();
    mySingly.popFront();
    mySingly.printData();

    cout << "Current size of list:" << endl;
    cout << mySingly.size() << endl;

    cout << "Contents after popping back: " << endl;
    mySingly.popBack();
    mySingly.printData();

    cout << "Contents after deleting: " << endl; 
    mySingly.clear();
    mySingly.printData();

    cout << "Current size after clearing: " << endl;
    cout << mySingly.size() << endl;

    moveOn();
    
    //************************
    // DOUBLY LINKED LIST    
    //************************
    cout << "Welcome to the Doubly Linked List Implementation" << endl; 
    doublyLinkedList<int> myDoubly;

    cout << "Contents after appending: " << endl; 
    myDoubly.append(10);
    myDoubly.append(12);
    myDoubly.append(2);
    myDoubly.append(99);
    myDoubly.printForward();

    cout << "Printing the array backward: " << endl; 
    myDoubly.printReverse();

    cout << "Contents after prepending: " << endl; 
    myDoubly.prepend(23);
    myDoubly.prepend(1);
    myDoubly.prepend(0);
    myDoubly.prepend(44);
    myDoubly.printForward();

    cout << "Contents after popping front:" << endl;
    myDoubly.popFront();
    myDoubly.printForward();

    cout << "Contents after popping back: " << endl;
    myDoubly.popBack();
    myDoubly.printForward();

    cout << "Current size:" << endl;
    cout << myDoubly.size() << endl; 

    cout << "Contents after clearing: " << endl; 
    myDoubly.clear();
    myDoubly.printForward();

    cout << "Size after clearing:" << endl;
    cout << myDoubly.size() << endl; 
    
    moveOn();

    //************************
    //          Stack   
    //************************
    cout << "Welcome to the Stack Implementation" << endl; 
    stack<int> myStack(6);

    cout << "The top of the stack after each push: " << endl;
    myStack.push(2);
    cout << myStack.peak() << endl; 
    myStack.push(43);
    cout << myStack.peak() << endl; 
    myStack.push(13);
    cout << myStack.peak() << endl; 
    myStack.push(90);
    cout << myStack.peak() << endl; 
    myStack.push(69);
    cout << myStack.peak() << endl; 
    myStack.push(420);
    cout << myStack.peak() << endl; 

    cout << "Current size of stack " << endl; 
    cout << myStack.size() << endl;

    cout << "Now let's see what happens if we push past the capacity: " << endl;
    myStack.push(0);

    cout << "Top of the stack after one pop:" << endl;
    myStack.pop();
    cout << myStack.peak() << endl; 

    cout << "Top of the stack after another pop:" << endl;
    myStack.pop();
    cout << myStack.peak() << endl; 

    cout << "The rest of the stack is cleared" << endl;
    for(int i = 0; i = myStack.size(); ++i){
        myStack.pop();
    }

    cout << "Let's see what happens if we pop from an empty stack:" << endl; 
    myStack.pop();

    cout <<"Size of empty stack: " << endl;
    cout << myStack.size() << endl; 

    moveOn();

    //************************
    //      QUEUE    
    //************************
    cout << "Welcome to the queue implementation" << endl; 
    queue<int> myQueue(5);

    cout << "The queue is currently empty because it returns " << myQueue.empty() << endl;
    for(int i = 0; i < 6; ++i){
        myQueue.push(i);        //Expected to say "queue is full" after the 6th push
    }
    cout << endl; 

    cout << "We will now pop the queue 5 times and print each front of the queue" << endl; 
    for (int i = 0; i < 5; ++i){    //Expected to say "queue is empty" after the 6th pop
        cout << "The front of the queue is " << myQueue.peek() << endl; 
        myQueue.pop();
    }

    moveOn();

    //************************
    // BINARY SEARCH TREE    
    //************************
    cout << "Welcome to the binary search tree implementation" << endl;
    binarySearchTree<int, string> familyTree;
    familyTree.insert(6, "Charlie");
    familyTree.insert(3, "Samantha");
    familyTree.insert(9, "Timothy");
    familyTree.insert(1, "Tyrone");
    familyTree.insert(4, "Dave");
    familyTree.insert(10, "Tommy");

    //Calling the 3 methods of traversal
    cout << "Performing preorder traversal: " << endl;
    familyTree.preorderRecursive();
    cout << endl;

    cout << "Performing inorder traversal: " << endl;
    familyTree.inorderRecursive();
    cout << endl;

    cout << "Performing postorder traversal: " << endl;
    familyTree.postorderRecursive();
    cout << endl;


    // Searching function
    cout << "Let's search for family names on the tree." << endl; 
    cout << "Charlie's address belongs in location " << familyTree.search(6) << endl;
    cout << "Let's search for a name that doesn't exist" << endl; 
    cout << "This should return a null value: " << familyTree.search(100) << endl << endl; 

    cout << "Deleting some nodes and printing it's contents: " << endl; 
    familyTree.remove(3);               // CASE 2
    familyTree.remove(4);               // CASE 3       
    familyTree.remove(9);               
    familyTree.inorderRecursive();

    cout <<  endl << "We will now clear the tree" << endl;
    familyTree.clear();
    cout << "Is the tree now empty? " << (familyTree.empty() ? "Yes" : "No") << endl;

    

    return 0;
}



// ============================================================END OF MODULE==============================================================
