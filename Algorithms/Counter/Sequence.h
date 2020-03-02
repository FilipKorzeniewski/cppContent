#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include <exception>
#include <fstream>
#include <string>

template <typename Val_type>
class Sequence{
private:
    struct Node{
        Val_type value;
        Node* next;
        Node(Val_type _value);
    };
    Node* head;
    Node* tail;
    unsigned int size;
    
    void print(Node* tmp);
    Node* go_forw(int number_of_element); //returns element that argument points out

    void move_back(Node* to_move);
public:
    bool setValue(int place, const Val_type& new_value);
    Val_type getValue(int place) const;

    bool isHead() const;
    void print();
    void clear_the_list();

    bool move_front(int place);
    bool move_back(int place);

    void push_front(const Val_type& _value);
    bool push_specific(int start, const Val_type& _value); //adds element at start place of the list
    void push_back(const Val_type& _value);

    bool pop_front();
    bool pop_specific(int Num_of_elem_todelete);
    bool pop_back();

    Sequence<Val_type>& operator+(const Sequence<Val_type>& x);
    Sequence<Val_type>& operator=(const Sequence<Val_type>& x);
    Sequence<Val_type>& operator+=(const Sequence<Val_type>& x);

    Sequence();
    Sequence(const Sequence<Val_type>& x);
    ~Sequence();
};

template<typename Val_type>
Sequence<Val_type>::Node::Node(Val_type _value){

    value = _value;
    next = nullptr;
}

template <typename Val_type>
bool Sequence<Val_type>::setValue(int place, const Val_type& new_value){

    if(place <= 0){
        return false;
    }
    if(place > size){
        return false;
    }
    Node* tmp = head;
    for(int i=1; i < place; i++){
        tmp = tmp->next;
    }
    tmp->value = new_value;
    return true;
}

template <typename Val_type>
Val_type Sequence<Val_type>::getValue(int place) const{

    Node* tmp = head;
    for(int i=1; i < place; i++){
        tmp = tmp->next;
    }
    return tmp->value;
}

template<typename Val_type>
void  Sequence<Val_type>::print() {

    if(!head) {
        std::cout <<"empty list" <<std::endl<<std::endl;
        return;
    }
    print(head);
    std::cout<<std::endl;
}

template <typename Val_type>
void Sequence<Val_type>::print(Node* tmp) {

    if(!tmp) {
        return;
    }
    else{
        std::cout << "value: "<< tmp->value << std::endl;
        print(tmp->next);
    }
}

template <typename Val_type>
bool Sequence<Val_type>::isHead() const{

    if(head) return true;
    else return false;
}

template <typename Val_type>
typename Sequence<Val_type>::Node* Sequence<Val_type>::go_forw(int number_of_element){

    if(size < number_of_element)
        return nullptr;

    Node* currNode = head;

    for(int i=1; i < number_of_element; i++){
        currNode = currNode->next;
    }
    return currNode;
}

template <typename Val_type>
void Sequence<Val_type>::push_front(const Val_type& _value){

    if(!head){
        head = new Node(_value);
        tail = head;
        size = 1;
    }
    else{
        Node* CurrNode = new Node(_value);
        CurrNode->next = head;
        head = CurrNode;
        size++;
    }
}

template <typename Val_type>
bool Sequence<Val_type>::push_specific(int start, const Val_type& _value){

    if(start <= 0)
        return false;
    
    if(start > size + 1)
        return false;
    
    if(start == 1){
        push_front(_value);
    }
    else if(start == size + 1){
        this->push_back(_value);
    }
    else{
        Node* currNode = this->go_forw(start - 1);
        Node* NewNode = new Node(_value);
        NewNode->next = currNode->next;
        currNode->next = NewNode;
        size++;
    }
    return true;
}

template <typename Val_type>
void Sequence<Val_type>::push_back(const Val_type& _value){

    if(!head){
        head = new Node(_value);
        tail = head;
        size = 1;
    }
    else{
        tail->next = new Node(_value);
        tail = tail->next;
        size++;
    }
}

