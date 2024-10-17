#include <string>
#include <vector>

using namespace std;

int count = 0;
int Size, tar;

void dfs(int idx, int sum, vector<int> nums) {
    
    if(idx == Size) {
        if(sum == tar) {
            count++;
        }
        return;
    }
    
    dfs(idx + 1, sum + nums[idx], nums);
    dfs(idx + 1, sum - nums[idx], nums);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    tar = target;
    Size = numbers.size();
    
    dfs(0, 0, numbers);
    
    answer = count;
    
    return answer;
}