#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
bool isInBounds(vector<vector<char>> &mat,ll i,ll j,ll &m,ll &n){
	return (i>=0 && i<m && j>=0 && j<n && mat[i][j]=='.');
}
 
void dfs(vector<vector<char>> &mat,ll i,ll j,ll &m,ll &n){
	mat[i][j]='#';
	if(isInBounds(mat,i,j+1,m,n)){
		dfs(mat,i,j+1,m,n);
	}
	if(isInBounds(mat,i+1,j,m,n)){
		dfs(mat,i+1,j,m,n);
	}
	if(isInBounds(mat,i,j-1,m,n)){
		dfs(mat,i,j-1,m,n);
	}
	if(isInBounds(mat,i-1,j,m,n)){
		dfs(mat,i-1,j,m,n);
	}
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll m,n;
	cin>>m>>n;
	vector<vector<char>> mat(m,vector<char>(n));
	for(vector<char> &it:mat){
		for(char &ch:it){
			cin>>ch;
		}
	}
	ll ans=0;
	for(ll i=0;i<m;i++){
		for(ll j=0;j<n;j++){
			if(isInBounds(mat,i,j,m,n)){
				dfs(mat,i,j,m,n);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
