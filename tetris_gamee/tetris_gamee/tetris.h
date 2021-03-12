#pragma once
#include <stdio.h>
#include <Windows.h>

#define center_x 16
#define center_y 4
#define spacee 2

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int print_bar(int shape, int direc, int x, int y, int* max_x, int background[28][24])
{
	int low_y = 0;
	switch (direc % 2)
	{
	case 0:
		for (int i = 0; i < 4; i++)
		{
			background[x - spacee + 2 * i][y]++;
			if (background[x - spacee + i * 2][y] > 1)
			{
				for (int j = 0; j <= i; j++)
					background[x - spacee + 2 * j][y]--;
				//	background[x - spacee + 2*i][y]--;
				return -1;
			}
		}
		gotoxy(x - spacee, y);
		printf("□□□□");
		low_y = y;
		*max_x = x + spacee * 2;
		break;
	case 1:

		for (int i = 0; i < 4; i++)
		{
			background[x][y + i]++;
			if (background[x][y + i] > 1)
			{
				for (int j = 0; j <= i; j++)
					background[x][y + j]--;
				//	background[x][y + i]--;
				return -1;
			}
		}

		gotoxy(x, y);
		printf("□");
		gotoxy(x, y + 1);
		printf("□");
		gotoxy(x, y + 2);
		printf("□");
		gotoxy(x, y + 3);
		printf("□");
		low_y = y + 3;
		*max_x = x;
		break;
	}

	return low_y;
}

void delete_bar(int shape, int direc, int x, int y, int background[28][24], int down)
{
	switch (direc % 2)
	{
	case 0:
		for (int i = 0; i < 4; i++)
			background[x - spacee + 2 * i][y]--;
		if (down == 1) {
			gotoxy(x - spacee, y);
			printf("        ");
		}
		break;
	case 1:
		for (int i = 0; i < 4; i++)
			background[x][y + i]--;
		gotoxy(x, y);
		printf("  ");
		gotoxy(x, y + 1);
		printf("  ");
		gotoxy(x, y + 2);
		printf("  ");
		gotoxy(x, y + 3);
		printf("  ");
		break;
	}
	return;
}

void cancel_delete_bar(int shape, int direc, int x, int y, int background[28][24])//ㄱㄱ
{
	switch (direc % 2)
	{
	case 0:
		for (int i = 0; i < 4; i++)
			background[x - spacee + 2 * i][y]++;
		break;
	case 1:
		for (int i = 0; i < 4; i++)
			background[x][y + i]++;
		break;
	}
	return;
}

int print_a1(int shape, int direc, int x, int y, int* max_x, int background[28][24])
{
	int low_y = 0;
	switch (direc)
	{
	case 0:
		if (++background[x][y + 1] > 1)
		{
			background[x][y + 1]--;
			return -1;
		}
		for (int i = 0; i < 3; i++)
		{
			background[x + 2 * i][y]++;
			if (background[x + i * 2][y] > 1)
			{
				for (int j = 0; j <= i; j++)	background[x + 2 * j][y]--;
				background[x][y + 1]--;
				//background[x + 2 * i][y] = 1;
				return -1;
			}
		}

		gotoxy(x, y);
		printf("□□□");
		gotoxy(x, y + 1);
		printf("□");
		low_y = y + 1;
		*max_x = x + spacee * 2;
		break;
	case 1:
		if (++background[x + spacee][y + 1] > 1)
		{
			background[x + spacee][y + 1]--;
			return -1;
		}
		if (++background[x + spacee][y + 2] > 1)
		{
			background[x + spacee][y + 2]--;
			background[x + spacee][y + 1]--;
			return -1;
		}
		for (int i = 0; i < 2; i++)
		{
			background[x + 2 * i][y]++;
			if (background[x + i * 2][y] > 1)
			{
				for (int j = 0; j <= i; j++)	background[x + 2 * j][y]--;
				background[x + spacee][y + 2]--;
				background[x + spacee][y + 1]--;
				//background[x - spacee + 2 * i][y] = 1;
				return -1;
			}
		}

		gotoxy(x, y);
		printf("□□");
		gotoxy(x + spacee, y + 1);
		printf("□");
		gotoxy(x + spacee, y + 2);
		printf("□");
		low_y = y + 2;
		*max_x = x + spacee;
		break;
	case 2:
		if (++background[x + 2 * spacee][y] > 1)
		{
			background[x + 2 * spacee][y]--;
			return -1;
		}
		for (int i = 0; i < 3; i++)
		{
			background[x + 2 * i][y + 1]++;
			if (background[x + i * 2][y + 1] > 1)
			{
				for (int j = 0; j <= i; j++)	background[x + 2 * j][y + 1]--;
				background[x + 2 * spacee][y]--;
				//background[x - spacee + 2 * i][y] = 1;
				return -1;
			}
		}

		gotoxy(x + 2 * spacee, y);
		printf("□");
		gotoxy(x, y + 1);
		printf("□□□");
		low_y = y + 1;
		*max_x = x + spacee * 2;
		break;
	case 3:
		if (++background[x][y] > 1)
		{
			background[x][y]--;
			return -1;
		}
		if (++background[x][y + 1] > 1)
		{
			background[x][y + 1]--;
			background[x][y]--;
			return -1;
		}
		for (int i = 0; i < 2; i++)
		{
			background[x + 2 * i][y + 2]++;
			if (background[x + i * 2][y + 2] > 1)
			{
				for (int j = 0; j <= i; j++)	background[x + 2 * j][y + 2]--;
				background[x][y + 1]--;
				background[x][y]--;
				//background[x - spacee + 2 * i][y] = 1;
				return -1;
			}
		}

		gotoxy(x, y);
		printf("□");
		gotoxy(x, y + 1);
		printf("□");
		gotoxy(x, y + 2);
		printf("□□");
		low_y = y + 2;
		*max_x = x + spacee;
		break;
	}
	return low_y;
}

