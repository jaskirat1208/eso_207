#include <iostream>
using namespace std;
void traverse_seg_tree(long long int i,long long int j, long long int start,long long int end, long long int a, long long int d ){
	if(i==start && j==end){
		cout<<start<<" "<<end<<endl;
		return ;
	}	
	// cout<<start<<" "<<end;
	int size_of_zero=(end-start+2)/3;
	int size_of_one=(end-start+1)/3;
	int size_of_two=(end-start)/3;
	// cout<<size_of_two<<size_of_one<<size_of_zero;
	if (i>=start && i <= start+size_of_two-1)//i is in first segment
	{
		cout<<"i in first";
		if(j>=start && j < start+size_of_two-1){
			cout<<"j in first";
			traverse_seg_tree(i,j,start,start+size_of_two-1,0,0);
		}
		else if(j >=start+size_of_two && j <= start+size_of_two+size_of_one-1)
		{
			cout<<"j in sec";
			traverse_seg_tree(i,start+size_of_two-1,start,start+size_of_two-1,0,0);
			traverse_seg_tree(start+size_of_two,j,start+size_of_two,start+size_of_two+size_of_one-1,0,0);
		}
		else if (j >=start+size_of_two+size_of_one && j <=end - 1 )
		{
			cout<<"j in third";
			traverse_seg_tree(i,start+size_of_two-1,start,start+size_of_two-1,0,0);
			traverse_seg_tree(start+size_of_two,start+size_of_two+size_of_one-1,start+size_of_two,start+size_of_two+size_of_one-1,0,0);
			traverse_seg_tree(start+size_of_two+size_of_one,j,start+size_of_two+size_of_one,end -1 ,0,0);	
		}
	}
	// i is in second segment
	if (i >=start+size_of_two && i <= start+size_of_two+size_of_one-1)
	{
		cout<<"i in second";
		if(j >=start+size_of_two && j <= start+size_of_two+size_of_one-1)
		{
			cout<<"j in sec";
			traverse_seg_tree(i,j,start+size_of_two,start+size_of_two+size_of_one-1,0,0);
		}
		else if (j >=start+size_of_two+size_of_one && j <=end - 1 )
		{
			cout<<"j in third";
			traverse_seg_tree(i, start+size_of_two+size_of_one-1, start+size_of_two, start+size_of_two+size_of_one-1, 0, 0);	
			traverse_seg_tree(start+size_of_two+size_of_one, j, start+size_of_two+size_of_one, end-1, 0, 0);	
		
		}

	}
	// i in third segment
	if (i >=start+size_of_two+size_of_one && i <=end-1)
	{
		cout<<"both in third";	
		traverse_seg_tree(i,j, start+size_of_two+size_of_one,end - 1, 0,0);
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int i,j;

	traverse_seg_tree(i,j,0,n-1,0,1);
	return 0;
}