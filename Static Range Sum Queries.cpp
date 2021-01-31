#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
void buildSegmentTree(vector<ll> &segmentTree,vector<ll> &val,ll index,ll start,ll end){
	if(start==end){
		segmentTree[index]=val[start];
		return ;
	}
	ll mid=(start+end)/2;
	buildSegmentTree(segmentTree,val,2*index,start,mid);
	buildSegmentTree(segmentTree,val,2*index+1,mid+1,end);
	segmentTree[index]=segmentTree[2*index]+segmentTree[2*index+1];
}
 
ll sum(vector<ll> &segmentTree,ll index,ll start,ll end,ll left,ll right){
	if(left>right){
		return 0;
	}
	if(left==start && right==end){
		return segmentTree[index];
	}
	ll mid=(start+end)/2;
	return sum(segmentTree,2*index,start,mid,left,min(right,mid))+
				sum(segmentTree,2*index+1,mid+1,end,max(left,mid+1),right);
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,q;
	cin>>n>>q;
	vector<ll> val(n+1);
	for(ll i=1;i<=n;i++){
		cin>>val[i];
	}
	vector<ll> segmentTree(1<<19);
	buildSegmentTree(segmentTree,val,1,1,n);
	for(ll i=0;i<q;i++){
		ll a,b;
		cin>>a>>b;
		cout<<sum(segmentTree,1,1,n,a,b)<<endl;
	}
	return 0;
}
