#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// ���� ���� �迭 �ʱ�ȭ
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// ���� �÷��̾ 'X'�� ����
char currentPlayer = 'X';
// ���带 ����ϴ� �Լ�
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