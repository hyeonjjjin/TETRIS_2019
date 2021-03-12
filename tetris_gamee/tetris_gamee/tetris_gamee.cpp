#include "pch.h"
#include "tetris.h"//테트리스 함수들
#include <iostream>
#include <time.h>//time 함수
#include <Windows.h>// Sleep 함수
#include <conio.h>//getch() 함수

#define center_x 16
#define center_y 4
#define left 75
#define right 77
#define down 80
#define rotate 72


typedef struct Point {
	int x;
	int y;
}Point;


void set_new_info(int* shape, int *direc, int* x, int* y)
{
	*x = center_x;
	*y = center_y;
	srand(time(NULL));
	*shape = rand() % 7;
	*direc = rand() % 4;
}

int print(int shape, int direc, int x, int y, int* max_x, int background[28][24])
{
	int ret = 0;
	//background[0][0] = 1;
	switch (shape)
	{
	case 0:
		ret = print_bar(shape, direc, x, y, max_x, background);
		break;
	case 1:
		ret = print_a1(shape, direc, x, y, max_x, background);
		break;
	case 2:
		ret = print_a2(shape, direc, x, y, max_x, background);
		break;
	case 3:
		ret = print_square(shape, direc, x, y, max_x, background);
		break;
	case 4:
		ret = print_b1(shape, direc, x, y, max_x, background);
		break;
	case 5:
		ret = print_b2(shape, direc, x, y, max_x, background);
		break;
	case 6:
		ret = print_o(shape, direc, x, y, max_x, background);
		break;
	}
	return ret;
}

int shift_p(int shape, int direc, int x, int y, int* max_x, int background[28][24])
{

	int ret = 0;
	switch (shape)
	{
	case 0:
		delete_bar(shape, direc, x, y, background, 1);
		ret = print_bar(shape, direc, x, y + 1, max_x, background);
		break;
	case 1:
		delete_a1(shape, direc, x, y, background, 1);
		ret = print_a1(shape, direc, x, y + 1, max_x, background);
		break;
	case 2:
		delete_a2(shape, direc, x, y, background, 1);
		ret = print_a2(shape, direc, x, y + 1, max_x, background);
		break;
	case 3:
		delete_square(shape, direc, x, y, background, 1);
		ret = print_square(shape, direc, x, y + 1, max_x, background);
		break;
	case 4:
		delete_b1(direc, x, y, background, 1);
		ret = print_b1(shape, direc, x, y + 1, max_x, background);
		break;
	case 5:
		delete_b2(direc, x, y, background, 1);
		ret = print_b2(shape, direc, x, y + 1, max_x, background);
		break;
	case 6:
		delete_o(direc, x, y, background, 1);
		ret = print_o(shape, direc, x, y + 1, max_x, background);
		break;
	}
	return ret;
}

int shift_l(int shape, int direc, int x, int y, int* max_x, int background[28][24])
{

	int ret = 0;
	switch (shape)
	{
	case 0:
		delete_bar(shape, direc, x, y, background, 0);
		ret = print_bar(shape, direc, x - spacee, y, max_x, background);
		if (ret < 0)	cancel_delete_bar(shape, direc, x, y, background);

		break;
	case 1:
		delete_a1(shape, direc, x, y, background, 0);
		ret = print_a1(shape, direc, x - spacee, y, max_x, background);
		if (ret < 0)	cancel_delete_a1(shape, direc, x, y, background);
		break;
	case 2:
		delete_a2(shape, direc, x, y, background, 0);
		ret = print_a2(shape, direc, x - spacee, y, max_x, background);
		if (ret < 0)	cancel_delete_a2(shape, direc, x, y, background);
		break;
	case 3:
		delete_square(shape, direc, x, y, background, 0);
		ret = print_square(shape, direc, x - spacee, y, max_x, background);
		if (ret < 0)	cancel_delete_square(shape, direc, x, y, background);
		break;
	case 4:
		delete_b1(direc, x, y, background, 0);
		ret = print_b1(shape, direc, x - spacee, y, max_x, background);
		if (ret < 0)	cancel_delete_b1(direc, x, y, background);
		break;
	case 5:
		delete_b2(direc, x, y, background, 0);
		ret = print_b2(shape, direc, x - spacee, y, max_x, background);
		if (ret < 0)	cancel_delete_b2(direc, x, y, background);
		break;
	case 6:
		delete_o(direc, x, y, background, 0);
		ret = print_o(shape, direc, x - spacee, y, max_x, background);
		if (ret < 0)	cancel_delete_o(direc, x, y, background);
		break;
	}
	return ret;
}

