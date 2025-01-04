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

const ll N=2e5+7;
std::vector<ll> lazy(4*N);

void propagate(ll n)
{
    lazy[2*n]+=lazy[n];
    lazy[2*n+1]+=lazy[n];
    lazy[n]=0;
}
void update(ll n,ll b,ll e,ll l,ll r)
{
    if(b>r||e<l)return;
    if(b>=l and e<=r)
    {
        lazy[n]++;
        return ;
    }
    ll mid=(b+e)/2;
    update(2*n,b,mid,l,r);
    update(2*n+1,mid+1,e,l,r);
}
ll query(ll n,ll b,ll e,ll i)
{
    if(b>i||e<i)return 0;
    if(b==i and e== i)return lazy[n];
    propagate(n);
    ll mid=(b+e)/2;
    return query(2*n,b,mid,i)+query(2*n+1,mid+1,e,i);
}

int solve()
{
    fill(lazy.begin(), lazy.end(),0);
    ll n, x,sum=0,a,b;
    cin>>n>>x;
    std::map<ll, ll> m;
    std::vector<pair<ll,ll>> v;
    std::vector<ll> ind(x);
    for (int i = 0; i < n; ++i)
    {
        cin>>a>>b;
        v.pb({a,b});
        m[a]++;
        m[b]++;
    }
    for (int i = 0; i < x; ++i)
    {
        cin>>ind[i];
        m[ind[i]]++;
    }
    for(auto &&i : m) {
        i.ss=++sum;
    }
    for (int i = 0; i < n; ++i)
    {
        update(1,1,m.size(),m[v[i].ff],m[v[i].ss]);
    }
    for (int i = 0; i < x; ++i)
    {
        cout<<query(1,1,m.size(),m[ind[i]])<<endl;
    }
    
    return 0;
}

int main()
{
    fast;
    ll tc = 1,x=0;cin>>tc;
    while (tc--)
    {
        cout<<"Case "<<++x<<": \n";
        if (solve()){
            //cout << "Yes\n";
        }
        else{
            //cout << "No\n";
        }
    }
    return 0;
}