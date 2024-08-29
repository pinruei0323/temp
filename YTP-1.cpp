#include<bits/stdc++.h>
#define f2(i, m) for(long long i=0; i<m; i++)
#define f3(i, n, m) for(long long i=n; i<m; i++)
#define ll long long
#define pb push_back
#define pob pop_back
#define len length()
#define elif else if
#define mod 1000000007
#define debug
/*
#ifdef debug
#endif
#ifndef debug
#endif
*/
using namespace std;

int main()
{
    ll n, tmp=0, l=0, minn=LONG_LONG_MAX, maxx=LONG_LONG_MIN;
    cin >> n;
    vector <ll> data(10000000);
    vector <ll> ans(10000000);
    f2(i, n)
    {
        ll a, b;
        cin >> a >> b;
        minn = min(minn, a);
        minn = min(minn, b);
        maxx = max(maxx, a);
        maxx = max(maxx, b);
        data[a]+=1;
        data[b]-=1;
    }
    f3(i, minn, maxx+1)
    {
        tmp+=data[i];
        ans[i]=tmp;
    }
    f3(i, minn, maxx+1)
        if(ans[i])    l++;
    cout << l;
}