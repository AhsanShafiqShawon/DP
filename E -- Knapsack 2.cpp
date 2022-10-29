#include <bits/stdc++.h>
using namespace std;
int n, W;
int v[105];
int w[105];
long long dp[105][100005];
long long func(int pos, int value) {
    if(value == 0)    return 0;
    if(pos + 1 > n)    return 1e15;
    if(dp[pos][value] != -1)    return dp[pos][value];
    long long res = func(pos + 1, value);
    if(value - v[pos] >= 0)
        res = min(res, func(pos + 1, value - v[pos]) + w[pos]);
    return dp[pos][value] = res;
}
int main() {
    cin >> n >> W;
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    for(int i = 1e5; i >= 0; i--) {
        if(func(0, i) <= W) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}