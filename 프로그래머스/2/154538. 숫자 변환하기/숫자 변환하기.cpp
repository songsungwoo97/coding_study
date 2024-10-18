#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1000001;

int solution(int x, int y, int n) {
    int dp[MAX];
    fill_n(dp, MAX, MAX);
    dp[x] = 0;
    
    for (int i = x; i <= y; i++) {
        if (dp[i] == MAX) continue;
        
        if (i + n < MAX) {
            dp[i + n] = min(dp[i + n], dp[i] + 1);
        }
        if (i * 2 < MAX) {
            dp[i * 2] = min(dp[i * 2], dp[i] + 1);
        }
        if (i * 3 < MAX) {
            dp[i * 3] = min(dp[i * 3], dp[i] + 1);
        }
    }
    
    return dp[y] == MAX ? -1 : dp[y];
}