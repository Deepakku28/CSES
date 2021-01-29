#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main(){
	ll n,m;
	cin>>n>>m;
	multiset<ll,greater<ll>> actual;
	for(ll i=0;i<n;i++){
		ll curr;
		cin>>curr;
		actual.insert(curr);
	}
	vector<ll> can(m);
	for(ll &it:can){
		cin>>it;
	}
	for(ll i=0;i<m;i++){
		auto it=actual.lower_bound(can[i]);
		if(it==actual.end()){
			cout<<-1<<endl;
		}
		else{
			cout<<*it<<endl;
			actual.erase(it);
		}
	}
	return 0;
}
