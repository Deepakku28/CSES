#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ll n;
	cin>>n;
	ll count=0;
	ll divisor=5;
	while(n/divisor>=1){
		count+=n/divisor;
		divisor*=5;
	}
	cout<<count<<endl;
	return 0;
}
