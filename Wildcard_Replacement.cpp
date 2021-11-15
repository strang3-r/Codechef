// Wildcard_Replacement.cpp
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

char* solve(string str) {
    int len = str.length();
    char* res = new char(len);
    int index = 0, i = 0;
    stack<int> s;
    s.push(0);
    while (i < len) {
        if(str[i] == '(' && i == 0) {
            i++;
            continue;
        }
        if (str[i] == '+') {
            if (s.top() == 1)
                res[index++] = '-';
            if (s.top() == 0)
                res[index++] = '+';
        } else if (str[i] == '-') {
            if (s.top() == 1)
                res[index++] = '+';
            else if (s.top() == 0)
                res[index++] = '-';
        } else if (str[i] == '(' && i > 0) {
            if (str[i - 1] == '-') {
                int x = (s.top() == 1) ? 0 : 1;
                s.push(x);
            }
            else if (str[i - 1] == '+')
                s.push(s.top());
        }
        else if (str[i] == ')')
            s.pop();
        else
            res[index++] = str[i];
        i++;
    }
    return res;
}

int main(int argc, char const *argv[])
{

	file_i_o();

	clock_t start, end;
    start = clock();

	w(t){
	
	string s;
    cin >> s;
    int q;
    cin >> q;
    while(q--) {
      int a, b;
      cin >> a >> b;
      string temp = s.substr(a-1, b-a+1);
      if(temp.size() < 3) {
        cout << 1 << " ";
        continue;
      }
      char *c = solve(temp);
      int ans = 0;
      for(int i = 0; i < strlen(c); i++) {
        if(c[i] == '+') {
          ans++;
        }
      }
      cout << ans + 1 << " ";
    }
    cout << '\n';	

	}

	end = clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cerr<<"\nTime : "<<fixed<<time_taken<<setprecision(5)<<" s \n";
    cerr<<"Coded by Mr. Black-D3vil"<<endl;

	return 0;
}