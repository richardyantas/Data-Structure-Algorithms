#include<iostream>
#include<algorithm>
#include<time.h>

using namespace std;
#define N 100000000
#define scale 1000

// 1000 10000 100000 1000000 10000000 100000000 1000000000s
int p[N];	
int a[N];

void merge(int,int, int*);

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

template<class FunctorType>
void merge(int ini,int fin,int* arr){
	FunctorType objFunctor;
	int i = ini;
	int mid = (ini + fin )/2;
	int j = mid + 1;
	int k = ini;	
	while(  ini <= k && k<= fin ){
		if( j > fin )p[k++] = arr[i++];			
		if( i > mid )p[k++] = arr[j++];
		if( ini<=i && i<=mid && mid+1<=j && j<=fin ){
			if( objFunctor( arr[i] , arr[j] ) ) {
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

template<class FunctorType>
void merge_sort( int ini,int fin, int* A){
	
	if( ini == fin ) return;
	int mid = (ini+fin)/2;
	merge_sort<FunctorType>( ini,mid,A);
	merge_sort<FunctorType>( mid+1,fin,A );
	merge<FunctorType>( ini,fin, A );
}

void print(int *a,int Ns){
	for (int i = 0; i < Ns; ++i)
	{
	 	cout << "(" << i << "," << a[i] << ")" << " ";
	}
	cout << endl;
}

int main(){
	
		for (int i = 0; i < N; ++i){a[i] = N-i-1;}
	  //random_shuffle(a,a+N);
		const clock_t begin_time = clock();

		merge_sort< lesS<int> > ( 0 , N-1, a );
		cout << float( (clock () - begin_time)*scale ) /  CLOCKS_PER_SEC<< endl;		
		//print(a,N);


/*

0.255
2.133
20.749
198.599
2318.75
26493.3




*/
	return 0;
}




