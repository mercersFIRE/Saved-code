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
    ll n, x,sum=0;
    string s;
    cin>>n>>s;
    ll flg=0;
    std::vector<char> v;
    for(ll i = 0; i < n/2; ++i) {
    	if(s[i]!=s[n-i-1]) {
            v.pb(s[i]);
            v.pb(s[n-1-i]);
            flg=1;
            break;
        }
    }
    if(flg==0||v.empty())return 0;
    
    ll ans1=0, ans2=0;
    auto check = [&](char a) -> ll {
        ll sum=0;
        for(ll i = 0,b = 0, e = n-1; b<e; ++b,--e) {
            while(b<e && s[b]!=s[e])
            {
                if(s[b]==a)
                {
                    b++;
                    sum++;
                }
                else if (s[e]==a)
                {
                    e--;
                    sum++;
                }
                else
                    break;
            }
            if (b<e && s[b]!=s[e])return -1;
        }
        return sum;
    };
    ans1= check(v[0]);
    ans2= check(v[1]);
    
    if(ans1==-1 && ans2==-1){
        cout<<-1<<endl;
        return 1;
    }
    if((ans1*ans2)<0)
    {
        cout<<max(ans1,ans2)<<endl;
        return 1;
    }
    cout<<min(ans1,ans2)<<endl;
    return 1;
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
            cout << "0\n";
        }
    }
    return 0;
}