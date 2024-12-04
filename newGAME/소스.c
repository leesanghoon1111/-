#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ���� ���� �迭 �ʱ�ȭ (1~9������ ���ڸ� ����� �ʱ� ���� ����)
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// ���� �÷��̾ 'X'�� �ʱ�ȭ (������ 'X'���� ����)
char currentPlayer = 'X';

// ���带 ����ϴ� �Լ�
void printBoard() {
    printf("\n");
    // 3x3 ���带 ���
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]); // ������ �� ĭ ���
            if (j < 2) printf("|"); // ���� ���м� ���
        }
        printf("\n");
        // �� �ٸ��� ���м� ��� (���� ���м�)
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// �¸� ������ �˻��ϴ� �Լ�
int checkWin() {
    // ����, ����, �밢���� ������ ���ڰ� �ִ��� Ȯ��
    for (int i = 0; i < 3; i++) {
        // ���� üũ
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1; // �¸�
        }
        // ���� üũ
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1; // �¸�
        }
    }
    // �밢�� üũ
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    return 0; // �¸� ������ �������� ����
}

// ���º� ������ �˻��ϴ� �Լ�
int checkDraw() {
    // ���忡 �� ĭ�� �ִ��� �˻�
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0; // �� ĭ�� ������ ���º� �ƴ�
            }
        }
    }
    return 1; // �� ĭ�� ������ ���º�
}

// ����� �Է¿� ���� ���� ���带 ������Ʈ�ϴ� �Լ�
void makeMove(int choice) {
    int row = (choice - 1) / 3;  // �� ��ȣ ���
    int col = (choice - 1) % 3;  // �� ��ȣ ���

    // �ش� ĭ�� �� ĭ�� ��쿡�� ����
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;  // ������ ĭ�� ���� �÷��̾��� ��ȣ �Է�
    }
    else {
        printf("�߸��� �Է�! �� ĭ�� �̹� �� �ֽ��ϴ�.\n");
    }
}

// ���带 �ʱ� ���·� �����ϴ� �Լ�
void resetBoard() {
    char tempBoard[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    // �ʱ� ���� ���� ����
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = tempBoard[i][j];
        }
    }
}

// AI�� ���� ������ �����ϴ� ������ �Լ�
int getAIChoice() {
    // AI�� ù ��° �� ĭ�� ����
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return (i * 3) + j + 1;  // �ش� ��ġ�� ��ȣ ����
            }
        }
    }
    return -1;  // �� �̻� ������ ���� ���� ���
}

// ������ �����ϴ� �Լ� (��� vs ��� �Ǵ� ��� vs AI)
void playGame(int vsAI) {
    int choice;
    while (1) {
        printBoard();  // ���� ���� ���

        // ��� vs AI�� ���, AI�� 'O'�� �÷���
        if (vsAI && currentPlayer == 'O') {
            printf("AI�� �����Դϴ�.\n");
            choice = getAIChoice();  // AI ����
        }
        else {
            // ��� �÷��̾��� ����
            printf("�÷��̾� %c, �����ϼ��� (1-9): ", currentPlayer);
            scanf_s("%d", &choice);
        }

        makeMove(choice);  // �ش� ���ÿ� ���� ���� ������Ʈ

        // �¸� ���� �˻�
        if (checkWin()) {
            printBoard();
            printf("�÷��̾� %c �¸�!\n", currentPlayer);
            break;
        }

        // ���º� ���� �˻�
        if (checkDraw()) {
            printBoard();
            printf("���º�!\n");
            break;
        }

        // �� ����: 'X'�� 'O'�� �����ư��� ����
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

// ������ �����ϴ� �Լ�
int main() {
    int choice;
    char playAgain;

    // ���� �ʱ�ȭ
    srand(time(NULL));  // ���� �Լ� �ʱ�ȭ

    do {
        // ���� ��� ���� (��� vs ��� �Ǵ� ��� vs AI)
        printf("ƽ���� ����\n");
        printf("1. ��� vs ���\n");
        printf("2. ��� vs AI\n");
        printf("����: ");
        scanf_s("%d", &choice);

        if (choice == 1) {
            playGame(0);  // ��� �� ���
        }
        else if (choice == 2) {
            playGame(1);  // ��� �� AI
        }
        else {
            printf("�߸��� �����Դϴ�.\n");
            continue;
        }

        // ���� ���� �� ����� ���� Ȯ��
        printf("������ �ٽ� �Ͻðڽ��ϱ�? (Y/N): ");
        scanf_s(" %c", &playAgain);
        if (playAgain == 'Y' || playAgain == 'y') {
            resetBoard();  // ���� �ʱ�ȭ
            currentPlayer = 'X';  // 'X'�� ���� ����
        }

    } while (playAgain == 'Y' || playAgain == 'y');

    printf("���� ����!\n");
    return 0;
}
