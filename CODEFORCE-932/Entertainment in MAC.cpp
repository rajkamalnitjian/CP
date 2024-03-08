#include <iostream>
using namespace std;
 void solve(){
      int n; cin>>n;
      string s; cin>>s;
      string temp=s;
      reverse(temp.begin(),temp.end());
      cout<<min(s,temp+s)<<endl;

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
//4
//cpm
//2
//grib
//10
//kupitimilablodarbuz
//1000000000
//capybara
//6
//abacaba
