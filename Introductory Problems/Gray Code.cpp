#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void helper(int &n){
	vector<string> val;
	val.push_back("0");
	val.push_back("1");
	for(int i=2;i<(1<<n);i=i<<1){
		for(int j=i-1;j>=0;j--){
			val.push_back(val[j]);
		}
		for(int j=0;j<i;j++){
            val[j]="0"+val[j];
		}
        for(int j=i;j<2*i;j++){
            val[j]="1"+val[j];
		}
	}
	for(auto it:val){
		cout<<it<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	helper(n);
	return 0;
}
