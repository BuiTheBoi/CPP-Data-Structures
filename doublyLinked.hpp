
//  ____              _     _         _     _       _            _   _     _     _
// |  _ \  ___  _   _| |__ | |_   _  | |   (_)_ __ | | _____  __| | | |   (_)___| |_
// | | | |/ _ \| | | | '_ \| | | | | | |   | | '_ \| |/ / _ \/ _` | | |   | / __| __|
// | |_| | (_) | |_| | |_) | | |_| | | |___| | | | |   <  __/ (_| | | |___| \__ \ |_
// |____/ \___/ \__,_|_.__/|_|\__, | |_____|_|_| |_|_|\_\___|\__,_| |_____|_|___/\__|
//                            |___/


#pragma once

#include<iostream>
using namespace std;

/***********************
 *        Node         *
 ***********************/ 
template<typename T>        
struct dNode{       //Doubly node
    T data;
    dNode<T>* prev;
    dNode<T>* next;
    dNode(T input): data(input), prev(nullptr), next(nullptr) {}
};

/***********************
 *  DLL Implementation *
 ***********************/ 
template<typename T>
class doublyLinkedList{
private:
    dNode<T>* head;
    dNode<T>* tail;

public:
    //Constructors
    doublyLinkedList();     //Default onstructor
    ~doublyLinkedList();

    bool empty();

    //Modifiers
    void prepend(T);
    void append(T);
    void remove(dNode<T>*);
    void popFront();
    void popBack();
    void clear();

    //Functions involving traversals 
    void printForward();
    void printReverse();
    unsigned size();

};

/***********************
 * Function Definitions
 ***********************/

template<typename T>
doublyLinkedList<T>::doublyLinkedList(){
    //Creating dummy nodes
    head = new dNode<T>(T());
    tail = new dNode<T>(T());

    //Connecting dummy nodes together
    head->next = tail;
    tail->prev = head;
}

template<typename T>
doublyLinkedList<T>::~doublyLinkedList(){
    clear();

    //To prevent memory leaks
    delete head;
    delete tail;

    //To prevent hanging pointers
    head = nullptr;
    tail = nullptr;
}

template<typename T>
bool doublyLinkedList<T>::empty(){
    if(head->next == tail && tail->prev == head) return true;
    else return false;
}

//Adding item to front of the list
template<typename T>
void doublyLinkedList<T>::prepend(T data){
    dNode<T>* newNode = new dNode<T>(data);     //Creating new node

    newNode->prev = head;
    newNode->next = head->next;
    head->next->prev = newNode;
    head->next = newNode;
}

//Adding item to back of the list
template<typename T>
void doublyLinkedList<T>::append(T data){
    dNode<T>* newNode = new dNode<T>(data);
    
    newNode->next = tail;
    newNode->prev = tail->prev;
    tail->prev->next = newNode;
    tail->prev = newNode;
}

template<typename T>
void doublyLinkedList<T>::remove(dNode<T>* node){
    if(empty()) cout << "List is empty" << endl; 
    else{
        dNode<T>* predecessor = node->prev;
        dNode<T>* successor = node->next;

        predecessor->next = successor;
        successor->prev = predecessor;

        delete node;
    }
}

//Deleting first item on the list
template<typename T>
void doublyLinkedList<T>::popFront(){
    if(!empty()){
        remove(head->next);
    }
}

//Deleting last item on the list
template<typename T>
void doublyLinkedList<T>::popBack(){
    if(!empty()){
        remove(tail->prev);

    }
}

template<typename T>
void doublyLinkedList<T>::clear(){
    while(!empty()){
        popFront();
    }
}

template<typename T>
void doublyLinkedList<T>::printForward(){
    dNode<T>* iterator = head->next;

    while(iterator != tail){
        cout << iterator->data << " ";
        iterator = iterator->next;
    }
    cout << endl;
}

template<typename T>
void doublyLinkedList<T>::printReverse(){
    dNode<T>* iterator = tail->prev;

    while(iterator != head){
        cout << iterator->data << " ";
        iterator = iterator->prev;
    }
    cout << endl;
}

template<typename T>
unsigned doublyLinkedList<T>::size(){
    unsigned amount = 0;
    dNode<T>* iterator = head->next;

    while(iterator != tail){
        iterator = iterator->next;
        amount++;
    }
    return amount;
}