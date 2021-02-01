#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll inf=1e18;

struct segment{
	ll x;
}st[1<<19];

void buildSegmentTree(ll val,ll i,ll index,ll left,ll right){
	if(left==right){
		st[index].x=val;
		return;
	}
	ll mid=(left+right)/2;
	if(i<=mid){
		buildSegmentTree(val,i,2*index,left,mid);
	}
	else{
		buildSegmentTree(val,i,2*index+1,mid+1,right);
	}
	st[index].x=(st[2*index].x^st[2*index+1].x);
}

ll xorVal(ll a,ll b,ll index,ll left,ll right){
	if(a<=left && right<=b){
		return st[index].x;
	}
	ll mid=(left+right)/2;
	return ((a<=mid?xorVal(a,b,2*index,left,mid):0)^(mid<b?xorVal(a,b,2*index+1,mid+1,right):0));
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
		ll a,b;
		cin>>a>>b;
		a--,b--;
		cout<<xorVal(a,b,1,0,n-1)<<endl;
	}
	return 0;
}
