#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
vector<int> two(vector<int> v){
	std::vector<int> v1;
	for(int i=2;i<v.size();i+=3){
		v1.push_back(v[i]);
	}
	return v1;
}
vector<int> one(vector<int> v){
	std::vector<int> v1;
	for(int i=1;i<v.size();i+=3){
		v1.push_back(v[i]);
	}
	return v1;
}
vector<int> zero(vector<int> v){
	std::vector<int> v1;
	for(int i=0;i<v.size();i+=3){
		v1.push_back(v[i]);
	}
	return v1;
}
vector<int> op(vector<int> v){
	if(v.size()==0 || v.size()==1)		return v;

	std::vector<int> v1,v2,v3,v0;
	v1=two(v);
	v2=one(v);
	v3=zero(v);
	v1=op(v1);
	v2=op(v2);
	v3=op(v3);
	// for(int i=0;i<v3.size();i++){
	// 	cout<<v3[i]<<" ";
	// }
	// cout<<v3.size()<<" ";
	for(int i=0;i < v1.size();i++){
		v0.push_back(v1[i]);
	}
	for(int i=0;i < v2.size();i++){
		v0.push_back(v2[i]);
	}
	for(int i=0;i < v3.size();i++){
		v0.push_back(v3[i]);
	}
	v=v0;
	return v;
}
int main(int argc, char const *argv[])	
{
	int n;
	cin>>n;
	// int *arr=(int*)calloc(n,sizeof(int));
	std::vector<int> v,v1,v2,v3;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}	
	v=op(v);
	for(int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
	// v1=two(v);
	// v2=one(v);
	// v3=zero(v);
	
	return 0;
}