void delete_a1(int shape, int direc, int x, int y, int background[28][24], int down)
{
	switch (direc)
	{
	case 0:
		for (int i = 0; i < 3; i++)
			background[x + 2 * i][y]--;
		background[x][y + 1]--;
		if (down == 1) {
			gotoxy(x, y);
			printf("      ");
			gotoxy(x, y + 1);
			printf("  ");
		}
		break;
	case 1:
		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y]--;
		background[x + spacee][y + 1]--;
		background[x + spacee][y + 2]--;
		if (down == 1) {
			gotoxy(x, y);
			printf("    ");
			gotoxy(x + spacee, y + 1);
			printf("  ");
			gotoxy(x + spacee, y + 2);
			printf("  ");
		}
		break;
	case 2:
		for (int i = 0; i < 3; i++)
			background[x + 2 * i][y + 1]--;
		background[x + 2 * spacee][y]--;
		if (down == 1) {
			gotoxy(x + 2 * spacee, y);
			printf("  ");
			gotoxy(x, y + 1);
			printf("      ");
		}
		break;
	case 3:
		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y + 2]--;
		background[x][y]--;
		background[x][y + 1]--;
		if (down == 1) {
			gotoxy(x, y);
			printf("  ");
			gotoxy(x, y + 1);
			printf("  ");
			gotoxy(x, y + 2);
			printf("    ");
		}
		break;
	}
}

void cancel_delete_a1(int shape, int direc, int x, int y, int background[28][24])
{
	switch (direc)
	{
	case 0:
		for (int i = 0; i < 3; i++)
			background[x + 2 * i][y]++;
		background[x][y + 1]++;
		break;
	case 1:
		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y]++;
		background[x + spacee][y + 1]++;
		background[x + spacee][y + 2]++;
		break;
	case 2:
		for (int i = 0; i < 3; i++)
			background[x + 2 * i][y + 1]++;
		background[x + 2 * spacee][y]++;
		break;
	case 3:
		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y + 2]++;
		background[x][y]++;
		background[x][y + 1]++;
		break;
	}
}

