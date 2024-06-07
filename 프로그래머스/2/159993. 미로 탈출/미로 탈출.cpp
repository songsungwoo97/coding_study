#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

bool visited1[100][100] = {false, };
bool visited2[100][100] = {false, };

int solution(vector<string> maps) {
    int answer = 0;
    
    int sx, sy;
    int ex, ey;
    int lx, ly;
    
    int n = maps.size();
    int m = maps[0].size();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maps[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if(maps[i][j] == 'E') {
                ex = i;
                ey = j;
            }
            if(maps[i][j] == 'L') {
                lx = i;
                ly = j;
            }
        }
    }
    
    queue<tuple<int, int, int>> q;
    visited1[sx][sy] = true;
    
    q.push(make_tuple(sx, sy, 0));
    int x = -1, y = -1, cnt = 0;
    while(!q.empty()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        cnt = get<2>(q.front());
        
        q.pop();
        
        if(x == lx && y == ly) 
            break;
        
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited1[nx][ny] && maps[nx][ny] != 'X') {
                q.push(make_tuple(nx, ny, cnt + 1));
                visited1[nx][ny] = true;
            }
        }
    }
    if(x != lx && y != ly)
        return -1;
    
    q = queue<tuple<int, int, int>>();
    q.push(make_tuple(x, y, cnt));
    visited2[x][y] = true;
    while(!q.empty()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        cnt = get<2>(q.front());
        
        q.pop();
        
        if(x == ex && y == ey) {
            return cnt;
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited2[nx][ny] && maps[nx][ny] != 'X') {
                q.push(make_tuple(nx, ny, cnt + 1));
                visited2[nx][ny] = true;
            }
        }
    }
    
    return -1;
}