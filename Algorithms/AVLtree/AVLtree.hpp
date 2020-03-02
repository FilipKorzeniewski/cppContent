#ifndef AVLtree_hpp
#define AVLtree_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename Key, typename Info>
class AVLtree{
private:
    struct Node{
        Key key;
        Info info;
        Node* left;
        Node* right;
        int height;
        Node(Key _key, Info _info): key(_key), info(_info), left(nullptr), right(nullptr), height(1) {};
    };
    
    Node* root;
    
    Node* mostLeft (Node* temp){Node* curr = temp;
        while(curr->left){
            curr = curr->left;
        } return curr;
    };
    int max(int a, int b){ return (a>b) ? a : b; };
    int height(Node* temp){ if(!temp){return 0;} return temp->height; }; //if null doesn't crush, just returns 0
    int getBalance(Node* temp); //gets balance factor of subtree
    
    Node* rebalance(Node* temp);
    
    Node* RightRotate(Node* temp); //rotate right subtree around temp
    Node* LeftRotate(Node* temp); //rotate left substree around temp
    
    Node* insert(Node* temp, const Key& _key, const Info& _info); //recursively inserts node;
    Node* find(Node* temp, const Key& _key); //reccursively
    Node* remove(Node* &temp, const Key& _key);
    int updateHeight(Node* temp);
    
    void print(Node* temp, int space) const;
    void printIn(Node* temp) const;
    void clearAll(Node* temp);
    
    void copyTree(Node* copied, Node* base);
    void copyTree(const AVLtree& x);
    
    void addSubtree(Node* temp);
public:
    class iterator;
    iterator insert(const Key& _key, const Info& _info);
    bool remove(const Key& _key);
    iterator find(const Key& _key);
    
    void print() const;
    void printIn() const;
    
    void clearAll();
    
    AVLtree<Key, Info>& operator=(const AVLtree<Key, Info>& x);
    AVLtree<Key, Info>& operator+=(const AVLtree<Key, Info>& x);
    AVLtree<Key, Info> operator+(const AVLtree<Key, Info>& x);


    AVLtree(): root(nullptr){};
    AVLtree(const AVLtree<Key, Info>& x);
    ~AVLtree(){ clearAll(); };
    
    class iterator{
    private:
        AVLtree& tree;
        Node* iter;
        
        bool operator==(const Node* node);
        bool operator!=(const Node* node);
        iterator& operator=(const Node* node);
    public:
        iterator(AVLtree& A): tree(A), iter(nullptr){};
        iterator(AVLtree& A, Node* node):tree(A), iter(node){};
        ~iterator(){};
        
        iterator& operator=(const iterator& it);
        
        iterator& operator++();
        iterator& operator--();
        bool operator==(const iterator& it);
        bool operator!=(const iterator& it);
        
        bool deleteNode();
        Key getKey();
        Info getInfo();
        bool setInfo(const Info& _info);
        
        bool isNull(); //returns true if nullptr and false if not
    };
    
};

template <typename Key, typename Info>
int AVLtree<Key, Info>::updateHeight(Node* temp){
    
    if(!temp)
        return 0;
    
    temp->height = 0;
    temp->height = max(updateHeight(temp->left), updateHeight(temp->right));
        
    return temp->height + 1;
}

