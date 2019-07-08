/*
Rohit is traveling in India. He is in Delhi and his actual position with coordinates
are (0,0). He wants to travel to other cities i.e. that city coordinates are (x,y).
If there is a path exist, print the minimum number of steps needed to reach it,
else print -1 if the destination is not reachable.
And print path found in next line, if there any path exists between the (0,0)
to (x,y), else print no path found.

Moves are possible in only four directions i.e. up, down, left and right.
The path can only be created out of a cell if its value is 1.
*/
#include<bits/stdc++.h>
using namespace std;
int arr[100][100];
struct cord{
    int x,y;
}typedef cord;
int checkpath(int n,int m,int x1,int y1)
{
    bool visited[n][m]={false};
    if(x1==0&&y1==0)
        return 0;
    queue<cord> q;
    int ans[100] = {0};
    cord temp;
    temp.x = 0;
    temp.y = 0;
    visited[0][0] = true;
    q.push(temp);
    ans[(m-1)*0+0+0] = 0;
    q.push(temp);
    while(!q.empty())
    {
            temp = q.front();
        if(arr[temp.x-1][temp.y]==1&&temp.x-1>=0&&temp.x-1<=n-1&&!visited[temp.x-1][temp.y])
        {
            ans[(m-1)*(temp.x-1)+temp.y+(temp.x-1)] = ans[(m-1)*temp.x+temp.y+temp.x] + 1;
            temp.x=temp.x-1;
            q.push(temp);
            temp.x=temp.x+1;
            visited[temp.x-1][temp.y] = true;
            if(temp.x-1==x1&&temp.y==y1)
                return ans[(m-1)*(temp.x-1)+temp.y+(temp.x-1)];
        }
            if(arr[temp.x+1][temp.y]==1&&temp.x+1>=0&&temp.x+1<=n-1&&!visited[temp.x+1][temp.y])
        {
            ans[(m-1)*(temp.x+1)+temp.y+(temp.x+1)] = ans[(m-1)*temp.x+temp.y+temp.x]+1;
            temp.x=temp.x+1;
            q.push(temp);
            temp.x=temp.x-1;
            visited[temp.x+1][temp.y] = true;
            if(temp.x+1==x1&&temp.y==y1)
                return ans[(m-1)*(temp.x+1)+temp.y+(temp.x+1)];
        }
        if(arr[temp.x][temp.y+1]==1&&temp.y+1>=0&&temp.y+1<=m-1&&!visited[temp.x][temp.y+1])
        {
            ans[(m-1)*temp.x+(temp.y+1)+temp.x] = ans[(m-1)*temp.x+temp.y+temp.x]+1;
            temp.y=temp.y+1;
            q.push(temp);
            temp.y=temp.y-1;
            visited[temp.x][temp.y+1] = true;
            if(temp.x==x1&&temp.y+1==y1)
                return ans[(m-1)*temp.x+(temp.y+1)+temp.x];
        }
        if(arr[temp.x][temp.y-1]==1&&temp.y-1>=0&&temp.y-1<=m-1&&!visited[temp.x][temp.y-1])
        {
            ans[(m-1)*temp.x+(temp.y-1)+temp.x] = ans[(m-1)*temp.x+temp.y+temp.x]+1;
            temp.y=temp.y-1;
            q.push(temp);
            temp.y=temp.y+1;
            visited[temp.x][temp.y-1] = true;
            if(temp.x==x1&&temp.y-1==y1)
                return ans[(m-1)*temp.x+(temp.y-1)+temp.x];
        }
        q.pop();
    }
   return -1;
    }

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int x1,y1;
    cin>>x1>>y1;
    if(arr[0][0]==0)
    {
        cout<<-1<<endl<<"no path found";
        return 0;
    }
    int ans=checkpath(n,m,x1,y1);
    if(ans==-1)
        cout<<ans<<endl<<"no path found";
    else{
        cout<<ans<<endl<<"path found";
    }
    return 0;
}
