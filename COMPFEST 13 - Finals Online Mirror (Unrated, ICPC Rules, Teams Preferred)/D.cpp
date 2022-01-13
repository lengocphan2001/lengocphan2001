#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define Fi(a,n) for(int i = a; i < n; i++)
#define Fd(n,a) for(int i = n; i >= a; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll mod = 1e9 + 7;
bool isNumber(string s)
{
    for (int i = 0; i < s.size(); i++)
        if (isdigit(s[i]) == false)
            return false;
    return true;
}
void solve()
{
    string s;
    std::cin >> s;
    if (isNumber(s)){
        ll x = 0;
        stringstream convert(s);
        convert >> x;
        if (x % 25 == 0)
            cout << 1;
        else
            cout << 0;
    }else{
        std::vector<int> space, x;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '_')
                space.pb(i);
            else if (s[i] == 'X')
                x.pb(i);
        }
        int n = s.size(), ans = 0;
        ll l = pow(10, n-1);
        if (l%10!=0)
            l++;
        if (l < 100 && l >= 10)
            l = 25;
        else if (l < 100)
            l = 0;
        ll r = 0;
        for (int i = 0; i<n; i++){
            r = r*10 + 9;
        }
        for (int i = l; i<=r; i+=25){
            if (i == 0){
                ans++;
            }else{
                
            }
        }
        cout << ans;
    }

}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}