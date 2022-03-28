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
const ll MOD = 1e9 + 7;
const int base = 31;
ll getHash(vector<ll> hashT, int i, int j, vector<ll> POW){
	return (hashT[j] - hashT[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}
void solve()
{
	string s;
	cin >> s;
	int n = sz(s);
	string cur = " " + s;
	reverse(all(s));
	string temp = " " + s;
	vector<ll> POW(n + 10, 1), hashT(n + 1, 0), hashS(n + 1, 0);
	for (int i = 1; i <= n; i++)
    	POW[i] = (POW[i - 1] * base) % MOD;
    for (int i = 1; i <= n; i++)
    	hashT[i] = (hashT[i - 1] * base + cur[i] - 'a' + 1) % MOD;
    for (int i = 1; i <= n; i++)
    	hashS[i] = (hashS[i - 1] * base + temp[i] - 'a' + 1) % MOD;
    int ans = 0;
   	for (int i = 1; i<=n; i++){
   		for (int j = i; j<=n; j++)
   			if (getHash(hashT, i, j, POW) == getHash(hashS, n - j + 1, n - i + 1, POW)) ans++;
   	}
   	cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}