#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;

#define N 100000000
#define scale 1000
// 1000 10000 100000 1000000 10000000 100000000 1000000000s
int p[N];	
int a[N];

class comparator{
    public:
    virtual bool comp(int a,int b)=0;
};
class cless:public comparator{
    public:
    bool comp(int a,int b){
        return a<b;
    }
};
class cgreater:public comparator{
    public:
    bool comp(int a,int b){
        return a>b;
    }
};
void merge(int ini,int fin,int* arr,comparator* cmp){

	int i = ini;
	int mid = (ini + fin )/2;
	int j = mid + 1;
	int k = ini;
	
	while(  ini <= k && k<= fin ){
		if( j > fin )p[k++] = arr[i++];			
		if( i > mid )p[k++] = arr[j++];
		if( ini<=i && i<=mid && mid+1<=j && j<=fin ){			
			if( cmp->comp(arr[i],arr[j]) ){
				p[k++] = arr[i++];	
			}
			else{
				p[k++] = arr[j++];
			}									
		}		  
	}
	for( int i=ini;i<=fin;i++ ){
		arr[i]=p[i];
	}
}
void merge_sort( int ini,int fin, int* A, comparator* cmp){
	if( ini == fin ) return;
	int mid = (ini+fin)/2;
	merge_sort( ini,mid,A,cmp);
	merge_sort( mid+1,fin,A,cmp);
	merge( ini,fin, A,cmp);
}
void print(int *a, int Nsize){
	for (int i = 0; i < Nsize; ++i)
	{
	 	cout << a[i] << " ";
	}
	cout << endl;
}


int main(){


		for (int i = 0; i < N; ++i){a[i] = i;}
	  random_shuffle(a,a+N);
		const clock_t begin_time = clock();
		cless* minorobject = new cless();
	  cgreater* mayorobject = new cgreater();  
		merge_sort( 0 , N-1 , a , mayorobject);
		cout << float( (clock () - begin_time)*scale ) /  CLOCKS_PER_SEC << endl;
		//print(a,N);

/*

0.191
5.625
30.722
332.657
3936.78
45359.8


*/

	return 0;
}

