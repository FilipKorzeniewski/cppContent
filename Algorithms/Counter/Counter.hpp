#ifndef Counter_hpp
#define Counter_hpp

#include <stdio.h>
#include "Sequence.h"

template <typename Key>
class Counter{
private:
    class Counter_element{
    private:
        Key key;
        unsigned int numerator;
    public:
        Key get_key();
        unsigned int get_numerator();

        void increase_numb(int how_many);
        void decrease_numb(int how_many);
        void change_numb(int new_numb);

        void swapKey(const Key& new_key);

        int operator==(Counter_element x);
        Counter_element& operator=(const Counter_element& x);
        Counter_element(const Key& _key):key(_key), numerator(1){};
        Counter_element(){};
        ~Counter_element(){};
    };

    Sequence<Counter_element>* Seq;

    bool add_numb(const Key& _key, int how_many_add);
public:
    int doesExist(const Key& _key); //checks if the element with the given key exists - if does, returns place in the list, if does not returns -1

    bool swap_key(const Key& base_key, const Key& new_key); //swaps the key if element exists
    int howMany(const Key& _key);  //returns the numerator - tells how many there are occurrences with the given key

    void print();
    int length_of_the_list() const;
    void clear_the_list();

    void push_front(const Key& _key);
    void push_specific(int place, const Key& _key);
    void push_back(const Key& _key);

    bool move_front(const Key& _key);
    bool move_back(const Key& _key);

    //deletes whole node
    bool pop_front();
    bool pop_specific(const Key& _key);
    bool pop_back();

    //changes number of occurrence
    bool decrease_numb(const Key& _key); //if exists - decreases number of occurances; if there is only 1 - deletes whole element
    bool change_num_of_occurr(const Key& _key, unsigned int new_numerator); //changes number of occurrences

    Counter<Key>& operator=(const Counter<Key>& x);
    Counter<Key> operator+(const Counter<Key>& x);
    Counter<Key>& operator+=(const Counter<Key>& x);

    Counter(const Counter<Key>& x);
    Counter();
    ~Counter();
};

