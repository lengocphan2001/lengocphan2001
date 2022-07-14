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
    string s;
    cin >> s;
    ll p, cur = 0;
    cin >> p;
    vector<int> ans(sz(s), 1);
    map<char, vector<int>> temp;
    for (int i = 0; i<sz(s); i++){
		cur += s[i] - 'a' + 1;
		temp[s[i]].pb(i);
	}
	if (p >= cur){
		cout << s << endl;
		return;
	}
	for (auto i = temp.rbegin(); i != temp.rend(); i++){
		if (cur - ((i->first - 'a' + 1) * sz(i->second)) > p){
			for (auto j: i->second) ans[j] = 0; 
			cur -= (i->first - 'a' + 1) * sz(i->second);
		}else{
			int current = cur - p, t;
			int cost = i->first - 'a' + 1;
			if (current % cost == 0) t = current/cost;
			else t = current/cost + 1;
			for (int j = 0; j<t; j++){
				ans[i->second[j]] = 0;
			}  
			break;
		}
	}
	for (int i = 0; i<sz(s); i++){
		if (ans[i] == 1) cout << s[i];
	}
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