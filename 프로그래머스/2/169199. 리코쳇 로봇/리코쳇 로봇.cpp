#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool visited[100][100] = {false, };

int solution(vector<string> board) {
    
    int n = board.size();
    int m = board[0].size();
    
    int rx, ry;
    int gx, gy;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'R') {
                rx = i; ry = j;
            }
            if(board[i][j] == 'G') {
                gx = i; gy = j;
            }
        }
    }

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(rx, ry, 0));
    visited[rx][ry] = true;
    
    while(!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        
        
        q.pop();
        
        if(x == gx && y == gy) {
            return cnt;
        }
        
        for(int i = 0; i < 4; i++) {
            
            int nx = x;
            int ny = y;
            //미끄러지는 로직 구현 필요
            while(nx + dx[i] >= 0 && nx + dx[i] < n && ny + dy[i] >= 0 && ny + dy[i] < m && board[nx + dx[i]][ny + dy[i]] != 'D') {
                nx += dx[i];
                ny += dy[i];
            }
            
            if(visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            cout << cnt << endl;
            q.push(make_tuple(nx, ny, cnt + 1));
        }
    }    
    
    return -1;
}