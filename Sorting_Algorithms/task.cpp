#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>

template <typename T>
struct cmpLess { inline bool operator()(const T &t1, const T &t2) const { return (t1 < t2); } };

template <typename T>
struct cmpGreater { inline bool operator()(const T &t1, const T &t2) const { return (t2 < t1); } };

template <typename RandomAccessIterator>
inline void InsertSort(RandomAccessIterator start, RandomAccessIterator end) {
  cmpLess < typename RandomAccessIterator::value_type > lessThan;
  InsertSort(start, end, lessThan);  
}

template <typename RandomAccessIterator>
inline void SelectSort(RandomAccessIterator start, RandomAccessIterator end) {
  cmpLess < typename RandomAccessIterator::value_type > lessThan;
  SelectSort(start, end, lessThan);
}
template <typename RandomAccessIterator>
inline void StableSelectSort(RandomAccessIterator start, RandomAccessIterator end) {
  cmpLess < typename RandomAccessIterator::value_type > lessThan;
  StableSelectSort(start, end, lessThan);
}
template <typename RandomAccessIterator>
inline void HeapSort(RandomAccessIterator start, RandomAccessIterator end) {
  cmpLess < typename RandomAccessIterator::value_type > lessThan;
  HeapSort(start, end, lessThan);
}
template <typename RandomAccessIterator>
inline void MergeSort(RandomAccessIterator start, RandomAccessIterator end) {
  cmpLess < typename RandomAccessIterator::value_type > lessThan;
  MergeSort(start, end, lessThan);
}


template <typename RandomAccessIterator>
inline void IterativeMergeSort(RandomAccessIterator start, RandomAccessIterator end) {
  cmpLess < typename RandomAccessIterator::value_type > lessThan;
  IterativeMergeSort(start, end, lessThan);
}
 
 
template <typename RandomAccessIterator>
inline void LomutoQuickSort(RandomAccessIterator start, RandomAccessIterator end) {
  cmpLess < typename RandomAccessIterator::value_type > lessThan;
  LomutoQuickSort(start, end, lessThan);
}
template <typename RandomAccessIterator>
inline void HoareQuickSort(RandomAccessIterator start, RandomAccessIterator end) {
  cmpLess < typename RandomAccessIterator::value_type > lessThan;
  HoareQuickSort(start, end, lessThan);
}
template <typename RandomAccessIterator>
inline void YaroslavskiyQuickSort(RandomAccessIterator start, RandomAccessIterator end) {
  cmpLess < typename RandomAccessIterator::value_type > lessThan;
  YaroslavskiyQuickSort(start, end, lessThan);
}


template <typename RandomAccessIterator, typename LessThan>
inline void InsertSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
     // Adicione el código de Insertion Sort.
    typedef typename RandomAccessIterator::value_type T;
    RandomAccessIterator i, j;
    
    for(i = start; i != end; i++)
    {
        T x = *i;
        j = i;
        while( !(j==start) && lessThan( *(j-1), x ) )
        {
            *j = *(j-1);
            j--;
        }
        *j = x;
    }
}

template <typename RandomAccessIterator, typename LessThan>
inline void SelectSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
  // Adicione el código de Selection Sort.
  
  typedef typename RandomAccessIterator::value_type T;
  RandomAccessIterator i, j, index_minor;
  
  for( i = start; i != end; i++)
  {
      T minor = 1e9;
      for( j = i + 1; j!= end; j++)
      {
          if( lessThan(*j , minor ) )
          {
                index_minor = j;
                minor = *j;
          }
                                                  
      }      
      T temp = *i;
      *i = *index_minor;
      *index_minor = temp;
  }
    /*
      std::cout<<std::endl;
      std::cout<<"insert "<<std::endl;
      for(i = start; i != end; i++)
      {
          std::cout<<*i<<" ";
      }
      std::cout<<std::endl;
    */

  
}

template <typename RandomAccessIterator, typename LessThan>
inline void StableSelectSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
  // Adicione el código de Selection Sort estable.
  
  typedef typename RandomAccessIterator::value_type T;
  RandomAccessIterator i, j, index_minor;
  
  for( i = start; i != end; i++)
  {
      T minor = 1e9;
      for( j = end; j != (i); j--)
      {
          
          if( *j <= minor )
          {
                index_minor = j;
                minor = *j;
          }                                                
      }      
      T temp = *i;
      *i = *index_minor;
      *index_minor = temp;
      
  }
    /*
  
      std::cout<<std::endl;
      std::cout<<"insert stable"<<std::endl;
      for(i = start; i != end; i++)
      {
          std::cout<<*i<<" ";
      }
      std::cout<<std::endl;
       */
  
  
 
}

template <typename RandomAccessIterator, typename LessThan>
inline void HeapSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
  // Adicione el código de Heap Sort, use std::make_heap y std::pop_heap.
  RandomAccessIterator i;
  std::make_heap( start, end );
  
  for( i = end-1; i != start; i-- )
  {
      std::pop_heap( start ,i );
  }
  
}


template<typename RandomAccessIterator >
void print(RandomAccessIterator start,RandomAccessIterator end){
    for(auto i = start ; i != end ; i++ ){
        std::cout << *i <<  " "; 
    }
    std::cout << std::endl;
}



template <typename RandomAccessIterator>
void Merge(RandomAccessIterator start,RandomAccessIterator end)
{    
    RandomAccessIterator mid = (end - start)/2 + start; 
    RandomAccessIterator i = start,j = mid+1;
    
    int k = 0;
    
    std::vector< typename RandomAccessIterator::value_type > a(end-start);
    
    while( start+k != end )
    {     
        //print(start,end);
        if( j >= end-1 )a[k++] = *(i++);        
        else if( i >= mid )a[k++] = *(j++);
        
        else if( start <= i && i < mid && mid <= j && j < end  )
        {
            if( *i <= *j )
                a[k++] = *(i++);                            
            else 
                a[k++] = *(j++);                        
        }                  
      
    }
    
}


