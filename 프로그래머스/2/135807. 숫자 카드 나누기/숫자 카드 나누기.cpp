#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    
    return gcd(b, a%b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int maxA = arrayA[0];
    for(int i = 1; i < arrayA.size(); i++) {
        maxA = gcd(maxA, arrayA[i]);
    }
    bool flag = true;
    for(int b : arrayB) {
        if(b % maxA == 0) {
            flag = false;
            break;
        }
    }
    if(flag) 
        answer = maxA;
    
    int maxB = arrayB[0];
    for(int i = 1; i < arrayB.size(); i++) {
        maxB = gcd(maxB, arrayB[i]);
    }
    flag = true;
    for(int a : arrayA) {
        if(a % maxB == 0) {
            flag = false;
            break;
        }
    }
    if(flag) 
        answer = max(answer, maxB);
    
    return answer;
}