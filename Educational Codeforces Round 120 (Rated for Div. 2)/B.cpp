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
    string s;
    cin >> s;
    vector<pair<int, int>> liked, disliked;
    for (int i = 0; i<n; i++){
    	if (s[i] == '0') disliked.pb({a[i], i});
    	else liked.pb({a[i], i});
    }
    sort(all(liked), greater<pair<int, int>>());
    sort(all(disliked));
    vector<int> ans(n);
    int tmp = n;
    int cur = 1;
    for (int i = 0; i<sz(liked); i++){
    	ans[liked[i].ss] = tmp--;
    }
    for (int i = 0; i<sz(disliked); i++){
    	ans[disliked[i].ss] = cur++;
    }
    for (auto i: ans) cout << i << " ";
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