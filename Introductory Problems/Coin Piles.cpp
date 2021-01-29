#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ll T;
	cin>>T;
	while(T--){
		ll a,b;
		cin>>a>>b;
		if((a+b)%3==0 && min(a,b)*2>=max(a,b)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
