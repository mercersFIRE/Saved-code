#include "bits/stdc++.h"
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
using namespace std;
typedef long long ll;

const ll N=1e6+7;

ll solve()
{
    ll n, x,sum=0,l,r,k;
    cin>>n>>l>>r>>k;

    if(n&1ll)return l;
    if(n==2)return -1;
    
    auto msbbit = [](ll x) {
        ll bit=0;
        while(x){
            bit++;
            x>>=1;
        }
        return bit;
    };
    if(msbbit(l)==msbbit(r))return -1;

    return k<(n-1)?l:1ll<<(msbbit(l));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;cin>>tc;
    while (tc--)
    {
        cout<<solve()<<endl;
    }
    return 0;
}