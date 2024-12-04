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