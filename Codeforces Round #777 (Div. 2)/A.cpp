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
    int t = 0;
    vector<int> ans,res;
    while(n >= 3){
    	n-=3;
    	t++;
    }
    for (int i = 0; i<t; i++){
    	ans.pb(1);
    	ans.pb(2);
    	res.pb(2);
    	res.pb(1);
    }
    if (n == 1){
    	if (sz(res) > 0)
    		res[0] = 3;
    	ans.pb(1);
    }
    if (n == 2){
    	res.pb(2);
    	ans.pb(1);
    	if (sz(ans) >= 2)
    		ans[1] = 3;
    }
    if (sz(ans) <= sz(res)){
    	for (auto i: res) cout << i;
    	cout << endl;
    }else{
    	for (auto i: ans) cout << i;
    	cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    	solve();
}