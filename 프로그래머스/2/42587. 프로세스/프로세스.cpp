#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int size = priorities.size();
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    // 큐에 (우선순위, 인덱스) 쌍을 저장하고, 우선순위 큐에 우선순위를 저장
    for (int i = 0; i < size; i++) {
        q.push(make_pair(priorities[i], i));
        pq.push(priorities[i]);
    }

    while (!q.empty()) {
        int priority = q.front().first;
        int index = q.front().second;
        q.pop();

        // 현재 프로세스의 우선순위가 가장 높다면 실행
        if (priority == pq.top()) {
            pq.pop();
            answer++;

            // 실행한 프로세스가 찾고자 하는 프로세스라면 반복문을 종료
            if (index == location)
                break;
        }
        else {
            q.push(make_pair(priority, index));
        }
    }

    return answer;
}