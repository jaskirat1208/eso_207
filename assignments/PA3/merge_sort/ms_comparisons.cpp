#include <iostream>
#include <ctime>
using namespace std;
long long int comparisons;
void merge(int arr[], int l, int m, int r)
{
    /* create temp arrays */
    int x=m-l+1;
    int y=r-m;
    int L[m-l+1], R[r-m];
 
    /* Copy data to temp arrays  */
    for (int i = 0; i < x; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < y; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    int i,j,k;
    i = 0; 
    j = 0; 
    k = l;
    while (i < x && j < y)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
        comparisons++;
    }
 
    /* Copy the remaining elements */
    while (i < x)
    {
        comparisons++;
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < y)
    {
        comparisons++;
        arr[k] = R[j];
        j++;
        k++;
    }
}


void ms(int arr[],int l,int r){
	if (l < r)
    {
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        ms(arr, l, m);
        ms(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

int main(int argc, char const *argv[])
{
	int repeat=1000;
	while(repeat--){
		comparisons=0;
		int n=10000;
		int arr[n];
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			arr[i]=x;
		}
		ms(arr,0,n);
		cout<<comparisons<<endl;
	}	
	// for(int i=0;i<100;i++)	cout<<arr[i]<<endl;
	return 0;
}