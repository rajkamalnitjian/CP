#include<iostream>
#include<queue>
//#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,l;
     cin>>n>>l;
     vector<pair<int,int>>arr(n);
      for(int i=0;i<n;i++){
          int a,b;
          cin>>a>>b;
          arr[i]={a,b};
      }
     sort(arr.begin(), arr.end(),
     [](const pair<int, int>& p1, const pair<int, int>& p2)
     {
         return p1.second<p2.second;
     } );

      int ans=0;
       for(int i=0;i<n;i++){
           priority_queue<int>pq;
           int sum=0;
           for(int j=i;j<n;j++){
               pq.push(arr[j].first);
               sum+=arr[j].first;
                while(!pq.empty() and sum+arr[j].second-arr[i].second>l){
                    sum-=pq.top();
                    pq.pop();
                }
                ans=max(ans,(int)pq.size());
           }
       }

 cout<<ans<<endl;
    return ;
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}
//5
//5 8
//4 3
//1 5
//2 4
//4 3
//2 3
//1 6
//4 10
//3 12
//4 8
//2 1
//2 12
//5 26
//24 7
//8 28
//30 22
//3 8
//17 17
//5 14
//15 3
//1000000000 998244353
//179 239
//228 1337
//993 1007

