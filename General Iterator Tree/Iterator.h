#include "Node.h"
#include <utility>

#define status second
#define node first

class preorder{
public:
    short LEFT = 1;
    short SHOW = 0;
    short RIGTH = 2;
};

class postorder{
public:
    short LEFT = 0;
    short SHOW = 2;
    short RIGTH = 1;
};

class inorder{
public:
    short LEFT = 0;
    short SHOW = 1;
    short RIGTH = 2;
};


class reversepreorder{
public:
    short LEFT = 2;
    short SHOW = 0;
    short RIGTH = 1;
};

class reversepostorder{
public:
    short LEFT = 1;
    short SHOW = 2;
    short RIGTH = 0;
};

class reverseinorder{
public:
    short LEFT = 2;
    short SHOW = 1;
    short RIGTH = 0;
};


template<class T,class O>
class CIterator{
    O order;
public:
    std::stack< std::pair< Node<T>*,T> > st;
    
    CIterator(){}

    CIterator(Node<T>* p){}
        
    void operator = (CIterator<T,O> i)
    {  
        st = i.st;
    }
    
    bool operator != (CIterator<T,O> i)
    {
        return !st.empty();
    }
    
    T operator *()
    {
        return st.top().node->data;
    }
    
    CIterator<T,O> operator ++(int) 
    {        
        while( !st.empty() )
        {
            Node<T>* p = st.top().node;

            if( st.top().status == order.SHOW )
            {
                st.top().status++;
                return *this;
            }
                        
            else if( st.top().status == order.LEFT )
            {
                st.top().status++;
                if(p->son[0])
                {
                    p = p->son[0];                    
                    st.push( std::make_pair(p,0) );
                }
            }
                        
            else if( st.top().status == order.RIGTH )
            {
                st.top().status++;
                if( p->son[1] )
                {
                    p = p->son[1];
                    st.push(std::make_pair(p,0));
                }
            }
            else if( st.top().status == 3 )
            {
                st.pop();
            }
        }        
        return *this;      
    }        
};