int print_a2(int shape, int direc, int x, int y, int* max_x, int background[28][24]) //수정 ㅇ
{
	int low_y = 0;
	switch (direc)
	{
	case 0:
		if (++background[x + 2 * spacee][y + 1] > 1)
		{
			background[x + 2 * spacee][y + 1]--;
			return -1;
		}
		for (int i = 0; i < 3; i++)
		{
			background[x + 2 * i][y]++;
			if (background[x + i * 2][y] > 1)
			{
				for (int j = 0; j <= i; j++)	background[x + 2 * j][y]--;
				background[x + 2 * spacee][y + 1]--;
				//background[x + 2 * i][y] = 1;
				return -1;
			}
		}

		gotoxy(x, y);
		printf("□□□");
		gotoxy(x + 2 * spacee, y + 1);
		printf("□");
		low_y = y + 1;
		*max_x = x + spacee * 2;
		break;
	case 1:
		if (++background[x + spacee][y] > 1)
		{
			background[x + spacee][y]--;
			return -1;
		}
		if (++background[x + spacee][y + 1] > 1)
		{
			background[x + spacee][y + 1]--;
			background[x + spacee][y]--;
			return -1;
		}
		for (int i = 0; i < 2; i++)
		{
			background[x + 2 * i][y + 2]++;
			if (background[x + i * 2][y + 2] > 1)
			{
				for (int j = 0; j <= i; j++)	background[x + 2 * j][y + 2]--;
				background[x + spacee][y + 1]--;
				background[x + spacee][y]--;
				//background[x - spacee + 2 * i][y] = 1;
				return -1;
			}
		}

		gotoxy(x + spacee, y);
		printf("□");
		gotoxy(x + spacee, y + 1);
		printf("□");
		gotoxy(x, y + 2);
		printf("□□");
		low_y = y + 2;
		*max_x = x + spacee;
		break;
	case 2:
		if (++background[x][y] > 1)
		{
			background[x][y]--;
			return -1;
		}
		for (int i = 0; i < 3; i++)
		{
			background[x + 2 * i][y + 1]++;
			if (background[x + i * 2][y + 1] > 1)
			{
				for (int j = 0; j <= i; j++)	background[x + 2 * j][y + 1]--;
				background[x][y]--;
				//background[x - spacee + 2 * i][y] = 1;
				return -1;
			}
		}

		gotoxy(x, y);
		printf("□");
		gotoxy(x, y + 1);
		printf("□□□");
		low_y = y + 1;
		*max_x = x + spacee * 2;
		break;
	case 3:
		if (++background[x][y + 1] > 1)
		{
			background[x][y + 1]--;
			return -1;
		}
		if (++background[x][y + 2] > 1)
		{
			background[x][y + 2]--;
			background[x][y + 1]--;
			return -1;
		}
		for (int i = 0; i < 2; i++)
		{
			background[x + 2 * i][y]++;
			if (background[x + i * 2][y] > 1)
			{
				for (int j = 0; j <= i; j++)	background[x + 2 * j][y]--;
				background[x][y + 2]--;
				background[x][y + 1]--;
				//background[x - spacee + 2 * i][y] = 1;
				return -1;
			}
		}

		gotoxy(x, y);
		printf("□□");
		gotoxy(x, y + 1);
		printf("□");
		gotoxy(x, y + 2);
		printf("□");
		low_y = y + 2;
		*max_x = x + spacee;
		break;
	}
	return low_y;
}

void delete_a2(int shape, int direc, int x, int y, int background[28][24], int down)
{
	switch (direc)
	{
	case 0:
		for (int i = 0; i < 3; i++)
			background[x + 2 * i][y]--;
		background[x + 2 * spacee][y + 1]--;
		if (down == 1) {
			gotoxy(x, y);
			printf("      ");
			gotoxy(x + 2 * spacee, y + 1);
			printf("  ");
		}
		break;
	case 1:
		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y + 2]--;
		background[x + spacee][y]--;
		background[x + spacee][y + 1]--;
		if (down == 1) {
			gotoxy(x + spacee, y);
			printf("  ");
			gotoxy(x + spacee, y + 1);
			printf("  ");
			gotoxy(x, y + 2);
			printf("    ");
		}
		break;
	case 2:
		for (int i = 0; i < 3; i++)
			background[x + 2 * i][y + 1]--;
		background[x][y]--;
		if (down == 1) {
			gotoxy(x, y);
			printf("  ");
			gotoxy(x, y + 1);
			printf("      ");
		}
		break;
	case 3:
		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y]--;
		background[x][y + 1]--;
		background[x][y + 2]--;
		if (down == 1) {
			gotoxy(x, y);
			printf("    ");
			gotoxy(x, y + 1);
			printf("  ");
			gotoxy(x, y + 2);
			printf("  ");
		}
		break;
	}
}

void cancel_delete_a2(int shape, int direc, int x, int y, int background[28][24])
{
	switch (direc)
	{
	case 0:
		for (int i = 0; i < 3; i++)
			background[x + 2 * i][y]++;
		background[x + 2 * spacee][y + 1]++;
		break;
	case 1:
		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y + 2]++;
		background[x + spacee][y]++;
		background[x + spacee][y + 1]++;
		break;
	case 2:
		for (int i = 0; i < 3; i++)
			background[x + 2 * i][y + 1]++;
		background[x][y]++;
		break;
	case 3:
		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y]++;
		background[x][y + 1]++;
		background[x][y + 2]++;
		break;
	}
}

