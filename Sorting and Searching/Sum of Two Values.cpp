#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,target;
	cin>>n>>target;
	vector<pair<ll,ll>> val(n);
	for(ll i=0;i<n;i++){
		cin>>val[i].first;
		val[i].second=i+1;
	}
	sort(val.begin(),val.end());
	ll start=0;
	ll end=n-1;
	while(start<end){
		ll sum=val[start].first+val[end].first;
		if(sum==target){
			cout<<min(val[start].second,val[end].second)<<" "<<max(val[start].second,val[end].second);
			return 0;
		}
		else if(sum<target){
			start++;
		}
		else{
			end--;
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