template <typename RandomAccessIterator, typename LessThan>
inline void MergeSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
  // Adicione el código de Merge Sort.
  if( end - start > 1 ){
      RandomAccessIterator mid = start + (end - start)/2;  
      MergeSort(start, mid);
      MergeSort(mid + 1, end);
      Merge(start,end);   
  }
      
}




template<typename RandomAccessIterator>
void IterativeMerge(RandomAccessIterator l,RandomAccessIterator m,RandomAccessIterator r)
{
    
     std::vector<typename RandomAccessIterator::value_type> a(r-l);    
    
    RandomAccessIterator mid = m;
    RandomAccessIterator i = l;
    RandomAccessIterator j = m + 1;
    int k=0;
    while( l+k != r )
    {     
        //print(start,end);
        if( j >= r-1 )a[k++] = *(i++);        
        else if( i >= mid )a[k++] = *(j++);
        
        else if( l <= i && i < mid && mid <= j && j < r  )
        {
            if( *i <= *j )
                a[k++] = *(i++);                            
            else 
                a[k++] = *(j++);                        
        }                  
    }
}

template <typename RandomAccessIterator, typename LessThan>
inline void IterativeMergeSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
  // Adicione el código de Merge Sort.
  
  
  int cs;
  int ls;
  int n = end - start;
  
  for( cs = 1; cs <= n-1; cs = 2*cs )
  {
      for( ls = 0; ls < n-1; ls += 2*cs )
      {
          int mid = ls + cs -1;
          int re  = std::min( ls+2*cs-1, n-1 );        
          IterativeMerge(start + ls,start + mid, start + re);
      }      
  } 
   
  
 
}



template<typename RandomAccessIterator>
RandomAccessIterator LomutoPartition(RandomAccessIterator start,RandomAccessIterator end)
{
    
    typename RandomAccessIterator::value_type pivot = *end;
    RandomAccessIterator i = start - 1;
    
    for(RandomAccessIterator j=start;j<=end-1;j++){
        if(*j <= pivot)
        {
            std::swap(*(++i),*j);           
        }
    }
    
    std::swap(*(i+1),*end);
    return (i+1);

}

    
template <typename RandomAccessIterator, typename LessThan>
inline void LomutoQuickSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
  // Adicione el código de Quick Sort de Lomuto.
  
  if( start < end ){
      RandomAccessIterator p = LomutoPartition(start,end);
      LomutoQuickSort(start,p-1);
      LomutoQuickSort(p+1,end);    
  }
 
}



template<typename RandomAccessIterator>
RandomAccessIterator HoarePartition(RandomAccessIterator start,RandomAccessIterator end)
{
    
    
    typename RandomAccessIterator::value_type pivot = *start;
    RandomAccessIterator i = start - 1;
    RandomAccessIterator j = end + 1;
    
    while(true)
    {
        do{
            i++;
        }while( *i < pivot );
                
        do{
            j--;
        }while( *j > pivot );
            
        if( i >= j)
        {
            return j;            
        }
        std::swap(*i,*j);       
    }
     
}



template <typename RandomAccessIterator, typename LessThan>
inline void HoareQuickSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
  // Adicione el código de Quick Sort de Hoare.
    
  if( start >= end )
  {
      return;
  }
  RandomAccessIterator p = HoarePartition(start,end);
  HoareQuickSort(start,p);
  HoareQuickSort(p+1,end);
   
}




template <typename RandomAccessIterator, typename LessThan>
inline void YaroslavskiyQuickSort(RandomAccessIterator start, RandomAccessIterator end, LessThan &lessThan) {
  // Adicione el código de Quick Sort con doble pivot y corte a insertion sort con pocos elementos.
}

int main(int argc, char** argv) {
  typedef void (*SORT_ALGORITHM)(std::vector<int>::iterator, std::vector<int>::iterator);
  //for ( auto & i : {100}){
  for ( auto & i : {100,1000,10000,100000,1000000,10000000,100000000}){
    std::vector<int> w(i),v;
    std::iota(w.begin(), w.end(), 1);
    for(auto a = w.begin(), _a = w.begin()+i/100; a < w.end(); _a += i/100)
    {
      std::shuffle (a, _a, std::default_random_engine(std::time(0)));
      a = _a;
    }
    // retire el comentario para estudiar datos completamente desordenados:
    std::shuffle (w.begin(), w.end(), std::default_random_engine(std::time(0)));
    std::vector<SORT_ALGORITHM> sort_algorithms = {InsertSort,  SelectSort, StableSelectSort, HeapSort, MergeSort, IterativeMergeSort, LomutoQuickSort, HoareQuickSort };
    
    if ( i > 100000 && i < 100000000)
    {
      sort_algorithms = {HeapSort, MergeSort, IterativeMergeSort, LomutoQuickSort, HoareQuickSort };
      std::cout << "-, -, -, ";
    }
    if (i == 100000000)
    {
      sort_algorithms = {IterativeMergeSort, LomutoQuickSort, HoareQuickSort };
      std::cout << "-, -, -, -, -, ";
    }
    for ( auto & sort_algorithm : sort_algorithms){
      v=w;
      std::clock_t inicio = std::clock();
      sort_algorithm(v.begin(),v.end());
      std::cout << 1000.0 * (double)(std::clock()-inicio)/(double)CLOCKS_PER_SEC << ", " << std::flush;
    }
    std::cout << std::endl;
    
  }
  return 0;
}
