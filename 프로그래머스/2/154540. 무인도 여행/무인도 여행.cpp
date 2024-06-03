#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n, m;
int visited[100][100] = {0,};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int sum = 0;

void dfs(int x, int y, vector<string> v) {
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] == 1 || v[nx][ny] == 'X')
            continue;
        visited[nx][ny] = 1;
        sum += v[nx][ny] - '0';
        dfs(nx, ny, v);
    }
}


vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    n = maps.size();
    m = maps[0].size();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j] == 1 || maps[i][j] == 'X')
                continue;
            
            visited[i][j] = 1;
            sum += maps[i][j] - '0';
            dfs(i, j, maps);
            answer.push_back(sum);
            sum = 0;
        }
    }
    
    if(answer.empty()) {
        answer.push_back(-1);
        return answer;
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}