
// Online C compiler to run C program online
#include <stdio.h>
int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int C, int n, int weight[], int value[])
{
int i, k;
int dp[n + 1][C + 1];

// Build table dp[][] in bottom up manner
for (i = 0; i <= n; i++) {
for (k = 0; k <= C; k++) {
if (i == 0 || k == 0)
dp[i][k] = 0;
else if (weight[i-1] <= k){
dp[i][k] = max(value[i-1]+ dp[i - 1][k - weight[i-1]],dp[i - 1][k]);
}
else
dp[i][k] = dp[i - 1][k];
}
}
return dp[n][C];
}
int main()
{
int value[] = { 15,10, 9, 5};
int weight[] = { 1, 5, 3, 4 };
int C = 8;

int n = sizeof(value) / sizeof(value[0]);
printf("%d", knapSack(C, n, weight, value));
return 0;
}
