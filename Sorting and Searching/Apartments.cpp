#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,m,diff;
	cin>>n>>m>>diff;
	vector<ll> desired(n);
	for(ll &it:desired){
		cin>>it;
	}
	vector<ll> actual(m);
	for(ll &it:actual){
		cin>>it;
	}
	sort(desired.begin(),desired.end());
	sort(actual.begin(),actual.end());
	ll i=0;
	ll j=0;
	int ans=0;
	while(i<n && j<m){
		if(abs(desired[i]-actual[j])<=diff){
			ans++;
			i++;
			j++;
		}
		else if(desired[i]<actual[j]){
			i++;
		}
		else{
			j++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
