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