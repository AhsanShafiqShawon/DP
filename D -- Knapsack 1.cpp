#include <bits/stdc++.h>
using namespace std;
int w[105];
int v[105];
long long dp[105][100005];
int n, W;
long long func(int pos, int W) {
	if(pos > n-1)
		return 0;
	if(dp[pos][W] != -1)	return dp[pos][W];
	long long val1 = 0;
	if(W - w[pos] >= 0)
		val1 = func(pos + 1, W - w[pos]) + v[pos];
	long long val2 = func(pos + 1, W);
	return dp[pos][W] = max(val1, val2);
}
int main() {
	cin >> n >> W;
	for(int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << func(0, W) << '\n';
	return 0;
}