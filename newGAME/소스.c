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
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");       
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}