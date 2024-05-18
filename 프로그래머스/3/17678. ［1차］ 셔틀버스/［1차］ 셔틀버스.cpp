#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string answer = "";

void print_time(int hour, int minute) {
    if(hour < 10) {
        answer += "0" + to_string(hour);
    }
    else {
        answer += to_string(hour);
    }
    answer += ":";
    if(minute < 10) {
        answer += "0" + to_string(minute);
    }
    else {
        answer += to_string(minute);
    }
    return;
}

string solution(int n, int t, int m, vector<string> timetable) {
    
    vector<int> times;
    
    for(int i = 0; i < timetable.size(); i++) {
        string time = timetable[i];
        int num = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 5));
        if(540 + t * (n - 1) >= num)
            times.push_back(num);
    }
    
    int t_n = times.size();
    
    if(t_n == 0) {
        int h = (540 + (n - 1) * t) / 60;
        int mi = (540 + (n - 1) * t) % 60;
        
        print_time(h, mi);
        return answer;
    }
    
    sort(times.begin(), times.end());
    int minute = 540; // 분
    int p = 0; // 순번
    for(int i = 0; i < n; i++) {
        int amount = 0;
        while(1) {
            if(times[p] <= minute && p < times.size() && amount < m)
            {
                //cout << times[p] << " " << minute <<endl;
                p++; amount++;
            }
            else
                break;
        }
        //마지막 번
        //cout << amount << " " << p << endl;
        if(i == n - 1) {
            if(amount >= m) {
                int last = times[p - 1] - 1;
                //cout << amount << " " << last << endl;
                print_time(last / 60, last % 60);
            }
            else {
                int h = (540 + (n - 1) * t) / 60;
                int mi = (540 + (n - 1) * t) % 60;
        
                print_time(h, mi);
            }
        }
        
        
        //다음회차로 이동
        minute += t;      
    }
    
    return answer;
}