int print_square(int shape, int direc, int x, int y, int* max_x, int background[28][24])//수정 ㅇ
{
	int low_y = 0;
	for (int i = 0; i < 2; i++)
	{
		background[x + 2 * i][y]++;
		if (background[x + i * 2][y] > 1)
		{
			for (int j = 0; j <= i; j++)	background[x + 2 * j][y]--;
			//background[x - spacee + 2 * i][y] = 1;
			return -1;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		background[x + 2 * i][y + 1]++;
		if (background[x + i * 2][y + 1] > 1)
		{
			for (int j = 0; j <= i; j++)	background[x + 2 * j][y + 1]--;
			for (int j = 0; j <= i; j++)	background[x + 2 * j][y]--;
			//background[x - spacee + 2 * i][y] = 1;
			return -1;
		}
	}
	gotoxy(x, y);
	printf("□□");
	gotoxy(x, y + 1);
	printf("□□");
	low_y = y + 1;
	*max_x = x + spacee;
	return y + 1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void delete_square(int shape, int direc, int x, int y, int background[28][24], int down)
{
	for (int i = 0; i < 2; i++)
		background[x + 2 * i][y]--;

	for (int i = 0; i < 2; i++)
		background[x + 2 * i][y + 1]--;

	if (down == 1) {
		gotoxy(x, y);
		printf("    ");
		gotoxy(x, y + 1);
		printf("    ");
	}
}

void cancel_delete_square(int shape, int direc, int x, int y, int background[28][24])
{
	for (int i = 0; i < 2; i++)
		background[x + 2 * i][y]++;

	for (int i = 0; i < 2; i++)
		background[x + 2 * i][y + 1]++;
}

int print_b1(int shape, int direc, int x, int y, int* max_x, int background[28][24])//수정 ㅇ
{
	int low_y = 0;
	switch (direc % 2)
	{
	case 0:
		for (int i = 0; i < 2; i++)
		{
			background[x + 2 * i][y]++;
			if (background[x + i * 2][y] > 1)
			{
				for (int j = 0; j <= i; j++)	background[x + 2 * j][y]--;
				//background[x - spacee + 2 * i][y] = 1;
				return -1;
			}
		}
		for (int i = 0; i < 2; i++)
		{
			background[x + spacee + 2 * i][y + 1]++;
			if (background[x + spacee + i * 2][y + 1] > 1)
			{
				for (int j = 0; j <= i; j++)	background[x + spacee + 2 * j][y + 1]--;
				for (int j = 0; j <= i; j++)	background[x + 2 * j][y]--;
				//background[x - spacee + 2 * i][y] = 1;
				return -1;
			}
		}
		gotoxy(x, y);
		printf("□□");
		gotoxy(x + spacee, y + 1);
		printf("□□");
		low_y = y + 1;
		*max_x = x + spacee * 2;
		break;
	case 1:
		if (++background[x + spacee][y] > 1)
		{
			background[x + spacee][y]--;
			return -1;
		}
		if (++background[x][y + 2] > 1)
		{
			background[x][y + 2]--;
			background[x + spacee][y]--;
			return -1;
		}
		for (int i = 0; i < 2; i++)
		{
			background[x + 2 * i][y + 1]++;
			if (background[x + i * 2][y + 1] > 1)
			{
				for (int j = 0; j <= i; j++)	background[x + 2 * j][y + 1]--;
				background[x][y + 2]--;
				background[x + spacee][y]--;
				//background[x - spacee + 2 * i][y] = 1;
				return -1;
			}
		}

		gotoxy(x + spacee, y);
		printf("□");
		gotoxy(x, y + 1);
		printf("□□");
		gotoxy(x, y + 2);
		printf("□");
		low_y = y + 2;
		*max_x = x + spacee;
		break;
	}
	return low_y;
}

void delete_b1(int direc, int x, int y, int background[28][24], int down)
{
	switch (direc % 2)
	{
	case 0:
		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y]--;

		for (int i = 0; i < 2; i++)
			background[x + spacee + 2 * i][y + 1]--;
		if (down == 1) {
			gotoxy(x, y);
			printf("    ");
			gotoxy(x + spacee, y + 1);
			printf("    ");
		}
		break;
	case 1:
		background[x + spacee][y]--;

		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y + 1]--;

		background[x][y + 2]--;
		if (down == 1) {
			gotoxy(x + spacee, y);
			printf("  ");
			gotoxy(x, y + 1);
			printf("    ");
			gotoxy(x, y + 2);
			printf("  ");
		}
		break;
	}
}

