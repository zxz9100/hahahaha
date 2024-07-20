#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

//함수
int game();
int name();
char *item();
int Player();
int gunStatus();
int FirstPlayer();
void Itemprocessing();

//이름
char name1[30];
char name2[30];

//플레이어 대답
char answer[100];

//플레이어 아이템
char m1[15] = "";
char m2[15] = "";
char m3[15] = "";
char m4[15] = "";
char m5[15] = "";
char m6[15] = "";
char m7[15] = "";
char m8[15] = "";

//변수
int gun1;
int gun2;
int Order = 0;
int life1 = 4;
int life2 = 9;
int gun3[8];
int i;

//목숨
char p[10] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};

int main()
{
    srand(time(NULL));

    name();
    i = FirstPlayer();
    gunStatus();
    Itemprocessing();
    
    do
    {
        if (gun3[Order] == 2)
        {
            printf("총알 다시 장전중....\n");
            Itemprocessing();
            gunStatus();
            Order = 0;
            Sleep(2000);
            system("cls");
        }
        game();
        Player();
        system("cls");
    } while (life1 >= 0 && life2 >= 5);

    if (life1 >= 0)
    {
        printf("%s님 승리!!!\n", name1);
        Sleep(5000);
    }
    else if (life2 >= 5)
    {
        printf("%s님 승리!!!\n", name2);
        Sleep(5000);
    }
    
    return 0;
}

int game()
{
    printf("실 : %d\n", gun1);
    printf("공 : %d\n", gun2);
    printf("------------------------------------------------------------------------------\n");
    printf("|%s : %s    %s    %s    %s\n", name1, m1, m2, m3, m4);
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
    printf("|%s : %s    %s    %s    %s\n", name2, m5, m6, m7, m8);
    printf("------------------------------------------------------------------------------\n");
    printf("상대 : 1\n");
    printf("나 :  2\n");
    // for (int i = 0; i < 8; i++)
    // {
    //     printf("%d\n", gun3[i]);
    // }
    return 0;
}

