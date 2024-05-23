#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(int n1, int n2) {
		if (abs(n1) > abs(n2)) {
			return true;
		}
		else if (abs(n1) == abs(n2)) {
			if (n1 > n2) {
				return true;
			}
			else {
				return false;
			}
		}
		return false;
	}
};

priority_queue<int, vector<int>, cmp> pq; //오름차순으로 정렬

int main() {
	int n;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while (n--) {
		int x; 
		cin >> x;
		if (x == 0) {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}
	return 0;
}
