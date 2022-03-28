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
map<int, pair<set<int>, vector<int>>> cur;
void solve()
{
   	int n;
   	cin >> n;
   	vector<pair<int, int>> a(n);
   	for (int i = 0; i<n; i++){
   		cin >> a[i].ff >> a[i].ss;
   		cur[a[i].ff].ff.insert(a[i].ss);
   	}
   	for (auto i = cur.begin(); i!=cur.end(); i++){
   		auto t = i->second.ff.end();
   		t--;
   		vector<int> mex(*t+10, 0);
   		for (auto j: i->second.ff){
   			mex[j] = 1;
   		}
   		for (int j = 0; j<=*t + 1; j++){
   			if (mex[j] == 0){
   				i->second.ss.pb(j);
   			}
   		}
   	}	
   	for (int i = 0; i<n; i++){
   		int ans;
   		vector<int> t = cur[a[i].ff].ss;
   		if (count(all(t), a[i].ss+1) == 0){
   			t.pb(a[i].ss + 1);
   		}
   		auto it = upper_bound(all(t), a[i].ss);
   		if (it != t.begin()){
   			auto tmp = it - 1;
   			if (abs(a[i].ss - *it) < abs(a[i].ss - *tmp)){
   				ans = *it;
   			}else{
   				ans = *tmp;
   			}
   			if (abs(a[i].ss - ans) >= abs(a[i].ss + 1)){
   				ans = -1;
   			}
   		}else{
   			if (abs(a[i].ss - *it) < abs(a[i].ss + 1)){
   				ans = *it;
   			}else{
   				ans = -1;
   			}
   		}
   		cout << a[i].ff << " " << ans << endl;
   	}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}