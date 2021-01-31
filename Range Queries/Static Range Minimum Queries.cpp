#include<bits/stdc++.h>
using namespace std;
 
void buildSegmentTree(int &ind,vector<int> &segmentTree,int &value,int index,int start,int end){
	if(start==end){
		segmentTree[index]=value;
		return ;
	}
	int mid=(start+end)/2;
	if(ind<=mid){
		buildSegmentTree(ind,segmentTree,value,2*index,start,mid);
	}
	else{
		buildSegmentTree(ind,segmentTree,value,2*index+1,mid+1,end);
	}
	segmentTree[index]=min(segmentTree[2*index],segmentTree[2*index+1]);
}
 
int minVal(int &a,int &b,vector<int> &segmentTree,int index,int start,int end){
	if(a<=start && end<=b){
		return segmentTree[index];
	}
	int mid=(start+end)/2;
	return min(a<=mid?minVal(a,b,segmentTree,2*index,start,mid):(int)1e9
				,mid<b?minVal(a,b,segmentTree,2*index+1,mid+1,end):(int)1e9);
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	vector<int> segmentTree(4*n);
	for(int i=0;i<n;i++){
		int val;
		cin>>val;
		buildSegmentTree(i,segmentTree,val,1,0,n-1);
	}
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		cout<<minVal(a,b,segmentTree,1,0,n-1)<<endl;
	}
	return 0;
}