void cancel_delete_b1(int direc, int x, int y, int background[28][24])
{
	switch (direc % 2)
	{
	case 0:
		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y]++;
		for (int i = 0; i < 2; i++)
			background[x + spacee + 2 * i][y + 1]++;

		break;
	case 1:
		background[x + spacee][y]++;
		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y + 1]++;

		background[x][y + 2]++;
		break;
	}
}

int print_b2(int shape, int direc, int x, int y, int* max_x, int background[28][24])//수정 ㅇ
{
	int low_y = 0;
	switch (direc % 2)
	{
	case 0:
		for (int i = 0; i < 2; i++)
		{
			background[x + spacee + 2 * i][y]++;
			if (background[x + spacee + i * 2][y] > 1)
			{
				for (int j = 0; j <= i; j++)	background[x + spacee + 2 * j][y]--;
				//background[x - spacee + 2 * i][y] = 1;
				return -1;
			}
		}
		for (int i = 0; i < 2; i++)
		{
			background[x + 2 * i][y + 1]++;
			if (background[x + i * 2][y + 1] > 1)
			{
				for (int j = 0; j <= i; j++)	background[x + 2 * j][y + 1]--;
				for (int j = 0; j <= i; j++)	background[x + spacee + 2 * j][y]--;
				//background[x - spacee + 2 * i][y] = 1;
				return -1;
			}
		}
		gotoxy(x + spacee, y);
		printf("□□");
		gotoxy(x, y + 1);
		printf("□□");
		low_y = y + 1;
		*max_x = x + spacee * 2;
		break;
	case 1:
		if (++background[x][y] > 1)
		{
			background[x][y]--;
			return -1;
		}
		if (++background[x + spacee][y + 2] > 1)
		{
			background[x + spacee][y + 2]--;
			background[x][y]--;
			return -1;
		}
		for (int i = 0; i < 2; i++)
		{
			background[x + 2 * i][y + 1]++;
			if (background[x + i * 2][y + 1] > 1)
			{
				for (int j = 0; j <= i; j++)	background[x + 2 * j][y + 1]--;
				background[x + spacee][y + 2]--;
				background[x][y]--;
				//background[x - spacee + 2 * i][y] = 1;
				return -1;
			}
		}
		gotoxy(x, y);
		printf("□");
		gotoxy(x, y + 1);
		printf("□□");
		gotoxy(x + spacee, y + 2);
		printf("□");
		low_y = y + 2;
		*max_x = x + spacee;
		break;
	}
	return low_y;
}

void delete_b2(int direc, int x, int y, int background[28][24], int down)
{
	switch (direc % 2)
	{
	case 0:
		for (int i = 0; i < 2; i++)
			background[x + spacee + 2 * i][y]--;

		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y + 1]--;
		if (down == 1) {
			gotoxy(x + spacee, y);
			printf("    ");
			gotoxy(x, y + 1);
			printf("    ");
		}
		break;
	case 1:
		background[x][y]--;

		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y + 1]--;
		background[x + spacee][y + 2]--;
		if (down == 1) {
			gotoxy(x, y);
			printf("  ");
			gotoxy(x, y + 1);
			printf("    ");
			gotoxy(x + spacee, y + 2);
			printf("  ");
		}
		break;
	}
}

void cancel_delete_b2(int direc, int x, int y, int background[28][24])
{
	switch (direc % 2)
	{
	case 0:
		for (int i = 0; i < 2; i++)
			background[x + spacee + 2 * i][y]++;

		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y + 1]++;
		break;
	case 1:
		background[x][y]++;

		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y + 1]++;
		background[x + spacee][y + 2]++;
		break;
	}
}

