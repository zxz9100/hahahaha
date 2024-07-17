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
int Order = 0;
int life1 = 4;
int life2 = 9;
int gun3[8] = {0, 0, 0, 0, 0, 0, 0, 0};
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
    
    do
    {
        if (Order == 8)
        {
            gunStatus();
            Order = 0;
            printf("총알 다시 장전중....\n");
            Sleep(2000);
            system("cls");
        }
        game();
        Player();
        system("cls");
    } while (o == 1);

    // if (p[0] == ' ' && p[1] == ' ' && p[2] == ' ' && p[3] == ' ' && p[4] ==  ' ')
    // {
    //     printf("%s님 승리!!!\n", name2);
    // }
    // else if (p[5] == ' ' && p[6] == ' ' && p[7] == ' ' && p[8] == ' ' && p[9] == ' ')
    // {
    //     printf("%s님 승리!!!\n", name1);
    // }
    
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
    for (int i = 0; i < 8; i++)
    {
        printf("%d\n", gun3[i]);
    }
    return 0;
}

int Player()
{
    if (i == 0)
    {
        printf("%s님 차례 : ", name1);
        scanf("%s", answer);
        if (strcmp(answer, "1") == 0 ||  strcmp(answer, "상대") == 0)
        {
            if (gun3[Order] == 0)
            {
                printf("실탄");
                Sleep(2000);
                p[life2] = ' ';
                life2 --;
                i = 1;
            }
            else if (gun3[Order] == 1)
            {
                printf("공포탄");
                Sleep(2000);
                i = 1;
            }
            Order ++;
        }
        else if (strcmp(answer, "2") == 0 || strcmp(answer, "나") == 0)
        {
            if (gun3[Order] == 0)
            {
                printf("실탄");
                Sleep(2000);
                p[life1] = ' ';
                life1 --;
                i = 1;
            }
            else if (gun3[Order] == 1)
            {
                printf("공포탄");
                Sleep(2000);
            }
            Order ++;
        }
        
    }
    else if (i == 1)
    {
        printf("%s님 차례 : ", name2);
        scanf("%s", answer);
        if (strcmp(answer, "1") == 0 ||  strcmp(answer, "상대") == 0)
        {
            if (gun3[Order] == 0)
            {
                printf("실탄");
                Sleep(2000);
                p[life1] = ' ';
                life1 --;
                i = 0;
            }
            else if (gun3[Order] == 1)
            {
                printf("공포탄");
                Sleep(2000);
                i = 0;
            }
            Order ++;
        }
        else if (strcmp(answer, "2") == 0 || strcmp(answer, "나") == 0)
        {
            if (gun3[Order] == 0)
            {
                printf("실탄");
                Sleep(2000);
                p[life2] = ' ';
                life2 --;
                i = 0;
            }
            else if (gun3[Order] == 1)
            {
                printf("공포탄");
                Sleep(2000);
            }
            Order ++;
        }
    }
    
    return 0;
}

int name()
{
    do
    {
    printf("첫번째 플레이어 이름 : ");
    gets(name1);
    system("cls");
    } while (strcmp(name1, "") == 0 || strcmp(name1, " ") == 0);
    
    do
    {
    printf("두번째 플레이어 이름 : ");
    gets(name2);
    system("cls");        
    } while (strcmp(name2, "") == 0 || strcmp(name2, " ") == 0);
    
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

int gunStatus()
{
    do
    {
        gun1 = 0;
        gun2 = 0;
       
       for (int i = 0; i < 8; i++)
        {
            gun3[i] = rand() % 2;

            if (gun3[i] == 0)
            {
                gun1++;
            }
            else if (gun3[i] == 1)
            {
                gun2++;
            }
        } 
    } while (gun1 == 0 || gun2 == 0);
    
    return 0;
}
