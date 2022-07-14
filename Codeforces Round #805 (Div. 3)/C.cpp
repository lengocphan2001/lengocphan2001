#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define Fi(a, n) for (int i = a; i < n; i++)
#define Fd(n, a) for (int i = n; i >= a; i--)
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define read(a) for (int i = 0; i<sz(a); i++) cin >> a[i]
const ll mod = 1e9 + 7;
void solve()
{
	int n, q;
	cin >> n >> q;
	vector<ll> a(n);
	read(a);
	map<ll, vector<int>> cur;
	for (int i = 0; i<n; i++){
		cur[a[i]].pb(i);
	}
	while(q--){
    	ll a1, b1;
    	cin >> a1 >> b1;
    	if (sz(cur[a1]) == 0 || sz(cur[b1]) == 0){
    		no;
    	}else{
    		int t = cur[a1][0];
    		if (lower_bound(all(cur[b1]), t) != cur[b1].end()) yes;
    		else no;
    	}
	}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif
    int t;
    cin >> t;
    while(t--)
        solve();
}