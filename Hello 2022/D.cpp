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
const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const int base1 = 31;
const int base2 = 311;
vector<ll> hash1(10e5 + 2, 0), hash2(10e5 + 2, 0);
vector<ll> POW1(10e5, 1), POW2(10e5, 1);
pair<ll, ll> getHash(int i, int j){
    pair<ll, ll> ans;
    ans.ff = (hash1[j] - hash1[i - 1] * POW1[j - i + 1] + mod1 * mod1) % mod1;
    ans.ss = (hash2[j] - hash2[i - 1] * POW2[j - i + 1] + mod2 * mod2) % mod2;
    return ans;
}
void initPOW(int n){
    for (int i = 1; i<=n; i++){
        POW1[i] = (POW1[i-1] * base1) % mod1;
        POW2[i] = (POW2[i-1] * base2) % mod2;
    }
}
void initHashS(string s){
    int n = sz(s);
    for (int i = 0; i<n; i++){
        hash1[i + 1] = (hash1[i] * base1 + s[i] - 'a' + 1) % mod1;
        hash2[i + 1] = (hash2[i] * base2 + s[i] - 'a' + 1) % mod2;
    }
}
void solve()
{
    string s;
    cin >> s;
    initHashS(s);
    initPOW(sz(s) + 1);
    s = " " + s;
    for (int i = 1; i<= n; i++){
        for (int j =  i + 1; j<=n; j++){
            tmp = getHash(i, i + k - 1);
            cur.insert(tmp);
        }
    }
    cout << sz(cur) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve(); 
}