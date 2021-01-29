#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
void solution(string &str,int start,int end,map<string,int> &mp){
	if(start==end){
		mp[str]++;
		return ;
	}
	for(int i=start;i<=end;i++){
		swap(str[start],str[i]);
		solution(str,start+1,end,mp);
		swap(str[start],str[i]);
	}
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin>>str;
	int n=str.size();
	map<string,int> mp;
	solution(str,0,n-1,mp);
	cout<<mp.size()<<endl;
	for(auto it:mp){
		cout<<it.first<<endl;
	}
	return 0;
}
