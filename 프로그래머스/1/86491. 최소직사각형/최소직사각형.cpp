#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int height=0; // 세로
    int width=0; // 가로
    
    for(int i = 0; i<sizes.size(); i++)
    {
        if(sizes[i][0] > sizes[i][1]) // 가로가 더 클 경우
        {
            width = max(width, sizes[i][0]);
            height = max(height, sizes[i][1]);
        }
        else // 세로가 더 클 경우
        {
            width = max(width, sizes[i][1]);
            height = max(height, sizes[i][0]);
        }

    }
    
    answer = height * width;
    return answer;
}