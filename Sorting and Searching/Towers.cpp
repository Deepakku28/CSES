#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	multiset<ll> s;
	for(ll i=0;i<n;i++){
		ll val;
		cin>>val;
		auto it=s.upper_bound(val);
		if(it!=s.end()){
			s.erase(it);
		}
		s.insert(val);
	}
	cout<<s.size()<<endl;
	return 0;
}
