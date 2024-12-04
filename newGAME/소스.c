#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 게임 보드 배열 초기화
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// 현재 플레이어를 'X'로 설정
char currentPlayer = 'X';
// 보드를 출력하는 함수
void printBoard() {
    printf("\n");
    // 3x3 보드를 출력합니다.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        // 각 줄마다 구분선 추가
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}
// 승리 조건을 검사하는 함수
int checkWin() {
    // 가로, 세로, 대각선 검사
    for (int i = 0; i < 3; i++) {
        // 가로 체크
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        // 세로 체크
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // 대각선 체크
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0; // 승자가 없으면 0 리턴
}
// 무승부 조건을 검사하는 함수
int checkDraw() {
    // 빈 칸이 있으면 0을 리턴
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0; 
            }
        }
    }
    return 1; // 빈 칸이 없으면 무승부
}