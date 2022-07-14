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
    int n, ans = 0;
    cin >> n;
    vector<string> a(n), b;
    for (int i = 0; i<n; i++){
    	cin >> a[i];
		string temp = "";
		for (int i = 0; i<n; i++) temp += '1';
		b.pb(temp);
    }
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			if (b[i][j] == '1'){
				int zero = (a[i][j] == '0'), one = (a[i][j] == '1');
				if (a[j][n-i-1] == '0') zero++;
				else one++;
				b[j][n-i-1] = '0';
				if (a[n-i-1][n-j-1] == '0') zero++;
				else one++;
				b[n-i-1][n-j-1] = '0';
				if (a[n-j-1][i] == '0') zero++;
				else one++;
				b[n-j-1][i] = '0';
				ans += min(one, zero);
			}
		}
	}
	cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif
    int t;
    cin >> t;
    while(t--)
        solve();
}