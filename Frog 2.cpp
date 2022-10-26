#include <bits/stdc++.h>
using namespace std;

int dp[100005];
int arr[100005];
int k;
int func(int pos) {
	if(pos == 0)
		return 0;
	int cost = INT_MAX;
	if(dp[pos] != -1)	return dp[pos];
	for(int i = 1; i <= k; i++) {
		if(pos > i-1) {
			cost = min(cost, func(pos - i) + abs(arr[pos] - arr[pos - i]));
		}
	}
	return dp[pos] = cost;
}

int main() {
	int n;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << func(n-1) << '\n';
	return 0;
}