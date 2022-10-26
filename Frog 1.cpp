#include <bits/stdc++.h>
using namespace std;

int dp[100005];
int arr[100005];
int func(int pos) {
	if(pos == 0)
		return 0;
	int cost = INT_MAX;
	if(dp[pos] != -1)	return dp[pos];
	cost = min(cost, func(pos - 1) + abs(arr[pos] - arr[pos - 1]));
	if(pos > 1)
		cost = min(cost, func(pos - 2) + abs(arr[pos] - arr[pos - 2]));
	return dp[pos] = cost;
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << func(n-1) << '\n';
	return 0;
}