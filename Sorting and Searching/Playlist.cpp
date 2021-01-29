#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> arr(n);
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	ll i=0,j=0,maxLen=1,currLen=0;
	map<int,int> freq;
	while(j<n){
		if(freq.find(arr[j])==freq.end() || freq[arr[j]]==0){
			freq[arr[j]]++;
			currLen++;
			maxLen=max(maxLen,currLen);
			j++;
		}
		else{
			currLen--;
			freq[arr[i]]--;
			i++;
		}
	}
	cout<<maxLen<<endl;
	return 0;
}
