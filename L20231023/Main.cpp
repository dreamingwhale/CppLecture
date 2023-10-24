#include <iostream>
#define COUNT		10

using namespace std;

//bit
//byte = 8bit = max 255
//2byte = 16bit = max 65535 = int(4byte) 원래는 2byte였지만 현재는 성능이 좋아져서 4byte를 잡는다.
//float = 32bit 실수. 소수 6번째는 표현하지 못함.
//long long = 64bit
//산술연산자,논리연산자,증감연산자


void Render(int PlayerLocationX, int PlayerLocationY, int GoalLocationX, int GoalLocationY, char PlayerShape, char GoalShape) {
	char Map[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 0 || i == 9 || j == 0 || j == 9) {
				Map[i][j] = '*';
			}
			else {
				Map[i][j] = ' ';
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == PlayerLocationX && i == PlayerLocationY) {
				cout << PlayerShape;
			}
			else if (j == GoalLocationX && i == GoalLocationY) {
				cout << GoalShape;
			}
			else {
				cout << Map[i][j];
			}

		}
		cout << endl;
	}

}
int Move(int PlayerLocationX, int PlayerLocationY, int GoalLocationX, int GoalLocationY, char Controller) {
	if (Controller == 'R') {
		if (PlayerLocationX < 10 && PlayerLocationX >= 1) {
			PlayerLocationX++;
			return PlayerLocationX;
		}
		else {
			return PlayerLocationX;
		}

		
	}
	else if (Controller == 'L') {
		if (PlayerLocationX <= 10 && PlayerLocationX > 1) {
			PlayerLocationX--;
			return PlayerLocationX;
		}
		else {
			return PlayerLocationX;
		}
	}
	else if (Controller == 'U') {
		if (PlayerLocationY < 10 && PlayerLocationY >= 1) {
			PlayerLocationY++;
			return PlayerLocationY;
		}
		else {
			return PlayerLocationY;
		}		
	}
	else if (Controller == 'D') {
		if (PlayerLocationY <= 10 && PlayerLocationX > 1) {
			PlayerLocationY--;
		return PlayerLocationY;
		}
		else {
			return PlayerLocationY;
		}
	}
	else {
		return 1;
	}
}



int main() {
	/*
	cout << "Hello World" << endl;
	for (int i = 1; i <= 5; i++) {
		printf("%d의 제곱은 %d입니다.\n", i, i + 1);
	}


	auto F = [](float newFloat, float newFloat2) ->float {bool a = (newFloat * newFloat2) == 0.02; std::cout << a << endl; return 0; };
	F(0.1, 0.2);

	int Korean = 100;
	int Math = 20;
	int English = 10;
	char T = (char)Korean;
	//Array
	int ArrayNum[COUNT][3];
	for (int i = 0; i < 10; i++) {
		ArrayNum[i][0] = 100;
	}
	for (int i = 0; i < 10; i++) {
		ArrayNum[i][1] = 10;
	}
	for (int i = 0; i < 10; i++) {
		ArrayNum[i][2] = 20;
	}
	//for (auto data : ArrayNum) {

	//}


	int Total = Korean + Math + English;
	float Average = (float)Total / 3.0f;

	cout << (int)(Average + 0.5f) << endl; //반올림하는 스킬
	cout << (int)Average + 0.5f << endl;
	cout << T << endl;
	*/

	int PlayerLocationX = 1;
	int PlayerLocationY = 1;
	int GoalLocationX = 8;
	int GoalLocationY = 8;
	char PlayerShape = 'P';
	char GoalShape = 'G';
	char Controller = ' ';

	int tmp = 0;
	int oddTotal = 0;
	int evenTotal = 0;
	int FourAddTotalUntilHundred = 0;
	int Sign = 1;
	int SignTotal = 0;

	for (int i = 0; i <= 100; i++) {
		tmp += i;
		if (i % 2 == 1) {
			oddTotal += i;
		}
		else if (i % 2 == 0) {
			evenTotal += i;
		}
	}
	for (int i = 0; i <= 100; i += 4) {
		FourAddTotalUntilHundred += i;
	}
	for (int i = 1; i <= 100; i++) {
		Sign = Sign * -1;
		SignTotal += i;
	}
	cout << tmp << endl;
	cout << oddTotal << endl;
	cout << evenTotal << endl;
	cout << FourAddTotalUntilHundred << endl;
	for (int i = 0; i < 5; i++) {
		cout << "*";
	}
	cout << endl;

	//*피라미드 그리기

	int Column = 0;
	int Stars = 0;
	//	cin >> Column;
	for (int i = 0; i < Column; i++) {
		for (int j = 0; j <= i; j++) {
			cout << '*';
		}
		cout << endl;
	}


	do {

		Render(PlayerLocationX, PlayerLocationY, GoalLocationX, GoalLocationY, PlayerShape, GoalShape);
		cout << "방향을 입력하세요(R,L,U,D)" << endl;
		cin >> Controller;
		cout << "입력값:" + Controller;
		if (Controller == 'R' || Controller == 'L') {
			PlayerLocationX = Move(PlayerLocationX, PlayerLocationY, GoalLocationX, GoalLocationY, Controller);
		}
		else if (Controller == 'U' || Controller == 'D') {
			PlayerLocationY = Move(PlayerLocationX, PlayerLocationY, GoalLocationX, GoalLocationY, Controller);
		}
		else {
			cout << "R,L,U,D를 입력해주세요." << endl;
		}

	} while ((PlayerLocationX != GoalLocationX) && (PlayerLocationX != GoalLocationY));

	return 0;
}

