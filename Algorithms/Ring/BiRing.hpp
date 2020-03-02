#ifndef BiRing_hpp
#define BiRing_hpp

#include <stdio.h>
#include <iostream>
#include <string.h>

template<typename Key, typename Info>
class BiRing{
private:
    struct Node{
        Key key;
        Info info;
        Node* prev;
        Node* next;
                
        Node(Key _key, Info _info): key(_key), info(_info), prev(nullptr), next(nullptr) {};
        Node(BiRing& Ring, Node* node, Key _key, Info _info);
        ~Node(){};
    };
    
    Node* head;
public:
    class iterator;
    void printRight();
    void printLeft();
    
    iterator getHead() const;
    bool DoesExist(const Key& _key);
    iterator find_element(const Key& _key);
    Info getInfo(const Key& _key);
    bool setInfo(const Key& _key, const Info& _info);
    
    iterator pushBack(const Key& _key, const Info& _info);
    iterator pushFront(const Key& _key, const Info& _info);
    bool pushAfter(const Key& AfterThisKey, const Key& _key, const Info& _info);
    
    bool pop_specific(const Key& KeyToDelete);
    
    void destroy_Ring();
    
    BiRing<Key, Info>& operator=(const BiRing<Key, Info>& x);
    BiRing<Key, Info> operator+(const BiRing<Key, Info>& x);
    BiRing<Key, Info>& operator+=(const BiRing<Key, Info>& x);

    BiRing(const BiRing<Key, Info>& x);
    BiRing(): head(nullptr){};
    ~BiRing(){ destroy_Ring(); };
    
    /* ITERATOR */
    class iterator{
    private:
        Node* iter;
    public:
        iterator(Node* temp): iter(temp) {};
        iterator& operator=(Node* temp){
            iter = temp;
            return *this;
        };
        
        iterator& operator=(const iterator& it){
            this->iter = it.iter;
            return *this;
        }
                
        void setHead(BiRing<Key, Info>& to_set_head, const iterator& it){
            to_set_head.head = it.iter;
        };
        
        bool setKey(const Key& _key){
            if(iter != nullptr){
                iter->key = _key;
                return true;
            }
            return false;
        };
        
        bool setInfo(const Info&  _info){
            if(iter != nullptr){
                iter->info = _info;
                return true;
            }
            return false;
        };
        
        bool setNext(const iterator& it){
            if(iter){
                iter->next = it.iter;
                return true;
            }
            return false;
        };
        
        bool setPrev(const iterator& it){
            if(iter){
                iter->prev = it.iter;
                return true;
            }
            return false;
        };
        
        void destroyNode(){
            iter->prev->next = iter->next;
            iter->next->prev = iter->prev;
            delete iter;
            iter = nullptr;
        };
        
        void createAfter(BiRing& Ring, const Key& _key, const Info& _info){
            Node* newNode = new Node(Ring, iter, _key, _info);
            iter = newNode->prev;
        };
        
        iterator getNext(){
            iterator it = iterator(nullptr);
            if(iter){
                it.iter = iter->next;
            }
            return it;
        };
        
        Key getKey(){
            if(iter)
                return iter->key;
            return nullptr;
        };
        
        Info getInfo(){
            if(iter)
                return iter->info;
            return nullptr;
        };
        
        bool isNull(){
            if(iter) return true;
            return false;
        };
        
        iterator& operator++(){
            if(iter){
                iter = iter->next;
            }
                return *this;
        };
        
        iterator& operator--(){
            if(iter){
                iter = iter->prev;
            }
            return *this;
        };
        
        bool operator==(const Node* node){
            return iter == node;
        };
        
        bool operator==(const iterator& rhs){
            return iter == rhs.iter;
        };
        
        bool operator!=(const Node* node){
            return iter != node;
        };
        
        bool operator!=(const iterator& rhs){
            return iter != rhs.iter;
        };

        iterator& operator+=(int x){
            for(int i=0; i<x ;i++){
                iter = iter->next;
            }
            return *this;
        };

        iterator& operator-=(int x){
            for(int i=0; i<x ;i++){
                iter = iter->prev;
            }
            return *this;
        };
    };
};

