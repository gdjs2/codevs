#include <cstdio>

const int Maxn = 31;
int n, num[Maxn], dp[Maxn][Maxn], tar[Maxn][Maxn];

int max(int a, int b) { return a > b ? a : b; }

void dfs(int l, int r)
{
    if(l > r) return;
    if(l == r)
    { printf("%d ", l); return; }
    printf("%d ", tar[l][r]);
    dfs(l, tar[l][r]-1); dfs(tar[l][r]+1, r);
    return;
}

int main()
{
    freopen("1090.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &dp[i][i]);
    for(int i = 1; i <= n; ++i) dp[i][i-1] = dp[i+1][i] = 1;

    for(int l = 1; l < n; ++l)
        for(int i = 1; i <= n-l; ++i)
        {
            int j = i + l;
            for(int k = i; k <= j; ++k)
            if(dp[i][k-1] * dp[k+1][j] + dp[k][k] > dp[i][j])
            {
                dp[i][j] = dp[i][k-1] * dp[k+1][j] + dp[k][k];
                tar[i][j] = k;
            }
        }
    printf("%d\n", dp[1][n]);
    dfs(1, n);
}
