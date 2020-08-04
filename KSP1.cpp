#include<iostream>
using namespace std;
 
int knapsack(int W[], int V[], int N, int K)
{
    //Sýrt çantasý aðýrlýðý yoksa.Buna 0 deðeri atanmýþsa 
    if(K==0)
        return 0;
 
    //Kaç tane item olacaðý.Eðer item 0 atanýrsa fonksiyon çalýþmaz.
    if(N==0)
        return 0;
 
    if(W[N-1]>K)
        return knapsack(W,V,N-1,K);   
     
    return max(knapsack(W,V,N-1,K),V[N-1]+knapsack(W,V,N-1,K-W[N-1]));
}
 
int main()
{
    int i,N=5;
    int K;  ///Sýrt çantasý kapasitesi
    
    char choice[N]={'A','B','C','D','E'};
    int W[N];  //Ýtemlarýn aðýrlýklarý
    int V[N];  //Ýtemlarýn adet sayýlarý
    
    for(i=0;i<N;i++){ // Itemlar için aðýrlýk ve adet sayýsý girilir.
    	cout<<choice[i]<<" icin agirlik ve adet sayisi giriniz : \n";
    	cin>>W[i];
    	cin>>V[i];
	}
 
    cout<<"Knapsack kapasitesi giriniz : ";
    cin>>K;
 
    cout<<"Cantaya konabilecek en fazla esya sayisi : \n"<<knapsack(W,V,N,K);
    
    return 0;
}
