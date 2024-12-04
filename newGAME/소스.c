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
    // 3x3 ���带 ����մϴ�.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        // �� �ٸ��� ���м� �߰�
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}
// �¸� ������ �˻��ϴ� �Լ�
int checkWin() {
    // ����, ����, �밢�� �˻�
    for (int i = 0; i < 3; i++) {
        // ���� üũ
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        // ���� üũ
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // �밢�� üũ
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0; // ���ڰ� ������ 0 ����
}
// ���º� ������ �˻��ϴ� �Լ�
int checkDraw() {
    // �� ĭ�� ������ 0�� ����
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0; 
            }
        }
    }
    return 1; // �� ĭ�� ������ ���º�
}