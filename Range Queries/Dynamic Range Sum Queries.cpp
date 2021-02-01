#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
struct segment{
	ll s;
}st[1<<19];
 
void buildSegmentTree(ll val,ll i,ll index,ll left,ll right){
	if(left==right){
		st[index].s=val;
		return;
	}
	ll mid=(left+right)/2;
	if(i<=mid){
		buildSegmentTree(val,i,2*index,left,mid);
	}
	else{
		buildSegmentTree(val,i,2*index+1,mid+1,right);
	}
	st[index].s=st[2*index].s+st[2*index+1].s;
}
 
ll sum(ll a,ll b,ll index,ll left,ll right){
	if(a<=left && right<=b){
		return st[index].s;
	}
	ll mid=(left+right)/2;
	return ((a<=mid?sum(a,b,2*index,left,mid):0)+(mid<b?sum(a,b,2*index+1,mid+1,right):0));
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,q;
	cin>>n>>q;
	for(ll i=0;i<n;i++){
		ll val;
		cin>>val;
		buildSegmentTree(val,i,1,0,n-1);
	}
	for(ll i=0;i<q;i++){
		ll q,a,b;
		cin>>q>>a>>b;
		a--,b--;
		if(q==1){
			buildSegmentTree(b+1,a,1,0,n-1);
		}
		if(q==2){
			cout<<sum(a,b,1,0,n-1)<<endl;
		}
	}
	return 0;
}
