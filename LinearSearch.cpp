#include <stdio.h>
#include<stdlib.h>

struct node{
	
	int data;
	struct node *next;
} * head;

void createList(int n);
void displayList();
int  RecLinearSearch(int key, struct node *curNode, int index);

//n node i�in liste yarat�yoruz
void createList(int n)
{
	struct node *newNode,*temp;
	int data ,i;
	
	head =(struct node *)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("yer ayrilamadi");
		exit(0);
	}
	printf("1.Elemanin sayi degeri  giriniz :");
	scanf("%d",&data);
	
	head->data=data;
	head->next=NULL;
	temp=head;

	// n node yarat�lacak ve listeye eklenecek
for(i=2;i<=n;i++)
{
	newNode=(struct node *)malloc(sizeof(struct node));  //Her eleman i�in bellekten yer a��lacak.
	
 	if (newNode == NULL) //Yer a��l�p a��lmad��� kontrol ediliyor.
        {
            printf("newNode i�in yer ayr�lamad�.");
            exit(0);
        }

        printf("%d.Elemanin sayi segerini giriniz : ", i);
        scanf("%d", &data);

        newNode->data = data; //Yeni eleman i�in atama yap�ld�
        newNode->next = NULL; // Yeni elemandan sonra hi�bir �ey gelmesin.

        temp->next = newNode; 
        temp = temp->next;	
}
}
//Girilen elemanlar�n listelenme fonksiyonu
void displayList()
{
	struct node *temp;
	if (head == NULL) //�lk elemean var m� yok mu kontrol�
    {
        printf("Liste bo�.\n");
        return;
    }
	temp = head;    
    while (temp != NULL)  //Listede eleman varsa kontrol�.Head temp'e atanm��t�.B�ylece ilk elemanda de�er var m� kontorl� de yap�l�yor.
    {
        //printf("%d, ", temp->data); //Listede eleman varsa o de�eri ekrana yazd�r�r.
        //temp = temp->next;    // Sonraki elemana ge�i� yap
        for(int i=1;i<=temp->data;i++){
        	if(temp->data%i==0)
        	 printf("%d sayisinin pozitif tam sayi bolenleri : %d \n ",temp->data,i);
		}
		temp=temp->next;
    }
    printf("\n");

    
}
//Linear Search Recursive Fonksiyonu
int RecLinearSearch(int key, struct node *curNode, int index)
{
    if (curNode == NULL)                // Aranan Eleman bulunamad�.
        return -1;
    else if (curNode->data == key)   // Eleman bulundu.�ndex d�nd�r�ld�.
        return index;
    else                                // Bulunamad�.Sonraki eleman� kontrol et.
        return RecLinearSearch(key, curNode->next, index + 1); //Recursive k�sm�.curNode->next ile bir sonraki elemana ge�i� yap�ld� ve liste sonunda gelene kadar kontrol edildi.
}

int main()
{
	int n, key, index; //n : eleman say�s�. key : aranan eleman
	
	printf("Bagli Listede kac eleman bulunacak ? ");
    scanf("%d", &n);
	createList(n);   //Girilen elemanlar� linked list yap�s�yla birbirine ba�lama
	//printf("\nData in list: \n"); 
    //displayList();   //Girilen elemanlar listelenip ekrana yazd�r�ld�.
    
    printf("\nAranacak elemani giriniz: ");
    scanf("%d", &key);  //Aranacak eleman de�eri girildi.
    // Fonksiyonu �ag�r�yoruz.Head ba�lang�� noktas� olmaz zorunda.
    index = RecLinearSearch(key, head, 0);
    
     if (index >= 0)
        printf("%d listede bulundu ve listede %d.pozisyonda\n", key, index + 1);
    else
        printf("%d Listede bulunamadi.\n", key);
    displayList();   //Girilen elemanlar listelenip ekrana yazd�r�ld�    
        
    return 0;
}
