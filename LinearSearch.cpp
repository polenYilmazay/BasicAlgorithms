#include <stdio.h>
#include<stdlib.h>

struct node{
	
	int data;
	struct node *next;
} * head;

void createList(int n);
void displayList();
int  RecLinearSearch(int key, struct node *curNode, int index);

//n node için liste yaratýyoruz
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

	// n node yaratýlacak ve listeye eklenecek
for(i=2;i<=n;i++)
{
	newNode=(struct node *)malloc(sizeof(struct node));  //Her eleman için bellekten yer açýlacak.
	
 	if (newNode == NULL) //Yer açýlýp açýlmadýðý kontrol ediliyor.
        {
            printf("newNode için yer ayrýlamadý.");
            exit(0);
        }

        printf("%d.Elemanin sayi segerini giriniz : ", i);
        scanf("%d", &data);

        newNode->data = data; //Yeni eleman için atama yapýldý
        newNode->next = NULL; // Yeni elemandan sonra hiçbir þey gelmesin.

        temp->next = newNode; 
        temp = temp->next;	
}
}
//Girilen elemanlarýn listelenme fonksiyonu
void displayList()
{
	struct node *temp;
	if (head == NULL) //Ýlk elemean var mý yok mu kontrolü
    {
        printf("Liste boþ.\n");
        return;
    }
	temp = head;    
    while (temp != NULL)  //Listede eleman varsa kontrolü.Head temp'e atanmýþtý.Böylece ilk elemanda deðer var mý kontorlü de yapýlýyor.
    {
        //printf("%d, ", temp->data); //Listede eleman varsa o deðeri ekrana yazdýrýr.
        //temp = temp->next;    // Sonraki elemana geçiþ yap
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
    if (curNode == NULL)                // Aranan Eleman bulunamadý.
        return -1;
    else if (curNode->data == key)   // Eleman bulundu.Ýndex döndürüldü.
        return index;
    else                                // Bulunamadý.Sonraki elemaný kontrol et.
        return RecLinearSearch(key, curNode->next, index + 1); //Recursive kýsmý.curNode->next ile bir sonraki elemana geçiþ yapýldý ve liste sonunda gelene kadar kontrol edildi.
}

int main()
{
	int n, key, index; //n : eleman sayýsý. key : aranan eleman
	
	printf("Bagli Listede kac eleman bulunacak ? ");
    scanf("%d", &n);
	createList(n);   //Girilen elemanlarý linked list yapýsýyla birbirine baðlama
	//printf("\nData in list: \n"); 
    //displayList();   //Girilen elemanlar listelenip ekrana yazdýrýldý.
    
    printf("\nAranacak elemani giriniz: ");
    scanf("%d", &key);  //Aranacak eleman deðeri girildi.
    // Fonksiyonu çagýrýyoruz.Head baþlangýç noktasý olmaz zorunda.
    index = RecLinearSearch(key, head, 0);
    
     if (index >= 0)
        printf("%d listede bulundu ve listede %d.pozisyonda\n", key, index + 1);
    else
        printf("%d Listede bulunamadi.\n", key);
    displayList();   //Girilen elemanlar listelenip ekrana yazdýrýldý    
        
    return 0;
}
