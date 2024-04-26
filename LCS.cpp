#include <iostream>
#include <string>
using namespace std;

int LCS(string t1, string t2) {
    int m = t1.size();
    int n = t2.size();
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (t1[i - 1] == t2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    string t1, t2;
    cout << "Enter DNA sequence 1: ";
    cin >> t1;
    cout << "Enter DNA sequence 2: ";
    cin >> t2;

    int lcsLength = LCS(t1, t2);
    cout << "Length of Longest Common Subsequence: " << lcsLength << endl;

    return 0;
}
