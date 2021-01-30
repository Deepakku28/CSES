#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,k;
	cin>>n>>k;
	vector<ll> val(n);
	for(auto &it:val){
		cin>>it;
	}
	multiset<ll> s(val.begin(),val.begin()+k);
	auto it=next(s.begin(),k/2);
	for(int i=k;i<=n;i++){
		if(k&1){
			cout<<*it<<endl;
		}
		else{
			cout<<*prev(it,1)<<endl;
		}
		s.insert(val[i]);
		if(val[i]<*it){
			it--;
		}
		if(val[i-k]<=*it){
			it++;
		}
		s.erase(s.lower_bound(val[i-k]));
	}
	return 0;
}
