// Hill_Sequence.cpp

		/*Coded By Mr. Black-D3vil*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ff                 first
#define ss                 second
#define endl               "\n"
#define ll                 long long
#define ld                 long double
#define loop(a, b, c)      for(ll (a) = (b); (a)<=(c); (a)++)
#define looprev(a, b, c)   for(ll (a) = (b); (a)>=(c); (a)--)
#define pb                 push_back
#define mp                 make_pair
#define pii                pair<ll, ll>
#define vi                 vector<ll>
#define mii                map<ll, ll>
#define pqb                priority_queue<ll>
#define pqs                priority_queue<int, vi, greater<ll> >
#define Unique(c)          (c).resize(unique(all(c))-(c).begin())
#define all(n)             n.begin(),n.end()
#define setbits(x)         __builtin_popcountll(x)
#define zrobits(x)         __builtin_ctzll(x)
#define mod                1000000007
#define inf                1e18
#define ps(x, y)           fixed<<setprecision(y)<<x
#define mk(arr,n,type)     type *arr = new type[n];
#define w(t)               int x; cin>>x; while(x--)
//mt19937                    rng(chrono::steady_clock::now,time_since_epoch(),count());
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

    
void file_i_o(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);                      	
	#ifndef ONLINE_JUDGE
		freopen("//home//black-devil//Desktop///InputOutput//input.txt", "r", stdin);
		freopen("//home//black-devil//Desktop//InputOutput//output.txt", "w", stdout);
	#endif
}

int main(int argc, char const *argv[])
{

	file_i_o();

	clock_t start, end;
    start = clock();

	w(t){
		
		ll n, x, freq = 0;

		cin>>n;

		map<ll, ll> mp;
		vi res, v;

		loop(i, 0, n-1){
			cin>>x;
			mp[x]++;
		}
		for(auto x: mp){
			if(x.ss>2){
				freq = 1;
				break;
			}
			v.pb(x.ff);
		}
		sort(v.begin(), v.end());

		if(freq == 1 or mp[v[v.size()-1]]==2)
			cout<<"-1"<<endl;
		else{
			loop(i, 0, v.size()-1){
				if(mp[v[i]]==2)
					cout<<v[i]<<" ";
			}
			looprev(i, v.size()-1, 0){
				cout<<v[i]<<" ";
			}cout<<endl;
		}

	}

	end = clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cerr<<"\nTime : "<<fixed<<time_taken<<setprecision(5)<<" s \n";
    cerr<<"Coded by Mr. Black-D3vil"<<endl;
	return 0;
}
