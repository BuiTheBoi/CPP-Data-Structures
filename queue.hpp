//   ___
//  / _ \ _   _  ___ _   _  ___ 
// | | | | | | |/ _ \ | | |/ _ \
// | |_| | |_| |  __/ |_| |  __/
//  \__\_\\__,_|\___|\__,_|\___|

#include<iostream>
using namespace std;

template<typename type>
class queue{
private:
    size_t front, rear,
            size, capacity;
    type* arr;
public:
    queue(size_t);            //Constructor
    ~queue();           //Deconstructor

    bool empty();
    type peek();

    //Modifiers
    void push(const type&);
    void pop();
};

/******************
 * Function Bodies
 * ****************/

template<typename type>
queue<type>::queue(size_t s): capacity(s), front(0), rear(0), size(0) {
    arr = new type[s];
} 

template<typename type>
queue<type>::~queue(){
    delete [] arr;
    arr = nullptr;
}

template<typename type>
bool queue<type>::empty(){
    if(size == 0) return true;
    else return false;
}

template<typename type>
type queue<type>::peek(){
    if(empty()) throw length_error("Queue is empty");  
    else{
        return arr[front];
    }
}

template<typename type>
void queue<type>::push(const type& value){
    if(size == capacity) cout << "Queue is full" << endl;
    else{
        arr[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
    }
}

template<typename type>
void queue<type>::pop(){
    if(empty()) cout << "Queue is empty" << endl;
    else{
        front = (front + 1) % capacity;
        size--;
    }
}
