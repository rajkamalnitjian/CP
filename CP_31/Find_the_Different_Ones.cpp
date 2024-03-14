//Codeforces
// D. Find the Different Ones!

#include <iostream>
#define int long long
using namespace std;
void solve(){
    int n;
    cin >>n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int>left(n,-1);
    for(int i=1;i<n;i++){
        left[i]=left[i-1];
        if(arr[i]!=arr[i-1]){
            left[i]=i-1;
        }
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l-=1,r-=1;
        if(left[r]<l or left[r]==-1){
            cout<<"-1 -1"<<endl;
        }
        else
            cout<<left[r]+1<<" "<<r+1<<endl;
    }

    return ;
}
signed main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}


// 7
// 6 5 2
// 1 2 7 4 9 6
// 7 9 5
// 1 10 15 3 8 12 15
// 9 4 10
// 14 10 2 2 11 11 13 5 6
// 9 5 6
// 10 7 6 7 9 7 7 10 10
// 9 6 2
// 4 9 7 1 2 2 13 3 15
// 9 2 3
// 14 6 1 15 12 15 8 2 15
// 10 5 7
// 13 3 3 2 12 11 3 7 13 14





