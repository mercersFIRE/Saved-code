#include "bits/stdc++.h"
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
using namespace std;
typedef long long ll;

const ll N = 2e5+7;


int solve()
{
    ll n, x,sum=0;
    cin>>n;
    unordered_map<ll,ll> v,div;
    for (int i = 0; i < n; ++i)
    {
        cin>>x;
        v[x]++;
    }
    for (int i = 1; i < N; ++i)
    {
        for (int j = i; j < N; j+=i)
        {
            div[i]+=v[j];
        }
    }
    cin>>x;
    while(x--) {
        ll a,b,c;
        cin>>a>>b;
        if(a==1||b==1) {
            cout<<n<<endl;
            continue;
        }
        c=(a/__gcd(a,b))*b;
        cout<<div[a]+div[b]-div[c]<<endl;
    }
    
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