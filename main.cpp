#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <windows.h>

void leggenda(),visualizza(),scelta_utente(),scelta_cpu(),controllo(),votazioni(),SetColor();

int campo_forza[6][7],voto[6][7],Colore[6][7];
int colonna;
int i,k,risultato;
bool fine=false,piena;

using namespace std;

void SetColor(short Color)
{
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hCon,Color);
}

main()
{
    for(i=0;i<6;i++)
    {
        for(k=0;k<7;k++)
        {
            campo_forza[i][k]=0;
            Colore[i][k]=15;
        }
    }
    srand(time(NULL));
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"||======================================================================||\n";
        cout<<"||======================================================================||\n";
        cout<<"||          __________   ____ _____   ___      __ __                    ||\n";
        cout<<"||         / ____/ __ \\/ __ /__  /   /   |    / // /                    ||\n";
        cout<<"||        / /_  / / / / /_/ /  / /  / /| |   / // /_                    ||\n";
        cout<<"||       / __/ / /_/ / _, _/  / /__/ ___ |  /__  __/                    ||\n";
        cout<<"||      /_/    \\____/_/ |_| /____ /_/  |_|    /_/  by federico         ||\n";
        cout<<"||======================================================================||\n";
        cout<<"||======================================================================||\n\n\n\n\n\n\n\n\n\n";
        system("pause");
        system("cls");
    leggenda();
    while( 1 )
    {
        scelta_utente();
        system("cls");
        visualizza();
        controllo();
        if(fine==true)
            break;
        system("pause");
        scelta_cpu();
        system("cls");
        visualizza();
        controllo();
        if(fine==true)
            break;
    }
    visualizza();
    cout<<endl;
    if(risultato==1)
    {
        cout<<"HAI VINTO!";
    }
    else
        cout<<"HAI PERSO!";
    cout<<endl<<endl;
    system("pause");
}

void visualizza()
{
    for(i=0;i<6;i++)
    {
        for(k=0;k<7;k++)
        {
            printf("%c%c%c%c%c",218,196,196,196,191);
        }
        cout<<endl;
        for(k=0;k<7;k++)
        {
            SetColor(Colore[i][k]);
            switch(campo_forza[i][k])
            {

            case 0:
                printf("%c   %c",179,179);
                break;
            case 1:
                printf("%c x %c",179,179);
                break;
            case 2:
                printf("%c 0 %c",179,179);
                break;
            }
            SetColor(15);
        }
        cout<<endl;
        for(k=0;k<7;k++)
        {
            printf("%c%c%c%c%c",192,196,196,196,217);
        }
        cout<<endl;
    }
    cout<<endl;
}

void scelta_utente()
{
    do
    {
        cout<<"\nQuale colonna scegli: ";
        cin>>colonna;
    }while(colonna<0 || colonna>6);
    piena=true;i=5;
    while(piena==true)
    {
        if(i<0)
        {
            cout<<"colonna piena!!!";
            scelta_utente();
        }
        if(campo_forza[i][colonna] == 0)
        {
            campo_forza[i][colonna]=1;
            piena=false;
        }
        else i--;
    }
}

void scelta_cpu()
{
    votazioni();
    colonna=rand()%(6)+1;
    for(i=0;i<6;i++)
    {
        for(k=0;k<7;k++)
        {
            if(voto[i][k]>voto[i][colonna])
            {
                colonna=k;
            }
        }
    }
    piena=true;i=5;
    while(piena==true)
    {
        if(i<0)
        {
            colonna=rand()%(6)+1;
            i=5;
        }
        if(campo_forza[i][colonna] == 0)
        {
            campo_forza[i][colonna]=2;
            piena=false;
        }
        else i--;
    }
}

void leggenda()
{
    cout<<"LEGGENDA:"<<endl<<endl;
    for(i=0;i<6;i++)
    {
        for(k=0;k<7;k++)
        {
            printf("%c%c%c%c%c",218,196,196,196,191);
            campo_forza[i][k]=0;
        }
        cout<<endl;
        for(k=0;k<7;k++)
        {
            printf("%c %d %c",179,k,179);
        }
        cout<<endl;
        for(k=0;k<7;k++)
        {
            printf("%c%c%c%c%c",192,196,196,196,217);
        }
        cout<<endl;
    }
}

