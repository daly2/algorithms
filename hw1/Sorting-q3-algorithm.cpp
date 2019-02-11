#include <iostream>
using namespace std;
#include <stdlib.h>

int *initializeArray( int N)
{
    //Initialize array of length N with radom values
    int *array = new int[N];
    for ( int i=0; i<N;++i) array[i]=rand()%100;
    return array;
}
void printArray(int *arr, int N)
{
    for ( int i=0; i<N; ++i) cout << " " << arr[i];
    cout << endl;
}
int findx(int N)
{
    int x = rand()%(N-1);
    return x;
}
int smallerthan(int x, int *arr, int N)
{
    int smaller = 0;
    for ( int i =0; i<N; ++i)
    {
        if(arr[i]<arr[x])
        {
            smaller++;
        }
    }
    return smaller;
}
int *copy(int *array, int N, int x, int smaller)
{
    int *arr2= new int[N];
    arr2[smaller] = array[x];
    int less=0;
    int more=smaller+1;
    for(int i =0; i<N; i++)
    {
        if(array[i]<array[x])
        {
            arr2[less]=array[i];
            less++;
        }
        else if( array[i]>=array[x]&&x!=i)
        {
            arr2[more]=array[i];
            more++;
        }
    }
    //printArray(arr2, N);
    delete [] array;
    return arr2;
}
bool check(int *array, int N)
{
    for( int i=0; i<N-1; i++)
    {
        if(array[i]>array[i+1])
        {
            return false;
        }
    }
    return true;
}
int *sortArray(int *array, int N)
{
    bool sorted =false;
    while( !sorted )
    {
        int x = findx(N);
        int smaller=smallerthan(x, array, N);
        array=copy(array, N, x, smaller);
        sorted = check(array, N);
    }
    return array;
}
int main()
{
    const int N = 10;
    const bool verbose = true;
    int *array= initializeArray(N);
    if ( verbose ) { cout << "input:"; printArray(array, N); }
    array=sortArray(array, N);
    if ( verbose ) { cout<< "Sorted:"; printArray(array,N); }
    delete [] array;
}