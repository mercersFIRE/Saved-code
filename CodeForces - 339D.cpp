#include "bits/stdc++.h"
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
using namespace std;
typedef long long ll;

const ll N=2e5+7;
std::vector<ll> v(N),t(4*N);
merge(ll l,ll r,ll flg)
{
    return (flg?l^r:l|r);
}
pair<ll,ll> build(ll n,ll b,ll e)
{
    if(b==e){
        t[n]=v[b];
        return {v[b],0};
    }
    ll mid=(b+e)/2;
    auto flg=build(2*n,b,mid);
    build(2*n+1,mid+1,e);
    t[n]=merge(t[2*n],t[2*n+1],flg.ss);
    return {t[n],flg.ss^1};

}
pair<ll,ll> update(ll n,ll b,ll e, ll i,ll x)
{
    if(b==e and b==i)
    {
        t[n]=v[b]=x;
        return {x,0};
    }
    ll mid=(b+e)/2;
    pair<ll,ll> flg;
    if(i<=mid)
    {
        flg=update(n*2,b,mid,i,x);
    }
    else
        flg=update(2*n+1,mid+1,e,i,x);
    t[n]=merge(t[2*n],t[2*n+1],flg.ss);
    return {t[n],flg.ss^1};
}
int solve()
{
    ll n, x,sum=0,q;
    cin>>n>>q;
    x=pow(2,n);
    for (int i = 0; i < x; ++i)
    {
        cin>>v[i+1];
    }
    auto ans=build(1,1,x);
    //cout<<ans.ff<<" "<<ans.ss<<endl;
    for (int i = 0; i < q; ++i)
    {
        ll ind,val;
        cin>>ind>>val;
        cout<<update(1,1,x,ind,val).ff<<endl;
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