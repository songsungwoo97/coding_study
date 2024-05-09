#include <iostream>

using namespace std;

int arr[102][102] = {
    0,
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;

  int sum = 0;
  cin >> n >> m;
  sum = 2 * n * m; // 위아랫면 합 : 2*n*m

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cin >> arr[i][j];
    }
  }
  // 4개의 옆면 합 구하기
  for (int x = 1; x <= n; x++)
  {
    for (int y = 1; y <= m; y++)
    {
      for (int i = 0; i < 4; i++)
      {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (arr[x][y] > arr[nx][ny])
          sum += (arr[x][y] - arr[nx][ny]);
      }
    }
  }
  cout << sum << "\n";

  return 0;
}