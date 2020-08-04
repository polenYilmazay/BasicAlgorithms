#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int KMPSearch(int A[],int a,int B[],int b){
	int i,j,x,check=0,locationIndex = 0;
	int locations[10];
	for(i=0;i<a - b + 1;i++)
	{
		for(j=0;j<b;j++)
		{
			if(A[i + j]==B[j])
			{
				check += 1;
				if(check == b)
				{
					locationIndex += 1;
					locations[locationIndex] = i;
				}
			}
			else
			{
				check = 0;
			}
		}
		if(j==a)
	     cout<<"B bulunamadý.";
	}
	for(i=1;i<=locationIndex;i++)
	{
		cout<<"\nKonum:"<<locations[i];
		
	}	
}



int main(){
	srand(time(NULL));
	int a,b;
	int i;
	cout<<"Aranacak ve aranan string uzunlugunu giriniz : ";
	cin>>a;
	cin>>b;
	int A[a];
	for(int i=0;i<a;i++)
	{
		int c=rand()%2;
		A[i]=c;
		cout<<A[i];
	}
	cout<<"\n";
	int B[b];
	for(int i=0;i<b;i++)
	{
		int c=rand()%2;
		B[i]=c;
		cout<<B[i];
	}
	KMPSearch(A,a,B,b);
	return 0;
	
}
