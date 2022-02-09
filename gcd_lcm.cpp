// gcd_lcm.cpp

#include <bits/stdc++.h>
using namespace std;

int main(){

	int testcases;

	cin>>testcases;

	while(testcases--){
		long long a,b;
		
		long long gcd = 1, lcm = 1;

		cin>>a>>b;

		for(int i = 1; i<=1000; i++){
			if((a%i == 0) and (b%i==0)){
				gcd = i;
			}
		}

		lcm = (a*b)/gcd;

		cout<<gcd<<" "<<lcm<<endl;
	}

	return 0;

}