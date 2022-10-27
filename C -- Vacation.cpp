#include <bits/stdc++.h>
using namespace std;
int arr[100005][3];
int dp[100005][3];
int n;
int func(int pos, int option) {
	if(pos > n-1)
		return 0;
	int res = 0;
	if(dp[pos][option] != -1)	return dp[pos][option];

	if(option == 0) {
		res = max(func(pos + 1, 1) + arr[pos+1][1], func(pos + 1, 2) + arr[pos+1][2]);
	} else if(option == 1) {
		res = max(func(pos + 1, 0) + arr[pos+1][0], func(pos + 1, 2) + arr[pos+1][2]);
	} else if(option == 2) {
		res = max(func(pos + 1, 0) + arr[pos+1][0], func(pos + 1, 1) + arr[pos+1][1]);
	}
	return dp[pos][option] = res;
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	int a = arr[0][0]; int b = arr[0][1]; int c = arr[0][2];
	int value, option;
	if(a > b) {
		if(a > c) {
			value = a;
			option = 0;
		} else {
			value = c;
			option = 2;
		}
	} else {
		if(b > c) {
			value = b;
			option = 1;
		} else {
			value = c;
			option = 2;
		}
	}
	for(int i = 0; i < 100005; i++) {
		for(int j = 0; j < 3; j++) {
			dp[i][j] = -1;
		}
	}
	cout << func(0, option) + value << '\n';
	return 0;
}