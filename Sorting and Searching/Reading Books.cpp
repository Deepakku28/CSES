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
	ll sum=0;
	ll maxVal=val[0];
	for(ll it:val){
		sum+=it;
		maxVal=max(maxVal,it);
	}
	if(2*maxVal>sum){
		cout<<2*maxVal<<endl;
	}
	else{
		cout<<sum<<endl;
	}
	return 0;
}
