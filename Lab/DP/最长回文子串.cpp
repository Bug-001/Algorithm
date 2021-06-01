#include "../lab.h"

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for (auto &v : dp)
    {
        for (auto &t : v)
        {
            ans = max(ans, t);
        }
    }
    cout << ans;
    return 0;
}