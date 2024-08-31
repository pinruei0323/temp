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

void dfs(ll a, ll b, ll &n, ll &m, bool first, auto &data, auto &visited, ll &ans, ll &maxAns, string s)
{
    if(a>=0 && b>=0 && a<n && b<m && !visited[a][b] && (s.find(data[a][b])+1))
    {
        visited[a][b] = 1;
        if(data[a][b] != '0')
        {
            ans++;
            maxAns = max(maxAns, ans);
            string s1 = "XILJ",
                   s2 = "XI7F",
                   s3 = "XHLF",
                   s4 = "XH7J"; 
            if(first)    ans=1;
            if(s1.find(data[a][b])+1)    dfs(a+1, b, n, m, 0, data, visited, ans, maxAns, s2);
            if(s2.find(data[a][b])+1)    dfs(a-1, b, n, m, 0, data, visited, ans, maxAns, s1);
            if(s3.find(data[a][b])+1)    dfs(a, b+1, n, m, 0, data, visited, ans, maxAns, s4);
            if(s4.find(data[a][b])+1)    dfs(a, b-1, n, m, 0, data, visited, ans, maxAns, s3);
        }
    }
}

int main()    //    https://zerojudge.tw/ShowProblem?problemid=m372
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, ans=0, maxAns=0;
    cin >> n >> m;
    vector <vector <char>> data(n, vector <char> (m));
    vector <vector <bool>> visited(n, vector <bool> (m));
    f2(i, n)    f2(j, m)    cin >> data[i][j];
    f2(i, n)    f2(j, m)    dfs(i, j, n, m, 1, data, visited, ans, maxAns, "FH7IXLJ0");
    cout << maxAns;
    return 0;
}
