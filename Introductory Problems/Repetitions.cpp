#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
	string str;
	cin>>str;
	ll maxLen=1;
	ll currLen=1;
	for(ll i=1;i<(ll)str.size();i++){
		if(str[i]==str[i-1]){
			currLen++;
		}
		else{
			currLen=1;
		}
		maxLen=max(currLen,maxLen);
	}
	cout<<maxLen<<endl;
	return 0;
}
