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
 	ll ans = 0;
 	for (int i = 0; i<n; i++){
 		for (int j = i; j<n; j++){
 			int tmp = 0;
 			for (int k = i; k<=j; k++){
 				tmp += (a[k] == 0);
 			}
 			ans += (j - i + 1);
 			ans += tmp;
 		}
 	}
 	cout << ans << endl;
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