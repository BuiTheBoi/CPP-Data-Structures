//  ____  _                          ____                      _     
// | __ )(_)_ __   __ _ _ __ _   _  / ___|  ___  __ _ _ __ ___| |__  
// |  _ \| | '_ \ / _` | '__| | | | \___ \ / _ \/ _` | '__/ __| '_ \ 
// | |_) | | | | | (_| | |  | |_| |  ___) |  __/ (_| | | | (__| | | |
// |____/|_|_| |_|\__,_|_|   \__, | |____/ \___|\__,_|_|  \___|_| |_|
//                           |___/
//  _____
// |_   _| __ ___  ___
//   | || '__/ _ \/ _ \
//   | || | |  __/  __/
//   |_||_|  \___|\___|

#include<iostream>
#include <algorithm>
template<typename K, typename V>
struct tNode {      // Tree node 
    tNode<K, V>* left;
    tNode<K, V>* right;
    tNode<K, V>* parent;
    K key;
    V value;

    tNode (K keyInput, V valInput): left(nullptr), right(nullptr), parent(nullptr),
                                    key(keyInput), value(valInput) {}
};

template<typename K, typename V>
class binarySearchTree {
private:
    tNode<K, V>* root;

    //Helper functions
    void preorderRecursiveHelp(tNode<K, V>*);
    void inorderRecursiveHelp(tNode<K, V>*);
    void postorderRecursiveHelp(tNode<K, V>*);
    void changeChild(tNode<K, V>*, tNode<K, V>*, tNode<K, V>*);
    void clearHelper(tNode<K, V>*);
    int getHeightHelper(tNode<K, V>*);

public:
    binarySearchTree(): root(nullptr) {}       // Constructor
    ~binarySearchTree() { clear(); }

    tNode<K, V>* search(K);
    bool empty();

    // Modifiers
    void insert(K, V);
    void remove(K);
    void clear();

    // Recursive Functions
    void preorderRecursive();
    void inorderRecursive();
    void postorderRecursive();

    // Getters
    tNode<K, V>* getRoot() { return root; }
    int getHeight();
    
};

/******************
 * Function Bodies
 * ****************/

template<typename K, typename V>
tNode<K, V>* binarySearchTree<K, V>::search(K keySearched){
    tNode<K, V>* curr = root;

    while(curr != nullptr) {
        if(curr->key == keySearched) return curr;       // Node is found
        else if (curr->key > keySearched) curr = curr->left;
        else if (curr->key < keySearched) curr = curr->right;
    }

    return nullptr;     // Node not found
}

template<typename K, typename V>
bool binarySearchTree<K, V>::empty(){
    return root == nullptr;
}

// ================================================MODIFIERS================================================

template<typename K, typename V>
void binarySearchTree<K, V>::insert(K keyInput, V valInput) {
    tNode<K, V>* newNode = new tNode<K, V>(keyInput, valInput);

    if(empty()) root = newNode;     // Tree empty

    else{                           // Tree not empty
        tNode<K, V>* current = root;
        tNode<K, V>* upper;

        while(current != nullptr) {
            upper = current;

            // Searching through tree to find parent (upper) of new node
            if (keyInput < current->key) current = current->left;
            else if (keyInput > current->key) current = current->right;
        }

        // Now inserting the node into the empty spot
        if(keyInput < upper->key) upper->left = newNode;
        else if (keyInput > upper->key) upper->right = newNode;
        
        newNode->parent = upper;        //Updating parent pointer to point to 'upper'
    }
}

template<typename K, typename V>            
void binarySearchTree<K, V>::changeChild(tNode<K, V>* parentNode,   // Parent of node to be replaced
                                        tNode<K, V>* currChild,     // Actual node to be replaced
                                        tNode<K, V>* newChild) {    // New node that takes over
    if (parentNode->left == currChild) parentNode->left = newChild;
    else if (parentNode->right == currChild) parentNode->right = newChild;

    if (newChild != nullptr) newChild->parent = parentNode;

    if (currChild != nullptr){
        // Deleting current child
        delete currChild;
    }
}

