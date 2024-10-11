#include <string>
#include <vector>

using namespace std;

bool checkWin(vector<string>& board, char player) {
    // 가로, 세로, 대각선 승리 조건 확인
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

int solution(vector<string> board) {
    int check_o = 0;
    int check_x = 0;
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == 'O')
                check_o++;
            if(board[i][j] == 'X')
                check_x++;
        }
    }
    
    // O와 X의 개수 확인
    if(check_o < check_x || check_o > check_x + 1) return 0;
    
    bool o_win = checkWin(board, 'O');
    bool x_win = checkWin(board, 'X');
    
    // O가 이겼을 때
    if (o_win && check_o != check_x + 1) return 0;
    
    // X가 이겼을 때
    if (x_win && check_o != check_x) return 0;
    
    // 둘 다 이긴 경우는 불가능
    if (o_win && x_win) return 0;
    
    return 1;
}