#include "bits/stdc++.h"
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
using namespace std;
typedef long long ll;

const ll N=1e6+7;
int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    long long s=1,e=n-1,mid,pivot;
    if(arr[0]<arr[n-1])pivot=0;
    else
    {
        while(s<=e)
        {
            mid=(s+e)/2;
            if(arr[mid-1]>arr[mid])
            {
                pivot=mid;
                break;
            }
            if(arr[0]<arr[mid])s=mid+1;
            else
                e=mid;
        }
    }
    //cout<<"Pivot "<<pivot<<endl;
    if(arr[0]<=k && pivot)
    {
        s=0;e=pivot-1;
    }
    else
    {
        s=pivot;e=n-1;
    }
    while(s<=e)
    {
        mid=(s+e)/2;
        if(arr[mid]==k)return mid;
        if(arr[mid]>k)e=mid-1;
        else
            s=mid+1;
    }
    return -1;
}


int solve()
{
    ll n, x,sum=0;
    cin>>n>>x;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }
    cout<<search(v,n,x)<<endl;

    
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