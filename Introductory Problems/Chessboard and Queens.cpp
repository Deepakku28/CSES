#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
bool isSafe(vector<vector<char>> &mat,int &row,int &col){
	for(int i=0;i<col;i++){
		if(mat[row][i]=='#'){
            return false;
		}
	}
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
		if(mat[i][j]=='#'){
            return false;
		}
	}
    for(int i=row,j=col;j>=0 && i<8;i++,j--){
        if(mat[i][j]=='#'){
            return false;
		}
	}
    return true;
}
 
void solution(vector<vector<char>> &mat,int col,int &ans){
	if(col==8){
		ans++;
		return;
	}
	for(int row=0;row<8;row++){
		if(mat[row][col]=='.'){
			if(isSafe(mat,row,col)){
				mat[row][col]='#';
				solution(mat,col+1,ans);
				mat[row][col]='.';
			}
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<vector<char>> mat(8,vector<char>(8));
	for(auto &it:mat){
		for(auto &itr:it){
			cin>>itr;
		}
	}
	int ans=0;
	solution(mat,0,ans);
	cout<<ans<<endl;
	return 0;
}
