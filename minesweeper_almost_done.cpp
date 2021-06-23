#include <iostream>
#include <cstdlib>
#include <time.h>
char  board [10][10], cover[10][10];
int unrevNB;
using namespace std;
void gen(int a,int b)
{
    if(board[a][b]!='*')
    {
        if(board[a+1][b]=='*' and a!=9)
        {
            board[a][b]++;
        }
        if(board[a-1][b]=='*' and a!=0)
        {
            board[a][b]++;
        }
        if(board[a][b+1]=='*' and b!=9)
        {
            board[a][b]++;
        }
        if(board[a][b-1]=='*' and b!=0)
        {
            board[a][b]++;
        }
        if(board[a+1][b+1]=='*' and a!=9 and b!=9)
        {
            board[a][b]++;
        }
        if(board[a-1][b-1]=='*' and a!=0 and b!=0)
        {
            board[a][b]++;
        }
        if(board[a+1][b-1]=='*' and a!=9 and b!=0)
        {
            board[a][b]++;
        }
        if(board[a-1][b+1]=='*' and a!=0 and b!=9)
        {
            board[a][b]++;
        }
    }
    return;
}
void rev (int c, int d)
{
    if(board[c+1][d]=='0' and c!=9 and cover[c+1][d]=='#')
    {
        cover[c+1][d]=board[c+1][d];
        unrevNB--;
        rev(c+1, d);
    }
    if(board[c-1][d]=='0' and c!=0 and cover[c-1][d]=='#')
    {
        cover[c-1][d]=board[c-1][d];
        unrevNB--;
        rev(c-1, d);
    }
    if(board[c][d+1]=='0' and d!=9 and cover[c][d+1]=='#')
    {
        cover[c][d+1]=board[c][d+1];
        unrevNB--;
        rev(c, d+1);
    }
    if(board[c][d-1]=='0' and d!=0 and cover[c][d-1]=='#')
    {
        cover[c][d-11]=board[c][d-1];
        unrevNB--;
        rev(c, d-1);
    }
    if(board[c+1][d+1]=='0' and c!=9 and d!=9 and cover[c+1][d+1]=='#')
    {
        cover[c+1][d+1]=board[c+1][d+1];
        unrevNB--;
        rev(c+1, d+1);
    }
    if(board[c-1][d-1]=='0' and c!=0 and d!=0 and cover[c-1][d-1]=='#')
    {
        cover[c-1][d-1]=board[c-1][d-1];
        unrevNB--;
        rev(c-1, d-1);
    }
    if(board[c+1][d-1]=='0' and c!=9 and d!=0 and cover[c+1][d-1]=='#')
    {
        cover[c+1][d-1]=board[c+1][d-1];
        unrevNB--;
        rev(c+1, d-1);
    }
    if(board[c-1][d+1]=='0' and c!=0 and d!=9 and cover[c-1][d+1]=='#')
    {
        cover[c-1][d+1]=board[c-1][d+1];
        unrevNB--;
        rev(c-1, d+1);
    }

}
void case0 (int c, int d)
int main()
{
    int x,y;
    srand((unsigned)time(NULL));
    for(int i=0; i<10; i++)
    {
        for(int ni=0; ni<10; ni++)
        {
            board[i][ni]='0';
            cover[i][ni]='#';
        }

    }
    for(int i=0; i<10; i++)
    {

        x=(rand() % 10) + 0;
        y=(rand() % 10) + 0;
//cout<<x<<" "<<y<<" ";
        if(board[x][y]!='*')
        {
            board[x][y]='*';
        }
        else if(board[x][y]=='*')
        {
            do
            {
                x=(rand() % 10) + 0;
                y=(rand() % 10) + 0;

                board[x][y]='*';

            }
            while (board[x][y]!='*');
        }
    }


    for(int k=0; k<10; k++)
    {
        for(int ki=0; ki<10; ki++)
        {
            gen(k, ki);
            cout<< cover[k][ki]<<" ";
        }
        cout<<endl<<endl;
    }

    int v,q;
    unrevNB=90;
    while(unrevNB>0){

        cin>>v>>q;
    if(board[v][q]!='*')
    {
        cover[v][q]=board[v][q];
        unrevNB--;
     rev(v, q);
        for(int k=0; k<10; k++)
        {
            for(int ki=0; ki<10; ki++)
            {

                cout<< cover[k][ki]<<" ";
            }

            cout<<endl<<endl;
        }

    }
    else
    {
         cover[v][q]=board[v][q];
                 for(int k=0; k<10; k++)
        {
            for(int ki=0; ki<10; ki++)
            {
                cout<< cover[k][ki]<<" ";
            }

            cout<<endl<<endl;
        }

cout<< "Game over";
break;
    }

}

return 0;}
