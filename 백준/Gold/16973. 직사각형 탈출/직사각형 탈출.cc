#include <iostream>
#include <queue>

using namespace std;

int N, M, H, W;
int map[1001][1001];
int c[1001][1001];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0};

bool InnerBfs(int s1, int s2, int i) {
	int x, y;
	switch (i) {
	case(0):
		x = s1;
		y = s2;
		for (int j = 0; j < H; j++) {
			if (map[x + j][y] == 1) return false;
		}
		break;
	case(1):
		x = s1;
		y = s2 + W - 1;
		if (y > M) return false;
		for (int j = 0; j < H; j++) {
			if (map[x + j][y] == 1) return false;
		}
		break;
	case(2):
		x = s1;
		y = s2;
		for (int j = 0; j < W; j++) {
			if (map[x][y+j] == 1) return false;
		}
		break;
	case(3):
		x = s1 + H - 1;
		y = s2;
		if (x > N) return false;
		for (int j = 0; j < W; j++) {
			if (map[x][y+j] == 1) return false;
		}
		break;
	}
	return true;
}
int Bfs(int s1, int s2, int e1,int e2) {
	queue<pair<int, int>> q;
	q.push(make_pair(s1, s2));
	c[s1][s2] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (x == e1 && y == e2) return c[x][y] - 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > N || ny > M || map[nx][ny] == 1) continue;
			if (!c[nx][ny] && InnerBfs(nx, ny, i)) {
				c[nx][ny] = c[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
	return -1;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int s1, s2;
	int e1, e2;

	cin >> N >> M;

	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	cin >> H >> W;
	cin >> s1 >> s2 >> e1 >> e2;

	cout << Bfs(s1, s2, e1, e2);

}