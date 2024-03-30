#include <iostream>
#include <climits>

using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int sum(int probs[], int i, int j) {
    int total = 0;
    for (int k = i; k <= j; k++) {
        total += probs[k];
    }
    return total;
}

int optimal_bst(int keys[], int probs[], int n) {
    int dp[n][n];
    for (int i = 0; i < n; i++) {
        dp[i][i] = probs[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j; k++) {
                int cost = (k > i ? dp[i][k - 1] : 0) +
                           (k < j ? dp[k + 1][j] : 0) +
                           sum(probs, i, j);
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    int keys[] = {1, 2, 3};
    int probs[] = {20, 40, 30};

    int n = sizeof(keys) / sizeof(keys[0]);

    int min_cost = optimal_bst(keys, probs, n);
    cout << "Minimum Cost: " << min_cost << endl;

    return 0;
}
