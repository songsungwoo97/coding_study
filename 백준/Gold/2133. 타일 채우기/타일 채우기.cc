#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int dp[31] = {0};  // long long으로 변경하여 큰 수 처리
    int n;
    cin >> n;

    if (n % 2 != 0) {  // n이 홀수인 경우 처리
        cout << 0 << endl;
        return 0;
    }

    dp[0] = 1;  // 초기값 설정
    dp[2] = 3;

    for (int i = 4; i <= n; i += 2)
    {
        dp[i] = dp[i - 2] * 3;  // 기본 경우

        for (int j = i - 4; j >= 0; j -= 2)
        {
            dp[i] += dp[j] * 2;  // 특별한 경우 추가
        }
    }

    cout << dp[n] << endl;

    return 0;
}