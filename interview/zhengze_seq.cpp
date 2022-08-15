#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>


using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	vector<int>que(n, 0);
	for (int i = 0; i < n; ++i) cin >> que[i];
	sort(que.begin(), que.end());
	for (int i = 1; i <= n; ++i) {
		ans += abs(i - que[i - 1]);
	}
	cout << ans;
	return 0;
}