template<typename K, typename V>
void binarySearchTree<K, V>::remove(K keyRemoved) {
    tNode<K, V>* node = search(keyRemoved);

    if (node == nullptr) return;                                 // CASE 1: Node not found (Either not in tree or tree is empty)

    else if (node->left != nullptr && node->right != nullptr) {  // CASE 2: Node has 2 children

        // Finding node's successor
        tNode<K, V>* successor = node->right;
        while(successor->left != nullptr) {
            successor = successor->left;
        }
            
        // Successor now becomes 'node'
        node->key = successor->key;
        node->value = successor->value;
        
        // Whichever pointer points to successor must now point to null
        if (successor->parent->left == successor) successor->parent->left = nullptr;
        else if (successor->parent->right == successor) successor->parent->right = nullptr;

        delete successor;

    }

    // The 1 child is left
    else if (node->left != nullptr) {                           // CASE 3: Node has only 1 child (Whether left or right)
        if (node == root) root = node->left;                    // SUB CASE: If node has 1 child and is root 
        else changeChild(node->parent, node, node->left);
    }
    // The 1 child is right
    else if (node->right != nullptr) {
        if (node == root) node->right = root;
        else changeChild(node->parent, node, node->right);
    }

    else if (node->left == nullptr && node->right == nullptr) { // CASE 4: This node is a leaf node (I.e no children)
        if (node->parent->left == node) changeChild (node->parent, node, nullptr);
        else if (node->parent->right == node) changeChild (node->parent, node, nullptr);
    }

}

template<typename K, typename V>
void binarySearchTree<K, V>::clearHelper(tNode<K, V>* current){
    if(current == nullptr) return;      // Base case

    // Recursive case (Going in postorder traversal)
    clearHelper(current->left);
    clearHelper(current->right);
    delete current;
}

template<typename K, typename V>
void binarySearchTree<K, V>::clear(){
    clearHelper(root);
    root = nullptr;
}


// ==========================================RECURSIVE FUNCTIONS AND HELPERS==============================================

template<typename K, typename V>
void binarySearchTree<K, V>::preorderRecursive(){
    preorderRecursiveHelp(root);
} 

template<typename K, typename V>
void binarySearchTree<K, V>::preorderRecursiveHelp(tNode<K, V>* current){
    if(current == nullptr) return;      // Base case

    // Recursive case
    else{
        std::cout << current->value << std::endl;       // V
        preorderRecursiveHelp(current->left);           // L 
       preorderRecursiveHelp(current->right);           // R
    }
}

template<typename K, typename V>
void binarySearchTree<K, V>::inorderRecursive(){
    inorderRecursiveHelp(root);
}

template<typename K, typename V>
void binarySearchTree<K, V>::inorderRecursiveHelp(tNode<K, V>* current) {
    if(current == nullptr) return;          // Base case
    else{
        inorderRecursiveHelp(current->left);            // L
        std::cout << current->value << std::endl;       // V
        inorderRecursiveHelp(current->right);           // R
    }
}

template<typename K, typename V>
void binarySearchTree<K, V>::postorderRecursive(){
    postorderRecursiveHelp(root);
}

template<typename K, typename V>
void binarySearchTree<K, V>::postorderRecursiveHelp(tNode<K, V>* current) {
    if(current == nullptr) return;          // Base case
    else{
        postorderRecursiveHelp(current->left);            // L
        postorderRecursiveHelp(current->right);           // R
        std::cout << current->value << std::endl;         // V
    }
}


template<typename K, typename V>
int binarySearchTree<K, V>::getHeight() {
    return getHeightHelper(getRoot());
}

template<typename K, typename V>
int binarySearchTree<K, V>::getHeightHelper(tNode<K, V>* node) {
    if (node == nullptr) return -1;

    int leftHeight = getHeightHelper(node->left);
    int rightHeight = getHeightHelper(node->right);

    return 1 + max(leftHeight, rightHeight);
}