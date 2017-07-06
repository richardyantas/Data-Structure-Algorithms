#include "Iterator.h"
#include <utility>
#include <stack>

template<class T>
class Tree{
    
    typedef CIterator<T,inorder> Iterator_inorder;
    typedef CIterator<T,preorder> Iterator_preorder;
    typedef CIterator<T,postorder> Iterator_postorder;
    typedef CIterator<T,reverseinorder> Iterator_reverseinorder;
    typedef CIterator<T,reversepreorder> Iterator_reversepreorder;
    typedef CIterator<T,reversepostorder> Iterator_reversepostorder;
    
    
public:

    Node<T> *root;
    Tree()
    {
        root = NULL;
    }
    
    bool find(T x, Node<T>** &p)
    {
        for( p = &root; (*p && ( (*p) -> data != x) ); p = &( (*p) -> son[( (*p) -> data) < x] )){};
        return !!(*p);        
    } 
       
    bool insert(T x)
    {
        Node<T> **p;
        if( find(x,p) )return false;
        *p = new Node<T> (x);
        return true;
    }
    
    bool remove(T x)
    {
        Node<T> **p;
        if( !find(x,p) )return false; 
        
        if((*p)->son[0] && (*p)->son[1])
        {
            Node<T> **q;
            for( q=&((*q)->son[1]);(*q)->son[0]; q=&((*q)->son[0]) ){};
            (*p)->dat=(*q)->dat;
            p=q;
        }
        
        Node<T> *t=*p;
        *p=(*p)->son[!((*p)->son[0])];
        delete t;
        return true;      
    }
    
    Iterator_inorder begin_in_order()
    {
        
        Iterator_inorder ret;
        Node<T>* r=root;       
        ret.st.push( std::make_pair(r,0) );
        ret++;        
        return ret;
    }
    
    Iterator_inorder end_in_order()
    {
        Iterator_inorder x;
        return x;
    }
    
    Iterator_reverseinorder begin_reverse_in_order()
    {
        
        Iterator_reverseinorder ret;
        Node<T>* r=root;       
        ret.st.push( std::make_pair(r,0) );
        ret++;        
        return ret;
    }
    
    Iterator_reverseinorder end_reverse_in_order()
    {
        Iterator_reverseinorder x;
        return x;
    }
        
    Iterator_preorder begin_pre_order()
    {        
        Iterator_preorder ret;
        Node<T>* r=root;
        ret.st.push( std::make_pair(r,0)); 
        ret++;
        return ret;
    }
    
    Iterator_preorder end_pre_order()
    {
        Iterator_preorder x;
        return x;
    }
    
    Iterator_reversepreorder begin_reverse_pre_order()
    {        
        Iterator_reversepreorder ret;
        Node<T>* r=root;
        ret.st.push( std::make_pair(r,0)); 
        ret++;
        return ret;
    }
    
    Iterator_reversepreorder end_reverse_pre_order()
    {
        Iterator_reversepreorder x;
        return x;
    }
    
    Iterator_postorder begin_post_order()
    {        
        Iterator_postorder ret;
        Node<T>* r=root;
        
        ret.st.push( std::make_pair(r,0) );
        ret++;        
        return ret;  
        
    }
    
    Iterator_postorder end_post_order()
    {
        Iterator_postorder x;
        return x;
    }
    
    Iterator_reversepostorder begin_reverse_post_order()
    {        
        Iterator_reversepostorder ret;
        Node<T>* r=root;
        
        ret.st.push( std::make_pair(r,0) );
        ret++;        
        return ret;  
        
    }
    
    Iterator_reversepostorder end_reverse_post_order()
    {
        Iterator_reversepostorder x;
        return x;
    }
    
    
    
};

