#include<iostream>
using namespace std;

template<class T>
class node{
    public:
        T data;
        node<T>* next;
        node<T> (){};
        node<T> (T _data,node<T>* _next){
            next = _next;
            data = _data;
        }
};

bool  Less(int a,int b){return a<b;}
bool Greater(int a,int b){return a>b;}

template<class T>
class list{
	node<T>* head;
	public:
	list(){head = NULL;};
	bool (*pf)(T,T);
	list<T> (bool (*f)(T,T)){pf = f;head = NULL;}; 

	bool find(T x,node<T> **&p){
		 p = &head;
		 while(*p && pf(x,(*p)->data) ){p = &((*p)->next);}
		 return *p && x==(*p)->data;
	}

	bool insert(T x){
		node<T> **p;
		if(find(x,p)) return false;
		node<T>* t = new node<T>(x,*p);
		(*p) = t;
		return true;		
	}

	bool remove(T x){
	    node<T>** p;
	    if(!find(x,p)){
	        return false; 	  													
	    }
	    node<T> *t = *p;
	    *p = (*p)->next;
	    delete t;
	    return true;
	}
  void print( ){
      node<T>** p = &head;
      while(*p){
          cout << (*p)->data << " ";
          p = &((*p)->next);
      }
      cout << endl;
  }
};

int main(){
	list<int> l(&Greater);
	l.insert(3);
  l.insert(4);
  l.insert(13);
  l.insert(5);
  l.print();
  return 0;
}