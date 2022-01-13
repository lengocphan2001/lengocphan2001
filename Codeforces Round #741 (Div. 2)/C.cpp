#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define Fi(a,n) for(int i = a; i < n; i++)
#define Fd(n,a) for(int i = n; i >= a; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
ll change(string s)
{
    ll decimalNumber = 0, j = 0, remainder, i = s.size() - 1;
    while (i >= 0)
    {
        remainder = (s[i] == '0')? 0: (s[i] - '0');
        i--;
        decimalNumber += remainder*pow(2,j);
        j++;
    }
    return decimalNumber;
}
void solve(){
    int n;
    string s;
    cin >> n >> s;
    int temp = n/2 - 1;
    vector<tuple<int, int, ll>> a, b;
    for (int i = 0; i<n - temp; i++){
        for (int j = i + temp; j<n; j++){
            string cur = s.substr(i, j + 1);
            auto tmp = make_tuple(i, j, change(cur));
            a.pb(tmp);
        }
    }
    for (int i = 0; i<a.size(); i++){
        cout << get<0>(a[i]) << " " << get<1>(a[i]) << " " << get<2>(a[i]);
        cout << endl;
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
