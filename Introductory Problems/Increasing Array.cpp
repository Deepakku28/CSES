#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
	ll n;
	cin>>n;
	vector<ll> val(n);
	for(ll &it:val){
		cin>>it;
	}
	ll minTurn=0;
	ll currMax=0;
	for(ll i=0;i<n;i++){
		currMax=max(currMax,val[i]);
		minTurn+=currMax-val[i];
	}
	cout<<minTurn<<endl;
	return 0;
}
