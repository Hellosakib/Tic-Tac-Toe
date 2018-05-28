//Library Functions

#include<stdio.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>

//Function names
void sel();
void con();
void final();
void choice();
void end();
void play();
void display();
void you();
void game();
void records();
void win();

struct record
{
    char name[100];
};

struct record rec;
int a[50][50],i,j,g,r,q,c,flag=0,cou=0,m,flag1=0,d,played=0,wi=0,lo=0,dr=0;
char s,s1,y,*n,*n1,n2[100];
FILE *fp;

void main()
{
        fp=fopen("tictactoe.txt","w");

    printf("\n                **************************************\n\n\n\n");
    printf("\n   ENTER YOUR NAME PLEASE!\n\n");

    scanf("%s",rec.name);
    fprintf(fp, "%s",rec.name);
    fclose(fp);
    fp=fopen("tictactoe.txt","r");
    fscanf(fp, "%s",n2);
    printf("\n   GENDER [ PRESS 1 FOR MALE , 2 FOR FEMALE]\n\n");
    scanf("%d",&g);
    if(g==1)
        n1="SIR";
    else
        n1="MADAM";

    strcpy(n2,strupr(n2));
    final();
    getch();
}

void final()
{

    printf("\n   HELLO %s %s!\n\n",n2,n1);
    printf("     WELCOME TO THE GAME OF TIC TAC TOE\n\n");
    printf("     **********************************\n\n");
    printf("\n   1 . GAME\n\n");
    printf("\n   2 . INSTRUCTIONS\n\n");
    printf("\n   3 . EXIT\n\n");
    scanf("%d",&d);
    switch(d)
    {
    case 1:
        played++;
        game();
        break;
    case 2:
        printf("                        TIC TAC TOE\n");
        printf("                        ***********\n");
        printf(" INSTRUCTIONS\n");
        printf(" ************\n\n");
        printf(" 1.This is a simple mind game\n\n");
        printf(" 2.The game involves two players\n\n");
        printf(" 3.Each player places his/her symbol 'X' or 'O' in turn\n");
        printf("   in any one of the place in the square containing\n");
        printf("   nine places of '.' shown below:\n");
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                a[i][j]='.';
                printf(" %c\t",a[i][j]);
            }
            printf(" \n");
        }
        printf(" 4.The player who occupy three consequtive places\n");
        printf("   either vertically or horizontally or diagnally\n");
        printf("   wins the game\n\n");
        printf("              BEST OF LUCK !\n");
        printf(" IF YOU WANT TO GO BACK TO MENU PRESS '1' OR TO EXIT PRESS '2'\n\n\n");
        scanf("%d",&q);
        if(q==1)
            main();
        else
            system("taskkill/IM cb_console_runner.exe");
        break;
    case 3:
        system("taskkill/IM cb_console_runner.exe");
        break;
    }
    getch();
}

void game()
{

    printf("                 TIC TAC TOE\n");
    printf("                 ***********\n\n\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            a[i][j]='.';
            printf(" %c\t",a[i][j]);
        }
        printf(" \n\n\n");
    }
    choice();
    getch();
}
void choice()
{
    printf(" SHALL I START,IF YES PRESS '1' ELSE '2'\n");
    scanf("%d",&m);
    if(m==1)
    {
        printf(" THANK YOU %s!\n",n1);
        printf(" MY SYMBOL IS X AND YOURS IS O\n");
        s1='X',s='O';
        play();
    }
    else
    {
        printf(" YOU SHALL %s PLEASE!\n",n1);
        sel();
    }
    getch();
}
void display()
{
    cou++;
    printf(" \n----------------------------------------\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            printf(" %c\t",a[i][j]);
        printf(" \n");
    }
    printf(" \n----------------------------------------\n");
}
void you()
{
    printf(" \n ENTER THE POSITION IE SPECIFY THE ROW AND COLUMN\n");
    scanf("%d%d",&r,&c);
    if(a[r-1][c-1]=='.')
        a[r-1][c-1]=s;
    else
    {
        printf(" \n INVALID INPUT\n");
        if(a[r-1][c-1]==s1)
        {
            printf(" \n  ALREADY OCCUPIED BY ME\n");
            you();
        }
        else
        {
            printf("\n  ALREADY  OCCUPIED BY YOU\n");
            you();
        }
    }
    display();
    play();
}

