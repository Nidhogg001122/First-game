#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
void BEGING();
void GAME();
void PVP();
void PVE();
char BOARD[3][3] = {"   ","   ","   "};
void PLAY1();
void PLAY2();
void EPLAY1();
void EPLAY2();
void MOVE();
void WIN1();
void WIN2();
void WIN3();
void WIN4();
int i = 0, j = 0, x = 0, y = 0, t = 0, c = 0, d = 0, k = 0, l = 0;


int a = 0, b = 0;
int main()
{
	BEGING();
	return 0;
}
void BEGING()
{
	int k = 0, l = 0;
	int a=0;
	for (k = 0; k < 3; k++)
	{
		for (l = 0; l < 3; l++)
		{
			BOARD[k][l] = ' ';
		}
	}
	printf("请选择：\n");
	printf("1.开始\n");
	printf("2.结束\n");
	scanf("%d", &a);
	if (a==1)
	{
		GAME();
	}
	if (a==2)
	{
		printf("谢谢使用");
		exit(0);
	}
	if(a!=1&&a!=2)
	{
		printf("请正确输入\n");
		getchar();
		return BEGING();
	}
}
void GAME()
{
	int b = 0;
	printf("请选择:\n");
	printf("1.和小伙伴玩\n");
	printf("2.人机对战\n");
	scanf("%d", &b);
	if (b == 1 || b == 2)
	{
		if (b == 1)
		{
			PVP();
			
		}
		else
		{
			PVE();
			
		}
	}
	else
	{
		printf("请正确输入\n");
		return GAME();
	}
		
}
void PVP()
{
	printf("请一号玩家先行，输入坐标以空格隔开,先行后列\n");
	printf("请二号玩家决定使用1.X或2.O\n");
	scanf("%d", &d);
	if (d == 2)
	{
		MOVE();
		PLAY1();
		for (t = 0; t <= 5; t++)
		{
			printf("一号玩家走：\n");
			MOVE();
			printf("         \n");
			if (t < 5)
			{
				PLAY2();
				printf("二号玩家走：\n");
				MOVE();
				printf("         \n");
			}
			PLAY1();
			WIN2();
		}
	}
	if (d == 1)
	{
		MOVE();
		PLAY2();
		for (t = 0; t <= 5; t++)
		{
			printf("一号玩家走：\n");
			MOVE();
			printf("         \n");
			if (t < 5)
			{
				PLAY1();
				printf("二号玩家走：\n");
				MOVE();
				printf("         \n");
			}
			PLAY2();
			WIN4();
		}
	}
	if (d != 1 || d != 2)
	{
		printf("请重新输入\n");
		return BEGING();
	}

}
void PVE()
{
	printf("请先行，输入坐标以空格隔开,先行后列\n");
	printf("请选择使用1.X或2.O\n");
	scanf("%d", &c);
	if (c == 1)
	{
		MOVE();
		PLAY1();
		for (t = 0; t <= 5; t++)
		{
			printf("你走：\n");
			MOVE();
			printf("         \n");
			if (t < 5)
			{
				EPLAY1();
				printf("电脑走：\n");
				MOVE();
				printf("         \n");
			}
			PLAY1();
			WIN1();
		}
	}
	if (c == 2)
	{
		MOVE();
		PLAY2();
		for (t = 0; t <= 5; t++)
		{
			printf("你走：\n");
			MOVE();
			printf("         \n");
			if (t < 5)
			{
				EPLAY2();
				printf("电脑走：\n");
				MOVE();
				printf("         \n");
			}
			PLAY2();
			WIN3();
		}
	}
	if (c != 1 || c != 2)
	{
		printf("请重新输入\n");
		return BEGING();
	}
}
void MOVE()
{
	for (i = 0; i < 3; i++)
	{
		printf(" %c | %c | %c |\n", BOARD[i][0], BOARD[i][1], BOARD[i][2]);
		printf("---|---|---|\n");
	}
}
void PLAY1()
{
	scanf("%d %d", &x, &y);
	if (x > 0 && x < 4 && y>0 && y < 4)
	{
		if (BOARD[x - 1][y - 1] == ' ')
		{
			BOARD[x - 1][y - 1] = 'X';
		}
		else
		{
			printf("错误，请重新开始\n");
			return BEGING();
		}
	}
	else
	{
		printf("错误，请重新开始\n");
		return BEGING();
	}
}
void EPLAY1()
{
	srand(time(NULL));
	while(b=2)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (BOARD[x][y] == ' ')
		{
			BOARD[x][y] = 'O';
			return;
		}
	}

}
void EPLAY2()
{
	srand(time(NULL));
	while (b = 2)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (BOARD[x][y] == ' ')
		{
			BOARD[x][y] = 'X';
			return;
		}
	}
}
void WIN1()
{

	if (t == 5)
	{
		printf("平局,三秒后返回\n");
		Sleep(3000);
		system("cls");
		return BEGING();
	}
	if ((BOARD[0][0] == 'X'&&BOARD[0][1] == 'X'&&BOARD[0][2] == 'X')||(BOARD[1][0] == 'X'&&BOARD[1][1] == 'X'&&BOARD[1][2] == 'X')||( BOARD[2][0] == 'X'&&BOARD[2][1] == 'X'&&BOARD[2][2] == 'X')||(BOARD[0][0] == 'X'&&BOARD[1][0] == 'X'&&BOARD[2][0] == 'X')||(BOARD[0][1] == 'X'&&BOARD[1][1] == 'X'&&BOARD[2][1] == 'X')||(BOARD[0][2] == 'X'&&BOARD[1][2] == 'X'&&BOARD[2][2] == 'X')||(BOARD[0][0] == 'X'&&BOARD[1][1] == 'X'&&BOARD[2][2] == 'X')||(BOARD[0][2] == 'X'&&BOARD[1][1] == 'X'&&BOARD[2][0] == 'X'))
	{
		printf("你打败了电脑,三秒后返回\n");
		Sleep(3000);
		system("cls");
		return BEGING();
	}
if ((BOARD[0][0] == 'O'&& BOARD[0][1] == 'O'&& BOARD[0][2] == 'O' )||( BOARD[1][0] == 'O'&&BOARD[1][1] == 'O'&& BOARD[1][2] == 'O')||( BOARD[2][0] == 'O'&& BOARD[2][1] == 'O'&& BOARD[2][2] == 'O' )|| (BOARD[0][0] == 'O'&& BOARD[1][0] == 'O'&&BOARD[2][0] == 'O' )||( BOARD[0][1] == 'O'&& BOARD[1][1] == 'O'&& BOARD[2][1] == 'O') ||( BOARD[0][2] == 'O'&& BOARD[1][2] == 'O'&& BOARD[2][2] == 'O' )|| (BOARD[0][0] == 'O'&& BOARD[1][1]=='O'&& BOARD[2][2]=='O')||(BOARD[0][2]=='O'&& BOARD[1][1]=='O'&& BOARD[2][0]=='O'))
	{
		printf("你被电脑打败了,三秒后返回\n");
		Sleep(3000);
		system("cls");
		return BEGING();
	}
}
void PLAY2()
{
	scanf("%d %d", &x, &y);
	if (x > 0 && x < 4 && y>0 && y < 4)
	{
		if (BOARD[x - 1][y - 1] == ' ')
		{
			BOARD[x - 1][y - 1] = 'O';
		}
		else
		{
			printf("错误，请重新开始\n");
			return BEGING();
		}
	}
	else
	{
		printf("错误，请重新开始\n");
		return BEGING();
	}
}
void WIN2()
{

	if (t == 5)
	{
		printf("平局,三秒后返回\n");
		Sleep(3000);
		system("cls");
		return BEGING();
	}
	if ((BOARD[0][0] == 'X' && BOARD[0][1] == 'X' && BOARD[0][2] == 'X') || (BOARD[1][0] == 'X' && BOARD[1][1] == 'X' && BOARD[1][2] == 'X') || (BOARD[2][0] == 'X' && BOARD[2][1] == 'X' && BOARD[2][2] == 'X') || (BOARD[0][0] == 'X' && BOARD[1][0] == 'X' && BOARD[2][0] == 'X') || (BOARD[0][1] == 'X' && BOARD[1][1] == 'X' && BOARD[2][1] == 'X') || (BOARD[0][2] == 'X' && BOARD[1][2] == 'X' && BOARD[2][2] == 'X') || (BOARD[0][0] == 'X' && BOARD[1][1] == 'X' && BOARD[2][2] == 'X') || (BOARD[0][2] == 'X' && BOARD[1][1] == 'X' && BOARD[2][0] == 'X'))
	{
		printf("一号玩家打败了二号玩家,三秒后返回\n");
		Sleep(3000);
		system("cls");
		return BEGING();
	}
	if ((BOARD[0][0] == 'O' && BOARD[0][1] == 'O' && BOARD[0][2] == 'O') || (BOARD[1][0] == 'O' && BOARD[1][1] == 'O' && BOARD[1][2] == 'O') || (BOARD[2][0] == 'O' && BOARD[2][1] == 'O' && BOARD[2][2] == 'O') || (BOARD[0][0] == 'O' && BOARD[1][0] == 'O' && BOARD[2][0] == 'O') || (BOARD[0][1] == 'O' && BOARD[1][1] == 'O' && BOARD[2][1] == 'O') || (BOARD[0][2] == 'O' && BOARD[1][2] == 'O' && BOARD[2][2] == 'O') || (BOARD[0][0] == 'O' && BOARD[1][1] == 'O' && BOARD[2][2] == 'O') || (BOARD[0][2] == 'O' && BOARD[1][1] == 'O' && BOARD[2][0] == 'O'))
	{
		printf("二号玩家打败了一号玩家,三秒后返回\n");
		Sleep(3000);
		system("cls");
		return BEGING();
	}
}
void WIN3()
{
	if (t == 5)
	{
		printf("平局,三秒后返回\n");
		Sleep(3000);
		system("cls");
		return BEGING();
	}
	if ((BOARD[0][0] == 'O' && BOARD[0][1] == 'O' && BOARD[0][2] == 'O') || (BOARD[1][0] == 'O' && BOARD[1][1] == 'O' && BOARD[1][2] == 'O') || (BOARD[2][0] == 'O' && BOARD[2][1] == 'O' && BOARD[2][2] == 'O') || (BOARD[0][0] == 'O' && BOARD[1][0] == 'O' && BOARD[2][0] == 'O') || (BOARD[0][1] == 'O' && BOARD[1][1] == 'O' && BOARD[2][1] == 'O') || (BOARD[0][2] == 'O' && BOARD[1][2] == 'O' && BOARD[2][2] == 'O') || (BOARD[0][0] == 'O' && BOARD[1][1] == 'O' && BOARD[2][2] == 'O') || (BOARD[0][2] == 'O' && BOARD[1][1] == 'O' && BOARD[2][0] == 'O'))
	{
		printf("你打败了电脑,三秒后返回\n");
		Sleep(3000);
		system("cls");
		return BEGING();
	}
	if ((BOARD[0][0] == 'X' && BOARD[0][1] == 'X' && BOARD[0][2] == 'X') || (BOARD[1][0] == 'X' && BOARD[1][1] == 'X' && BOARD[1][2] == 'X') || (BOARD[2][0] == 'X' && BOARD[2][1] == 'X' && BOARD[2][2] == 'X') || (BOARD[0][0] == 'X' && BOARD[1][0] == 'X' && BOARD[2][0] == 'X') || (BOARD[0][1] == 'X' && BOARD[1][1] == 'X' && BOARD[2][1] == 'X') || (BOARD[0][2] == 'X' && BOARD[1][2] == 'X' && BOARD[2][2] == 'X') || (BOARD[0][0] == 'X' && BOARD[1][1] == 'X' && BOARD[2][2] == 'X') || (BOARD[0][2] == 'X' && BOARD[1][1] == 'X' && BOARD[2][0] == 'X'))
	{
		printf("你被电脑打败了,三秒后返回\n");
		Sleep(3000);
		system("cls");
		return BEGING();
	}
}
void WIN4()
{
	if (t == 5)
	{
		printf("平局,三秒后返回\n");
		Sleep(3000);
		system("cls");
		return BEGING();
	}
	if ((BOARD[0][0] == 'O' && BOARD[0][1] == 'O' && BOARD[0][2] == 'O') || (BOARD[1][0] == 'O' && BOARD[1][1] == 'O' && BOARD[1][2] == 'O') || (BOARD[2][0] == 'O' && BOARD[2][1] == 'O' && BOARD[2][2] == 'O') || (BOARD[0][0] == 'O' && BOARD[1][0] == 'O' && BOARD[2][0] == 'O') || (BOARD[0][1] == 'O' && BOARD[1][1] == 'O' && BOARD[2][1] == 'O') || (BOARD[0][2] == 'O' && BOARD[1][2] == 'O' && BOARD[2][2] == 'O') || (BOARD[0][0] == 'O' && BOARD[1][1] == 'O' && BOARD[2][2] == 'O') || (BOARD[0][2] == 'O' && BOARD[1][1] == 'O' && BOARD[2][0] == 'O'))
	{
		printf("一号玩家打败了二号玩家,三秒后返回\n");
		Sleep(3000);
		system("cls");
		return BEGING();
	}
	if ((BOARD[0][0] == 'X' && BOARD[0][1] == 'X' && BOARD[0][2] == 'X') || (BOARD[1][0] == 'X' && BOARD[1][1] == 'X' && BOARD[1][2] == 'X') || (BOARD[2][0] == 'X' && BOARD[2][1] == 'X' && BOARD[2][2] == 'X') || (BOARD[0][0] == 'X' && BOARD[1][0] == 'X' && BOARD[2][0] == 'X') || (BOARD[0][1] == 'X' && BOARD[1][1] == 'X' && BOARD[2][1] == 'X') || (BOARD[0][2] == 'X' && BOARD[1][2] == 'X' && BOARD[2][2] == 'X') || (BOARD[0][0] == 'X' && BOARD[1][1] == 'X' && BOARD[2][2] == 'X') || (BOARD[0][2] == 'X' && BOARD[1][1] == 'X' && BOARD[2][0] == 'X'))
	{
		printf("一号玩家打败了二号玩家,三秒后返回\n");
		Sleep(3000);
		system("cls");
		return BEGING();
	}
}