template <typename Key, typename Info>
typename AVLtree<Key, Info>::Node* AVLtree<Key, Info>::RightRotate(Node* temp){
    
    if(root == temp)
        root = temp->left;
    Node* x = temp->left;
    Node* T2 = x->right;
    
    // Perform rotation
    x->right = temp;
    temp->left = T2;
    
    // Update heights
    temp->height = max(height(temp->left),
                    height(temp->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
        
    return x;
}

template <typename Key, typename Info>
typename AVLtree<Key, Info>::Node* AVLtree<Key, Info>::LeftRotate(Node* temp){
    
    if(root == temp){
        root = temp->right;
    }
    Node* x = temp->right;
    Node* T2 = x->left;
    
    // Perform rotation
    x->left = temp;
    temp->right = T2;
    
    // Update heights
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
        
    return x;
}

template <typename Key, typename Info>
int AVLtree<Key, Info>::getBalance(Node *temp){
    
    if(!temp){
        return 0;
    }
    return height(temp->left) - height(temp->right);
}

template <typename Key, typename Info>
typename AVLtree<Key, Info>::Node* AVLtree<Key, Info>::rebalance(Node* temp){
   
    if(!temp)
        return nullptr;
    
    int balance = getBalance(temp);
    
//       Left Left Case
    if (balance > 1 && getBalance(temp->left) >= 0)
        return RightRotate(temp);

//       Right Right Case
    if (balance < -1 && getBalance(temp->left) < 0)
        return LeftRotate(temp);
        
//       Left Right Case
    if (balance > 1 && getBalance(temp->right) <= 0){
        temp->left = LeftRotate(temp->left);
        return RightRotate(temp);
    }
        
//       Right Left Case
    if (balance < -1 && getBalance(temp->right) > 0){
        temp->right = RightRotate(temp->right);
        return LeftRotate(temp);
    }
    
    return temp;
}

template <typename Key, typename Info>
typename AVLtree<Key, Info>::Node* AVLtree<Key, Info>::insert(Node* temp, const Key& _key, const Info& _info){
    
//    1. Perform the normal BST insertion
    if (!temp){
        Node* newNode = new Node(_key, _info);
        if(!root)
            root = newNode;
        return newNode;
    }
    
    if (_key < temp->key)
        temp->left = insert(temp->left, _key, _info);
    else if (_key > temp->key)
        temp->right = insert(temp->right, _key, _info);
    else // Equal keys are not allowed in BST
        return temp;
    
//    2. Update height of this ancestor node
    temp->height = 1 + max(height(temp->left), height(temp->right));
    
//    3. Get the balance factor of this ancestor
//    node to check whether this node became
//    unbalanced
    int balance = getBalance(temp);
    
//       If this node becomes unbalanced, then
//       there are 4 cases
    
//       Left Left Case
    if (balance > 1 && _key < temp->left->key)
        return RightRotate(temp);
    
//       Right Right Case
    if (balance < -1 && _key > temp->right->key)
        return LeftRotate(temp);
    
//       Left Right Case
    if (balance > 1 && _key > temp->left->key){
        temp->left = LeftRotate(temp->left);
        return RightRotate(temp);
    }
    
//       Right Left Case
    if (balance < -1 && _key < temp->right->key){
        temp->right = RightRotate(temp->right);
        return LeftRotate(temp);
    }
    
    return temp;
}

template <typename Key, typename Info>
typename AVLtree<Key, Info>::iterator AVLtree<Key, Info>::insert(const Key& _key, const Info& _info){
    
    iterator it = iterator(*this, insert(root, _key, _info));
    return it;
}

template <typename Key, typename Info>
typename AVLtree<Key, Info>::Node* AVLtree<Key, Info>::find(Node* temp, const Key& _key){
    
    Node* isFound = nullptr;
    if(!temp)
        return nullptr;
    if(_key == temp->key)
        return temp;
    else if(_key < temp->key){
        isFound = find(temp->left, _key);
    }
    else{
        isFound = find(temp->right, _key);
    }
    
    return isFound;
}

template <typename Key, typename Info>
typename AVLtree<Key, Info>::iterator AVLtree<Key, Info>::find(const Key& _key){
    
    iterator it = iterator(*this, find(root, _key));
    if(!it.isNull()){
        cout << "found element:" << endl;
        cout << "key: " << it.getKey() << " ";
        cout << "info: " << it.getInfo() << " " << endl;
    }
    else
        cout << "There is no element " << _key << endl;
    
    return it;
}

template <typename Key, typename Info>
typename AVLtree<Key, Info>::Node* AVLtree<Key,Info>::remove(Node* &temp, const Key& _key){
    
    if (!temp)
        return nullptr;
    
    if (_key < temp->key){
        temp->left = remove(temp->left, _key);
    }
    else if (_key > temp->key){
        temp->right = remove(temp->right, _key);
    }
    else{
        if( (!temp->left) || (!temp->right) ){
            Node* curr = temp->left ? temp->left : temp->right;
            delete temp;
            temp = curr;
        }
        else{
            Node* curr = mostLeft(temp->right);
            temp->key = curr->key;
            temp->info = curr->info;
            temp->right = remove(temp->right, temp->key);
        }
        
        if(!temp){
            return nullptr;
        }
    }
    updateHeight(temp);
    return rebalance(temp);
}

template <typename Key, typename Info>
bool AVLtree<Key, Info>::remove(const Key& _key){
    
    return remove(root, _key) != nullptr;
}

template <typename Key, typename Info>
void AVLtree<Key, Info>::print(Node * temp, int space) const{
    if (temp == NULL)
        return;

    space += 10;

    this->print(temp->right, space);

    cout << endl << endl;

    for (int i = 10; i < space; i++)
    {
        cout << " ";
    }
    cout << temp->key << endl;

    this->print(temp->left, space);
}

template <typename Key, typename Info>
void AVLtree<Key, Info>::print() const{
    if (!root)
    {
        cout << "Tree is empty" << endl;
    }
    else
    {
        cout << "-----------------------------------------" << endl;
        this->print(root, 0);
        cout << "-----------------------------------------" << endl;
        cout << endl;
    }
}

template <typename Key, typename Info>
void AVLtree<Key, Info>::printIn(Node* temp) const{
    
    if(!temp)
        return;
    if(temp->left)
        printIn(temp->left);
    
    cout << temp->key << " ";

    if(temp->right)
        printIn(temp->right);
}

template <typename Key, typename Info>
void AVLtree<Key, Info>::printIn() const{
    
    cout << "In order print:" << endl;
    printIn(root);
    cout << endl << endl;
}

template <typename Key, typename Info>
void AVLtree<Key,Info>::clearAll(Node* temp){
    
    if(!temp)
        return;
    if(temp->left){
        clearAll(temp->left);
    }
    if(temp->right){
        clearAll(temp->right);
    }
    delete temp;
    temp = nullptr;
}

template <typename Key, typename Info>
void AVLtree<Key, Info>::clearAll(){
    
    if(!root)
        return;
    clearAll(root);
    root = nullptr;
}

template <typename Key, typename Info>
void AVLtree<Key, Info>::addSubtree(Node* temp){
    
    if(!temp)
        return;

    if(temp->left)
        addSubtree(temp->left);

    this->insert(temp->key, temp->info);

    if(temp->right)
        addSubtree(temp->right);
}

template <typename Key, typename Info>
void AVLtree<Key, Info>::copyTree(Node* copied, Node* base){

    if(!copied)
        return;

    if(copied->left){
        base->left = new Node(copied->left->key, copied->left->info);
        copyTree(copied->left, base->left);
    }
    
    if(copied->right){
        base->right = new Node(copied->right->key, copied->right->info);
        copyTree(copied->right, base->right);
    }
}

template <typename Key, typename Info>
void AVLtree<Key, Info>::copyTree(const AVLtree& x){

    clearAll();
    if(x.root)
        root = new Node(x.root->key, x.root->info);
    copyTree(x.root,this->root);
    
}
       
template <typename Key, typename Info>
AVLtree<Key, Info>& AVLtree<Key, Info>::operator=(const AVLtree<Key, Info>& x){

    if(this == &x) { //it is assigning itself
        return *this;
    }

    this->copyTree(x);
    
    return *this;
}

template <typename Key, typename Info>
AVLtree<Key, Info>& AVLtree<Key, Info>::operator+=(const AVLtree<Key, Info>& x){

    this->addSubtree(x.root);
    
    return *this;
}

template <typename Key, typename Info>
AVLtree<Key, Info> AVLtree<Key, Info>::operator+(const AVLtree<Key, Info>& x){

    AVLtree<Key,Info> to_return(*this);
    
    return to_return += x;
}

template <typename Key, typename Info>
AVLtree<Key,Info>::AVLtree(const AVLtree<Key, Info>& x){
    
    this->root = nullptr;
    
    *this = x;
}

/* ITERATOR */

template <typename Key, typename Info>
typename AVLtree<Key, Info>::iterator& AVLtree<Key,Info>::iterator::operator=(const typename AVLtree<Key, Info>::Node* node){

    iter = node;
    return *this;
}

template <typename Key, typename Info>
typename AVLtree<Key, Info>::iterator& AVLtree<Key,Info>::iterator::operator=(const iterator& it){
    
    iter = it.iter;
    tree = it.tree;
    
    return *this;
}

template <typename Key, typename Info>
typename AVLtree<Key, Info>::iterator& AVLtree<Key,Info>::iterator::operator++(){
    
    if(iter)
        iter = iter->right;
    
    return *this;
}

template <typename Key, typename Info>
typename AVLtree<Key, Info>::iterator& AVLtree<Key,Info>::iterator::operator--(){
    
    if(iter)
        iter = iter->left;
    
    return *this;
}

template <typename Key, typename Info>
Key AVLtree<Key,Info>::iterator::getKey(){
 
    if(iter)
        return iter->key;

    string exceptionKey;
    throw exceptionKey;
}

template <typename Key, typename Info>
Info AVLtree<Key,Info>::iterator::getInfo(){
 
    if(iter)
        return iter->info;
    
    string exceptionInfo;
    throw exceptionInfo;
}

template <typename Key, typename Info>
bool AVLtree<Key, Info>::iterator::setInfo(const Info& _info){
    
    if(iter){
        iter->info = _info;
        return true;
    }
    
    return false;
}

template <typename Key, typename Info>
bool AVLtree<Key, Info>::iterator::isNull(){
    
    if(iter)
        return false;
    else
        return true;
}

template <typename Key, typename Info>
bool AVLtree<Key, Info>::iterator::operator==(const typename AVLtree<Key, Info>::Node* node){
    
    return iter == node;
}

template <typename Key, typename Info>
bool AVLtree<Key, Info>::iterator::operator==(const iterator& it){
    
    return iter == it.iter;
}

template <typename Key, typename Info>
bool AVLtree<Key, Info>::iterator::operator!=(const typename AVLtree<Key, Info>::Node* node){
    
    return iter != node;
}

template <typename Key, typename Info>
bool AVLtree<Key, Info>::iterator::operator!=(const iterator& it){
    
    return iter != it.iter;
}

template <typename Key, typename Info>
bool AVLtree<Key, Info>::iterator::deleteNode(){
    
    if(!iter)
        return false;
    
    tree.remove(iter->key);
    return true;
}


/* COUNT WORDS FUNCTION */

int count_words(AVLtree<string, string>& cnt, ifstream& src){
    
    int total_number_of_words = 0;
    AVLtree<string, string>::iterator it = AVLtree<string,string>::iterator(cnt, nullptr);
    
    if(!src.is_open()){
            cout << "Failed to open file" << endl;
    }
//    ascii 48 - 90
    string word;
    string exist;
    while(src >> word){
        total_number_of_words++;
        exist = to_string(0);
        it = cnt.insert(word,exist);
        exist = to_string(stoi(exist) + 1);
        it.setInfo(exist);
    }
    return total_number_of_words;
};

#endif /* AVLtree_hpp */

