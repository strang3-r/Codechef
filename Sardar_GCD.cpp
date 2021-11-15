// Sardar_GCD.cpp

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

void dfs(vector<vector<ll>> & graph, vector<ll> & gcd, ll u, ll par){
    for(auto & to:graph[u]){
        if(to == par) continue;
        dfs(graph,gcd,to,u);
        gcd[u] = __gcd(gcd[u],gcd[to]);
    }
}

ll ans=0;

void dfs1(vector<vector<ll>> & graph, vector<ll> & gcd, ll u, ll par, ll exc, vector<ll> & arr){
    ll temp = exc;
    for(auto & to:graph[u]){
        if(to == par) continue;
        temp+=gcd[to];
    }
    ans=max(ans,temp);
    ll transfer = __gcd(arr[u],exc);
    ll n = graph[u].size();
    if(par!=-1){
        n--;
    }
    vector<ll> pref(n+2,transfer),suff(n+2,transfer);
    ll idx=0;
    for(auto & to:graph[u]){
        if(to == par) continue;
        idx++;
        pref[idx]=__gcd(pref[idx],gcd[to]);
        suff[idx]=__gcd(suff[idx],gcd[to]);
    }
    for(ll i=1;i<=n;i++){
        pref[i] = __gcd(pref[i],pref[i-1]);
    }
    for(ll i=n;i>=1;i--){
        suff[i]=__gcd(suff[i],suff[i+1]);
    }
    idx=0;
    for(auto & to:graph[u]){
        if(to == par) continue;
        idx++;
        ll combine = __gcd(pref[idx-1], suff[idx+1]);
        dfs1(graph,gcd,to,u,combine,arr);
    }
}

void solve(){
    ll n;
    cin>>n;
    ans=0;
    vector<vector<ll>> graph(n);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<ll> arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll> gcd(arr.begin(),arr.end());
    dfs(graph,gcd,0,-1);
    dfs1(graph,gcd,0,-1,0,arr);
    cout<<ans<<endl;
}

int main(int argc, char const *argv[])
{

	file_i_o();

	clock_t start, end;
    start = clock();

	w(t){

		solve();	

	}

	end = clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cerr<<"\nTime : "<<fixed<<time_taken<<setprecision(5)<<" s \n";
    cerr<<"Coded by Mr. Black-D3vil"<<endl;

	return 0;
}