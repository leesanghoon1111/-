#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 게임 보드 배열 초기화 (1~9까지의 숫자를 사용해 초기 상태 설정)
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// 현재 플레이어를 'X'로 초기화 (게임은 'X'부터 시작)
char currentPlayer = 'X';

// 보드를 출력하는 함수
void printBoard() {
    printf("\n");
    // 3x3 보드를 출력
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]); // 보드의 각 칸 출력
            if (j < 2) printf("|"); // 세로 구분선 출력
        }
        printf("\n");
        // 각 줄마다 구분선 출력 (가로 구분선)
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// 승리 조건을 검사하는 함수
int checkWin() {
    // 가로, 세로, 대각선에 동일한 문자가 있는지 확인
    for (int i = 0; i < 3; i++) {
        // 가로 체크
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1; // 승리
        }
        // 세로 체크
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1; // 승리
        }
    }
    // 대각선 체크
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    return 0; // 승리 조건을 만족하지 않음
}

// 무승부 조건을 검사하는 함수
int checkDraw() {
    // 보드에 빈 칸이 있는지 검사
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0; // 빈 칸이 있으면 무승부 아님
            }
        }
    }
    return 1; // 빈 칸이 없으면 무승부
}

// 사용자 입력에 따라 게임 보드를 업데이트하는 함수
void makeMove(int choice) {
    int row = (choice - 1) / 3;  // 행 번호 계산
    int col = (choice - 1) % 3;  // 열 번호 계산

    // 해당 칸이 빈 칸일 경우에만 선택
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;  // 선택한 칸에 현재 플레이어의 기호 입력
    }
    else {
        printf("잘못된 입력! 이 칸은 이미 차 있습니다.\n");
    }
}

// 보드를 초기 상태로 리셋하는 함수
void resetBoard() {
    char tempBoard[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    // 초기 보드 상태 복원
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = tempBoard[i][j];
        }
    }
}

// AI의 다음 선택을 결정하는 간단한 함수
int getAIChoice() {
    // AI는 첫 번째 빈 칸을 선택
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return (i * 3) + j + 1;  // 해당 위치의 번호 리턴
            }
        }
    }
    return -1;  // 더 이상 선택할 곳이 없을 경우
}

// 게임을 진행하는 함수 (사람 vs 사람 또는 사람 vs AI)
void playGame(int vsAI) {
    int choice;
    while (1) {
        printBoard();  // 게임 보드 출력

        // 사람 vs AI일 경우, AI는 'O'로 플레이
        if (vsAI && currentPlayer == 'O') {
            printf("AI의 차례입니다.\n");
            choice = getAIChoice();  // AI 선택
        }
        else {
            // 사람 플레이어의 차례
            printf("플레이어 %c, 선택하세요 (1-9): ", currentPlayer);
            scanf_s("%d", &choice);
        }

        makeMove(choice);  // 해당 선택에 따라 보드 업데이트

        // 승리 조건 검사
        if (checkWin()) {
            printBoard();
            printf("플레이어 %c 승리!\n", currentPlayer);
            break;
        }

        // 무승부 조건 검사
        if (checkDraw()) {
            printBoard();
            printf("무승부!\n");
            break;
        }

        // 턴 변경: 'X'와 'O'가 번갈아가며 진행
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

// 게임을 시작하는 함수
int main() {
    int choice;
    char playAgain;

    // 게임 초기화
    srand(time(NULL));  // 랜덤 함수 초기화

    do {
        // 게임 모드 선택 (사람 vs 사람 또는 사람 vs AI)
        printf("틱택토 게임\n");
        printf("1. 사람 vs 사람\n");
        printf("2. 사람 vs AI\n");
        printf("선택: ");
        scanf_s("%d", &choice);

        if (choice == 1) {
            playGame(0);  // 사람 대 사람
        }
        else if (choice == 2) {
            playGame(1);  // 사람 대 AI
        }
        else {
            printf("잘못된 선택입니다.\n");
            continue;
        }

        // 게임 종료 후 재시작 여부 확인
        printf("게임을 다시 하시겠습니까? (Y/N): ");
        scanf_s(" %c", &playAgain);
        if (playAgain == 'Y' || playAgain == 'y') {
            resetBoard();  // 보드 초기화
            currentPlayer = 'X';  // 'X'가 먼저 시작
        }

    } while (playAgain == 'Y' || playAgain == 'y');

    printf("게임 종료!\n");
    return 0;
}