int Player()
{
    if (i == 0)
    {
        printf("%s님 차례 : ", name1);
        gets(answer);
        if (strcmp(answer, "1") == 0 ||  strcmp(answer, "상대") == 0)
        {
            if (gun3[Order] == 1)
            {
                printf("실탄");
                Sleep(2000);
                p[life2] = ' ';
                -- life2;
                i = 1;
            }
            else if (gun3[Order] == 0)
            {
                printf("공포탄");
                Sleep(2000);
                i = 1;
            }
            ++ Order;
        }
        else if (strcmp(answer, "2") == 0 || strcmp(answer, "나") == 0)
        {
            if (gun3[Order] == 1)
            {
                printf("실탄");
                Sleep(2000);
                p[life1] = ' ';
                -- life1;
                i = 1;
            }
            else if (gun3[Order] == 0)
            {
                printf("공포탄");
                Sleep(2000);
            }
            ++ Order;
        }
        else if (strcmp(answer, "수갑") == 0)
        {
            if (strcmp(m1, "수갑") == 0 || strcmp(m2, "수갑") == 0 || strcmp(m3, "수갑") == 0 || strcmp(m4, "수갑") == 0)
            {
            if (strcmp(m1, "수갑") == 0)
            {
                strcpy(m1, "");
            }
            else if (strcmp(m2, "수갑") == 0)
            {
                strcpy(m2, "");
            }
            else if (strcmp(m3, "수갑") == 0)
            {
                strcpy(m3, "");
            }
            else if (strcmp(m4, "수갑") == 0)
            {
                strcpy(m4, "");
            }
            else if (strcmp(m5, "수갑") == 0)
            {
                strcpy(m5, "");
            }
            else if (strcmp(m6, "수갑") == 0)
            {
                strcpy(m6, "");
            }
            else if (strcmp(m7, "수갑") == 0)
            {
                strcpy(m7, "");
            }
            else if (strcmp(m8, "수갑") == 0)
            {
                strcpy(m8, "");
            }
            //수갑 함수 만들기
        }
        else
        {
            printf("아이템이 없습니다.\n");
            Sleep(5000);
        }
    }
        else if (strcmp(answer, "아드레날린") == 0)
        {
            if (strcmp(m1, "아드레날린") == 0 || strcmp(m2, "아드레날린") == 0 || strcmp(m3, "아드레날린") == 0 || strcmp(m4, "아드레날린") == 0)
            {
                if (strcmp(m1, "아드레날린") == 0)
                {
                    strcpy(m1, "");
                }
                else if (strcmp(m2, "아드레날린") == 0)
                {
                    strcpy(m2, "");
                }
                else if (strcmp(m3, "아드레날린") == 0)
                {
                    strcpy(m3, "");
                }
                else if (strcmp(m4, "아드레날린") == 0)
                {
                    strcpy(m4, "");
                }
                else if (strcmp(m5, "아드레날린") == 0)
                {
                    strcpy(m5, "");
                }
                else if (strcmp(m6, "아드레날린") == 0)
                {
                    strcpy(m6, "");
                }
                else if (strcmp(m7, "아드레날린") == 0)
                {
                    strcpy(m7, "");
                }
                else if (strcmp(m8, "아드레날린") == 0)
                {
                    strcpy(m8, "");
                }
                //아드레날린 함수 만들기
            }
            else
            {
                printf("아이템이 없습니다.\n");
                Sleep(5000);
            }
        }
        else if (strcmp(answer, "담배") == 0)
        {
            if (strcmp(m1, "담배") == 0 || strcmp(m2, "담배") == 0 || strcmp(m3, "담배") == 0 || strcmp(m4, "담배") == 0)
            {
                if (strcmp(m1, "담배") == 0)
                {
                    strcpy(m1, "");
                }
                else if (strcmp(m2, "담배") == 0)
                {
                    strcpy(m2, "");
                }
                else if (strcmp(m3, "담배") == 0)
                {
                    strcpy(m3, "");
                }
                else if (strcmp(m4, "담배") == 0)
                {
                    strcpy(m4, "");
                }
                else if (strcmp(m5, "담배") == 0)
                {
                    strcpy(m5, "");
                }
                else if (strcmp(m6, "담배") == 0)
                {
                    strcpy(m6, "");
                }
                else if (strcmp(m7, "담배") == 0)
                {
                    strcpy(m7, "");
                }
                else if (strcmp(m8, "담배") == 0)
                {
                    strcpy(m8, "");
                }
                //담배 함수 만들기
            }
            else
            {
                printf("아이템이 없습니다.\n");
                Sleep(5000);
            }
        }
        else if (strcmp(answer, "대포폰") == 0)
        {
            if (strcmp(m1, "대포폰") == 0 || strcmp(m2, "대포폰") == 0 || strcmp(m3, "대포폰") == 0 || strcmp(m4, "대포폰") == 0)
            {
                if (strcmp(m1, "대포폰") == 0)
                {
                    strcpy(m1, "");
                }
                else if (strcmp(m2, "대포폰") == 0)
                {
                    strcpy(m2, "");
                }
                else if (strcmp(m3, "대포폰") == 0)
                {
                    strcpy(m3, "");
                }
                else if (strcmp(m4, "대포폰") == 0)
                {
                    strcpy(m4, "");
                }
                else if (strcmp(m5, "대포폰") == 0)
                {
                    strcpy(m5, "");
                }
                else if (strcmp(m6, "대포폰") == 0)
                {
                    strcpy(m6, "");
                }
                else if (strcmp(m7, "대포폰") == 0)
                {
                    strcpy(m7, "");
                }
                else if (strcmp(m8, "대포폰") == 0)
                {
                    strcpy(m8, "");
                }
                //대포폰 함수 만들기
            }
            else
            {
                printf("아이템이 없습니다.\n");
                Sleep(5000);
            }
        }
        else if (strcmp(answer, "톱") == 0)
        {
            if (strcmp(m1, "톱") == 0 || strcmp(m2, "톱") == 0 || strcmp(m3, "톱") == 0 || strcmp(m4, "톱") == 0)
            {
                if (strcmp(m1, "톱") == 0)
                {
                    strcpy(m1, "");
                }
                else if (strcmp(m2, "톱") == 0)
                {
                    strcpy(m2, "");
                }
                else if (strcmp(m3, "톱") == 0)
                {
                    strcpy(m3, "");
                }
                else if (strcmp(m4, "톱") == 0)
                {
                    strcpy(m4, "");
                }
                else if (strcmp(m5, "톱") == 0)
                {
                    strcpy(m5, "");
                }
                else if (strcmp(m6, "톱") == 0)
                {
                    strcpy(m6, "");
                }
                else if (strcmp(m7, "톱") == 0)
                {
                    strcpy(m7, "");
                }
                else if (strcmp(m8, "톱") == 0)
                {
                    strcpy(m8, "");
                }
                //톱 함수 만들기
            }
            else
            {
                printf("아이템이 없습니다.\n");
                Sleep(5000);
            }
        }
        else if (strcmp(answer, "맥주") == 0)
        {
            if (strcmp(m1, "맥주") == 0 || strcmp(m2, "맥주") == 0 || strcmp(m3, "맥주") == 0 || strcmp(m4, "맥주") == 0)
            {
                if (strcmp(m1, "맥주") == 0)
                {
                    strcpy(m1, "");
                }
                else if (strcmp(m2, "맥주") == 0)
                {
                    strcpy(m2, "");
                }
                else if (strcmp(m3, "맥주") == 0)
                {
                    strcpy(m3, "");
                }
                else if (strcmp(m4, "맥주") == 0)
                {
                    strcpy(m4, "");
                }
                else if (strcmp(m5, "맥주") == 0)
                {
                    strcpy(m5, "");
                }
                else if (strcmp(m6, "맥주") == 0)
                {
                    strcpy(m6, "");
                }
                else if (strcmp(m7, "맥주") == 0)
                {
                    strcpy(m7, "");
                }
                else if (strcmp(m8, "맥주") == 0)
                {
                    strcpy(m8, "");
                }
                //맥주 함수 만들기
            }
            else
            {
                printf("아이템이 없습니다.\n");
                Sleep(5000);
            }
        }
        else if (strcmp(answer, "인버터") == 0)
        {
            if (strcmp(m1, "인버터") == 0 || strcmp(m2, "인버터") == 0 || strcmp(m3, "인버터") == 0 || strcmp(m4, "인버터") == 0)
            {
                if (strcmp(m1, "인버터") == 0)
                {
                    strcpy(m1, "");
                }
                else if (strcmp(m2, "인버터") == 0)
                {
                    strcpy(m2, "");
                }
                else if (strcmp(m3, "인버터") == 0)
                {
                    strcpy(m3, "");
                }
                else if (strcmp(m4, "인버터") == 0)
                {
                    strcpy(m4, "");
                }
                else if (strcmp(m5, "인버터") == 0)
                {
                    strcpy(m5, "");
                }
                else if (strcmp(m6, "인버터") == 0)
                {
                    strcpy(m6, "");
                }
                else if (strcmp(m7, "인버터") == 0)
                {
                    strcpy(m7, "");
                }
                else if (strcmp(m8, "인버터") == 0)
                {
                    strcpy(m8, "");
                }
                //인버터 함수 만들기
            }
            else
            {
                printf("아이템이 없습니다.\n");
                Sleep(5000);
            }
    }
    else if (strcmp(answer, "상한 약") == 0 || strcmp(answer, "상한약") == 0)
    {
        if (strcmp(m1, "상한 약") == 0 || strcmp(m2, "상한 약") == 0 || strcmp(m3, "상한 약") == 0 || strcmp(m4, "상한 약") == 0)
        {
            if (strcmp(m1, "상한 약") == 0)
            {
                strcpy(m1, "");
            }
            else if (strcmp(m2, "상한 약") == 0)
            {
                strcpy(m2, "");
            }
            else if (strcmp(m3, "상한 약") == 0)
            {
                strcpy(m3, "");
            }
            else if (strcmp(m4, "상한 약") == 0)
            {
                strcpy(m4, "");
            }
            else if (strcmp(m5, "상한 약") == 0)
            {
                strcpy(m5, "");
            }
            else if (strcmp(m6, "상한 약") == 0)
            {
                strcpy(m6, "");
            }
            else if (strcmp(m7, "상한 약") == 0)
            {
                strcpy(m7, "");
            }
            else if (strcmp(m8, "상한 약") == 0)
            {
                strcpy(m8, "");
            }
            //상한약 함수 만들기
        }
        else
        {
            printf("아이템이 없습니다.\n");
            Sleep(5000);
        }
    }
    else if (strcmp(answer, "돋보기") == 0)
    {
        if (strcmp(m1, "돋보기") == 0 || strcmp(m2, "돋보기") == 0 || strcmp(m3, "돋보기") == 0 || strcmp(m4, "돋보기") == 0)
        {
            if (strcmp(m1, "돋보기") == 0)
            {
                strcpy(m1, "");
            }
            else if (strcmp(m2, "돋보기") == 0)
            {
                strcpy(m2, "");
            }
            else if (strcmp(m3, "돋보기") == 0)
            {
                strcpy(m3, "");
            }
            else if (strcmp(m4, "돋보기") == 0)
            {
                strcpy(m4, "");
            }
            else if (strcmp(m5, "돋보기") == 0)
            {
                strcpy(m5, "");
            }
            else if (strcmp(m6, "돋보기") == 0)
            {
                strcpy(m6, "");
            }
            else if (strcmp(m7, "돋보기") == 0)
            {
                strcpy(m7, "");
            }
            else if (strcmp(m8, "돋보기") == 0)
            {
                strcpy(m8, "");
            }
            //돋보기 함수 만들기
        }
        else
        {
            printf("아이템이 없습니다.\n");
            Sleep(5000);
        }
    }
    }
    else if (i == 1)
    {
        printf("%s님 차례 : ", name2);
        gets(answer);
        if (strcmp(answer, "1") == 0 ||  strcmp(answer, "상대") == 0)
        {
            if (gun3[Order] == 1)
            {
                printf("실탄");
                Sleep(2000);
                p[life1] = ' ';
                -- life1;
                i = 0;
            }
            else if (gun3[Order] == 0)
            {
                printf("공포탄");
                Sleep(2000);
                i = 0;
            }
            ++ Order;
        }
        else if (strcmp(answer, "2") == 0 || strcmp(answer, "나") == 0)
        {
            if (gun3[Order] == 1)
            {
                printf("실탄");
                Sleep(2000);
                p[life2] = ' ';
                -- life2;
                i = 0;
            }
            else if (gun3[Order] == 0)
            {
                printf("공포탄");
                Sleep(2000);
            }
            ++ Order;
        }
        else if (strcmp(answer, "수갑") == 0)
        {
            if (strcmp(m1, "수갑") == 0 || strcmp(m2, "수갑") == 0 || strcmp(m3, "수갑") == 0 || strcmp(m4, "수갑") == 0)
            {
            if (strcmp(m1, "수갑") == 0)
            {
                strcpy(m1, "");
            }
            else if (strcmp(m2, "수갑") == 0)
            {
                strcpy(m2, "");
            }
            else if (strcmp(m3, "수갑") == 0)
            {
                strcpy(m3, "");
            }
            else if (strcmp(m4, "수갑") == 0)
            {
                strcpy(m4, "");
            }
            else if (strcmp(m5, "수갑") == 0)
            {
                strcpy(m5, "");
            }
            else if (strcmp(m6, "수갑") == 0)
            {
                strcpy(m6, "");
            }
            else if (strcmp(m7, "수갑") == 0)
            {
                strcpy(m7, "");
            }
            else if (strcmp(m8, "수갑") == 0)
            {
                strcpy(m8, "");
            }
            //수갑 함수 만들기
        }
        else
        {
            printf("아이템이 없습니다.\n");
            Sleep(5000);
        }
    }
        else if (strcmp(answer, "아드레날린") == 0)
        {
            if (strcmp(m1, "아드레날린") == 0 || strcmp(m2, "아드레날린") == 0 || strcmp(m3, "아드레날린") == 0 || strcmp(m4, "아드레날린") == 0)
            {
                if (strcmp(m1, "아드레날린") == 0)
                {
                    strcpy(m1, "");
                }
                else if (strcmp(m2, "아드레날린") == 0)
                {
                    strcpy(m2, "");
                }
                else if (strcmp(m3, "아드레날린") == 0)
                {
                    strcpy(m3, "");
                }
                else if (strcmp(m4, "아드레날린") == 0)
                {
                    strcpy(m4, "");
                }
                else if (strcmp(m5, "아드레날린") == 0)
                {
                    strcpy(m5, "");
                }
                else if (strcmp(m6, "아드레날린") == 0)
                {
                    strcpy(m6, "");
                }
                else if (strcmp(m7, "아드레날린") == 0)
                {
                    strcpy(m7, "");
                }
                else if (strcmp(m8, "아드레날린") == 0)
                {
                    strcpy(m8, "");
                }
                //아드레날린 함수 만들기
            }
            else
            {
                printf("아이템이 없습니다.\n");
                Sleep(5000);
            }
        }
        else if (strcmp(answer, "담배") == 0)
        {
            if (strcmp(m1, "담배") == 0 || strcmp(m2, "담배") == 0 || strcmp(m3, "담배") == 0 || strcmp(m4, "담배") == 0)
            {
                if (strcmp(m1, "담배") == 0)
                {
                    strcpy(m1, "");
                }
                else if (strcmp(m2, "담배") == 0)
                {
                    strcpy(m2, "");
                }
                else if (strcmp(m3, "담배") == 0)
                {
                    strcpy(m3, "");
                }
                else if (strcmp(m4, "담배") == 0)
                {
                    strcpy(m4, "");
                }
                else if (strcmp(m5, "담배") == 0)
                {
                    strcpy(m5, "");
                }
                else if (strcmp(m6, "담배") == 0)
                {
                    strcpy(m6, "");
                }
                else if (strcmp(m7, "담배") == 0)
                {
                    strcpy(m7, "");
                }
                else if (strcmp(m8, "담배") == 0)
                {
                    strcpy(m8, "");
                }
                //담배 함수 만들기
            }
            else
            {
                printf("아이템이 없습니다.\n");
                Sleep(5000);
            }
        }
        else if (strcmp(answer, "대포폰") == 0)
        {
            if (strcmp(m1, "대포폰") == 0 || strcmp(m2, "대포폰") == 0 || strcmp(m3, "대포폰") == 0 || strcmp(m4, "대포폰") == 0)
            {
                if (strcmp(m1, "대포폰") == 0)
                {
                    strcpy(m1, "");
                }
                else if (strcmp(m2, "대포폰") == 0)
                {
                    strcpy(m2, "");
                }
                else if (strcmp(m3, "대포폰") == 0)
                {
                    strcpy(m3, "");
                }
                else if (strcmp(m4, "대포폰") == 0)
                {
                    strcpy(m4, "");
                }
                else if (strcmp(m5, "대포폰") == 0)
                {
                    strcpy(m5, "");
                }
                else if (strcmp(m6, "대포폰") == 0)
                {
                    strcpy(m6, "");
                }
                else if (strcmp(m7, "대포폰") == 0)
                {
                    strcpy(m7, "");
                }
                else if (strcmp(m8, "대포폰") == 0)
                {
                    strcpy(m8, "");
                }
                //대포폰 함수 만들기
            }
            else
            {
                printf("아이템이 없습니다.\n");
                Sleep(5000);
            }
        }
        else if (strcmp(answer, "톱") == 0)
        {
            if (strcmp(m1, "톱") == 0 || strcmp(m2, "톱") == 0 || strcmp(m3, "톱") == 0 || strcmp(m4, "톱") == 0)
            {
                if (strcmp(m1, "톱") == 0)
                {
                    strcpy(m1, "");
                }
                else if (strcmp(m2, "톱") == 0)
                {
                    strcpy(m2, "");
                }
                else if (strcmp(m3, "톱") == 0)
                {
                    strcpy(m3, "");
                }
                else if (strcmp(m4, "톱") == 0)
                {
                    strcpy(m4, "");
                }
                else if (strcmp(m5, "톱") == 0)
                {
                    strcpy(m5, "");
                }
                else if (strcmp(m6, "톱") == 0)
                {
                    strcpy(m6, "");
                }
                else if (strcmp(m7, "톱") == 0)
                {
                    strcpy(m7, "");
                }
                else if (strcmp(m8, "톱") == 0)
                {
                    strcpy(m8, "");
                }
                //톱 함수 만들기
            }
            else
            {
                printf("아이템이 없습니다.\n");
                Sleep(5000);
            }
        }
        else if (strcmp(answer, "맥주") == 0)
        {
            if (strcmp(m1, "맥주") == 0 || strcmp(m2, "맥주") == 0 || strcmp(m3, "맥주") == 0 || strcmp(m4, "맥주") == 0)
            {
                if (strcmp(m1, "맥주") == 0)
                {
                    strcpy(m1, "");
                }
                else if (strcmp(m2, "맥주") == 0)
                {
                    strcpy(m2, "");
                }
                else if (strcmp(m3, "맥주") == 0)
                {
                    strcpy(m3, "");
                }
                else if (strcmp(m4, "맥주") == 0)
                {
                    strcpy(m4, "");
                }
                else if (strcmp(m5, "맥주") == 0)
                {
                    strcpy(m5, "");
                }
                else if (strcmp(m6, "맥주") == 0)
                {
                    strcpy(m6, "");
                }
                else if (strcmp(m7, "맥주") == 0)
                {
                    strcpy(m7, "");
                }
                else if (strcmp(m8, "맥주") == 0)
                {
                    strcpy(m8, "");
                }
                //맥주 함수 만들기
            }
            else
            {
                printf("아이템이 없습니다.\n");
                Sleep(5000);
            }
        }
        else if (strcmp(answer, "인버터") == 0)
        {
            if (strcmp(m1, "인버터") == 0 || strcmp(m2, "인버터") == 0 || strcmp(m3, "인버터") == 0 || strcmp(m4, "인버터") == 0)
            {
                if (strcmp(m1, "인버터") == 0)
                {
                    strcpy(m1, "");
                }
                else if (strcmp(m2, "인버터") == 0)
                {
                    strcpy(m2, "");
                }
                else if (strcmp(m3, "인버터") == 0)
                {
                    strcpy(m3, "");
                }
                else if (strcmp(m4, "인버터") == 0)
                {
                    strcpy(m4, "");
                }
                else if (strcmp(m5, "인버터") == 0)
                {
                    strcpy(m5, "");
                }
                else if (strcmp(m6, "인버터") == 0)
                {
                    strcpy(m6, "");
                }
                else if (strcmp(m7, "인버터") == 0)
                {
                    strcpy(m7, "");
                }
                else if (strcmp(m8, "인버터") == 0)
                {
                    strcpy(m8, "");
                }
                //인버터 함수 만들기
            }
            else
            {
                printf("아이템이 없습니다.\n");
                Sleep(5000);
            }
    }
    else if (strcmp(answer, "상한 약") == 0 || strcmp(answer, "상한약") == 0)
    {
        if (strcmp(m1, "상한 약") == 0 || strcmp(m2, "상한 약") == 0 || strcmp(m3, "상한 약") == 0 || strcmp(m4, "상한 약") == 0)
        {
            if (strcmp(m1, "상한 약") == 0)
            {
                strcpy(m1, "");
            }
            else if (strcmp(m2, "상한 약") == 0)
            {
                strcpy(m2, "");
            }
            else if (strcmp(m3, "상한 약") == 0)
            {
                strcpy(m3, "");
            }
            else if (strcmp(m4, "상한 약") == 0)
            {
                strcpy(m4, "");
            }
            else if (strcmp(m5, "상한 약") == 0)
            {
                strcpy(m5, "");
            }
            else if (strcmp(m6, "상한 약") == 0)
            {
                strcpy(m6, "");
            }
            else if (strcmp(m7, "상한 약") == 0)
            {
                strcpy(m7, "");
            }
            else if (strcmp(m8, "상한 약") == 0)
            {
                strcpy(m8, "");
            }
            //상한약 함수 만들기
        }
        else
        {
            printf("아이템이 없습니다.\n");
            Sleep(5000);
        }
    }
    else if (strcmp(answer, "돋보기") == 0)
    {
        if (strcmp(m1, "돋보기") == 0 || strcmp(m2, "돋보기") == 0 || strcmp(m3, "돋보기") == 0 || strcmp(m4, "돋보기") == 0)
        {
            if (strcmp(m1, "돋보기") == 0)
            {
                strcpy(m1, "");
            }
            else if (strcmp(m2, "돋보기") == 0)
            {
                strcpy(m2, "");
            }
            else if (strcmp(m3, "돋보기") == 0)
            {
                strcpy(m3, "");
            }
            else if (strcmp(m4, "돋보기") == 0)
            {
                strcpy(m4, "");
            }
            else if (strcmp(m5, "돋보기") == 0)
            {
                strcpy(m5, "");
            }
            else if (strcmp(m6, "돋보기") == 0)
            {
                strcpy(m6, "");
            }
            else if (strcmp(m7, "돋보기") == 0)
            {
                strcpy(m7, "");
            }
            else if (strcmp(m8, "돋보기") == 0)
            {
                strcpy(m8, "");
            }
            //돋보기 함수 만들기
        }
        else
        {
            printf("아이템이 없습니다.\n");
            Sleep(5000);
        }
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
        for (int i = 0; i < 8; i++)
        {
            gun3[i] = 2;
        }
        
        gun1 = 0;
        gun2 = 0;

        int y = rand() % 7;
       
       for (int i = 0; i < y + 1; i++)
        {
            gun3[i] = rand() % 2;

            if (gun3[i] == 0)
            {
                ++ gun2;
            }
            else if (gun3[i] == 1)
            {
                ++ gun1;
            }
        } 
    } while (gun1 == 0 || gun2 == 0);
    
    return 0;
}

void Itemprocessing()
{
    if (strcmp(m1, "") == 0)
    {
        strcpy(m1, item());
    }
    if (strcmp(m2, "") == 0)
    {
        strcpy(m2, item());
    }
    if (strcmp(m3, "") == 0)
    {
        strcpy(m3, item());
    }
    if (strcmp(m4, "") == 0)
    {
        strcpy(m4, item());
    }
    if (strcmp(m5, "") == 0)
    {
        strcpy(m5, item());
    }
    if (strcmp(m6, "") == 0)
    {
        strcpy(m6, item());
    }
    if (strcmp(m7, "") == 0)
    {
       strcpy(m7, item()); 
    }
    if (strcmp(m8, "") == 0)
    {
        strcpy(m8, item());
    }
}

char *item()
{
    int item8;
    char *a;

    item8 = rand() % 9;

    switch (item8)
    {
    case 0:
        a = "수갑";
        break;
    case 1:
        a = "아드레날린";
        break;
    case 2:
        a = "담배";
        break;
    case 3:
        a = "대포폰";
        break;
    case 4:
        a = "톱";
        break;
    case 5:
        a = "맥주";
        break;
    case 6:
        a = "인버터";
        break;
    case 7:
        a = "상한 약";
        break;
    case 8:
        a = "돋보기";
        break;
    }

    return a;
}
