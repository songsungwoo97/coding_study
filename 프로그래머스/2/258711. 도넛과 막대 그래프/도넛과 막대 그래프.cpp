#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    int max_node = 0;
    int root = 0;
    int sum = 0;
    int in[1000001] = {0};
    int out[1000001] = {0};
    for(int i = 0; i < edges.size(); i++) {
        int temp1 = edges[i][0]; //out
        int temp2 = edges[i][1]; //in
        
        in[temp2]++;
        out[temp1]++;
        
        max_node = max(max_node, temp1);
        max_node = max(max_node, temp2);
    }
    
    //cout << max_node << endl;
    
    for(int i = 1; i <= max_node; i++) {
        
        if(in[i] == 0 && out[i] >= 2) {
            root = i;
            sum = out[i];
        }
    }
    cout << sum << endl;
    int rod = 0; //막대
    int donut = 0;
    int eight = 0; //8자
        
    for(int i = 1; i <= max_node; i++) {
        if(in[i] >= 2 && out[i] == 2)
            eight++;
        if((in[i] >= 1 && out[i] == 0))
            rod++;
    }
    donut = sum - eight - rod;
        
    answer.push_back(root);
    answer.push_back(donut);
    answer.push_back(rod);
    answer.push_back(eight);
    
    
    return answer;
}