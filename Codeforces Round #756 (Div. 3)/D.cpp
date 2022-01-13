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
vector<int> res(n+1);
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    read(a);
    read(b);
    int root = 1;
    for (int i = 0; i<n; i++){
    	if (a[i] == i + 1){
    		root = a[i];
    		break;
    	}
    }
    vector<vector<int>> cur(n + 1);
    for (int i = 0; i<n; i++){
    	if (a[i] != i + 1){
    		cur[a[i]].pb(i+1);
    	}
    }
    if (b[0] != root){
    	cout << -1 << endl;
    }else{
    	vector<int> ans(n + 1, 0);
    	for (int i = 1; i<=n; i++){
    		cout << res[i] << " ";
    	}
    	cout << endl;
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