#include <iostream>
//#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int ,int>mp;
    int Mex=0;
    vector<int>prefix(n,-1),suffix(n,-1);
    for(int i=0;i<n;i++){
        mp[arr[i]]+=1;
        while(mp[Mex]>0){
            Mex+=1;
        }
        prefix[i]=Mex;
    }
    mp.clear();
    Mex=0;
    for(int i=n-1;i>=0;i--){
        mp[arr[i]]+=1;
        while(mp[Mex]>0){
            Mex+=1;
        }
        suffix[i]=Mex;
    }

    for(int i=0;i<n;i++){
        if(i+1<n){
            if(prefix[i]==suffix[i+1] and prefix[i]!=-1){
                cout<<2<<endl;
                cout<<1<<" "<<i+1<<endl;
                cout<<i+2<<" "<<n<<endl;
                return ;
            }
        }

    }
    cout<<"-1"<<endl;
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
//
//5
//2
//0 0
//5
//0 1 2 3 4
//8
//0 1 7 1 0 1 0 3
//3
//2 2 2
//4
//0 1 2 0

