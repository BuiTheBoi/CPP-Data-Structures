//  ____  _             _         _     _       _            _   _     _     _       
// / ___|(_)_ __   __ _| |_   _  | |   (_)_ __ | | _____  __| | | |   (_)___| |_     
// \___ \| | '_ \ / _` | | | | | | |   | | '_ \| |/ / _ \/ _` | | |   | / __| __|    
//  ___) | | | | | (_| | | |_| | | |___| | | | |   <  __/ (_| | | |___| \__ \ |_     
// |____/|_|_| |_|\__, |_|\__, | |_____|_|_| |_|_|\_\___|\__,_| |_____|_|___/\__|    
//                |___/   |___/

#pragma once

#include<iostream>
using namespace std;


/***********************
 *        Node         *
 ***********************/ 
template<typename T>
struct Node{
    T data;
    Node<T>* next;
    Node(T input): data(input), next(nullptr){}
};


/***********************
 *  SLL Implementation *
 ***********************/ 
template<typename T>
class singlyLinkedList{
private:
    Node<T>* head;
    Node<T>* tail;

public: 
    singlyLinkedList(): head(nullptr), tail(nullptr){}     //Default constructor
    ~singlyLinkedList();        //Destructor


    bool empty();

    //Modifiers
    void append(T);
    void prepend(T);
    void removeAfter(Node<T>*);
    void popBack();
    void popFront();
    void clear();

    //Having to do with traversals
    unsigned size();
    void printData();
};

/***********************
 * Function Definitions
 ***********************/ 
template<typename T>
bool singlyLinkedList<T>::empty(){
    if(head == nullptr && tail == nullptr) return true;
    else return false;
}

template<typename T>
singlyLinkedList<T>::~singlyLinkedList(){
    clear();
}

//Adding to the back of the list
template<typename T>
void singlyLinkedList<T>::append(T data){
    Node<T>* newNode = new Node<T>(data);       //Making new node
    if(empty()){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}


//Adding to the front of the list
template<typename T>
void singlyLinkedList<T>::prepend(T data){
    Node<T>* newNode = new Node<T>(data);       //Creating new dynamically allocated node

    if(empty()){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

template<typename T>
void singlyLinkedList<T>::removeAfter(Node<T>* index){
    //Special case to remove the head
    if(index == nullptr && head != nullptr){        
        Node<T>* successor = head->next;    
        head = successor;
        if(successor == nullptr){
            delete tail;
            tail = nullptr;    //If head is the only item
        }
    }
    //Removing element in the middle of the list
    else if (index->next != nullptr){
        Node<T>* successor = index->next->next;      //Successor = node after the one removed
        delete index->next;
        index->next = successor;

        if(successor == nullptr){           //Last item of list is removed
            tail = index;
        }
    }   
    //Special case if list is empty
    else if (empty()) cout << "List is already empty" << endl; 
}

//Deleting first item on the list
template<typename T>
void singlyLinkedList<T>::popFront(){
    removeAfter(nullptr);
}

//Deleting last item on the list
template<typename T>
void singlyLinkedList<T>::popBack(){
    Node<T>* secondToLast = head;    
    while(secondToLast->next != tail){        //Traversing to find second to last item
        secondToLast = secondToLast->next;
    }
    removeAfter(secondToLast);
}

template<typename T>
void singlyLinkedList<T>::clear(){
    while(!empty()){
        popFront();
    }
}

template<typename T>
unsigned singlyLinkedList<T>::size(){
    unsigned amt = 0;
    
    if(empty()){
        return amt;
    }
    else{
        Node<T>* iterator = head;

        while(iterator != nullptr){
            iterator = iterator->next;
            amt += 1;
        }
        return amt;
    }
}

template<typename T>
void singlyLinkedList<T>::printData(){
    Node<T>* iterator = head;

    while(iterator != nullptr){
        cout << iterator->data << " "; 
        iterator = iterator->next;
    }
    cout << endl; 
}
