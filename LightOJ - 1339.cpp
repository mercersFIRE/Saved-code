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

struct node {
    ll l,lc,r,rc,mx;
};
std::vector<ll> v(N);
std::vector<node> t(4*N);

node merge(node left,node right)
{
    if(left.mx==-1)return right;
    if(right.mx==-1)return left;
    node ans;
    ans.l=left.l;
    ans.lc=left.lc+(left.l==right.l?right.lc:0);
    ans.r=right.r;
    ans.rc=right.rc+(left.r==right.r?left.rc:0);
    ans.mx=max({left.mx,right.mx,(left.r==right.l?left.rc+right.lc:0ll)});
    return ans;
}

void build(ll n,ll b,ll e)
{
    if(b==e)
    {
        t[n].l=v[b];
        t[n].lc=1;
        t[n].r=v[b];
        t[n].rc=1;
        t[n].mx=1;
        return ;
    }
    ll mid=(b+e)/2;
    build(2*n,b,mid);
    build(2*n+1,mid+1,e);
    t[n]=merge(t[2*n],t[2*n+1]);
}

node query(ll n,ll b,ll e,ll l,ll r)
{
    if(b>r||e<l)return {-1,-1,-1,-1,-1};
    if(b>=l and e<= r)return t[n];
    ll mid=(b+e)/2;
    return merge(query(2*n,b,mid,l,r),query(2*n+1,mid+1,e,l,r));
}

int solve()
{
    ll n,c,q;
    cin>>n>>c>>q;
    for (int i = 0; i < n; ++i)
    {
        cin>>v[i+1];
    }
    build(1,1,n);
    for (int i = 0; i < q; ++i)
    {
        ll r,l;
        cin>>l>>r;
        cout<<query(1,1,n,l,r).mx<<endl;
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