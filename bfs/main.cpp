#include <iostream>
#include <string>
using namespace std;

int BreadFirstSearch(int A[5][5],int v)
{
    int queue[25],n = 5,front = -1,rear = -1;

    for(int i =0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            int value=0;

            if (rear == n - 1)
             {
                 cout<<"Overflow"<<endl;
             }
            else
              {
                if (front == - 1)
                {
                   front = 0;
                }

                rear++;
                if(A[i][j]==1)
                {
                    value = j;
                    cout<<value<<endl;
                }
                queue[rear] = value;
             }
       }
    }
    for(int i=0;i<rear;i++)
    {
       if(queue[i]==v)
        {
           return v;
           front++;
        }
    }
     return 0;
}
int main()
{
int nodes=0;
int edge;
int p;
int A[5][5];
for(int i=0;i<5;i++)
{
    for(int j= 0;j<5;j++)
    {
        A[i][j]=0;
    }
}
cout<<"Enter edge:";
cin>>edge;
for(int i=0;i<edge;i++)
{
    int o;
    int p;
    cout<<"edge starts:";
    cin>>o;
    cout<<"edge ends:";
    cin>>p;
    A[o][p]=1;
}
for(int i=0;i<5;i++)
{
    for(int j= 0;j<5;j++)
    {
        cout<<A[i][j];
        cout<<"";
    }
    cout<<""<<endl;
}
int v;
cout<<"enter value which you want to find : ";

cin>>v;
int found =  BreadFirstSearch(A,v);
cout<<found<<endl;
if(found>0)
{
    cout<<"Found";
}
else
{
    cout<<"Not Found";
}
}
