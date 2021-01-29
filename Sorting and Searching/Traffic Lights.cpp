#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll len,n;
	cin>>len>>n;
	vector<ll> val(n);
	for(ll &it:val){
		cin>>it;
	}
	multiset<ll> ms;
	ms.insert(len);
	set<ll> s;
	s.insert(0);
	s.insert(len);
	for(ll i=0;i<n;i++){
		auto it1=s.lower_bound(val[i]);
		auto it2=it1;
		--it2;
		ms.erase(ms.find(*it1 - *it2));
		ms.insert(val[i] - *it2);
		ms.insert(*it1 - val[i]);
		cout<<*--ms.end()<<" ";
		s.insert(val[i]);
	}
	return 0;
}
