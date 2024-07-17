#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

//함수
int game();
int name();
int Player();
int gunStatus();
int FirstPlayer();

//이름
char name1[30];
char name2[30];

//플레이어 대답
char answer[100];

//변수
int gun1;
int gun2;
int i;

//목숨
char p[10] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};

int main()
{
    int o = 1;

    srand(time(NULL));

    name();
    i = FirstPlayer();
    gunStatus();

    while (o == 1)
    {
        game();
        Player();
        system("cls");
    }

    return 0;
}

int game()
{
    printf("실 : %d\n", gun1);
    printf("공 : %d\n", gun2);
    printf("------------------------------------------------------------------------------\n");
    printf("|%s\n", name1);
    printf("|                                                                            |\n");
    printf("|                                                                            |\n");
    printf("|                                                                            |\n");
    printf("|                                                                            |\n");
    printf("|목숨 : %c %c %c %c %c                                                            |\n", p[0], p[1] ,p[2], p[3], p[4]);
    printf("------------------------------------------------------------------------------\n");
    printf("|목숨 : %c %c %c %c %c                                                            |\n", p[5], p[6], p[7], p[8], p[9]);
    printf("|                                                                            |\n");
    printf("|                                                                            |\n");
    printf("|                                                                            |\n");
    printf("|                                                                            |\n");
    printf("|%s\n", name2);
    printf("------------------------------------------------------------------------------\n");
    printf("상대 : 1\n");
    printf("나 :  2\n");

    return 0;
}

int name()
{
    printf("첫번째 플레이어 이름 : ");
    gets(name1);
    printf("두번째 플레이어 이름 : ");
    gets(name2);
    system("cls");
    printf("플레이어 이름 저장 완료!\n");
    printf("게임을 시작 합니다.\n");
    Sleep(5000);
    system("cls");

    return 0;
}

int FirstPlayer()
{
    int i = rand() % 2;

    if (i == 0)
    {
        printf("%s님 선공\n", name1);
        Sleep(3000);
        system("cls");
    }
    else if (i == 1)
    {
        printf("%s님 선공\n", name2);
        Sleep(3000);
        system("cls");
    }

    return i;
}

int Player()
{
    if (i == 0)
    {
        printf("%s님 차례 : ", name1);
        scanf("%s", answer);
        if (strcmp(answer, "1") == 0 || strcmp(answer, "2") == 0 || strcmp(answer, "상대") == 0 || strcmp(answer, "나") == 0)
        {
            i = 1;
        }
    }
    else if (i == 1)
    {
        printf("%s님 차례 : ", name2);
        scanf("%s", answer);
        if (strcmp(answer, "1") == 0 || strcmp(answer, "2") == 0 || strcmp(answer, "상대") == 0 || strcmp(answer, "나") == 0)
        {
            i = 0;
        }

    }

    return 0;
}

int gunStatus()
{
    do
    {
        gun1 = 0;
        gun2 = 0;

       for (int i = 0; i < 8; i++)
        {
            int gun = rand() % 3;

            if (gun == 0)
            {
                gun1++;
            }
            else if (gun == 2)
            {
                gun2++;
            }
        } 
    } while (gun1 == 0 || gun2 == 0);

    return 0;
}
