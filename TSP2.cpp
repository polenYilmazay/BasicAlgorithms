//#include<stdio.h>
//#include<conio.h>
#include <iostream>
using namespace std;

class TSP{
	private:
		int city;
		int c;
	public:
		void get();
		void mincost(int city);
		int least(int c);
};

int a[10][10],visited[10],n,cost=0;

int TSP::least(int c)
{
	int i,nc=999;
	int min=999,kmin;
	for(i=0;i < n;i++)
	{
		if((a[c][i]!=0)&&(visited[i]==0))
			if(a[c][i] < min)
			{
				min=a[i][0]+a[c][i];
				kmin=a[c][i];
				nc=i;
			}
	}
	if(min!=999)
		cost+=kmin;
	return nc;
}


void TSP::get() //Kaç þehir olacaðýný ve yol maaliyetlerini kullanýcýdan alan fonksiyon
{
	int i,j;
	
	//cout<<"\nYol Maliyetlerini giriniz : \n";
	for(i=0;i < n;i++)
	{
		cout<<"\nRow # "<<i+1<<" icin elemanlari giriniz : ";
		for( j=0;j < n;j++)
			cin>>a[i][j];
		visited[i]=0;
	}
	cout<<"\n\n Maaliyet Listesi :\n\n";
	for( i=0;i < n;i++)
	{
		cout<<"\n\n";
		for(j=0;j < n;j++)
			cout<<"\t"<<a[i][j];
	}

}

void TSP::mincost(int city)  //Minimum yolu hesaplayan fonksiyon
{
	int i,ncity;
	visited[city]=1;	
	cout<<"\t -->"<<city+1;
	ncity=least(city);
	if(ncity==999)
	{
		ncity=0;
		cout<<"\t"<<ncity+1;
		cost+=a[city][ncity];
		return;
	}
	mincost(ncity);
}


int main()
{
	cout<<"Sehir sayisini giriniz : ";
	cin>>n;
	if(n>=3&&n<=50){
	TSP ob;
	ob.get();
	cout<<"\n\nThe Path is:\n\n";
	ob.mincost(0);
	cout<<"\n\nMinimum cost:";
	cout<<"\t"<<cost;
	//getch();
    }
    else 
	   cout<<"Gerekli kosullari saglamadi.";
	return -1 ;
}
