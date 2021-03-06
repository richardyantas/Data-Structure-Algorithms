#include <iostream>
#include <utility>
#include <map>
#include <stack>
#include "Tree.h"

using namespace std;

int main(){
    Tree<float> t;
    
    t.insert(9);
    t.insert(4);
    t.insert(2);
    t.insert(3);
    t.insert(1);
    t.insert(12);
    t.insert(15);
    t.insert(10);
    t.insert(14);
    t.insert(13);
    
    CIterator_preorder<float> i;
    i = t.begin_pre_order();
    
    
    for(i = t.begin_pre_order(); i != t.end_pre_order(); i++)
    {
        cout << *i << endl; 
        cin.get();
    }
       
    
    cout << "-------------------" << endl;
    
    //t.preorder();
	return 0;
}