int print_o(int shape, int direc, int x, int y, int* max_x, int background[28][24])//수정ㅇ
{
	int low_y = 0;
	switch (direc)
	{
	case 0:
		if (++background[x + spacee][y] > 1)
		{
			background[x + spacee][y]--;
			return -1;
		}
		for (int i = 0; i < 3; i++)
		{
			background[x + 2 * i][y + 1]++;
			if (background[x + i * 2][y + 1] > 1)
			{
				for (int j = 0; j <= i; j++)	background[x + 2 * j][y + 1]--;
				background[x + spacee][y]--;
				//background[x - spacee + 2 * i][y] = 1;
				return -1;
			}
		}

		gotoxy(x + spacee, y);
		printf("□");
		gotoxy(x, y + 1);
		printf("□□□");
		low_y = y + 1;
		*max_x = x + spacee * 2;
		break;
	case 1:
		if (++background[x][y] > 1)
		{
			background[x][y]--;
			return -1;
		}
		if (++background[x][y + 2] > 1)
		{
			background[x][y + 2]--;
			background[x][y]--;
			return -1;
		}
		for (int i = 0; i < 2; i++)
		{
			background[x + 2 * i][y + 1]++;
			if (background[x + i * 2][y + 1] > 1)
			{
				for (int j = 0; j <= i; j++)	background[x + 2 * j][y + 1]--;
				background[x][y + 2]--;
				background[x][y]--;
				//background[x - spacee + 2 * i][y] = 1;
				return -1;
			}
		}

		gotoxy(x, y);
		printf("□");
		gotoxy(x, y + 1);
		printf("□□");
		gotoxy(x, y + 2);
		printf("□");
		low_y = y + 2;
		*max_x = x + spacee;
		break;
	case 2:
		if (++background[x + spacee][y + 1] > 1)
		{
			background[x + spacee][y + 1]--;
			return -1;
		}
		for (int i = 0; i < 3; i++)
		{
			background[x + 2 * i][y]++;
			if (background[x + i * 2][y] > 1)
			{
				for (int j = 0; j <= i; j++)	background[x + 2 * j][y]--;
				background[x + spacee][y + 1]--;
				//background[x + 2 * i][y] = 1;
				return -1;
			}
		}

		gotoxy(x, y);
		printf("□□□");
		gotoxy(x + spacee, y + 1);
		printf("□");
		low_y = y + 1;
		*max_x = x + spacee * 2;
		break;
	case 3:
		if (++background[x + spacee][y] > 1)
		{
			background[x + spacee][y]--;
			return -1;
		}
		if (++background[x + spacee][y + 2] > 1)
		{
			background[x + spacee][y + 2]--;
			background[x + spacee][y]--;
			return -1;
		}
		for (int i = 0; i < 2; i++)
		{
			background[x + 2 * i][y + 1]++;
			if (background[x + i * 2][y + 1] > 1)
			{
				for (int j = 0; j <= i; j++)	background[x + 2 * j][y + 1]--;
				background[x + spacee][y + 2]--;
				background[x + spacee][y]--;
				//background[x - spacee + 2 * i][y] = 1;
				return -1;
			}
		}

		gotoxy(x + spacee, y);
		printf("□");
		gotoxy(x, y + 1);
		printf("□□");
		gotoxy(x + spacee, y + 2);
		printf("□");
		low_y = y + 2;
		*max_x = x + spacee;
		break;
	}
	return low_y;
}

void delete_o(int direc, int x, int y, int background[28][24], int down)
{
	switch (direc)
	{
	case 0:
		for (int i = 0; i < 3; i++)
			background[x + 2 * i][y + 1]--;

		background[x + spacee][y]--;
		if (down == 1) {
			gotoxy(x + spacee, y);
			printf("  ");
			gotoxy(x, y + 1);
			printf("      ");
		}
		break;
	case 1:
		background[x][y]--;

		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y + 1]--;

		background[x][y + 2]--;
		if (down == 1) {
			gotoxy(x, y);
			printf("  ");
			gotoxy(x, y + 1);
			printf("    ");
			gotoxy(x, y + 2);
			printf("  ");
		}
		break;
	case 2:
		for (int i = 0; i < 3; i++)
			background[x + 2 * i][y]--;
		background[x + spacee][y + 1]--;
		if (down == 1) {
			gotoxy(x, y);
			printf("      ");
			gotoxy(x + spacee, y + 1);
			printf("  ");
		}
		break;
	case 3:
		background[x + spacee][y]--;

		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y + 1]--;

		background[x + spacee][y + 2]--;
		if (down == 1) {
			gotoxy(x + spacee, y);
			printf("  ");
			gotoxy(x, y + 1);
			printf("    ");
			gotoxy(x + spacee, y + 2);
			printf("  ");
		}
		break;
	}
}

void cancel_delete_o(int direc, int x, int y, int background[28][24])
{
	switch (direc)
	{
	case 0:
		for (int i = 0; i < 3; i++)
			background[x + 2 * i][y + 1]++;

		background[x + spacee][y]++;
		break;
	case 1:
		background[x][y]++;
		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y + 1]++;
		background[x][y + 2]++;
		break;
	case 2:
		for (int i = 0; i < 3; i++)
			background[x + 2 * i][y]++;
		background[x + spacee][y + 1]++;
		break;
	case 3:
		background[x + spacee][y]++;

		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y + 1]++;

		background[x + spacee][y + 2]++;
		break;
	}
}


