#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ll n;
	cin>>n;
	ll sum=n*(n+1)/2;
	if(sum%2==1){
		cout<<"NO"<<endl;
		return 0;
	}
	sum/=2;
	vector<ll> val1;
	vector<ll> val2;
	while(n){
		if(sum-n>=0){
			val1.push_back(n);
			sum=sum-n;
		}
		else{
			val2.push_back(n);
		}
		n--;
	}
	cout<<"YES"<<endl;
	cout<<val1.size()<<endl;
	for(ll it:val1){
		cout<<it<<" ";
	}
	cout<<endl;
	cout<<val2.size()<<endl;
	for(ll it:val2){
		cout<<it<<" ";
	}
	cout<<endl;
	return 0;
}
