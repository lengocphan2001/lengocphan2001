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
    int n;
    cin >> n;
    vector<int> a(n);
    read(a);
    set<vector<int>> ans;
    bool check = false;
    for (int i = 0; i<n; i++){
    	if (a[i] != i + 1){
    		for (int j = i + 1; j<n; j++){
    			if (a[j] == i + 1){
    				check = true;
    				int t = j;
    				vector<int> cur;
    				for (int k = t; k>=i; k--) cur.pb(a[k]);
    				int m = 0;
    				for (int k = i; k<=j; k++) a[k] = cur[m++];
    				break;
    			}
    		}
    	}
    	if (check) break;
    }
    for (auto i: a) cout << i << " ";
    cout << endl;
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