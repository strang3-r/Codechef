#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[]) {

	vector<int> v;

	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);


	cout << v.size() << endl;

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	v.pop_back();

	cout << v.size() << endl;

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	v.push_back(4);

	cout << endl;

	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	v.clear();

	cout << endl << v.size();


}