#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> arr(n);
	vector<ll> dept(n);
	for(ll i=0;i<n;i++){
		cin>>arr[i]>>dept[i];
	}
	sort(arr.begin(),arr.end());
	sort(dept.begin(),dept.end());
	ll i=0;
	ll j=0;
	ll ans=1;
	ll count=0;
	while(i<n && j<n){
		if(arr[i]<dept[j]){
			i++;
			count++;
		}
		else if(arr[i]>dept[j]){
			j++;
			count--;
		}
		else{
			i++;
			j--;
		}
		ans=max(ans,count);
	}
	cout<<ans<<endl;
	return 0;
}
