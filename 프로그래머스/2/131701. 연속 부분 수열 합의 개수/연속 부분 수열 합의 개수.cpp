#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int n = elements.size();
    vector<int> v(2 * n);
    
    // 원형 수열을 일직선 수열로 변환
    for (int i = 0; i < 2 * n; i++) {
        v[i] = elements[i % n];
    }
    
    set<int> s;
    
    // 모든 연속 부분 수열의 합을 구하고 Set에 저장
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < i + n; j++) {
            sum += v[j];
            s.insert(sum);
        }
    }
    
    return s.size();
}