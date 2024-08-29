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
    ll n, ans=0;
    cin >> n;
    vector <pair <ll, ll>> data(n);
    vector <bool> ok(n, 1);
    f2(i, n)    cin >> data[i].first >> data[i].second;
    sort(&data[0], &data[n]);
    ll maxEnd = data[0].second;
    f3(i, 1, n)
    {
        if(data[i].first < maxEnd)
        {
            if(data[i].second <= maxEnd)
                ok[i] = 0;
            else
            {
                data[i].first = maxEnd;
                maxEnd = data[i].second;
            }
        }
        else
            maxEnd = data[i].second;
    }
    f2(i, n)
        if(ok[i])    ans+=data[i].second-data[i].first;
    cout << ans;
}