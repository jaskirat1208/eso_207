#include <iostream>
using namespace std;
void traverse_seg_tree(long long int i,long long int j, long long int start,long long int end, long long int a, long long int d ){
	if(i==start && j==end){
		// cout<<start<<" "<<end;
		// return 0;
	}	
	// cout<<start<<" "<<end;
	int size_of_zero=(end-start+2)/3;
	int size_of_one=(end-start+1)/3;
	int size_of_two=(end-start)/3;
	cout<<size_of_two<<size_of_one<<size_of_zero;
	if (start+size_of_two>i)																					//i is in first segment
	{
		cout<<"i is in first segment"<<" ";
		if (start + size_of_two > j)																				//j is in first segment
		{
			cout<<"j is in 2 segment"<<endl;
			// traverse_seg_tree(i,j,start,start+size_of_two,a,d*3);	
		}
		if (start + size_of_two < j && start + size_of_two + size_of_one > j)  										//j is in second segment
		{
			cout<<"j is in 2 segment"<<endl;
			// traverse_seg_tree(i,start+size_of_two,start,start+size_of_two,a,d*3);
			// traverse_seg_tree(start+size_of_two,j,start+size_of_two,start+size_of_one,a,d*3);	
		}
		if (start + size_of_two +size_of_one + size_of_zero < j && start + size_of_two + size_of_one > j)			//j is in third segment
		{
			cout<<"j is in 2 segment"<<endl;
			// traverse_seg_tree(i,start+size_of_two,start,start+size_of_two,a,d*3);
			// traverse_seg_tree(start+size_of_two, start+size_of_two+size_of_one, start, start+size_of_two, a, d*3);
			// traverse_seg_tree(start+size_of_two+size_of_one, j, start+size_of_two+size_of_one, end, a, 3*d);	
		}
	}
	if(start+size_of_two <= i && start+size_of_two+size_of_one > i)
	{
		cout<<"i is in 2 segment"<<endl;
		if(start+size_of_two+size_of_one <= j && start+size_of_two > j)												//j is in second segment
		{
			cout<<"j is in 2 segment"<<endl;
			// traverse_seg_tree(i,j,start+size_of_two,start+size_of_two+size_of_one,a,d*3);	
		}
		if (start + size_of_two +size_of_one + size_of_zero <= j && start + size_of_two + size_of_one > j)			//j is in third segment
		{
			cout<<"j is in 3 segment"<<endl;
			// traverse_seg_tree(i,start+size_of_two+size_of_one,start+size_of_two,start+size_of_two+size_of_one,a,d*3);	
			// traverse_seg_tree(start+size_of_two+size_of_one,j,start+size_of_two+size_of_one,end);
		}
	}
	if (start+size_of_two+size_of_one <= i && i <end)
	{
		cout<<"i is in 3 segment"<<endl;
		// traverse_seg_tree(i,j,start+size_of_two+size_of_one,a,)
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	traverse_seg_tree(3,8,0,n,0,0);
	return 0;
}