#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int dp[100005];
int n, k;
int func(int pos) {
	if(pos >= n - 1)
		return 0;
	int val = INT_MAX;
	if(dp[pos] != -1)	return dp[pos];
	for(int i = 1; i <= k; i++) {
		if(pos + i < n)
			val = min(val, func(pos + i) + abs(arr[pos] - arr[pos + i]));
	}
	return dp[pos] = val;
}
int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << func(0) << '\n';
	return 0;
}