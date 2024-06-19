#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int n = topping.size();
    map<int, int> left_count, right_count;

    for (int i = 0; i < n; i++) {
        right_count[topping[i]]++;
    }

    int left_unique = 0, right_unique = right_count.size();

    for (int i = 0; i < n; i++) {
        left_count[topping[i]]++;
        right_count[topping[i]]--;

        if (left_count[topping[i]] == 1) {
            left_unique++;
        }

        if (right_count[topping[i]] == 0) {
            right_unique--;
        }

        if (left_unique == right_unique) {
            answer++;
        }
    }

    return answer;
}