int fix(int shape, int direc, int x, int y, int background[28][24])
{

	switch (shape)
	{
	case 0:
		switch (direc % 2)
		{
		case 0:
			for (int i = 0; i < 4; i++)
				background[x - spacee + 2 * i][y] = 2;
			break;
		case 1:
			for (int i = 0; i < 4; i++)
				background[x][y + i] = 2;
			break;
		}
		break;
	case 1:
		switch (direc)
		{
		case 0:
			for (int i = 0; i < 3; i++)
				background[x + 2 * i][y] = 2;
			background[x][y + 1] = 2;
			break;
		case 1:
			for (int i = 0; i < 2; i++)
				background[x + 2 * i][y] = 2;
			background[x + spacee][y + 1] = 2;
			background[x + spacee][y + 2] = 2;
			break;
		case 2:
			for (int i = 0; i < 3; i++)
				background[x + 2 * i][y + 1] = 2;
			background[x + 2 * spacee][y] = 2;
			break;
		case 3:
			for (int i = 0; i < 2; i++)
				background[x + 2 * i][y + 2] = 2;
			background[x][y] = 2;
			background[x][y + 1] = 2;
			break;
		}
		break;
	case 2:
		switch (direc)
		{
		case 0:
			for (int i = 0; i < 3; i++)
				background[x + 2 * i][y]--;
			background[x + 2 * spacee][y + 1]--;
			/*gotoxy(x, y);
			printf("      ");
			gotoxy(x + 2 * spacee, y + 1);
			printf("  ");*/
			break;
		case 1:
			for (int i = 0; i < 2; i++)
				background[x + 2 * i][y + 2] = 2;
			background[x + spacee][y] = 2;
			background[x + spacee][y + 1] = 2;
			break;
		case 2:
			for (int i = 0; i < 3; i++)
				background[x + 2 * i][y + 1] = 2;
			background[x][y] = 2;
			break;
		case 3:
			for (int i = 0; i < 2; i++)
				background[x + 2 * i][y] = 2;
			background[x][y + 1] = 2;
			background[x][y + 2] = 2;
			break;
		}
		break;
	case 3:
		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y] = 2;

		for (int i = 0; i < 2; i++)
			background[x + 2 * i][y + 1] = 2;
		break;
	case 4:
		switch (direc % 2)
		{
		case 0:
			for (int i = 0; i < 2; i++)
				background[x + 2 * i][y] = 2;

			for (int i = 0; i < 2; i++)
				background[x + spacee + 2 * i][y + 1] = 2;
			break;
		case 1:
			background[x + spacee][y] = 2;

			for (int i = 0; i < 2; i++)
				background[x + 2 * i][y + 1] = 2;

			background[x][y + 2] = 2;
			break;
		}
		break;
	case 5:
		switch (direc % 2)
		{
		case 0:
			for (int i = 0; i < 2; i++)
				background[x + spacee + 2 * i][y] = 2;

			for (int i = 0; i < 2; i++)
				background[x + 2 * i][y + 1] = 2;
			break;
		case 1:
			background[x][y] = 2;

			for (int i = 0; i < 2; i++)
				background[x + 2 * i][y + 1] = 2;
			background[x + spacee][y + 2] = 2;
			break;
		}
		break;
	case 6:
		switch (direc)
		{
		case 0:
			for (int i = 0; i < 3; i++)
				background[x + 2 * i][y + 1] = 2;

			background[x + spacee][y] = 2;
			break;
		case 1:
			background[x][y] = 2;

			for (int i = 0; i < 2; i++)
				background[x + 2 * i][y + 1] = 2;

			background[x][y + 2] = 2;
			break;
		case 2:
			for (int i = 0; i < 3; i++)
				background[x + 2 * i][y] = 2;
			background[x + spacee][y + 1] = 2;
			break;
		case 3:
			background[x + spacee][y] = 2;

			for (int i = 0; i < 2; i++)
				background[x + 2 * i][y + 1] = 2;

			background[x + spacee][y + 2] = 2;
			break;
		}
		break;
	}
	return y;
}

