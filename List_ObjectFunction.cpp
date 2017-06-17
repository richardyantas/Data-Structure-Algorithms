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


template<class T>
class greateR{
    public:
    bool operator()(T a,T b){
        return a>b;
    }
};

template<class T>
class lesS{
    public:
    bool operator()(T a,T b){
        return a<b;
    }
};


template<class T,class typeoffunction>
class list{
	node<T>* head;
	public:
	list(){head = NULL;};

	typeoffunction functor; 	

	bool find(T x,node<T> **&p){
		 p = &head;
		 while(*p && functor(x,(*p)->data)) {p = &((*p)->next);}
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
	list< int,greateR<int> > l;
	l.insert(3);
  l.insert(4);
  l.insert(13);
  l.insert(5);
  l.print();
  return 0;
}