#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
	ll n;
	cin>>n;
	if(n==2 or n==3){
		cout<<"NO SOLUTION"<<endl;
		return 0;
	}
	vector<ll> val(n);
	ll index=0;
	if(n%2==1){
		for(ll i=n;i>=1;i=i-2){
			val[index]=i;
			index++;
		}
		for(ll i=n-1;i>=2;i=i-2){
			val[index]=i;
			index++;
		}
	}
	else{
		for(ll i=n-1;i>=1;i=i-2){
			val[index]=i;
			index++;
		}
		for(ll i=n;i>=2;i=i-2){
			val[index]=i;
			index++;
		}
	}
	for(ll it:val){
		cout<<it<<" ";
	}
	cout<<endl;
	return 0;
}
