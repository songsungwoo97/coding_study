/* #include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  int n, m; // n은 사다리 개수, m은 뱀의 수
  vector<vector<int>> ladder(30, vector<int>(2));
  queue<pair<int, int>> q;

  cin >> n >> m;

  for (int i = 0; i < n + m; i++)
    cin >> ladder[i][0] >> ladder[i][1];

  q.push(make_pair(1, 0));

  while (!q.empty())
  {
    int idx = q.front().first;
    int cnt = q.front().second;

    q.pop();

    if (idx > 100)
      continue;
    if (idx == 100)
    {
      cout << cnt << endl;
      return 0;
    }

    bool flag = true;
    for (int i = 1; i <= 6; i++)
    {
      int n_idx = idx + i;
      for (auto row : ladder)
      {
        if (row[0] == n_idx)
        {
          flag = false;
          q.push(make_pair(row[1], cnt + 1));
          break;
        }
      }
      if (flag)
      {
        flag = true;
        q.push(make_pair(n_idx, cnt + 1));
      }
    }
  }

  return 0;
} */
#include <iostream>
#include <queue>
using namespace std;
int map[102] = {0};
bool visit[102] = {0};
 
void game(int x, int c){
    queue<pair<int, int>> q;
    q.push(make_pair(x, c));
    while(!q.empty()){
        int loc = q.front().first; // 현재 좌표
        int cnt = q.front().second; // 카운트
        q.pop();
 
        for (int i = 1; i <= 6;i++){
            int nx = loc + i; // 다음 좌표
            if(nx == 100){
                cout << cnt+1; // 도착했으면 출력
                return;
            }
            else if(nx < 100){ // 100보다 작은 좌표라면 
                while(map[nx] != 0){ // 사다리 혹은 뱀인지 확인
                    nx = map[nx]; // 점프한 자리로 이동
                }
                if(!visit[nx]){ // 처음 방문한 좌표일때
                    q.push(make_pair(nx, cnt + 1)); // 큐에 넣어줌
                    visit[nx] = true; // 방문처리
                }
                
            }
        }
    }
}
 
int main(){
    int n, m, t1, t2;
    
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        cin >> t1 >> t2; 
        map[t1] = t2; // 사다리 저장
    }
    for (int i = 0; i < m;i++){
        cin >> t1 >> t2;
        map[t1] = t2; // 뱀 저장
    }
    game(1, 0);
    return 0;
}