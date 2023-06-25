#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int matrixChainMultiplication(const vector<int>& dimensions) {
    int n = dimensions.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; ++len)
     {
        for (int i = 1; i < n - len + 1; ++i) 
        {
            int j = i + len - 1;
            dp[i][j] = numeric_limits<int>::max();
            for (int k = i; k <= j - 1; ++k)
            {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (cost < dp[i][j]) 
         {
                    dp[i][j] = cost;
         }
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    vector<int> dimensions(n + 1);
    cout << "Enter the dimensions of matrices: ";
    for (int i = 0; i < n + 1; ++i) {
        cin >> dimensions[i];
    }

    int minScalarMultiplications = matrixChainMultiplication(dimensions);
    cout << "Minimum scalar multiplications required: " << minScalarMultiplications << endl;

    return 0;
}
