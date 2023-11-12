#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool IsIncludeBroken(int number, int broken[], int brokenKey);

int FindDigit(int number);

int main() {
   
	int N;
    int M;
    int broken[11] = { 0, };
	scanf("%d\n%d", &N, &M);
    
    for (int index = 0; index < M; index++) {
        scanf("%d", &broken[index]);
    }
    int plus = N;
    bool CanPress = true;
    while (1) {
        CanPress = IsIncludeBroken(plus, broken, M);
        if (CanPress == 0 || plus - N > 500000) {
            break;
        }
        plus++;
    }
    
    CanPress = true;
    int minus = N;
    while (1) {
        CanPress = IsIncludeBroken(minus, broken, M);
        if (CanPress == 0 || N - minus > 500000) {
            if (minus < 0) {
            minus = -600000;
            }
            break;
        }
        minus--;
    }

    int onlyUpDown = 0;
    if (100 > N) {
        onlyUpDown = 100 - N;
    }
    else if (N > 100) {
        onlyUpDown = N - 100;
    }
    int digitMinus = FindDigit(minus);
    int digitPlus = FindDigit(plus);
    
    if (onlyUpDown < plus - N + digitPlus && onlyUpDown < N - minus + digitMinus) {
        printf("%d", onlyUpDown); // up down 키만 이용할 경우
    }
    else if (N - minus + digitMinus > plus - N + digitPlus) {
        printf("%d", plus - N + digitPlus);
    }
    else if (plus - N + digitPlus > N - minus + digitMinus) {
        printf("%d",N - minus + digitMinus);
    }
    else if (plus - N + digitPlus == N - minus + digitMinus) {
        printf("%d", plus - N + digitPlus);
    }
	return 0;
}

bool IsIncludeBroken(int number, int broken[], int brokenKey) {
    int element = 0;
    do {
        element = number % 10;
        for (int index = 0; index < brokenKey; index++) {
            if (broken[index] == element) {
                return true; // 채널 직접 못 누름 : true
            }
        }
        number /= 10;
    } while (number != 0);
    return false;
}

int FindDigit(int number) {
    int count = 0;
    if (number == 0) {
        return 1;
    }
    while (number != 0) {
        number /= 10;
        ++count;
    }
    return count;
}
