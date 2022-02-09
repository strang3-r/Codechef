#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[]) {

	int testcase;

	cin >> testcase;

	while (testcase--) {

		long long num;

		cin >> num;

		int rem = num % 10;

		while (num > 9) {
			num /= 10;
		}

		cout << num+rem << endl;

	}


}