#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define Fi(a,n) for(int i = a; i < n; i++)
#define Fd(n,a) for(int i = n; i >= a; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
bool isPrime(int n)
{
    if (n <= 2)
        return true;
    for (int i = 2; i*i<=n; i++)
        if (n%i == 0)
            return false;
    return true;
}
void solve()
{
    int k, ans = 0;
    cin >> k;
    string s;
    cin >> s;
    for (int i = 0; i<k; i++)
    {
        if (s[i] != '2' && s[i] != '3' && s[i] != '7' && s[i] != '5')
        {
            cout << 1 << endl;
            cout << s[i] << endl;
            return;
        }
    }
    for (int i = 0; i<k-1; i++){
        for (int j = i + 1; j<k; j++){
            ans = ans * 10 + (s[i] - '0');
            ans = ans * 10 + (s[j] - '0');
            if (!isPrime(ans)){
                cout << 2 << endl;
                cout << s[i] << s[j] << endl;
                return;
            }
            ans = 0;
        }
    }
    cout << k << endl;
    cout << s << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
