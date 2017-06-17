#include<iostream>
#include<algorithm>
#include<time.h>

using namespace std;
#define N 100000000
#define scale 1000
// 1000 10000 100000 1000000 10000000 100000000 1000000000s
int p[N];	
int a[N];

void merge(int,int, int*,bool (*)(int,int));

bool  Less(int a,int b){return a<b;}
bool Greater(int a,int b){return a>b;}
bool (*pf)(int,int);

void merge_sort( int ini,int fin, int* A,bool (*f)(int,int) ){
	if( ini == fin ) return;
	int mid = (ini+fin)/2;
	merge_sort( ini,mid,A,f);
	merge_sort( mid+1,fin,A,f);
	merge( ini,fin, A , f);
}
void merge(int ini,int fin,int* arr,bool (*f)(int,int)){
	int i = ini;
	int mid = (ini + fin )/2;
	int j = mid + 1;
	int k = ini;
	
	while(  ini <= k && k<= fin ){
		if( j > fin )p[k++] = arr[i++];			
		if( i > mid )p[k++] = arr[j++];
		if( ini<=i && i<=mid && mid+1<=j && j<=fin ){			
			
			if( f(arr[i],arr[j]) ){// arr[i] <= arr[j]
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
	 	//cout << a[i] << " ";
	 	cout << "(" << i << "," << a[i] << ")" << " ";
	}
	cout << endl;
}

int main(){


		for (int i = 0; i < N; ++i){a[i] = N-i-1;}
	  //random_shuffle(a,a+N);

		//print(a,N);

		const clock_t begin_time = clock();

		merge_sort( 0 , N-1 , a , &Less);

		//p += float( (clock () - begin_time )*scale ) /  CLOCKS_PER_SEC;
		cout << float( (clock() - begin_time)*scale ) /  CLOCKS_PER_SEC << endl;

		//print(a,N);
		


	/*
	0.37
  2.813
  22.03
  203.586
  2268
  26271.7
	

	*/

	return 0;
}