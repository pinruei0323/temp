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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector <vector <ll>> dp(max(n, m)+1, vector <ll> (max(n, m)+1, LONG_LONG_MAX));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 0;
    if(n>m)    swap(n, m);
    f2(i, n+1)
    {
        f2(j, m+1)
        {
            if(dp[i][j]!=LONG_LONG_MAX)    continue;
            if(i==j || i==0 || j==0)
            {
                dp[i][j] = 0;
                dp[j][i] = 0;
                continue;
            }
            f3(k, 1, j/2+1)
            {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
                dp[j][i] = dp[i][j];
            }
        }
    }
    cout << dp[n][m];

    #ifndef debug
    cout << "\n\n";
    f2(i, max(n, m)+1)
    {
        f2(j, max(n, m)+1)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }
    #endif

    return 0;
}