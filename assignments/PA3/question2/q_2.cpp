#include <iostream>
#include <stdlib.h>
// #include <vector>
using namespace std;
void two(int* v,int size,int *v1){

	
	for(int i=2;i<size;i+=3){
		v1[i/3]=v[i];
		// cout<<v1[i]<<" ";
	}
	// return v1;
}
int *one(int* v,int size,int *v1){
	// int *v1=(int*)calloc((size+1)/3,sizeof(int));
	for(int i=1;i<size;i+=3){
		v1[i/3]=v[i];
		// cout<<v1[i]<<" ";
	}
	return v1;
}
int *zero(int* v,int size,int *v1){
	// int *v1=(int*)calloc((size+2)/3,sizeof(int));
	for(int i=0;i<size;i+=3){
		v1[i/3]=v[i];
		// cout<<v1[i]<<" ";
	}
	return v1;
}
int *op(int *v,int size){
	if(size==1 || size==0)	return v;
	int size_of_v1=size/3;
	int size_of_v2=(size+1)/3;
	int size_of_v3=(size+2)/3;
	int *v1=(int*)calloc(size/3,sizeof(int));
	int *v2=(int*)calloc((size+1)/3,sizeof(int));
	int *v3=(int*)calloc((size+2)/3,sizeof(int));
	two(v,size,v1);
	v2=one(v,size,v2);
	v3=zero(v,size,v3);
	v1=op(v1,size_of_v1);
	v2=op(v2,size_of_v2);
	v3=op(v3,size_of_v3);
	// for(int i=0;i<v3.size();i++){
	// 	cout<<v3[i]<<" ";
	// }
	// cout<<v3.size()<<" ";
	for(int i=0;i < size_of_v1;i++){
		v[i]=v1[i];
	}
	for(int i=0;i < size_of_v2;i++){
		v[i+size_of_v1]=v2[i];
	}
	for(int i=0;i < size_of_v3;i++){
		v[i+size_of_v2+size_of_v1]=v3[i];
	}
	
	return v;
}
int main(int argc, char const *argv[])	
{
	int n;
	cin>>n;
	int *v=(int*)calloc(n,sizeof(int));
	
	for(int i=0;i<n;i++){
		cin>>v[i];
	}	
	v=op(v,n);
	// for(int i=0;i<n;i++){
	// 	cout<<v[i]<<" ";
	// }
	// two(v,n);
	// one(v,n);
	// zero(v,n);
	long *sum_sub=(long int*)calloc(n,sizeof(long int));
	sum_sub[0]=v[0];
	for(int i=1;i<n;i++){
		sum_sub[i]=sum_sub[i-1]+v[i];
	}
	int q;
	cin>>q;
	while(q--){
		int i,j,l,r;
		cin>>i>>j>>l>>r;
		if(i!=0)
			cout<<sum_sub[j]-sum_sub[i-1]<<endl;
		if(i==0)	cout<<sum_sub[j]<<endl;
		
	}
	return 0;
}