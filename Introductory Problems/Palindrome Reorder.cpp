#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
	string str;
	cin>>str;
	int n=str.size();
	unordered_map<char,int> mp;
    for(int i=0;i<n;i++){
        mp[str[i]]++;
    }
    int oddCount=0;
    string odd="";
    for(auto it:mp){
        if(it.second%2==1){
            oddCount++;
            odd=it.first;
        }
    }
    if(oddCount>1 || (oddCount==1 && n%2==0)){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    string firstPart="";
    string secondPart="";
    for (auto it:mp) {
        string s(it.second/2,it.first);
        firstPart=firstPart+s;
        secondPart=s+secondPart;
    } 
    cout<<firstPart+odd+secondPart<<endl;
	return 0;
}
