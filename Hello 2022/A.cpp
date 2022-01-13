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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> ans(n, vector<char>(n, 'R'));
    for (int i = 0; i<n; i++){
    	for (int j = 0; j<n; j++){
    		if (ans[i][j] == 'R'){
    			for (int k = j + 1; k<n; k++) ans[i][k] = '.';
    			if (i + 1 < n)
    				for (int k = 0; k<n; k++) ans[i+1][k] = '.';
    			if (j + 1 < n)
    				for (int k = i + 1; k<n; k++) ans[k][j+1] = '.';
    			for (int k = i + 1; k<n; k++) ans[k][j] = '.';
    		}
    	}
    }
    int cur = 0;
    vector<pair<int, int>> res;
    for (int i = 0; i<n; i++) {
    	for (int j = 0; j<n; j++) {
    		if (ans[i][j] == 'R') {
    			cur++;
    			res.pb({i, j});
    		}
    	}
    }
	if(cur < m){
		cout << -1 << endl;
	}else{
		int i = 0;
		while(cur != m){
			ans[res[i].ff][res[i].ss] = '.';
			cur--;
			i++;
		}
		for (int i = 0; i<n; i++) {
	    	for (int j = 0; j<n; j++) {
	    		cout << ans[i][j];
	    	}
	    	cout << endl;
    	}
	}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}