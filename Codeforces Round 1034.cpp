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
    ll n, x,sum=0,mex=0;
    cin>>n;
    map<ll,ll>m,freq;
    std::vector<ll> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>v[i];
        m[v[i]]++;
    }
    for(unsigned i = 0; i <= n; ++i) {
        if(m.find(i)!=m.end()){
            freq[m[i]]++;
            mex=i+1;
        }
        else
            break;
    }
    std::vector<ll> ans(n+1);
    ans[n]=1;ans[0]=1;
    //cout<<"mex "<<mex<<" ";

    for(unsigned i = 0; i<mex; ++i) {
        ans[n-i]=i+1;
    }
    for(unsigned i = 1; !ans[i]; ++i) {
        ans[i]=ans[i-1]+freq[i];
    }
    for(auto&& i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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