template <typename Key, typename Info>
BiRing<Key, Info>::Node::Node(BiRing& Ring,  Node* node, Key _key, Info _info){
    
    if(!node){
        key = _key;
        info = _info;
        next = this;
        prev = this;
        Ring.head = this;
    }
    else{
        key = _key;
        info = _info;
        next = node->next;
        prev = node;
        node->next = this;
        this->next->prev = this;
    }
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::iterator BiRing<Key, Info>::find_element(const Key& _key){
    
    iterator it = iterator(head);
    if(!head) return it;
    do{
        if(it.getKey() == _key){
            return it;
        }
        ++(it);
    }while(it != head);
    
    it = nullptr;
    return it;
}

template <typename Key, typename Info>
void BiRing<Key, Info>::printRight(){
    
    if(!head){
        std::cout << "LIST IS EMPTY" << std::endl;
        return;
    }
    iterator it = head;
    do{
        std::cout << "Key: " << it.getKey() << "\t Info: " << it.getInfo() << std::endl;
        ++it;
    }while(it != head);
}

template <typename Key, typename Info>
void BiRing<Key, Info>::printLeft(){
    
    if(!head) std::cout << "List is empty" << std::endl;
    Node* temp = head;

    do{
        std::cout << "Key: " << temp->key << "\t Info: " << temp->info << std::endl;
        temp = temp->prev;
    }while(temp != head);
}

template <typename Key, typename Info>
bool BiRing<Key, Info>::DoesExist(const Key& _key){
    
    iterator found_element = find_element(_key);
    if(found_element.isNull()){
        std::cout << "The element with key: "<< _key <<" exists"<< std::endl;
        return true;
    }
    std::cout << "The element with key: "<< _key <<" does not exist"<< std::endl;
    return false;
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::iterator BiRing<Key, Info>::getHead() const{
    
    iterator it = iterator(head);
    return it;
}

template <typename Key, typename Info>
Info BiRing<Key, Info>::getInfo(const Key& _key){
    
    iterator found_element = find_element(_key);
    if(found_element.isNull()){
        return found_element.getInfo();
    }
    std::cout << "Element with given Key does not exist" << std::endl;
    return found_element; //returned iterator consists nullptr
}

template <typename Key, typename Info>
bool BiRing<Key, Info>::setInfo(const Key& _key, const Info& _info){
    
    iterator found_element = find_element(_key);
    if(found_element.isNull()){
        found_element.setInfo(_info);
        return true;
    }
    return false;
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::iterator BiRing<Key, Info>::pushBack(const Key& _key, const Info& _info){
    
    iterator it = iterator(head);
    if(!(it.isNull())){ //head is nullptr
        it.createAfter(*this, _key, _info);
        return it;
    }
    else{ //head is not nullptr
        --it;
        it.createAfter(*this, _key, _info);
        ++it;
        return it;
    }
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::iterator BiRing<Key, Info>::pushFront(const Key& _key, const Info& _info){
    
    pushBack(_key, _info);
    head = head->prev;
    iterator it = iterator(head);
    return it;
}

template <typename Key, typename Info>
bool BiRing<Key, Info>::pushAfter(const Key& AfterThisKey, const Key& _key, const Info& _info){
    
    if(!head) return false;
    iterator temp = find_element(AfterThisKey);
    if(temp.isNull()){
        temp.createAfter(*this, _key, _info);
    }
    
    return false;
}

template <typename Key, typename Info>
bool BiRing<Key, Info>::pop_specific(const Key& KeyToDelete){
    
    if(!head) return false;
    iterator it = head;
    iterator last = head->prev;
    
    if(it == it.getNext()){
        if(it.getKey() == KeyToDelete){
            it.destroyNode();
            head = nullptr;
            return true;
        }
        return false;
    }
    do{
        if(it.getKey() == KeyToDelete){
            it.destroyNode();
            if(head == nullptr) it.setHead(*this, last);
            return true;
        }
        last = it;
        ++it;
    }while(it != head);
    return false;
}

template <typename Key, typename Info>
void BiRing<Key, Info>::destroy_Ring(){
    if(head){
        head->prev->next = nullptr; //break the ring
        Node* temp = head;
        Node* curr = head; int i = 0;
        while(temp){
            i++;
            temp = temp->next;
            delete curr;
            curr = temp;
        }
    }
    head = nullptr;
}

template <typename Key, typename Info>
BiRing<Key, Info>& BiRing<Key, Info>::operator=(const BiRing<Key, Info>& x){
    
    if(this == &x){ //assigning itself
        return *this;
    }
    
    this->destroy_Ring();
    if(x.head == nullptr) return *this;
    
    iterator it = x.head;
    do{
        this->pushBack(it.getKey(), it.getInfo());
        ++it;
    }while(it != x.head);
        
    return *this;
}

template <typename Key, typename Info>
BiRing<Key, Info> BiRing<Key, Info>::operator+(const BiRing<Key, Info> &x){
    
    BiRing<Key, Info> to_return = BiRing<Key, Info>();
    iterator it = this->head;
    
    if(it.isNull()){
        do{
            to_return.pushBack(it.getKey(), it.getInfo());
            ++it;
        }while(it != this->head);
    }
    it = x.head;
    if(it.isNull()){
        do{
            to_return.pushBack(it.getKey(), it.getInfo());
            ++it;
        }while(it != x.head);
    }
    return to_return;
}

template <typename Key, typename Info>
BiRing<Key, Info>& BiRing<Key, Info>::operator+=(const BiRing<Key, Info> &x){
    
    *this = *this + x;
    return *this;
}

template <typename Key, typename Info>
BiRing<Key,Info>::BiRing(const BiRing<Key, Info>& x){
    
    this->head = nullptr;
    
    *this = x;
}

bool check_arguments(int nbfirst, int nbsecond, int reps){
    if(nbfirst >= 0 && nbsecond >= 0 && reps >=0) return true;
    return false;
};

template <typename Key, typename Info>
BiRing<Key, Info> shuffle(const BiRing<Key, Info>& first, const BiRing<Key, Info>& second, int nbfirst, int nbsecond, int reps){
    
    BiRing<Key, Info> to_return = BiRing<Key, Info>();
    if(!check_arguments(nbfirst, nbsecond, reps)){
        std::cout << "WRONG PARAMETERS" << std::endl;
        return to_return;
    }
    
    typename BiRing<Key, Info>::iterator it1 = first.getHead();
    typename BiRing<Key, Info>::iterator it2 = second.getHead();
    
    for(int j = 0; j < reps; j++){
        for(int i=0; i < nbfirst; i++){
            to_return.pushBack(it1.getKey(), it1.getInfo());
            ++it1;
        }
        for(int i=0; i < nbsecond; i++){
            to_return.pushBack(it2.getKey(), it2.getInfo());
            ++it2;
        }
    }
    return to_return;
};

#endif
