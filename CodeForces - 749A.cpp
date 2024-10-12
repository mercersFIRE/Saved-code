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

int solve()
{
    ll n, x,sum=0,a=0,b=0;
    cin>>n;
    if(n%2==1)
    {
    	a++;
    	n-=3;
    }
    b=n/2;
    cout<<a+b<<endl;
    for (int i = 0; i < a; ++i)
    {
    	cout<<3<<" ";
    }
    for (int i = 0; i < b; ++i)
    {
    	cout<<2<<" ";
    }
    cout<<endl;
    
    return 0;
}

int main()
{
    fast;
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