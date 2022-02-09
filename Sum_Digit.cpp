#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {

	int testcase;

	cin >> testcase;

	while (testcase--) {

		long long num;

		cin >> num;

		long long sum = 0;

		while (num > 0) {

			long long k = num % 10;

			sum += k;

			num /= 10;

		}

		cout << sum << endl;

	}

}