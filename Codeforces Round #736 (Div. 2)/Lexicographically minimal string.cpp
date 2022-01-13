#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define Fi(a,n) for(int i = a; i < n; i++)
#define Fd(n,a) for(int i = n; i >= a; i--)
#define all(a) a.begin(), a.end()
#define pb push_back

int parent[26];

void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    else{
        v = find_set(parent[v]);
        return v;
    }
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a < b){
        parent[b] = min(parent[b], a);
    }else if (a > b){
        parent[a] = min(parent[a], b);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.size();
    for (int i = 0; i<26; i++)
        make_set(i);
    for (int i = 0; i<n; i++){
        union_sets(a[i] - 97, b[i] - 97);
    }
    for (int i = 0; i<c.size(); i++){

        c[i] = min(c[i]-97 + 'a', find_set(c[i]-97) + 'a');
    }
    cout << c;
}
