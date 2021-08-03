//  ____  _             _
// / ___|| |_ __ _  ___| | __
// \___ \| __/ _` |/ __| |/ /
//  ___) | || (_| | (__|   <
// |____/ \__\__,_|\___|_|\_\

#pragma once

#include<iostream>
#include<stdexcept>
using namespace std;



template<typename type>
class stack{
private:

    type* arr;          //Dynamic array of stack elements
    size_t capacity;
    int top;

public:
    stack(size_t);            //Constructor   
    ~stack();                 //Destructor

    bool empty();
    size_t size();

    //Modifiers
    void push(const type&);
    void pop();
    type peak();
};


//**************************
//  Function Definitions  
//**************************

template<typename type>
stack<type>::stack(size_t input): capacity(input), top(-1){
    arr = new type[input];      //Create dynamically allocated array
}

template<typename type>
stack<type>::~stack(){
    delete []arr;
    arr = nullptr;
}

template<typename type>
bool stack<type>::empty(){
    if(top == -1) return true;
    else return false;
}

//Returns current number of elements in the array
template<typename type>
size_t stack<type>::size(){
    return top + 1;
}

//Put new item on top of stack
//(In this case, the back of the array)
template<typename type>
void stack<type>::push(const type& input){

    //Array full
    if(top == capacity - 1) cout << "The stack is full" << endl;//throw length_error("The stack is full");     
    else{
        top += 1;       //Advancing top of stack up
        arr[top] = input;
    }
}

template<typename type>
type stack<type>::peak(){
    if(empty()) cout << "The stack is empty" << endl; //throw length_error("The stack is empty");
    return arr[top];        //Top is the back of array
}

//Popping top of the stack (Last item in array)
template<typename type>
void stack<type>::pop(){
    if(empty()) cout << "The stack is empty" << endl; //throw length_error("The stack is empty"); 
    else top--;
}
