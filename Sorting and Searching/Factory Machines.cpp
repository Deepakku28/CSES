#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
ll solution(vector<ll> &val,ll &target,ll &minVal,ll &n){
	ll start=0;
	ll end=target*minVal+1;
	ll ans=0;
	while(start<=end){
		ll mid=start+(end-start)/2;
		ll sum=0;
		for(auto it:val){
			sum+=mid/it;
		}
		if(sum>=target){
			ans=mid;
			end=mid-1;
		}
		else{
			start=mid+1;
		}
	}
	return ans;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,target;
	cin>>n>>target;
	vector<ll> val(n);
	for(auto &it:val){
		cin>>it;
	}
	//sort(val.begin(),val.end());
	ll minVal=*min_element(val.begin(),val.end());
	cout<<solution(val,target,minVal,n)<<endl;
	return 0;
}
