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
    
    CIterator<float,inorder> i1; 
    CIterator<float,preorder> i2; 
    CIterator<float,postorder> i3;
    CIterator<float,reverseinorder> i4; 
    CIterator<float,reversepreorder> i5; 
    CIterator<float,reversepostorder> i6;  
    
    cout << "inorder: " << endl;
    for(i1 = t.begin_in_order(); i1 != t.end_in_order(); i1++)
    {
        cout << *i1 << " ";
    }
    cout << endl;
    
    cout << "preorder: " << endl;
    for(i2 = t.begin_pre_order(); i2 != t.end_pre_order(); i2++)
    {
        cout << *i2 << " ";
    }
    cout << endl;
    
    cout << "postorder: " << endl;    
    for(i3 = t.begin_post_order(); i3 != t.end_post_order(); i3++)
    {
        cout << *i3 << " ";
    }
    cout << endl;
    
    
    cout << "reverseinorder: " << endl;
    for(i4 = t.begin_reverse_in_order(); i4 != t.end_reverse_in_order(); i4++)
    {
        cout << *i4 << " ";
    }
    cout << endl;
    
    cout << "reversepreorder: " << endl;
    for(i5 = t.begin_reverse_pre_order(); i5 != t.end_reverse_pre_order(); i5++)
    {
        cout << *i5 << " ";
    }
    cout << endl;
    
    cout << "reversepostorder: " << endl;
    for(i6 = t.begin_reverse_post_order(); i6 != t.end_reverse_post_order(); i6++)
    {
        cout << *i6 << " ";
    }
    cout << endl;    
    cout << endl << "-------------------" << endl;
    
    //t.preorder();
	return 0;
}