int shift_r(int shape, int direc, int x, int y, int* max_x, int background[28][24])
{
	int ret = 0;
	switch (shape)
	{
	case 0:
		delete_bar(shape, direc, x, y, background, 0);
		ret = print_bar(shape, direc, x + spacee, y, max_x, background);
		if (ret < 0)	cancel_delete_bar(shape, direc, x, y, background);
		break;
	case 1:
		delete_a1(shape, direc, x, y, background, 0);
		ret = print_a1(shape, direc, x + spacee, y, max_x, background);
		if (ret < 0)	cancel_delete_a1(shape, direc, x, y, background);
		break;
	case 2:
		delete_a2(shape, direc, x, y, background, 0);
		ret = print_a2(shape, direc, x + spacee, y, max_x, background);
		if (ret < 0)	cancel_delete_a2(shape, direc, x, y, background);
		break;
	case 3:
		delete_square(shape, direc, x, y, background, 0);
		ret = print_square(shape, direc, x + spacee, y, max_x, background);
		if (ret < 0)	cancel_delete_square(shape, direc, x, y, background);
		break;
	case 4:
		delete_b1(direc, x, y, background, 0);
		ret = print_b1(shape, direc, x + spacee, y, max_x, background);
		if (ret < 0)	cancel_delete_b1(direc, x, y, background);
		break;
	case 5:
		delete_b2(direc, x, y, background, 0);
		ret = print_b2(shape, direc, x + spacee, y, max_x, background);
		if (ret < 0)	cancel_delete_b2(direc, x, y, background);
		break;
	case 6:
		delete_o(direc, x, y, background, 0);
		ret = print_o(shape, direc, x + spacee, y, max_x, background);
		if (ret < 0)	cancel_delete_o(direc, x, y, background);
		break;
	}
	return ret;
}

