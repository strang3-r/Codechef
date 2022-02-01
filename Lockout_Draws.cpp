#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[]) {

	int testcase;

	cin >> testcase;

	while (testcase--) {

		vector<int> points(3);

		for (int i = 0; i < 3; i++){
			cin >> points[i];
		}

		sort(points.begin(), points.end());

		if(points[0]+points[1] == points[2]){
			cout<<"YES"<<endl;
		}

		else {
			cout<<"NO"<<endl;
		}

	}


}