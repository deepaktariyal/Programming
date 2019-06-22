using namespace std;
#include<iostream>
#include<bits/stdc++.h>
void swap(char &a,char &b)
{
	char temp = a;
	a = b;
	b = temp;
}
void permute(char a[],char str[],int l,int k,int loc)
{
	int i,j;
	if(l==k)
	{
		a[l]='\0';
		cout<<a<<endl;
		return;
	}
	for(i=loc;i<9;i++)
	{
		a[l] = str[i];
		swap(str[i],str[loc]);
		permute(a,str,l+1,k,loc+1);
		swap(str[i],str[loc]);
	}
		
}
int main(){
	int k;
	char str[] = {'1','2','3','4','5','6','7','8','9'};
	cin>>k;
	char a[k+1];
	for(int i=0;i<9;i++)
	{
		a[0] = str[i];
		swap(str[i],str[0]);
		permute(a,str,1,k,1);
		swap(str[i],str[0]);
	}
}
