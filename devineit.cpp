#include "bits/stdc++.h"
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
using namespace std;
typedef long long ll;

const ll N=1e6+7;

int solve()
{
    ll n,x,m,sum=0;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
    }
    cin>>m;
    for (ll i = 0; i < m; i++) {
        ll c;
        cin >> c;
        ll l = -1, r = -1;
        for (ll j = 0; j < n; j++) {
            if (a[j] == c) {
                if (l == -1) l = j;
                r = j;
            }
        }
        if (l != -1 && l != r) {
            for (ll j = l; j <= r; j++) {
                a[j] = c;
            }
        }
    }
    for (ll i = 0; i < n; i++) {
        cout << a[i];
        if (i < n-1) cout << " ";
    }
    cout << endl;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;//cin>>tc;
    while (tc--)
    {
        if (solve()){
            //cout << "Yes\n";
        }
        else{
            //cout << "No\n";
        }
    }
    return 0;
}