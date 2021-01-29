#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> val(n);
	for(ll &it:val){
		cin>>it;
	}
	ll globalMax=*max_element(val.begin(),val.end());
	if(globalMax<=0){
		cout<<globalMax<<endl;
		return 0;
	}
	ll currMax=0;
	for(ll i=0;i<n;i++){
		currMax+=val[i];
		if(currMax<0){
			currMax=0;
		}
		globalMax=max(globalMax,currMax);
	}
	cout<<globalMax<<endl;
	return 0;
}