void print_set(int level, int score, int shape_next, int direc_next, int background[28][24])//백그라운드 1인거 다출력하는 함수도 만들어야할듯
{

	for (int j = 4; j <= 23; j++)
	{
		for (int i = 8; i <= 26; i += 2)
		{
			if (background[i][j] == 2)
			{
				gotoxy(i, j);
				printf("■");
			}
		}
	}
	gotoxy(4, 2);
	printf("□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(4, 3);
	printf("□□□□□□□□□□□□□□□□□□□□□□");
	for (int i = 0; i < 20; i++)	printf("\n\t\b\b\b\b□□\t\t\t\b\b\b\b□□\t\t\b\b\b\b□□");
	gotoxy(4, 24);
	printf("□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(4, 25);
	printf("□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(32, 12);
	printf("□□□□□□");
	gotoxy(32, 13);
	printf("□□□□□□");
	gotoxy(35, 15);
	printf("LEVEL %d", level);
	gotoxy(32, 17);
	printf("□□□□□□");
	gotoxy(32, 18);
	printf("□□□□□□");
	gotoxy(36, 20);
	printf("SCORE");
	if (score == 0)	gotoxy(38, 22);
	else if (score > 1000) gotoxy(36, 22);
	else gotoxy(37, 22);
	printf("%d", score);
	//다음도형 출력
	//gotoxy(32, 8);
	print_next(shape_next, direc_next, 36, 8);
	gotoxy(36, 5);
	printf("NEXT");
}



void check_input(int shape, int* direc, int* x, int y, int* max_x, int background[28][24], int* input_down, int flag_1, int flag_2)
{
	int input = 0;
	int uaaaa = 0;
	if (_kbhit())
	{
		input = _getch();
		if (input == 224)
		{
			do {
				input = _getch();
			} while (input == 224);
		}
		switch (input)
		{
		case left:
			//system("cls");
			if (*x > 8)
			{
				uaaaa = shift_l(shape, *direc, *x, y, max_x, background);//지우는거 새로 만들어야할듯
				if (uaaaa > 0) {
					*x -= spacee;
					system("cls");
				}
			}
			break;
		case right:
			//	system("cls");
			if (*max_x < 26)//얘도
			{
				uaaaa = shift_r(shape, *direc, *x, y, max_x, background);
				if (uaaaa > 0) {
					*x += spacee;
					system("cls");
				}
			}
			break;
		case down:
			*input_down = 5;
			break;
		case rotate:
			//	system("cls");
			system("cls");
			switch (shape)
			{
			case 0:

				delete_bar(shape, *direc, *x, y, background, 0);

				break;
			case 1:
				delete_a1(shape, *direc, *x, y, background, 0);

				break;
			case 2:
				delete_a2(shape, *direc, *x, y, background, 0);

				break;
			case 3:
				delete_square(shape, *direc, *x, y, background, 0);

				break;
			case 4:
				delete_b1(*direc, *x, y, background, 0);

				break;
			case 5:
				delete_b2(*direc, *x, y, background, 0);

				break;
			case 6:
				delete_o(*direc, *x, y, background, 0);
				break;
			}
			if (*direc == 3)
				*direc = 0;
			else
				(*direc)++;//돌리면 멈춘다,,, 지우기 해야함
			break;//돌았ㅇ을때 겹치는게 없으면 돌고 아님 못돌고
		}

	}
}

int check_line(int background[28][24], int flag_line[24])
{
	int exist = 0;
	int j = 4;
	for (j = 4; j <= 23; ++j)
	{
		for (int i = 8; i <= 26; i += 2)
		{
			if (background[i][j] != 2)
			{
				flag_line[j] = 1;
				i = 27;
			}
			else if (i == 26)
			{
				flag_line[j] = 0;
				exist = 1;
			}
		}
	}
	return exist;
}

void line_complete(int* max_y, int background[28][24], int flag_line[24], int* score)
{
	for (int j = 23; j >= 4; --j)
	{
		if (flag_line[j] == 0)
		{
			//for (int i = 8; i <= 26; i += 2) background[i][j + 4] = 0;

			*score += 100;
			for (int k = j; k >= *max_y; k--)
			{
				for (int l = 8; l <= 26; l += 2)
					background[l][k] = background[l][k - 1];
			}
			(*max_y)++;
		}
	}


}

void check_game_end(int max_y, int level, int score, int shape_next, int direc_next, int* flag)
{
	if (max_y <= 4)
	{
		gotoxy(4, 2);
		printf("□□□□□□□□□□□□□□□□□□□□□□");
		gotoxy(4, 3);
		printf("□□□□□□□□□□□□□□□□□□□□□□");
		for (int i = 0; i < 20; i++)	printf("\n\t\b\b\b\b□□\t\t\t\b\b\b\b□□\t\t\b\b\b\b□□");
		gotoxy(4, 24);
		printf("□□□□□□□□□□□□□□□□□□□□□□");
		gotoxy(4, 25);
		printf("□□□□□□□□□□□□□□□□□□□□□□");
		gotoxy(32, 12);
		printf("□□□□□□");
		gotoxy(32, 13);
		printf("□□□□□□");
		gotoxy(35, 15);
		printf("LEVEL %d", level);
		gotoxy(32, 17);
		printf("□□□□□□");
		gotoxy(32, 18);
		printf("□□□□□□");
		gotoxy(36, 20);
		printf("SCORE");
		if (score == 0)	gotoxy(38, 22);
		else if (score > 1000)	gotoxy(36, 22);
		else gotoxy(37, 22);
		printf("%d", score);
		//다음도형 출력
		//gotoxy(32, 8);
		print_next(shape_next, direc_next, 36, 8);
		gotoxy(36, 5);
		printf("NEXT");

		gotoxy(14, 14);
		printf("GAME OVER");
		Sleep(400);
		gotoxy(14, 14);
		printf("         ");
		Sleep(300);
		gotoxy(14, 14);
		printf("GAME OVER");
		Sleep(400);
		gotoxy(14, 14);
		printf("         ");
		Sleep(300);
		gotoxy(14, 14);
		printf("GAME OVER");

		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		Sleep(3000);
		*flag = 0;

	}

}

int main()
{
	//gotoxy(center_x, center_y-1);
	//printf("☆");

	int shape = 0, shape_next = 0;
	int direc = 0, direc_next = 0;
	int x = 0, y = 0;
	int background[28][24] = { 0 };
	int flag = 1;//while문
	int flag_1 = 0;//칸이 겹쳐지는가
	int flag_2 = 1;//옮겨질 자리가 겹쳐지는가
//	int buffer = 0, input = 0;
	int max_x = 0;//오른쪽벽 못넘어가게하려구
	int max_y = 23;
	int is_max_y = 0;
	int flag_line[24] = { 0 };
	int exist = 0;
	int score = 0;
	int level = 1;
	int speed = 450;
	int total_p = 1;
	int repeat = 0;
	int input_down = 0;
	//case 첫번째 실행 초기조건
	srand(time(NULL));
	shape = rand() % 7;
	shape_next = rand() % 7;
	srand(time(NULL));
	direc = rand() % 4;
	direc_next = rand() % 4;
	x = center_x;
	y = center_y;

	getchar();
	gotoxy(8, 10);
	printf("□□□");
	gotoxy(10, 11);
	printf("□");
	gotoxy(10, 12);
	printf("□");
	gotoxy(10, 13);
	printf("□");
	gotoxy(10, 14);
	printf("□");

	gotoxy(16, 10);
	printf("□□□");
	gotoxy(16, 11);
	printf("□");
	gotoxy(16, 12);
	printf("□□□");
	gotoxy(16, 13);
	printf("□");
	gotoxy(16, 14);
	printf("□□□");

	gotoxy(24, 10);
	printf("□□□");
	gotoxy(26, 11);
	printf("□");
	gotoxy(26, 12);
	printf("□");
	gotoxy(26, 13);
	printf("□");
	gotoxy(26, 14);
	printf("□");

	gotoxy(32, 10);
	printf("□□□");
	gotoxy(32, 11);
	printf("□   □");
	gotoxy(32, 12);
	printf("□□□");
	gotoxy(32, 13);
	printf("□   □");
	gotoxy(32, 14);
	printf("□   □");

	gotoxy(41, 10);
	printf("□□□");
	gotoxy(43, 11);
	printf("□");
	gotoxy(43, 12);
	printf("□");
	gotoxy(43, 13);
	printf("□");
	gotoxy(41, 14);
	printf("□□□");

	gotoxy(49, 10);
	printf("□□□");
	gotoxy(48, 11);
	printf("□");
	gotoxy(49, 12);
	printf("□□□");
	gotoxy(54, 13);
	printf("□");
	gotoxy(49, 14);
	printf("□□□");

	gotoxy(26, 20);
	printf("- GAME START");
	gotoxy(28, 22);
	printf("> ENTER");

	getchar();
	system("cls");
	flag_1 = print(shape, direc, x, y, &max_x, background);
	print_set(level, score, shape_next, direc_next, background);
	while (flag)
	{


		exist = 0;

		if (flag_2 > 0)
			check_input(shape, &direc, &x, y, &max_x, background, &input_down, flag_1, flag_2);
		//system("cls");
		print_set(level, score, shape_next, direc_next, background);
		speed = check_level(&level, speed, total_p, &repeat);
		exist = check_line(background, flag_line);
		if (exist == 1)
		{
			total_p++;
			line_complete(&max_y, background, flag_line, &score);
		}
		if ((flag_1 > 0 && flag_2 < 23) && flag_2 > 0)
		{
			flag_2 = shift_p(shape, direc, x, y++, &max_x, background);

			if (input_down-- > 0)
				Sleep(50);
			else
				Sleep(speed);
		}

		else//땅에 닿음
		{
			if (flag_2 < 0)
				is_max_y = fix(shape, direc, x, y - 1, background);
			else
				is_max_y = fix(shape, direc, x, y, background);
			if (is_max_y < max_y)
				max_y = is_max_y;
			shape = shape_next;
			direc = direc_next;
			set_new_info(&shape_next, &direc_next, &x, &y);
			flag_1 = print(shape, direc, x, y, &max_x, background);
			flag_2 = 1;
			system("cls");
			print_set(level, score, shape_next, direc_next, background);
			check_game_end(max_y, level, score, shape_next, direc_next, &flag);

			//flag = 0;
		}

	}

	//system("cls");


}


/*
	system("cls");
	flag = print(1, 0, x, y, background);

	system("cls");
	flag = print(1, 1, x, y, background);

	system("cls");
	flag = print(1, 2, x, y, background);

	system("cls");
	flag = print(1, 3, x, y, background);
*/