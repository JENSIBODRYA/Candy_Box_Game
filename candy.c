#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

void gotoxy(int x, int y)
{

    COORD CRD;
    CRD.X=x;
    CRD.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}

int instruction()
{
    system("cls");
    printf("----------------\n");
    printf("| Instructions |\n");
    printf("----------------\n");
    printf("\n(1) Use 'a' key to move slider left.\n");
    printf("(2) Use 'd' key to move slider right.\n");
    printf("\n Press any key to go back to Menu.");
    getch();
}

void play()
{
    int candyX=rand()%45+1, candyY=5, boxX=20, boxY=23;
    int score=0, lives=3, d;
    char ch;
     start:
        system("cls");
        gotoxy(46,4);
        printf("score = %d",score);
        gotoxy(46,3);
        printf("lives = %d",lives);
        gotoxy(candyX,candyY);
        printf("0");
        gotoxy(boxX,boxY);
        printf("#");
        gotoxy(boxX+7,boxY);
        printf("#");
        gotoxy(boxX,boxY+1);
        printf("########");
        if(kbhit())
        {
            ch=getch();
            switch(ch)
            {
            case 'a':
                if(boxX>1)
                    boxX -= 2;
            break;
            case 'd':boxX += 2;
            break;
            case 27:exit(0);
            }
        }
        candyY++;
        if(candyY==24)
        {
            if(candyX>=boxX && candyX<boxX+7)
            {
                score++;
                Beep(300,1000);
            }
            else
            {
                lives--;
            }
            candyY=5;
            candyX=rand()%45+1;
        }
        if(lives==0)
        {
            system("cls");
            gotoxy(40,13);
            printf("GAME OVER");
            Beep(200,2000);

            char sc[50];
            FILE *fptr;
            fptr=fopen("History1.txt", "a");
            sprintf(sc, " %d", score);
            fputs(sc, fptr);
            fputs("\n", fptr);
            fclose(fptr);
            getch();
            exit(0);
        }
        Beep(300,100);
        goto start;
}

int main()
{
    srand(time(0));
    mainMenu:
    system("cls");
        gotoxy(10,5);
        printf("----------------------");
        gotoxy(10,6);
        printf("|   CANDY BOX GAME   |");
        gotoxy(10,7);
        printf("----------------------");
        gotoxy(10,9);
        printf("1. Start Game");
        gotoxy(10,10);
        printf("2. Instructions");
        gotoxy(10,11);
        printf("3. Score");
        gotoxy(10,12);
        printf("4. Quit");
        gotoxy(10,14);
        printf("Select Option : ");
        char op=getch();
        if(op=='1'){
            play();
        }
        else if(op=='2'){
            instruction();
            goto mainMenu;
        }
        else if(op=='3')
        {
            system("cls");
            FILE *fptr;
            fptr=fopen("History1.txt","r");
            char c='\0';
            while(c!=EOF)
            {
                c=fgetc(fptr);
                printf("%c",c);
            }
            fclose(fptr);
            printf("\n\n Press any key to go back to Menu.");
            getch();
            goto mainMenu;
        }
        else if(op=='4')
        {
            exit(0);
        }

        else{
            goto mainMenu;
        }
        exit(0);
        return 0;
}
