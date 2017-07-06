#include<iostream>
//#include "list.h"
using namespace std;

template<class T>
struct Node{
    T data;
    Node *next;
    Node(){
        next=NULL;
    }
    Node(T _data){
        next = NULL;
        data=_data;
    }
    Node(T _data, Node* _next){
        data = _data;
        next=_next;
    }
};


template<class T>
class Iterator{

public:
    Node<T>* it;
    void operator = (Node<T> *p){
        it = p;
    }
    bool operator != (Node<T> *p){
        return it != p;
    }
    void operator ++(int){
        it = it->next;        
    }
    T operator *(){
        return it->data;
    }
};


template<class T>
class list{
    Node<T> *head;    
public:
    
    typedef Iterator<T> iterator;
    
    list()
    {
        head=NULL;
    };
    
    bool find(T data,Node<T>** &p){
        while( *p && data > (*p)->data ){
            p = &( (*p)->next);
        }
        return *p && data > (*p)->data;
    }
    
    bool insert(T data){
        Node<T>** p = &head;
        if( find(data,p) ){
            return false;
        }
        Node<T>* t = new Node<T>(data);
        t->next = *p;
        *p = t;
        return 1;
    }
    
    Node<T>* begin(){
        return head;
    }
    Node<T>* end(){    
        return NULL;
    }
    
    void print(){
        Node<T>* p = head;
        while( p ){
            cout << p->data << " ";
            p = p->next;
        }
    }
};




int main(){    
    //new Node<int>(1);    
    int**************** k;    
    list<int> l;    
    
    l.insert(1);
    l.insert(4);
    l.insert(5);
    l.insert(3);
    l.insert(2);
    l.insert(8);

    list<int>::iterator i;
    for(i = l.begin(); i != l.end(); i++)
        cout<<*i<<" ";
        
    //l.print();
    
    return 0;
}