void sel()
{
    printf(" SELECT YOUR SYMBOL 'X' OR  'O'\n");
    scanf(" %c",&s);
    if(s=='X'||s=='x')
        s1='O',s='X';
    else if(s=='O'||s=='o')
        s1='X',s='O';
    printf(" YOUR SYMBOL IS %c AND MINE IS %c\n",s,s1);
    you();
}
void play()
{
    flag=0,flag1=0;
    if((a[2][0]==s)&&(a[1][1]==s1))
    {
        if(a[0][2]=='.')
        {
            a[0][2]=s1;
            flag=1;
            flag1=2;
        }
    }
    if((a[0][0]==s1)&&(a[1][1]==s1)&&(a[0][1]==s))
    {
        if(a[2][0]=='.')
        {
            if(flag1==0)
            {
                a[2][0]=s1;
                flag1=2;
                flag=1;
            }
        }
    }
    if(((a[0][0]==s)&&(a[0][1]==s))||((a[0][0]==s1)&&(a[0][1]==s1)))
    {
        if(a[0][2]=='.')
        {
            if(flag1==0)
            {
                a[0][2]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[0][0]==s)&&(a[1][0]==s))||((a[0][0]==s1)&&(a[1][0]==s1)))
    {
        if(a[2][0]=='.')
        {
            if(flag1==0)
            {
                a[2][0]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[0][0]==s)&&(a[0][2]==s))||((a[0][0]==s1)&&(a[0][2]==s1)))
    {
        if(a[0][1]=='.')
        {
            if(flag1==0)
            {
                a[0][1]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[2][0]==s)&&(a[2][1]==s))||((a[2][0]==s1)&&(a[2][1]==s1)))
    {
        if(a[2][2]=='.')
        {
            if(flag1==0)
            {
                a[2][2]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[2][0]==s)&&(a[2][2]==s))||((a[2][0]==s1)&&(a[2][2]==s1)))
    {
        if(a[2][1]=='.')
        {
            if(flag1==0)
            {
                a[2][1]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[2][1]==s)&&(a[2][2]==s))||((a[2][1]==s1)&&(a[2][2]==s1)))
    {
        if(a[2][0]=='.')
        {
            if(flag1==0)
            {
                a[2][0]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[1][1]==s)&&(a[1][2]==s))||((a[1][1]==s1)&&(a[1][2]==s1)))
    {
        if(a[1][0]=='.')
        {
            if(flag1==0)
            {
                a[1][0]=s1;
                flag=1;
            }
        }
    }
    if(((a[1][0]==s)&&(a[1][1]==s))||((a[1][0]==s1)&&(a[1][1]==s1)))
    {
        if(a[1][2]=='.')
        {
            if(flag1==0)
            {
                a[1][2]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[0][1]==s)&&(a[1][1]==s))||((a[0][1]==s1)&&(a[1][1]==s1)))
    {
        if(a[2][1]=='.')
        {
            if(flag1==0)
            {
                a[2][1]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[0][0]==s)&&(a[0][2]==s))||((a[0][0]==s1)&&(a[0][2]==s1)&&(a[0][1]!=s)))
    {
        if(a[0][1]=='.')
        {
            if(flag1==0)
            {
                a[0][1]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[0][1]==s)&&(a[0][2]==s))||((a[0][1]==s1)&&(a[0][2]==s1)))
    {
        if(a[0][0]=='.')
        {
            if(flag1==0)
            {
                a[0][2]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[1][0]==s)&&(a[1][1]==s))||((a[1][0]==s1)&&(a[1][1]==s1)))
    {
        if(a[1][2]=='.')
        {
            if(flag1==0)
            {
                a[1][2]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[1][1]==s)&&(a[2][1]==s))||((a[1][1]==s1)&&(a[2][1]==s1)))
    {
        if(a[0][1]=='.')
        {
            if(flag1==0)
            {
                a[0][1]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[0][1]==s)&&(a[2][1]==s))|| ((a[0][1]==s1)&&(a[2][1]==s1)))
    {
        if(a[1][1]=='.')
        {
            if(flag1==0)
            {
                a[1][1]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[1][1]==s)&&(a[1][2]==s))||((a[1][1]==s1)&&(a[1][2]==s1)))
    {
        if(a[1][0]=='.')
        {
            if(flag1==0)
            {
                a[1][0]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[1][0]==s)&&(a[1][1]==s))||((a[1][0]==s1)&&(a[1][1]==s1)))
    {
        if(a[1][2]=='.')
        {
            if(flag1==0)
            {
                a[1][2]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[0][0]==s)&&(a[1][1]==s))||((a[0][0]==s1)&&(a[1][1]==s1)))
    {
        if(a[2][2]=='.')
        {
            if(flag1==0)
            {
                a[2][2]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[0][0]==s)&&(a[2][0]==s))||((a[0][0]==s1)&&(a[2][0]==s1)))
    {
        if(a[1][0]=='.')
        {
            if(flag1==0)
            {
                a[1][0]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[0][2]==s)&&(a[1][2]==s))||((a[0][2]==s1)&&(a[1][2]==s1)))
    {
        if(a[2][2]=='.')
        {
            if(flag1==0)
            {
                a[2][2]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[0][2]==s)&&(a[2][2]==s))||((a[0][2]==s1)&&(a[2][2]==s1)))
    {
        if(a[1][2]=='.')
        {
            if(flag1==0)
            {
                a[1][2]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[1][1]==s)&&(a[2][1]==s))||((a[1][1]==s1)&&(a[2][1]==s1)))
    {
        if(a[0][1]=='.')
        {
            if(flag1==0)
            {
                a[0][1]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(((a[2][2]==s)&&(a[1][2]==s))||((a[2][2]==s1)&&(a[1][2]==s1)))
    {
        if(a[0][2]=='.')
        {
            if(flag1==0)
            {
                a[0][2]=s1;
                flag=1;
                flag1=2;
            }
        }
    }
    if(flag!=1)
    {
        if(a[1][1]=='.')
            a[1][1]=s1;
        else if(a[0][0]=='.')
            a[0][0]=s1;
        else if(a[0][2]=='.')
            a[0][2]=s1;
        else if(a[2][0]=='.')
            a[2][0]=s1;
        else if(a[2][2]=='.')
            a[2][2]=s1;
        else if(a[1][2]=='.')
            a[1][2]=s1;
        else if(a[2][1]=='.')
            a[2][1]=s1;
    }
    printf("     MY TURN !!!\n");
    display();
            if((a[0][0]==s && a[0][1]==s && a[0][2]==s))
    {
        a[0][0]=a[0][1]=a[0][2]='!';
        wi++;
        display();
        win();
    }
    else if(a[0][2]==s && a[1][1]==s && a[2][0]==s)
    {
        a[0][2]=a[1][1]=a[2][0]='!';
        wi++;
        display();
        win();
    }
    else if(a[1][0]==s&& a[1][1]==s && a[1][2]==s)
    {
        a[1][0]=a[1][1]=a[1][2]='!';
        wi++;
        display();
        win();
    }
    else if(a[2][0]==s && a[2][1]==s && a[2][2]==s)
    {
        a[2][0]=a[2][1]=a[2][2]='!';
        wi++;
        display();
        win();
    }
    else if(a[0][0]==s && a[1][0]==s && a[2][0]==s)
    {
        a[0][0]=a[1][0]=a[2][0]='!';
        wi++;
        display();
        win();
    }
    else if(a[0][1]==s && a[1][1]==s && a[2][1]==s)
    {
        a[0][1]=a[1][1]=a[2][1]='!';
        wi++;
        display();
        win();
    }
    else if(a[0][2]==s && a[1][2]==s && a[2][2]==s)
    {
        a[0][2]=a[1][2]=a[2][2]='!';
        wi++;
        display();
        win();
    }
    else if(a[0][0]==s && a[1][1]==s && a[2][2]==s)
    {
        a[0][0]=a[1][1]=a[2][2]='!';
        wi++;
        display();
        win();
    }
    if((a[0][0]==s1 && a[0][1]==s1 && a[0][2]==s1))
    {
        a[0][0]=a[0][1]=a[0][2]='!';
        lo++;
        display();
        con();
    }
    else if(a[0][2]==s1 && a[1][1]==s1 && a[2][0]==s1)
    {
        a[0][2]=a[1][1]=a[2][0]='!';
        lo++;
        display();
        con();
    }
    else if(a[1][0]==s1 && a[1][1]==s1 && a[1][2]==s1)
    {
        a[1][0]=a[1][1]=a[1][2]='!';
        lo++;
        display();
        con();
    }
    else if(a[2][0]==s1 && a[2][1]==s1 && a[2][2]==s1)
    {
        a[2][0]=a[2][1]=a[2][2]='!';
        lo++;
        display();
        con();
    }
    else if(a[0][0]==s1 && a[1][0]==s1 && a[2][0]==s1)
    {
        a[0][0]=a[1][0]=a[2][0]='!';
        lo++;
        display();
        con();
    }
    else if(a[0][1]==s1 && a[1][1]==s1 && a[2][1]==s1)
    {
        a[0][1]=a[1][1]=a[2][1]='!';
        lo++;
        display();
        con();
    }
    else if(a[0][2]==s1 && a[1][2]==s1 && a[2][2]==s1)
    {
        a[0][2]=a[1][2]=a[2][2]='!';
        lo++;
        display();
        con();
    }
    else if(a[0][0]==s1 && a[1][1]==s1 && a[2][2]==s1)
    {
        a[0][0]=a[1][1]=a[2][2]='!';
        lo++;
        display();
        con();
    }

    if(cou > 7)
    {
        dr++;
        printf("  \n    NEITHER OF US WON THE GAME %s %s\n",n2,n1);
        printf("   YOU ARE EQUALLY TALENTED\n");
        cou=0;
        records();
        end();
    }
    you();
}
void end()
{
    printf("    DO YOU WANT TO CONTINUE IF YES PRESS '1' ELSE '2' \n");
    scanf("%d",&m);
    if(m==1)
        final();
    else
        exit(0);
}
void con()
{
    printf(" SORRY %s %s\n\n",n2,n1);
    printf("  YOU LOSE!\n");
    printf("  BETTER LUCK NEXT TIME\n");
    cou=0;
    records();
    end();
}
void win()
{
    printf(" CONGRATULATION %s %s !!!!\n\n",n2,n1);
    printf("  YOU WIN!\n");
    cou=0;
    records();
    end();
}
void records()
{
    printf("\n\n\t\tYour game record:\n\t\t*****************\n\n\t\tYour name is %s \n\t\tYou played %d times \n\t\tYou won %d times \n\t\tYou lost %d times \n\t\tYour drawn %d times\n\n",n2,played,wi,lo,dr);
}
