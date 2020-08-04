#include<iostream>
using namespace std;
 
int knapsack(int W[], int V[], int N, int K)
{
    //S�rt �antas� a��rl��� yoksa.Buna 0 de�eri atanm��sa 
    if(K==0)
        return 0;
 
    //Ka� tane item olaca��.E�er item 0 atan�rsa fonksiyon �al��maz.
    if(N==0)
        return 0;
 
    if(W[N-1]>K)
        return knapsack(W,V,N-1,K);   
     
    return max(knapsack(W,V,N-1,K),V[N-1]+knapsack(W,V,N-1,K-W[N-1]));
}
 
int main()
{
    int i,N=5;
    int K;  ///S�rt �antas� kapasitesi
    
    char choice[N]={'A','B','C','D','E'};
    int W[N];  //�temlar�n a��rl�klar�
    int V[N];  //�temlar�n adet say�lar�
    
    for(i=0;i<N;i++){ // Itemlar i�in a��rl�k ve adet say�s� girilir.
    	cout<<choice[i]<<" icin agirlik ve adet sayisi giriniz : \n";
    	cin>>W[i];
    	cin>>V[i];
	}
 
    cout<<"Knapsack kapasitesi giriniz : ";
    cin>>K;
 
    cout<<"Cantaya konabilecek en fazla esya sayisi : \n"<<knapsack(W,V,N,K);
    
    return 0;
}
