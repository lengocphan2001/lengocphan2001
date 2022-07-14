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
    vector<string> a(n);
    read(a);
    vector<int> ans;
    map<string, int> cur;
    for (auto i: a) cur[i] = 1;
    for (int i = 0; i<n; i++){
    	bool check = false;
    	for (int j = 1; j<sz(a[i]); j++){
    		string temp = "", res = "";
    		for (int k = 0; k<j; k++){
    			temp+=a[i][k];
    		}
    		for (int k = j; k<sz(a[i]); k++){
    			res += a[i][k];
    		}
    		if (cur[temp] == 1 && cur[res] == 1) {
    			check = true;
    			break;
    		}
    	}
    	if (check) ans.pb(1);
    	else ans.pb(0);
    }
    for (auto i: ans) cout << i;
    cout << endl;
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