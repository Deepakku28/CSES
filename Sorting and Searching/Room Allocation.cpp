#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<pair<pair<int,int>,int>> val(n);
	for(int i=0;i<n;i++){
		cin>>val[i].first.first>>val[i].first.second;
		val[i].second=i;
	}
	sort(val.begin(),val.end());
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	int maxVal=0;
	int room=0;
	vector<int> ans(n,0);
	for(int i=0;i<n;i++){
		if(pq.empty()){
			room++;
			pq.push(make_pair(val[i].first.second,room));
			ans[val[i].second]=room;
		}
		else{
			pair<int,int> minimum=pq.top();
            if(minimum.first<val[i].first.first){
                pq.pop();
                pq.push(make_pair(val[i].first.second,minimum.second));
                ans[val[i].second]=minimum.second;
            }
            else {
                room++;
                pq.push(make_pair(val[i].first.second,room));
                ans[val[i].second]=room;
            }
		}
		maxVal=max(maxVal,(int)pq.size());
	}
	cout<<maxVal<<endl;
	for(auto it:ans){
		cout<<it<<endl;
	}
	return 0;
}
