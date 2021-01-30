#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
const static bool compare(pair<ll,ll> a,pair<ll,ll> b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	return a.second<b.second;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,k;
	cin>>n>>k;
	vector<pair<ll,ll>> val(n);
	for(ll i=0;i<n;i++){
		cin>>val[i].first>>val[i].second;
	}
	sort(val.begin(),val.end(),compare);
	int count=0;
	multiset<ll> s;
	for(ll i=0;i<n;i++){
		bool flag=false;
		if(!s.empty()){
			auto it=s.upper_bound(val[i].first);
			if(it!=s.begin()){
				it--;
				if(*it<=val[i].first){
					s.erase(it);
					s.insert(val[i].second);
					count++;
					flag=true;
				}
			}
		}
		if((ll)s.size()<k && flag==false){
			s.insert(val[i].second);
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}
