#include<iostream>
#include<algorithm>
#include<time.h>

using namespace std;
#define N 100000000
#define scale 1000

// 1000 10000 100000 1000000 10000000 100000000 1000000000
int p[N];	
int a[N];
void merge(int,int, int*);
void merge_sort( int ini,int fin, int* A){
	if( ini == fin ) return;
	int mid = (ini+fin)/2;
	merge_sort( ini,mid,A);
	merge_sort( mid+1,fin,A );
	merge( ini,fin, A );
}
void merge(int ini,int fin,int* arr){
	int i = ini;
	int mid = (ini + fin )/2;
	int j = mid + 1;
	int k = ini;
	while(  ini <= k && k<= fin ){
		if( j > fin )p[k++] = arr[i++];			
		if( i > mid )p[k++] = arr[j++];
		if( ini<=i && i<=mid && mid+1<=j && j<=fin ){			
			if( arr[i] <= arr[j] ){
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
		//print(a,N);
		const clock_t begin_time = clock();
		merge_sort( 0 , N-1 , a );
		
		cout << float( (clock () - begin_time )*scale ) /  CLOCKS_PER_SEC << endl;


	// 1) 1000 - 0.14422
	// 2) 10000
	
	return 0;
}

// 1000 - 0.002
// 10000 - 1.92227
// 100000 - 24.1373
// 1000000 - 325.303
// 10000000 - 3544.27
// 100000000 - 39942.8


// retesteo 
/*
0.241
2.398
32.945
165.403
1886.97
21280.8


*/