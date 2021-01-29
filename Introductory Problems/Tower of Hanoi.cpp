#include<bits/stdc++.h>
using namespace std;
 
void toh(int n,int from,int to,int aux,vector<string> &ans){
    if(n<=0){
        return ;
    }
    toh(n-1,from,aux,to,ans);
    ans.push_back(to_string(from)+" "+to_string(to));
    toh(n-1,aux,to,from,ans);
}
 
int  main() {
    int n;
    cin>>n;
    vector<string> ans;
    toh(n, 1, 3, 2,ans);
    cout<<(int)ans.size()<<endl;
    for(auto it:ans){
		cout<<it<<endl;
	}
    return 0;
}
