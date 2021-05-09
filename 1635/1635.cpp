#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
const int MOD = 1e9 + 7;
int dp[maxn+5],a[105];
int main(){
    int n,x;
    cin >> n >> x;
    for(int i=1;i<=n;i++) cin >> a[i];
    dp[0] = 1;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=n;j++){
            if(i - a[j] >= 0){
                dp[i] = (dp[i] + dp[i-a[j]]) % MOD;
            }
        }
    }
    cout << dp[x];
}
