#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	ll n;
	cin>>n;
	ll ans=1;
	while(n){
	    ans=((((ans)%1000000007)*2)%1000000007);
	    n--;
	}
	cout<<ans<<endl;
	return 0;
}
