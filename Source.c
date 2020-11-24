#include <stdio.h>
#include <math.h>
#include <windows.h>

typedef enum {
	false,
	true
} bool;

int main(void)
{
	HANDLE hout = GetStdHandle(-11);
	int arr[24][80] = {0};
	bool isLeft = true;
	bool isEven = false;
	for (int i = 0; i < 40; i++) {
		for (int j = 23; j >= 0; j--) {
			COORD pos;
			if (isLeft) {
				pos = (COORD){ i, j };j += 1;
			}
			else {
				pos = (COORD){ 79 - i, 23 - j};
				
			}
			if (isEven) {
				pos.Y = 23 - pos.Y;
			}
			SetConsoleCursorPosition(hout, pos);
			printf("%d", arr[pos.Y][pos.X]);
			isLeft = !isLeft;
			
			Sleep(5);
		}
		isEven = !isEven;
	}
	SetConsoleCursorPosition(hout, (COORD){0,24});
	return 0;
}