template <typename Val_type>
bool Sequence<Val_type>::pop_front(){
    if(head){
        Node* tmp = head;
        head = tmp->next;
        size--;
        delete tmp;
        if(!head)
            tail = nullptr;
        return true;
    }
    std::cout<< "The list does not have any element - nothing to be deleted" <<std::endl;
    return false;
}

template <typename Val_type>
bool Sequence<Val_type>::pop_specific(int Num_of_elem_todelete){

    if(Num_of_elem_todelete < 0){
        return false;
    }
    if(Num_of_elem_todelete > size){
        return false;
    }

    if(!head){
        return false;
    }

    if(Num_of_elem_todelete == 1){
        pop_front();
        return true;
    }


    Node* tmp = go_forw(Num_of_elem_todelete -1);
    Node* to_delete = tmp->next;
    tmp->next = tmp->next->next;
    delete to_delete;
    return true;
}

template <typename Val_type>
bool Sequence<Val_type>::pop_back(){

    if(head){
        if(!head->next){
            delete head;
            head = nullptr;
            tail = nullptr;
            size = 0;
        }
        else{
            Node* tmp = this->go_forw(size - 1);
            delete tail;
            tail = tmp;
            tail->next = nullptr;
            size--;
        }
        return true;
    }
    std::cout<< "The list does not have any element - nothing to be deleted" <<std::endl;
    return false;
}

template <typename Val_type>
void Sequence<Val_type>::clear_the_list(){

    if(head){
        Node* prev = this->head;
        Node* curr = this->head;
        while(curr){
            curr = prev->next;
            delete prev;
            prev = curr;
        }
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<typename Val_type>
bool Sequence<Val_type>::move_front(int place){

    if(place <= 0) return false;
    if(place > size) return false;
    if(place == 1) return true;

    Node* tmp = head;
    for(int i=1; i < place - 1; i++){
        tmp = tmp->next;
    }
    if(tmp->next == tail)
        tail = tmp;
    //tmp->next is the Node to be moved
    Node* to_move = tmp->next;
    tmp->next = tmp->next->next;
    to_move->next = head;
    head = to_move;

    return true;
}

template<typename Val_type>
bool Sequence<Val_type>::move_back(int place){

    if(place <= 0) return false;
    if(place > size) return false;
    if(place == size) return true;
    if(place == 1){
        tail->next = head;
        head = head->next;
        tail->next = nullptr;
        return true;
    }

    Node* tmp = head;
    for(int i=1; i < place - 1; i++){
        tmp = tmp->next;
    }
    //tmp->next is the Node to be moved
    Node* to_move = tmp->next;
    tmp->next = tmp->next->next;
    tail->next = to_move;
    tail = to_move;
    tail->next = nullptr;
    
    return true;
}

template <typename Val_type>
Sequence<Val_type>::Sequence(const Sequence<Val_type>& x){

    head = nullptr;
    tail = nullptr;
    size = 0;

    Node* tmp = x.head;
    while(tmp){
        this->push_back(tmp->value);
        tmp = tmp->next;
    }
}

template <typename Val_type>
Sequence<Val_type>& Sequence<Val_type>::operator+(const Sequence<Val_type>& x){

    Sequence<Val_type>* to_return = new Sequence();
    *to_return = *this;
    *to_return += x;
    return *to_return;
}

template <typename Val_type>
Sequence<Val_type>& Sequence<Val_type>::operator=(const Sequence<Val_type>& x){

    if(this == &x) { //it is assigning itself
        return *this;
    }

    this->clear_the_list();

    Node* tmp = x.head;
    while(tmp) {
        this->push_back(tmp->value);
        tmp = tmp->next;
    }
    return *this;
}

template<typename Val_type>
Sequence<Val_type>& Sequence<Val_type>::operator+= (const Sequence<Val_type>& x){


    Node* tmp = x.head;
    while(tmp){
        this->push_back(tmp->value);
        tmp = tmp->next;
    }
    return *this;
}

template <typename Val_type>
Sequence<Val_type>::Sequence()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename Val_type>
Sequence<Val_type>::~Sequence()
{
    this->clear_the_list();
}

#endif // SEQUENCE_H
