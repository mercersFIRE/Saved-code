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

const int MOD = 1e9 + 7,maxN=1e5 +1;

int precompute(ll b,ll e ,ll m) {
    ll sum=1;
    while(e>0)
    {
        if(e%2==1)
        {
            sum=(sum*b)%MOD;
        }
        b=(b*b)%MOD;
        e/=2;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<int> n(t), k(t);
    int maxN = 0;

    for (int i = 0; i < t; i++) {
        cin >> n[i];
        maxN = max(maxN, n[i]);
    }
    for (int i = 0; i < t; i++) {
        cin >> k[i];
    }

    for (int i = 0; i < t; i++) {
        cout << precompute(2,k[i],MOD)<<endl;
    }

    return 0;
}
