#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
ll solution(ll &x,ll &y){
	if(x==1 && y==1){
		return 1;
	}
	if(x==y){
		return (x*x)-x+1;
	}
	if(x>y){
		ll val=(x*x)-x+1;
		if(x%2==0){
			return val+(x-y);
		}
		return val-(x-y);
	}
	else{
		ll val=(y*y)-y+1;
		if(y%2==0){
			return val+(x-y);
		}
		return val-(x-y);
	}
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll T;
	cin>>T;
	while(T--){
		ll x,y;
		cin>>x>>y;
		cout<<solution(x,y)<<endl;
	}
	return 0;
}
