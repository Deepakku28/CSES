#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 int main(){
	 ios_base::sync_with_stdio(0);
	 cin.tie(0);
	 ll n,target;
	 cin>>n>>target;
	 vector<ll> val(n);
	 for(ll &it:val){
		 cin>>it;
	 }
	 sort(val.begin(),val.end());
	 ll start=0;
	 ll end=n-1;
	 ll ans=0;
	 while(start<=end){
		 int weight=val[start]+val[end];
		 if(weight<=target){
			 ans++;
			 start++;
			 end--;
		 }
		 else{
			 end--;
			 ans++;
		 }
	 }
	 cout<<ans<<endl;
	 return 0;
 }
