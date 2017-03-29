#include <iostream>
// #include <chrono>
 using namespace std;
 long long int comparisons;
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 

int partition (int* arr, int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        comparisons++;
        if (arr[j] <= pivot)
        {
            i++;    
            swap(arr+i, arr+j);
            
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
 
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
/* Function to print an array */
void printArray(int *arr, int size)
{
    int i;
    for (i=0; i < size; i++)
       cout<<arr[i]<<" ";
    
}
 
// Driver program to test above functions
int main()
{
    
    int repeat=1000;
    // std::chrono::time_point<std::chrono::system_clock> start, end;
    while(repeat--){
        comparisons=0;
        int n=10000;
        int arr[n];
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr[i]=x;
        }
        // start = std::chrono::system_clock::now();
        quickSort(arr,0,n);
        // end = std::chrono::system_clock::now();
        // std::chrono::duration<double> elapsed_seconds = end-start;
        // std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        // cout<< elapsed_seconds.count()<<endl;
        cout<<comparisons<<endl;
    }   
    return 0;
}