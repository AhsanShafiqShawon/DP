#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int dp[100005];
int n;
int func(int pos) {
	if(pos >= n - 1)
		return 0;
	int val2 = INT_MAX;
	if(dp[pos] != -1)	return dp[pos];
	int val1 = func(pos + 1) + abs(arr[pos] - arr[pos + 1]);
	if(pos + 2 < n)
		val2 = func(pos + 2) + abs(arr[pos] - arr[pos + 2]);
	return dp[pos] = min(val1, val2);
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << func(0) << '\n';
	return 0;
}