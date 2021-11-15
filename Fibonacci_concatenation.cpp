// Fibonacci_concatenation.cpp

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

const ll maxn = 1e5 + 5;

    
void file_i_o(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("//home//black-devil//Desktop///InputOutput//input.txt", "r", stdin);
		freopen("//home//black-devil//Desktop//InputOutput//output.txt", "w", stdout);
	#endif
}

ll add(ll x, ll y) {ll res = x + y; return (res >= mod ? res - mod : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= mod ? res % mod : res);}
ll sub (ll x, ll y) {ll res = x - y; return (res < 0 ? res + mod : res);}
ll power(ll x, ll y) {if (y < 0) return 1; ll res = 1; x %= mod; while(y) {if(y & 1) res = mul(res, x); y >>= 1; ll res = mul(res, y); x <<=   1;} return res;}
ll inv (ll x) {return power(x, mod - 2);}	


vi sz(maxn);
vi ones(maxn);


void precompute(){
	sz[0] = 1, sz[1] = 1;

	ones[0] = 0, ones[1] = 1;

	loop(i, 2, maxn-1){
		ones[i] = add(ones[i - 1], ones[i - 2]);
		sz[i] = (sz[i - 1] + sz[i - 2]) % (mod - 1);
	}
}

	
int main(int argc, char const *argv[])
{

	file_i_o();

	clock_t start, end;
    start = clock();

    precompute();

	w(t){

			ll n;
			
			cin>>n;

			ll ans = mul(ones[n], power(2, (sz[n] - 1) % (mod - 1) ));

			cout<<ans<<endl; 	

	}


	end = clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cerr<<"\nTime : "<<fixed<<time_taken<<setprecision(5)<<" s \n";
    cerr<<"Coded by Mr. Black-D3vil"<<endl;

	return 0;
}