void print_next(int shape_next, int direc_next, int x, int y)
{
	switch (shape_next)
	{
	case 0:
		switch (direc_next % 2)
		{
		case 0:
			gotoxy(x - spacee, y);
			printf("□□□□");
			break;
		case 1:
			gotoxy(x + 1, y - 1);
			printf("□");
			gotoxy(x + 1, y);
			printf("□");
			gotoxy(x + 1, y + 1);
			printf("□");
			gotoxy(x + 1, y + 2);
			printf("□");
			break;
		}
		break;
	case 1:
		switch (direc_next)
		{
		case 0:

			gotoxy(x - 1, y);
			printf("□□□");
			gotoxy(x - 1, y + 1);
			printf("□");
			break;
		case 1:
			gotoxy(x, y);
			printf("□□");
			gotoxy(x + spacee, y + 1);
			printf("□");
			gotoxy(x + spacee, y + 2);
			printf("□");
			break;
		case 2:
			gotoxy(x + 2 * spacee - 1, y);
			printf("□");
			gotoxy(x - 1, y + 1);
			printf("□□□");
			break;
		case 3:
			gotoxy(x, y);
			printf("□");
			gotoxy(x, y + 1);
			printf("□");
			gotoxy(x, y + 2);
			printf("□□");
			break;
		}
		break;
	case 2:
		switch (direc_next)
		{
		case 0:
			gotoxy(x - 1, y);
			printf("□□□");
			gotoxy(x + 2 * spacee - 1, y + 1);
			printf("□");
			break;
		case 1:
			gotoxy(x + spacee, y);
			printf("□");
			gotoxy(x + spacee, y + 1);
			printf("□");
			gotoxy(x, y + 2);
			printf("□□");
			break;
		case 2:
			gotoxy(x - 1, y);
			printf("□");
			gotoxy(x - 1, y + 1);
			printf("□□□");
			break;
		case 3:
			gotoxy(x, y);
			printf("□□");
			gotoxy(x, y + 1);
			printf("□");
			gotoxy(x, y + 2);
			printf("□");
			break;
		}
		break;
	case 3:
		gotoxy(x, y);
		printf("□□");
		gotoxy(x, y + 1);
		printf("□□");
		break;
	case 4:
		switch (direc_next % 2)
		{
		case 0:
			gotoxy(x - 1, y);
			printf("□□");
			gotoxy(x + spacee - 1, y + 1);
			printf("□□");
			break;
		case 1:
			gotoxy(x + spacee, y);
			printf("□");
			gotoxy(x, y + 1);
			printf("□□");
			gotoxy(x, y + 2);
			printf("□");
			break;
		}
		break;
	case 5:
		switch (direc_next % 2)
		{
		case 0:
			gotoxy(x + spacee - 1, y);
			printf("□□");
			gotoxy(x - 1, y + 1);
			printf("□□");
			break;
		case 1:
			gotoxy(x, y);
			printf("□");
			gotoxy(x, y + 1);
			printf("□□");
			gotoxy(x + spacee, y + 2);
			printf("□");
			break;
		}
		break;
	case 6:
		switch (direc_next)
		{
		case 0:
			gotoxy(x + spacee - 1, y);
			printf("□");
			gotoxy(x - 1, y + 1);
			printf("□□□");
			break;
		case 1:
			gotoxy(x, y);
			printf("□");
			gotoxy(x, y + 1);
			printf("□□");
			gotoxy(x, y + 2);
			printf("□");
			break;
		case 2:
			gotoxy(x - 1, y);
			printf("□□□");
			gotoxy(x + spacee - 1, y + 1);
			printf("□");
			break;
		case 3:
			gotoxy(x + spacee, y);
			printf("□");
			gotoxy(x, y + 1);
			printf("□□");
			gotoxy(x + spacee, y + 2);
			printf("□");
			break;
		}
		break;
	}
}

int check_level(int* level, int speed, int total_p, int* repeat)
{
	switch (total_p)
	{
	case 3:
		if ((*repeat) == 0)
		{
			(*repeat)++;
			(*level)++;
			speed = 400;
		}
		break;
	case 6:
		if ((*repeat) == 1)
		{
			(*repeat)++;
			(*level)++;
			speed = 350;
		}
		break;
	case 9:
		if ((*repeat) == 2)
		{
			(*repeat)++;
			(*level)++;
			speed = 300;
		}
		break;
	case 12:
		if ((*repeat) == 3)
		{
			(*repeat)++;
			(*level)++;
			speed = 250;
		}
		break;
	case 15:
		if ((*repeat) == 4)
		{
			(*repeat)++;
			(*level)++;
			speed = 200;
		}
		break;
	case 18:
		if ((*repeat) == 5)
		{
			(*repeat)++;
			(*level)++;
			speed = 150;
		}
		break;
	case 21:
		if ((*repeat) == 6)
		{
			(*repeat)++;
			(*level)++;
			speed = 100;
		}
		break;
	case 24:
		if ((*repeat) == 7)
		{
			(*repeat)++;
			(*level)++;
			speed = 50;
		}
		break;
	}
	return speed;
}