void controllo()
{
    for(i=0;i<6;i++)
    {
        for(k=0;k<7;k++)
        {
            if(campo_forza[i][k]!=0)
            {
                if(campo_forza[i][k]==campo_forza[i-1][k-1] && campo_forza[i][k]==campo_forza[i-2][k-2] &&
                   campo_forza[i][k]==campo_forza[i-3][k-3])
                {
                        Colore[i][k]=12;
                        Colore[i-1][k-1]=12;
                        Colore[i-2][k-2]=12;
                        Colore[i-3][k-3]=12;
                        fine=true;
                        risultato=campo_forza[i][k];

                }
                if(campo_forza[i][k]==campo_forza[i-1][k] && campo_forza[i][k]==campo_forza[i-2][k] &&
                   campo_forza[i][k]==campo_forza[i-3][k])
                {
                        Colore[i][k]=12;
                        Colore[i-1][k]=12;
                        Colore[i-2][k]=12;
                        Colore[i-3][k]=12;
                        fine=true;
                        risultato=campo_forza[i][k];
                }
                if(campo_forza[i][k]==campo_forza[i-1][k+1] && campo_forza[i][k]==campo_forza[i-2][k+2] &&
                   campo_forza[i][k]==campo_forza[i-3][k+3])
                {
                    Colore[i][k]=12;
                    Colore[i-1][k+1]=12;
                    Colore[i-2][k+2]=12;
                    Colore[i-3][k+3]=12;
                        fine=true;
                        risultato=campo_forza[i][k];
                }
                if(campo_forza[i][k]==campo_forza[i][k-1] && campo_forza[i][k]==campo_forza[i][k-2] &&
                   campo_forza[i][k]==campo_forza[i][k-3])
                {
                    Colore[i][k]=12;
                    Colore[i][k-1]=12;
                    Colore[i][k-2]=12;
                    Colore[i][k-3]=12;
                        fine=true;
                        risultato=campo_forza[i][k];
                }
                if(campo_forza[i][k]==campo_forza[i][k+1] && campo_forza[i][k]==campo_forza[i][k+2] &&
                   campo_forza[i][k+3]==campo_forza[i][k])
                {
                    Colore[i][k]=12;
                    Colore[i][k+1]=12;
                    Colore[i][k+2]=12;
                    Colore[i][k+3]=12;
                        fine=true;
                        risultato=campo_forza[i][k];
                }
                if(campo_forza[i][k]==campo_forza[i+1][k-1] && campo_forza[i][k]==campo_forza[i+2][k-2] &&
                   campo_forza[i][k]==campo_forza[i+3][k-3])
                {
                    Colore[i][k]=12;
                    Colore[i+1][k-1]=12;
                    Colore[i+2][k-2]=12;
                    Colore[i+3][k-3]=12;
                        fine=true;
                        risultato=campo_forza[i][k];
                }
                if(campo_forza[i][k]==campo_forza[i+1][k] && campo_forza[i][k]==campo_forza[i+2][k] &&
                   campo_forza[i][k]==campo_forza[i+3][k])
                {
                    Colore[i][k]=12;
                    Colore[i+1][k]=12;
                    Colore[i+2][k]=12;
                    Colore[i+3][k]=12;
                        fine=true;
                        risultato=campo_forza[i][k];
                }
                if(campo_forza[i][k]==campo_forza[i+1][k+1] && campo_forza[i][k]==campo_forza[i+2][k+2] &&
                   campo_forza[i][k]==campo_forza[i+3][k+3])
                {
                    Colore[i][k]=12;
                    Colore[i+1][k+1]=12;
                    Colore[i+2][k+2]=12;
                    Colore[i+3][k+3]=12;
                        fine=true;
                        risultato=campo_forza[i][k];
                }
            }
        }
    }
}
//algoritmo MIN MAX da implementare a piacimento
void votazioni()
{
    for(i=0;i<6;i++)
    {
        for(k=0;k<7;k++)
        {
            voto[i][k]=0;
            if(campo_forza[i-1][k-1]==campo_forza[i-2][k-2] && campo_forza[i-1][k-1]==campo_forza[i-3][k-3]
               && campo_forza[i-1][k-1]!=0)
                {
                        voto[i][k]=10;
                }
                if(campo_forza[i-1][k]==campo_forza[i-2][k] && campo_forza[i-1][k]==campo_forza[i-3][k]
                   && campo_forza[i-1][k]!=0)
                {
                        voto[i][k]=10;
                }
                if(campo_forza[i-1][k+1]==campo_forza[i-2][k+2] && campo_forza[i-1][k+1]==campo_forza[i-3][k+3]
                   && campo_forza[i-1][k+1]!=0)
                {
                        voto[i][k]=10;
                }
                if(campo_forza[i][k-1]==campo_forza[i][k-2] && campo_forza[i][k-1]==campo_forza[i][k-3]
                   && campo_forza[i][k-1]!=0)
                {
                        voto[i][k]=10;
                }
                if(campo_forza[i][k+1]==campo_forza[i][k+2] && campo_forza[i][k+3]==campo_forza[i][k+1]
                   && campo_forza[i][k+1]!=0)
                {
                        voto[i][k]=10;
                }
                if(campo_forza[i+1][k-1]==campo_forza[i+2][k-2] && campo_forza[i+1][k-1]==campo_forza[i+3][k-3]
                   && campo_forza[i+1][k-1]!=0)
                {
                        voto[i][k]=10;
                }
                if(campo_forza[i+1][k]==campo_forza[i+2][k] &&campo_forza[i+1][k]==campo_forza[i+3][k]
                   && campo_forza[i+1][k]!=0)
                {
                        voto[i][k]=10;
                }
                if(campo_forza[i+1][k+1]==campo_forza[i+2][k+2] && campo_forza[i+1][k+1]==campo_forza[i+3][k+3]
                   && campo_forza[i+1][k+1]!=0)
                {
                        voto[i][k]=10;
                }
        }
    }
}
