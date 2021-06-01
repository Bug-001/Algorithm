#include <cstdio>
#include <iostream>
using namespace std;

int T, M;

int dp[101][1001];
int vi[101][1001];
int v[101];
int t[101];

void dfs(int n, int time)
{
    vi[n][time] = true;
    if (vi[n - 1][time] == false)
    {
        dfs(n - 1, time);
    }
    if (time >= t[n])
    {
        if (vi[n - 1][time - t[n]] == false)
        {
            dfs(n - 1, time - t[n]);
        }
        dp[n][time] = max(dp[n - 1][time], dp[n - 1][time - t[n]] + v[n]);
    }
    else
    {
        dp[n][time] = dp[n - 1][time];
    }
}

int main()
{
    cin >> T >> M;
    for (int i = 1; i <= M; ++i)
    {
        cin >> t[i] >> v[i];
    }
    for (int i = 0; i <= M; ++i)
    {
        vi[i][0] = true;
    }
    for (int j = 0; j <= T; ++j)
    {
        vi[0][j] = true;
    }
    dfs(M, T);
    cout << dp[M][T];
    return 0;
}