#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<int> nums(n);


	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());

	bool ok = false;

	for (int i = 0; i < n; i++) {
		if (nums[i] % 2 == 0) cout << nums[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		if (nums[i] % 2 != 0) cout << nums[i] << " ";
	}

}