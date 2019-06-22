using namespace std;
#include<iostream>
#include<conio.h>
#include<bits/stdc++.h>
struct cord{
	int x,y;
}typedef cord;
bool allRotten(int arr[][5])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(arr[i][j]==1)
				return false;
		}
	}
	return true;
}
int rotOranges(int arr[][5])
{
	queue<cord> q;
	cord temp;
	int ans=-1,i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			if(arr[i][j]==2)
			{
				temp.x=i;
				temp.y=j;
				q.push(temp);
			}
		}
	}
	temp.x=-1;
	temp.y=-1;
	q.push(temp);
	//cout<<q.back().x<<","<<q.back().y;
	while(!q.empty())
{
	
	while(q.front().x!=-1&&q.front().y!=-1)
	{
		temp = q.front();
		if(arr[temp.x-1][temp.y]==1&&temp.x-1>=0&&temp.x-1<=2)
		{//	cout<<"1";
			arr[temp.x-1][temp.y]=2;
			temp.x=temp.x-1;
			q.push(temp);
			temp.x=temp.x+1;
		}if(arr[temp.x+1][temp.y]==1&&temp.x+1>=0&&temp.x+1<=2)
		{
		//	cout<<"2";
			arr[temp.x+1][temp.y]=2;
			temp.x=temp.x+1;
			q.push(temp);
			temp.x=temp.x-1;
		}
		if(arr[temp.x][temp.y+1]==1&&temp.y+1>=0&&temp.y+1<=4)
		{//	cout<<"3";
			arr[temp.x][temp.y+1]=2;
			temp.y=temp.y+1;
			q.push(temp);
			temp.y=temp.y-1;
		}
		if(arr[temp.x][temp.y-1]==1&&temp.y-1>=0&&temp.y-1<=4)
		{//	cout<<"4";
			arr[temp.x][temp.y-1]=2;
			temp.y=temp.y-1;
			q.push(temp);
			temp.y=temp.y+1;
		}
		//exit(0);
		//cout<<q.size();
		q.pop();
		/*cout<<q.size()<<endl;
		cout<<q.front().x<<" "<<q.front().y;
		exit(0);
		cout<<"1";*/
		
	}
	q.pop();
	if(!q.empty())
	{
		temp.x=-1;
		temp.y=-1;
		q.push(temp);
	}
	ans++;
	//cout<<q.size();
	queue <cord> q1;
	q1 = q;
	
/*	while(!q1.empty())
	{
		cout<<q1.front().x<<" "<<q1.front().y<<endl;
		q1.pop();
	}*/
}
	if(allRotten(arr))
		return ans;
	else
		return -1;
}
int main(){
	int ans;
	int a[][5]={{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,2}
	};
	/*{{2,1,0,2,1},
			{1,0,1,2,1},
			{1,0,0,2,1}};*/
	ans = rotOranges(a);
	cout<<"\n\n\n"<<ans;
}
