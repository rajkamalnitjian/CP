

#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans=0;
    for (int k = 1; k <= n; k++) {
        if (n % k == 0) {
            int g = 0;
            for (int i = 0; i + k < n; i++)
                g = __gcd(g, abs(arr[i + k] - arr[i]));
            ans += (g != 1);
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


//8
//4
//1 2 1 4
//3
//1 2 3
//5
//1 1 1 1 1
//6
//1 3 1 1 3 1
//6
//6 2 6 2 2 2
//6
//2 6 3 6 6 6
//10
//1 7  5 1  4 3  1 3  1 4
//1
//1

