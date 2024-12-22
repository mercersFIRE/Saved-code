#include "bits/stdc++.h"
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
typedef long long ll;

const ll N=1e6+7;
vector<ll>prime,spf(N);
void seive()
{
    for (ll i = 1; i < N; ++i)spf[i]=i;
    for (ll i = 2; i*i<N; ++i)
    {
        if(spf[i]==i)
            for (ll j = i*i; j < N; j+=i) 
                spf[j]=min(i,spf[j]);
    }
    for (int i = 2; i < N; ++i)if(spf[i]==i)prime.pb(i);
}

int solve()
{
    ll x, y, n;
    cin >> n >> x >> y;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += a[i];
    }
    ll low_bound = total_sum - y;
    ll high_bound = total_sum - x;
    sort(a.begin(), a.end());

    ll count = 0;

    for (int i = 0; i < n; i++) {
        ll left_bound = low_bound - a[i];
        ll right_bound = high_bound - a[i];

        auto left_idx = lower_bound(a.begin() + i + 1, a.end(), left_bound) - a.begin();
        auto right_idx = upper_bound(a.begin() + i + 1, a.end(), right_bound) - a.begin();

        count += (right_idx - left_idx);
    }

    cout << count << endl;
    
    return 0;
}

int main()
{
    fast;
    ll tc = 1;cin>>tc;
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