template <typename Key>
int Counter<Key>::Counter_element::operator==(Counter_element x){

    if(std::is_same<Key, std::string>::value){
        if (strcmp(this->key, x.key) == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(this->key == x.key){
            return 1;
        }
        else{
            return 0;
        }
    }
}

template<typename Key>
typename Counter<Key>::Counter_element& Counter<Key>::Counter_element::operator=(const Counter_element& x){
    this->key = x.key;
    this->numerator = x.numerator;

    return *this;
}

template<typename Key>
Key Counter<Key>::Counter_element::get_key(){
    return this->key;
}

template<typename Key>
unsigned int Counter<Key>::Counter_element::get_numerator(){
    return this->numerator;
}

template<typename Key>
void Counter<Key>::Counter_element::increase_numb(int how_many){
    this->numerator += how_many;
}

template<typename Key>
void Counter<Key>::Counter_element::decrease_numb(int how_many){
    this->numerator -= how_many;
}

template<typename Key>
void Counter<Key>::Counter_element::change_numb(int new_numb){
    this->numerator = new_numb;
}

template<typename Key>
void Counter<Key>::Counter_element::swapKey(const Key& new_key){
    this->key = new_key;
}

template <typename Key>
int Counter<Key>::doesExist(const Key& _key){

    int length = Seq->length_of_sequence();
    Counter_element* tmp = new Counter_element();

    for(int i = 1; i<=length; i++){
        *tmp = Seq->getValue(i);
        if(tmp->get_key() == _key){
            delete tmp;
            return i;
        }
    }
    delete tmp;
    return -1;
}

template <typename Key>
bool Counter<Key>::swap_key(const Key& base_key, const Key& new_key){

    int i = doesExist(base_key);
    if(i == -1){
        return false;
    }
    else{
        Counter_element* tmp = new Counter_element();
        *tmp = Seq->getValue(i);
        tmp->swapKey(new_key);
        Seq->setValue(i, *tmp);
        delete tmp;
        return true;
    }
}

template<typename Key>
int Counter<Key>::howMany(const Key& _key){
    int i = doesExist(_key);

    if(i == -1) return 0;
    else{
       Counter_element* tmp = new Counter_element();
        *tmp = Seq->getValue(i);
        int to_return = tmp->get_numerator();
        delete tmp;
        return to_return;
    }
}

template<typename Key>
void Counter<Key>::print(){

    int length = Seq->length_of_sequence();
    Counter_element* tmp = new Counter_element();

    std::cout << "Counter list:" << std::endl;

    if(length == 0){
        std::cout << "list is empty" << std::endl;
        return;
    }

    for(int i=1; i <= length; i++){
        *tmp = Seq->getValue(i);
        std::cout << "Key: " << tmp->get_key() << '\t' << "Number of occurrences: " << tmp->get_numerator() << std::endl;
    }
    delete tmp;
    std::cout << "end of the list" << std::endl <<std::endl;
}

template<typename Key>
int Counter<Key>::length_of_the_list() const{

    return Seq->length_of_sequence();
}

template<typename Key>
void Counter<Key>::clear_the_list(){

    Seq->clear_the_list();
}

template<typename Key>
void Counter<Key>::push_front(const Key& _key){

    int i = doesExist(_key);

    if(i == -1){
        Counter_element* tmp = new Counter_element(_key);
        Seq->push_front(*tmp);
        delete tmp;
    }
    else{
        Counter_element* tmp = new Counter_element();
        *tmp = Seq->getValue(i);
        tmp->increase_numb(1);
        Seq->setValue(i, *tmp);
        delete tmp;
    }
}

template<typename Key>
void Counter<Key>::push_specific(int place, const Key& _key){

    int i = doesExist(_key);
    Counter_element* tmp = new Counter_element(_key);

    if(i == -1){
        Seq->push_specific(place, *tmp);
    }
    else{
        *tmp = Seq->getValue(i);
        tmp->increase_numb(1);
        Seq->setValue(i, *tmp);
    }

    delete tmp;
}

template<typename Key>
void Counter<Key>::push_back(const Key& _key){

    int i = doesExist(_key);

    if(i == -1){
        Counter_element* tmp = new Counter_element(_key);
        Seq->push_back(*tmp);
        delete tmp;
    }
    else{
        Counter_element* tmp = new Counter_element();
        *tmp = Seq->getValue(i);
        tmp->increase_numb(1);
        Seq->setValue(i, *tmp);
        delete tmp;
    }
}

template<typename Key>
bool Counter<Key>::decrease_numb(const Key& _key){

    int i = doesExist(_key);
    if(i == -1) return false;
    else{
        Counter_element* tmp = new Counter_element();
        *tmp = Seq->getValue(i);
        if(tmp->get_numerator() == 1){
            Seq->pop_specific(i);
            delete tmp;
            return true;
        }
        else{
            tmp->decrease_numb(1);
            Seq->setValue(i,*tmp);
            delete tmp;
            return true;
        }
    }
}

template<typename Key>
bool Counter<Key>::change_num_of_occurr(const Key& _key, unsigned int new_numerator){

    int i = doesExist(_key);
    if(i == -1) return false;
    else{
        Counter_element* tmp = new Counter_element();
        *tmp = Seq->getValue(i);
        tmp->change_numb(new_numerator);
        Seq->setValue(i, *tmp);
        delete tmp;
    }
    return true;
}

template<typename Key>
bool Counter<Key>::add_numb(const Key& _key, int how_many_add){

    int i = doesExist(_key);
    if(i == -1) return false;
    else{
        Counter_element* tmp = new Counter_element();
        *tmp = Seq->getValue(i);
        tmp->increase_numb(how_many_add);
        Seq->setValue(i, *tmp);
        delete tmp;
    }
    return true;
}

template<typename Key>
bool Counter<Key>::move_front(const Key& _key){

    int i = doesExist(_key);
    if(i == -1) return false;
    else{
        Seq->move_front(i);
        return true;
    }
}

template<typename Key>
bool Counter<Key>::move_back(const Key& _key){

    int i = doesExist(_key);
    if(i == -1) return false;
    else{
        Seq->move_back(i);
        return true;
    }
}

template<typename Key>
bool Counter<Key>::pop_front(){

    bool isPoped = Seq->pop_front();
    return isPoped;
}

template<typename Key>
bool Counter<Key>::pop_specific(const Key& _key){

    int i = doesExist(_key);
    if(i == -1){
        return false;
    }
    else{
        Seq->pop_specific(i);
        return true;
    }
}

template<typename Key>
bool Counter<Key>::pop_back(){
    bool isPoped = Seq->pop_back();
    return isPoped;
}

template<typename Key>
Counter<Key>& Counter<Key>::operator=(const Counter<Key>& x){

    if(this == &x) { //it is assigning itself
        return *this;
    }

    this->Seq->clear_the_list();
    *(this->Seq) = *(x.Seq);
    
    return *this;
}

template <typename Key>
Counter<Key> Counter<Key>::operator+(const Counter<Key>& x){

    Counter<Key>* to_return = new Counter<Key>(*this);

    int length2 = x.length_of_the_list();
    Counter_element* tmp = new Counter_element();

    for(int i=1; i <= length2; i++){
        *tmp = x.Seq->getValue(i);
        if(to_return->doesExist(tmp->get_key()) == -1){
            to_return->Seq->push_back(*tmp);
        }
        else{
            to_return->add_numb(tmp->get_key(), tmp->get_numerator());
        }
    }
    delete tmp;
    return *to_return;
}

template<typename Key>
Counter<Key>& Counter<Key>::operator+=(const Counter<Key>& x){

    int length2 = x.length_of_the_list();
    Counter_element* tmp = new Counter_element();

    for(int i=1; i <= length2; i++){
        *tmp = x.Seq->getValue(i);
        if(this->doesExist(tmp->get_key()) == -1){
            this->Seq->push_back(*tmp);
        }
        else{
            this->add_numb(tmp->get_key(), tmp->get_numerator());
        }
    }
    delete tmp;
    return *this;
}

template <typename Key>
Counter<Key>::Counter(const Counter<Key>& x){

    this->Seq = new Sequence<Counter_element>(*(x.Seq));
}

template <typename Key>
Counter<Key>::Counter(){

    Seq = new Sequence<Counter_element>();
}

template<typename Key>
Counter<Key>::~Counter(){

    clear_the_list();
    delete Seq;
}


#endif /* Counter_hpp */
