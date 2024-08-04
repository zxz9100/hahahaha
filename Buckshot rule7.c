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

//아이템 함수
int ItemCigarettes();
int Itemsaw();
int Itemglass();
int ItemBeer();
int ItemInverter();
int ItemMedicine();
int ItemHandcuffs();
int ItemsAdrenaline();
int Itemphone();

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
int Sawing[2] = {0, 0};
int handcuffs[2] = {0, 0};
int adrenaline[2] = {0, 0};

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
        if (gun3[Order] == 2 || Order > 8)
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
        if (adrenaline[0] == 0)
        {
            printf("%s님 차례 : ", name1);
            gets(answer);
            if (strcmp(answer, "1") == 0 ||  strcmp(answer, "상대") == 0)
            {
                if (gun3[Order] == 1)
                {
                    if (Sawing[0] == 0)
                    {
                        p[life2] = ' ';
                        -- life2;
                    }
                    else if (Sawing[0] == 1)
                    {
                        p[life2] = ' ';
                        -- life2;
                        p[life2] = ' ';
                        -- life2;
                        Sawing[0] = 0;
                    }
                    printf("실탄");
                    Sleep(2000);
                    if (handcuffs[0] == 1)
                    {
                        i = 0;
                        handcuffs[0] = 0;
                    }
                    else if (handcuffs[0] == 0)
                    {
                        i = 1;
                    }
                }
                else if (gun3[Order] == 0)
                {
                    if (Sawing[0] == 1)
                    {
                        Sawing[0] = 0;
                    }
                    printf("공포탄");
                    Sleep(2000);
                    if (handcuffs[0] == 1)
                    {
                        i = 0;
                        handcuffs[0] = 0;
                    }
                    else if (handcuffs[0] == 0)
                    {
                        i = 1;
                    }
                }
                ++ Order;
            }
            else if (strcmp(answer, "2") == 0 || strcmp(answer, "나") == 0)
            {
                if (gun3[Order] == 1)
                {
                    if (Sawing[0] == 0)
                    {
                        p[life1] = ' ';
                        -- life1;
                    }
                    else if (Sawing[0] == 1)
                    {
                        p[life1] = ' ';
                        -- life1;
                        p[life1] = ' ';
                        -- life1;
                        Sawing[0] = 0;
                    }
                    printf("실탄");
                    Sleep(2000);
                    if (handcuffs[0] == 1)
                    {
                        i = 0;
                        handcuffs[0] = 1;
                    }
                    else if (handcuffs[0] == 0)
                    {
                        i = 1;
                    }
                }
                else if (gun3[Order] == 0)
                {
                    if (Sawing[0] == 1)
                    {
                        Sawing[0] = 0;
                    }
                    printf("공포탄");
                    Sleep(2000);
                    if (handcuffs[0] == 1)
                    {
                        i = 0;
                        handcuffs[0] = 1;
                    }
                    else if (handcuffs[0] == 0)
                    {
                        i = 0;
                    }
                }
                ++ Order;
            }
            else if (strcmp(answer, "수갑") == 0)
            {
                if (strcmp(m1, "수갑") == 0 || strcmp(m2, "수갑") == 0 || strcmp(m3, "수갑") == 0 || strcmp(m4, "수갑") == 0)
                {
                    if (handcuffs[0] == 1)
                    {
                        printf("수갑 사용중....\n");
                        Sleep(5000);
                    }
                    else if (strcmp(m1, "수갑") == 0)
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
                    ItemHandcuffs();
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
                    ItemsAdrenaline();
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
                    ItemCigarettes();
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
                    Itemphone();
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
                    Itemsaw();
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
                    ItemBeer();
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
                    ItemInverter();
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
                    ItemMedicine();
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
                    Itemglass();
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
            }
        }
        else if (adrenaline[0] == 1)
        {
            printf("%s님아이템 가져오기 : ", name2);
            gets(answer);
            if (strcmp(answer, "수갑") == 0)
            {
                if (strcmp(m5, "수갑") == 0 || strcmp(m6, "수갑") == 0 || strcmp(m7, "수갑") == 0 || strcmp(m8, "수갑") == 0)
                {
                    if (handcuffs[1] == 1)
                    {
                        printf("수갑 사용중....\n");
                        Sleep(5000);
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
                    ItemHandcuffs();
                    adrenaline[0] = 0;
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
            }
            else if (strcmp(answer, "아드레날린") == 0)
            {
                if (strcmp(m5, "아드레날린") == 0 || strcmp(m6, "아드레날린") == 0 || strcmp(m7, "아드레날린") == 0 || strcmp(m8, "아드레날린") == 0)
                {
                    if (strcmp(m5, "아드레날린") == 0)
                    {
                        printf("가져올 수 없는 아이템 입니다.\n");
                        Sleep(2000);
                    }
                    else if (strcmp(m6, "아드레날린") == 0)
                    {
                        printf("가져올 수 없는 아이템 입니다.\n");
                        Sleep(2000);
                    }
                    else if (strcmp(m7, "아드레날린") == 0)
                    {
                        printf("가져올 수 없는 아이템 입니다.\n");
                        Sleep(2000);
                    }
                    else if (strcmp(m8, "아드레날린") == 0)
                    {
                        printf("가져올 수 없는 아이템 입니다.\n");
                        Sleep(2000);
                    }
                    ItemsAdrenaline();
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
            }
            else if (strcmp(answer, "담배") == 0)
            {
                if (strcmp(m5, "담배") == 0 || strcmp(m6, "담배") == 0 || strcmp(m7, "담배") == 0 || strcmp(m8, "담배") == 0)
                {
                    if (strcmp(m5, "담배") == 0)
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
                    ItemCigarettes();
                    adrenaline[0] = 0;
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
            }
            else if (strcmp(answer, "대포폰") == 0)
            {
                if (strcmp(m5, "대포폰") == 0 || strcmp(m6, "대포폰") == 0 || strcmp(m7, "대포폰") == 0 || strcmp(m8, "대포폰") == 0)
                {
                    if (strcmp(m5, "대포폰") == 0)
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
                    Itemphone();
                    adrenaline[0] = 0;
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
            }
            else if (strcmp(answer, "톱") == 0)
            {
                if (strcmp(m5, "톱") == 0 || strcmp(m6, "톱") == 0 || strcmp(m7, "톱") == 0 || strcmp(m8, "톱") == 0)
                {
                    if (strcmp(m5, "톱") == 0)
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
                    Itemsaw();
                    adrenaline[0] = 0;
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
            }
            else if (strcmp(answer, "맥주") == 0)
            {
                if (strcmp(m5, "맥주") == 0 || strcmp(m6, "맥주") == 0 || strcmp(m7, "맥주") == 0 || strcmp(m8, "맥주") == 0)
                {
                    if (strcmp(m5, "맥주") == 0)
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
                    ItemBeer();
                    adrenaline[0] = 0;
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
            }
            else if (strcmp(answer, "인버터") == 0)
            {
                if (strcmp(m5, "인버터") == 0 || strcmp(m6, "인버터") == 0 || strcmp(m7, "인버터") == 0 || strcmp(m8, "인버터") == 0)
                {
                    if (strcmp(m5, "인버터") == 0)
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
                    ItemInverter();
                    adrenaline[0] = 0;
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
            }
            else if (strcmp(answer, "상한 약") == 0 || strcmp(answer, "상한약") == 0)
            {
                if (strcmp(m5, "상한 약") == 0 || strcmp(m6, "상한 약") == 0 || strcmp(m7, "상한 약") == 0 || strcmp(m8, "상한 약") == 0)
                {
                    if (strcmp(m5, "상한 약") == 0)
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
                    ItemMedicine();
                    adrenaline[0] = 0;
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
            }
            else if (strcmp(answer, "돋보기") == 0)
            {
                if (strcmp(m5, "돋보기") == 0 || strcmp(m6, "돋보기") == 0 || strcmp(m7, "돋보기") == 0 || strcmp(m8, "돋보기") == 0)
                {
                    if (strcmp(m5, "돋보기") == 0)
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
                    Itemglass();
                    adrenaline[0] = 0;
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
            }
        } 
    }
    else if (i == 1)
    {
        if (adrenaline[1] == 0)
        {
            printf("%s님 차례 : ", name2);
            gets(answer);
            if (strcmp(answer, "1") == 0 ||  strcmp(answer, "상대") == 0)
            {
                if (gun3[Order] == 1)
                {
                    if (Sawing[1] == 0)
                    {
                        p[life1] = ' ';
                        -- life1;
                    }
                    else if (Sawing[1] == 1)
                    {
                        p[life1] = ' ';
                        -- life1;
                        p[life1] = ' ';
                        -- life1;
                        Sawing[1] = 0;
                    }
                    printf("실탄");
                    Sleep(2000);
                    if (handcuffs[1] == 1)
                    {
                        i = 1;
                        handcuffs[1] = 0;
                    }
                    else if (handcuffs[1] == 0)
                    {
                        i = 0;
                    }
                }
                else if (gun3[Order] == 0)
                {
                    if (Sawing[1] == 1)
                    {
                        Sawing[1] = 0;
                    }
                    printf("공포탄");
                    Sleep(2000);
                    if (handcuffs[1] == 1)
                    {
                        i = 1;
                        handcuffs[1] = 0;
                    }
                    else if (handcuffs[1] == 0)
                    {
                        i = 0;
                    }
                }
                ++ Order;
            }
            else if (strcmp(answer, "2") == 0 || strcmp(answer, "나") == 0)
            {
                if (gun3[Order] == 1)
                {
                    if (Sawing[1] == 0)
                    {
                        p[life2] = ' ';
                        -- life2;
                    }
                    else if (Sawing[1] == 1)
                    {
                        p[life2] = ' ';
                        -- life2;
                        p[life2] = ' ';
                        -- life2;
                        Sawing[1] = 0;
                    }
                    printf("실탄");
                    Sleep(2000);
                    if (handcuffs[1] == 1)
                    {
                        i = 1;
                        handcuffs[1] = 1;
                    }
                    else if (handcuffs[1] == 0)
                    {
                        i = 0;
                    }
                }
                else if (gun3[Order] == 0)
                {
                    if (Sawing[1] == 1)
                    {
                        Sawing[1] = 0;
                    }
                    printf("공포탄");
                    Sleep(2000);
                    if (handcuffs[1] == 1)
                    {
                        i = 1;
                        handcuffs[1] = 1;
                    }
                    else if (handcuffs[1] == 0)
                    {
                        i = 1;
                    }
                }
                ++ Order;
            }
            else if (strcmp(answer, "수갑") == 0)
            {
                if (strcmp(m5, "수갑") == 0 || strcmp(m6, "수갑") == 0 || strcmp(m7, "수갑") == 0 || strcmp(m8, "수갑") == 0)
                {
                    if (handcuffs[1] == 1)
                    {
                        printf("수갑 사용중....\n");
                        Sleep(5000);
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
                    ItemHandcuffs();
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
            }
            else if (strcmp(answer, "아드레날린") == 0)
            {
                if (strcmp(m5, "아드레날린") == 0 || strcmp(m6, "아드레날린") == 0 || strcmp(m7, "아드레날린") == 0 || strcmp(m8, "아드레날린") == 0)
                {
                    if (strcmp(m5, "아드레날린") == 0)
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
                    ItemsAdrenaline();
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
            }
            else if (strcmp(answer, "담배") == 0)
            {
                if (strcmp(m5, "담배") == 0 || strcmp(m6, "담배") == 0 || strcmp(m7, "담배") == 0 || strcmp(m8, "담배") == 0)
                {
                    if (strcmp(m5, "담배") == 0)
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
                    ItemCigarettes();
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
            }
            else if (strcmp(answer, "대포폰") == 0)
            {
                if (strcmp(m5, "대포폰") == 0 || strcmp(m6, "대포폰") == 0 || strcmp(m7, "대포폰") == 0 || strcmp(m8, "대포폰") == 0)
                {
                    if (strcmp(m5, "대포폰") == 0)
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
                    Itemphone();
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
            }
            else if (strcmp(answer, "톱") == 0)
            {
                if (strcmp(m5, "톱") == 0 || strcmp(m6, "톱") == 0 || strcmp(m7, "톱") == 0 || strcmp(m8, "톱") == 0)
                {
                    if (strcmp(m5, "톱") == 0)
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
                    Itemsaw();
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
            }
            else if (strcmp(answer, "맥주") == 0)
            {
                if (strcmp(m5, "맥주") == 0 || strcmp(m6, "맥주") == 0 || strcmp(m7, "맥주") == 0 || strcmp(m8, "맥주") == 0)
                {
                    if (strcmp(m5, "맥주") == 0)
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
                ItemBeer();
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
            }
            else if (strcmp(answer, "인버터") == 0)
            {
                if (strcmp(m5, "인버터") == 0 || strcmp(m6, "인버터") == 0 || strcmp(m7, "인버터") == 0 || strcmp(m8, "인버터") == 0)
                {
                    if (strcmp(m5, "인버터") == 0)
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
                    ItemInverter();
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
            }
            else if (strcmp(answer, "상한 약") == 0 || strcmp(answer, "상한약") == 0)
            {
                if (strcmp(m5, "상한 약") == 0 || strcmp(m6, "상한 약") == 0 || strcmp(m7, "상한 약") == 0 || strcmp(m8, "상한 약") == 0)
                {
                    if (strcmp(m5, "상한 약") == 0)
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
                    ItemMedicine();
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
            }
            else if (strcmp(answer, "돋보기") == 0)
            {
                if (strcmp(m5, "돋보기") == 0 || strcmp(m6, "돋보기") == 0 || strcmp(m7, "돋보기") == 0 || strcmp(m8, "돋보기") == 0)
                {
                    if (strcmp(m5, "돋보기") == 0)
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
                    Itemglass();
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
            }
        }
        else if (adrenaline[1] == 1)
        {
            printf("%s님아이템 가져오기 : ", name1);
            gets(answer);
            if (strcmp(answer, "수갑") == 0)
            {
                if (strcmp(m1, "수갑") == 0 || strcmp(m2, "수갑") == 0 || strcmp(m3, "수갑") == 0 || strcmp(m4, "수갑") == 0)
                {
                    if (handcuffs[0] == 1)
                    {
                        printf("수갑 사용중....\n");
                        Sleep(5000);
                    }
                    else if (strcmp(m1, "수갑") == 0)
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
                    ItemHandcuffs();
                    adrenaline[1] = 0;
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
                        printf("가져올 수 없는 아이템 입니다.\n");
                        Sleep(2000);
                    }
                    else if (strcmp(m2, "아드레날린") == 0)
                    {
                        printf("가져올 수 없는 아이템 입니다.\n");
                        Sleep(2000);
                    }
                    else if (strcmp(m3, "아드레날린") == 0)
                    {
                        printf("가져올 수 없는 아이템 입니다.\n");
                        Sleep(2000);
                    }
                    else if (strcmp(m4, "아드레날린") == 0)
                    {
                        printf("가져올 수 없는 아이템 입니다.\n");
                        Sleep(2000);
                    }
                    ItemsAdrenaline();
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
                    ItemCigarettes();
                    adrenaline[1] = 0;
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
                    Itemphone();
                    adrenaline[1] = 0;
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
                    Itemsaw();
                    adrenaline[1] = 0;
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
                    ItemBeer();
                    adrenaline[1] = 0;
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
                    ItemInverter();
                    adrenaline[1] = 0;
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
                    ItemMedicine();
                    adrenaline[1] = 0;
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
                    Itemglass();
                    adrenaline[1] = 0;
                }
                else
                {
                    printf("아이템이 없습니다.\n");
                    Sleep(5000);
                }
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

        int y = rand() % 8;
       
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
//아이템
int ItemCigarettes()
{
    if (i == 0)
    {
        if (life1 <= 3)
        {
            ++ life1;
            p[life1] = '0';
        }
    }
    else if (i == 1)
    {
        if (life2 <= 8)
        {
            ++ life2;
            p[life2] = '0';
        }
    }
    
    return 0;
}

int Itemsaw()
{
    if (i == 0)
    {
        Sawing[0] = 1;
    }
    else if (i == 1)
    {
        Sawing[1] = 1;
    }
    
    return 0;
}

int Itemglass()
{
    if (i == 0)
    {
        if (gun3[Order] == 0)
        {
            printf("현재 탄은 공포탄 입니다.\n");
            Sleep(5000);
        }
        else if (gun3[Order] == 1)
        {
            printf("현재 탄은 실탄 입니다.\n");
            Sleep(5000);
        }
    }
    else if (i == 1)
    {
        if (gun3[Order] == 0)
        {
            printf("현재 탄은 공포탄 입니다.\n");
            Sleep(5000);
        }
        else if (gun3[Order] == 1)
        {
            printf("현재 탄은 실탄 입니다.\n");
            Sleep(5000);
        }
    }

    return 0;
} 

int ItemBeer()
{
    if (gun3[Order] == 0)
    {
        printf("현재 탄은 공포탄 입니다.(탄 빠짐)");
        ++ Order;
        Sleep(5000);
    }
    else if (gun3[Order] == 1)
    {
        printf("현재 탄은 실탄 입니다.(탄 빠짐)");
        ++ Order;
        Sleep(5000);
    }
    
    return 0;
}

int ItemInverter()
{
    if (gun3[Order] == 0)
    {
        gun3[Order] = 1;
    }
    else if (gun3[Order] == 1)
    {
        gun3[Order] = 0;
    }

    return 0;
}

int ItemMedicine()
{
    int pp = 0;
    int h = rand() % 2;

    if (i == 0)
    {
        if (h == 1)
        {
            while (life1 <= 3 && pp < 2)
            {
                ++ life1;
                p[life1] = '0';
                ++ pp;
            }
        }
        else if (h == 0)
        {
            p[life1] = ' ';
            -- life1;
        }
    }
    else if (i == 1)
    {
        if (h == 1)
        {
            while (life2 <= 8 && pp < 2)
            {
                ++ life2;
                p[life2] = '0';
                ++ pp;
            }
        }
        else if (h == 0)
        {
            p[life2] = ' ';
            -- life2;
        }
    }
    
    return 0;
}

int ItemHandcuffs()
{
    if (i == 0)
    {
        handcuffs[0] = 1;
    }
    else if (i == 1)
    {
        handcuffs[1] = 1;
    }
      
    return 0;
}

int ItemsAdrenaline()
{
    if (i == 0)
    {
        adrenaline[0] = 1;
    }
    else if (i == 1)
    {
        adrenaline[1] = 1;
    }

    return 0;
}

int Itemphone()
{
    int k;
    int G;

    k = Order + 1;
    if (i == 0)
    {
        printf("%s님은 뒤돌아 보세요(3초뒤 대포폰 능력 실행)\n", name2);
        Sleep(3000);

        if (gun3[k] == 2)
        {
            printf("안타깝게... 됐군...\n");
            Sleep(3000);
        }
        else
        {
            do
            {
                G = rand() % 8 + 1;
                k = Order;
                
                k = k + G;
            } while (gun3[k] == 2 || k > 8);
            
            if (gun3[k] == 2 || k > 8)
            {
                G = Order + 1; 
            }

            if (gun3[k] == 0)
            {
                printf("다음 탄 부터 %d번째는 공포탄 입니다.\n", G);
                Sleep(3000);
            }
            else if (gun3[k] == 1)
            {
                printf("다음 탄부터 %d번째는 실탄 입니다.\n", G);
                Sleep(3000);
            }
        }
    }
    else if (i == 1)
    {
        printf("%s님은 뒤돌아 보세요(3초뒤 대포폰 능력 실행)\n", name1);
        Sleep(3000);

        if (gun3[k] == 2)
        {
            printf("안타깝게... 됐군...\n");
            Sleep(3000);
        }
        else
        {
            do
            {
                G = rand() % 8 + 1;
                k = Order;
                
                k = k + G;
            } while (gun3[k] == 2 || k > 8);

            if (gun3[k] == 2 || k > 8)
            {
                G = Order + 1; 
            }
            
            if (gun3[k] == 0)
            {
                printf("다음 탄 부터 %d번째는 공포탄 입니다.\n", G);
                Sleep(3000);
            }
            else if (gun3[k] == 1)
            {
                printf("다음 탄 부터 %d번째는 실탄 입니다.\n", G);
                Sleep(3000);
            }
        }
    }
    
    return 0;
}
