#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
using namespace std;

char output(char u[])
{
    char a;
    int lu;
    lu=strlen(u);
    int pos=(int)((80-1)/2);
    for(int i=0;i<pos;i++)
        cout<<" ";
    cout<<u<<endl;
    return a;
}


class game
{
private:
    char mat[3][3];
public:

    game()
    {

        srand(time(NULL));
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                    mat[i][j]=NULL;
    }

    display()
    {
            cout<<"_______________"<<endl;
           for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        if(mat[i][j]==NULL)
                        {
                            cout.width(4);
                            cout<<" "<<"|" ;
                        }
                        else
                        {
                            cout.width(4);
                            cout<<mat[i][j]<<"|";
                        }
                    }
                    cout<<endl;
                }
            cout<<"---------------"<<endl<<endl<<endl;
        }

    int input(int i,int j, int val)
    {
        if(mat[i][j]!=NULL)
        {
            cout<<"Invalid Choice!! Try AGAIN"<<endl;
            return 1;
        }

        {
            if(val==0)
            {
                mat[i][j]='O';
            }
            else
                mat[i][j]='X';
        }
        display();
        int z=win();
        if(z==1 && val==1)
        {
            cout<<"Player 1 Wins"<<endl;
            exit(0);
        }
        else
            if(z==1 && val==0)
        {
            cout<<"Player 1 Looses"<<endl;
            exit(0);
        }
    }

    int win()
    {
        int i,j;
        { ///row
            for(i=0;i<3;i++)
                if(mat[i][0]!=NULL && mat[i][1]!=NULL && mat[i][2]!=NULL && mat[i][0]==mat[i][1] && mat[i][1]==mat[i][2])
                {
                    ///cout<<"!!!YOU WIN!!!"<<endl;
                    ///exit(0);
                    return 1;
                }
        }
        { ///column
            for(i=0;i<3;i++)
                if(mat[0][i]!=NULL && mat[1][i]!=NULL && mat[2][i]!=NULL && mat[0][i]==mat[1][i] && mat[1][i]==mat[2][i])
                {
                    ///cout<<"!!!YOU WIN!!!"<<endl;
                    ///exit(0);
                    return 1;
                }
        }
        { ///right daigonal
                if(mat[0][0]!=NULL && mat[1][1]!=NULL && mat[2][2]!=NULL && mat[0][0]==mat[1][1] && mat[1][1]==mat[2][2])
                {
                    ///cout<<"!!!YOU WIN!!!"<<endl;
                    ///exit(0);
                    return 1;
                }
        }
        { ///left daigonal
                if(mat[0][2]!=NULL && mat[1][1]!=NULL && mat[2][0]!=NULL && mat[0][2]==mat[1][1] && mat[1][1]==mat[2][0])
                {
                   /// cout<<"!!!YOU WIN!!!"<<endl;
                   /// exit(0);
                   return 1;
                }
        }
        { ///draw
            for(i=0;i<3;i++)
                for(j=0;j<3;j++)
                    if(mat[i][j]==NULL)
                        return 0;
                cout<<"!!!DRAW!!!"<<endl;
                cout<<"Better Luck Next Time"<<endl;
                exit(0);
        }
    }

    cpu()
    {
        int i,j;
        i=rand()%3;
        j=rand()%3;
        while(mat[i][j]!=NULL)
        {
         i=rand()%3;
         j=rand()%3;
        }
        input(i,j,0);

    }





};

int main()
{
    game obj1;
    int c,m,a;
    output("Tic-Tac-Toe");
    cout<<"1> V/s Player"<<endl;
    cout<<"2> V/s CPU"<<endl;
    cin>>m;


    ///PLAYER MODE
    if(m==1)
    {
    cout<<"Player1 takes 'X'"<<endl;
    cout<<"Player2 takes 'O'"<<endl;
    for(int i=0;;i++)
    {
        if(i%2==0)
        {
            cout<<"Player 1"<<endl;
        }
        else
            cout<<"Player 2"<<endl;

    cout<<"Select cell using num pad[1-9]"<<endl;
    cin>>c;
    switch(c)
    {
    case 1:
        if(i%2==0)
        obj1.input(2,0,1);
        else
        obj1.input(2,0,0);
        break;
    case 2:
         if(i%2==0)
        obj1.input(2,1,1);
        else
        obj1.input(2,1,0);
        break;
    case 3:
        if(i%2==0)
        obj1.input(2,2,1);
        else
        obj1.input(2,2,0);
        break;
    case 4:
        if(i%2==0)
        obj1.input(1,0,1);
        else
        obj1.input(1,0,0);
        break;
    case 5:
        if(i%2==0)
        obj1.input(1,1,1);
        else
        obj1.input(1,1,0);
        break;
    case 6:
        if(i%2==0)
        obj1.input(1,2,1);
        else
        obj1.input(1,2,0);
        break;
    case 7:
        if(i%2==0)
        obj1.input(0,0,1);
        else
        obj1.input(0,0,0);
        break;
    case 8:
        if(i%2==0)
        obj1.input(0,1,1);
        else
        obj1.input(0,1,0);
        break;
    case 9:
        if(i%2==0)
        obj1.input(0,2,1);
        else
        obj1.input(0,2,0);
        break;
    default:
        i--;
        cout<<"!Invalid Choice  TRY AGAIN"<<endl;

    }
    }
    }


    ///cpu mode
    else

        cout<<"Player takes X"<<endl;
        cout<<"CPU takes O"<<endl;



        for(int i=0;;i++)
    {
       if(i%2==0)
        {
                start:
                cout<<"Player 1"<<endl;
                cout<<"Select cell using num pad[1-9]"<<endl;
                cin>>c;
                    switch(c)
                        {
                        case 1:
                            a=obj1.input(2,0,1);
                            break;
                        case 2:
                            a=obj1.input(2,1,1);
                            break;
                        case 3:
                            a=obj1.input(2,2,1);
                            break;
                        case 4:
                            a=obj1.input(1,0,1);
                            break;
                        case 5:
                            a=obj1.input(1,1,1);
                            break;
                        case 6:
                            a=obj1.input(1,2,1);
                            break;
                        case 7:
                            a=obj1.input(0,0,1);
                            break;
                        case 8:
                            a=obj1.input(0,1,1);
                            break;
                        case 9:
                            a=obj1.input(0,2,1);
                            break;
                        default:
                                cout<<"!Invalid Choice  TRY AGAIN"<<endl;
                        }
                        if(a==1)
                            goto  start;
        }
        else
            {
                cout<<"CPU Plays"<<endl;
                obj1.cpu();


            }

    }
    return 0;
}
