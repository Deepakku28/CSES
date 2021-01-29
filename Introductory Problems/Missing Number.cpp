#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
	ll n;
	cin>>n;
	vector<ll> val(n-1);
	ll sum=0;
	for(ll &it:val){
		cin>>it;
		sum+=it;
	}
	cout<<((n*(n+1)/2)-sum)<<endl;
	return 0;
}
