#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> dp;
	for(int i=0;i<n;i++){
		int val;
		cin>>val;
		auto it=lower_bound(dp.begin(),dp.end(),val);
		if(it==dp.end()){
			dp.push_back(val);
		}
		else{
			*it=val;
		}
	}
	cout<<(ll)dp.size()<<endl;
	return 0;
}
