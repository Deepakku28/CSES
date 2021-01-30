#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> val(n);
	for(ll &it:val){
		cin>>it;
	}
	stack<ll> s;
	for(ll i=0;i<n;i++){
		while(!s.empty() && val[s.top()]>=val[i]){
			s.pop();
		}
		if(s.empty()){
			cout<<"0 ";
		}
		else{
			cout<<s.top()+1<<" ";
		}
		s.push(i);
	}
	return 0;
}
