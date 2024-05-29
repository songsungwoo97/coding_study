#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    bool visited[100][100] = {false, };
    
    queue<tuple<int, int, int>> q;
    
    q.push(make_tuple(0, 0, 1)); // x, y, cnt
    
    while(!q.empty()) {
        
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        
        q.pop();
        
        if(x == n - 1 && y == m - 1) {
            return cnt;
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || maps[nx][ny] == 0)
                continue;
            
            visited[nx][ny] = true;
            q.push(make_tuple(nx, ny, cnt + 1));
        }
    }
    
    return -1;
}