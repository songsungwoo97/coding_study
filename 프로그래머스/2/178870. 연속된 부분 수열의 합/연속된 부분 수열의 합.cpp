#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct a {
    int length;
    int start;
    int end;
};

bool cmp(a a1, a a2) {
    if (a1.length == a2.length) {
        return a1.start < a2.start;
    }
    return a1.length < a2.length;
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int start = 0, end = 0;
    int sum = sequence[0];
    
    vector<a> v;
    
    
    while(start <= end && end < sequence.size()) {
        if(sum == k) {
            a temp;
            temp.length = end - start;
            temp.start = start;
            temp.end = end;
            v.push_back(temp);
            sum += sequence[++end];
        }
        else if(sum < k) {
            sum += sequence[++end];
        }
        else {
            sum -= sequence[start++];
        }
    }
    
    sort(v.begin(), v.end(), cmp);
    
    answer.push_back(v[0].start);
    answer.push_back(v[0].end);
    
    return answer;
}