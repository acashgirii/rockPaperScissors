#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

char compMove()
{
    srand(time(0));
    int ind = rand()%3;

    if(ind==0)
    {
        return 'r';
    }
    else if(ind==1)
    {
        return 's';
    }
    else
    {
        return 'p';
    }
}

int counter(int n)
{
    char u;
   
    int uCount=0;
    int cCount=0;

    for(int i=0;i<n;i++)
    {
        cin>>u;
        char v = compMove();
        cout<<"User Input: "<<u<<endl;
        cout<<"Comp Input: "<<v<<endl;
        if(u=='r' && v=='p'||u=='p'&& v=='s' || u=='s' && v=='r')
        {
            cCount++;
        }
        else
        {
            uCount++;
        }
    }

    if(cCount>uCount)
    {
        cout<<"Computer Wins, score: "<<cCount<<endl;
    }
    else if(uCount>cCount)
    {
        cout<<"User Wins, score: "<<uCount<<endl;
    }
    else
    {
        cout<<"It's a tie. Initiating tie-breaker round"<<endl;
        counter(1);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of rounds to be played: ";
    cin>>n;

    counter(n);
}