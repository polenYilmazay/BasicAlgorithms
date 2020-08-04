#include<iostream>
#include<string>

using namespace std;


class Kuyruk{
	private:
		int frontElement,rearElement;
		int top,size,boy;
        int *Queue;
	public:
		Kuyruk(int boy);
		void BubbleSortRecursion(int a[],int num);
		void BubbleSort(int Queue[],int n);
		int sirala();
		int enQueue(int);
		int deQueue();
		int QueueYazdir();
		int isFull();
		int isEmpty();
};
Kuyruk::Kuyruk(int boy)
{
	frontElement=0;
	rearElement=-1;
	top=-1;
    size=boy;
    Queue = new int [boy];
};

int Kuyruk::isEmpty(){
	int empty=0;
	if(frontElement=rearElement+1)
	  empty=1;
	return empty;
}

int Kuyruk::isFull(){
	int full=0;
	if(rearElement=size-1)
	 full=1;
	return full; 
}



int Kuyruk::enQueue(int n)
{
    if(rearElement==size-1)
    {
        cout<<"\n ***************\n";
        cout<<"\n Kuyruk Dolu, Eleman Ekleyemezsiniz. Eleman Eklemek icin eleman cikarmalisiniz. \n";
    }
    else
    {
        if(frontElement == -1)
        {
            frontElement = frontElement + 1;
        }
        rearElement = rearElement + 1;
        Queue[rearElement] = n;
    }
}

int Kuyruk::deQueue()
{
    if(frontElement == -1 || frontElement > rearElement)
    {
        cout<<"\n ***************\n";
        cout<<"\n Kuyrugunuz zaten bos, lutfen eleman ekleyin";
    }
    else
    {
        int veri;
        veri=Queue[0];
        for(int k=1;k<rearElement;k++){
        	Queue[k-1]=Queue[k];
        frontElement--;	
		}
        frontElement = frontElement + 1;
    }

}

int Kuyruk::QueueYazdir()
{
    int i;
    if(frontElement == -1 || frontElement > rearElement)
    {
        cout<<"\n ***************\n";
        cout<<"\n Kuyrugunuz bos, lutfen eleman ekleyin";
    }
    else
    {
        for( i = rearElement; i >= frontElement; i--)
        {
            cout<< Queue[i];
        }
    }
}

void Kuyruk::BubbleSortRecursion(int Queue[],int num)
{
 int i,j,temp;
 i=num;
if(i>0)
  {
       for(j=0;j<num-1;j++)
       {
         if(Queue[j]>Queue[j+1])
          {
            temp=Queue[j];
            Queue[j]=Queue[j+1];
            Queue[j+1]=temp;
          }
      }
  BubbleSortRecursion(Queue,num-1);
  }
else
  {
       return ;
   }
}

void Kuyruk::BubbleSort(int Queue[],int n){
	int temp,k,move;
	for(move=0;move<(n-1);move++){
		for(k=0;k<(n-1-move);k++){
			if(Queue[k]>Queue[k+1]){
				temp=Queue[k];
				Queue[k]=Queue[k+1];
				Queue[k+1]=temp;
			}
		}
	}
}

//Bubble sort siralama fonksiyonu
int Kuyruk::sirala()
{
	int choice,i;
	cout<<"Non-Recursive icin 1,Recursive icin 2'yi seciniz..'";
	cin>>choice;
	
	switch(choice){
		case 1 :
			BubbleSort(Queue,size-1);
		/*for (int i=0;i<boy;i++){
          for(int j=0;j<boy-1;j++){
             if(Queue[j]>Queue[j+1]){
                int gecici=Queue[j];       //Sýralama yapyyoruz.
                Queue[j]=Queue[j+1];
                Queue[j+1]=gecici;        
    }
   }
  }*/
  
        break;
		case 2:
			BubbleSortRecursion(Queue,size);
            break;  
		
		default: cout<<"Bilinmeyen bir deger girdiniz!..";	
	}
  
  for(int i=0;i<size;i++){
   cout<<Queue[i];//Ekrana yazdýrýyoruz.
  }
}
int main()
{

   int choice,temp,n;

   cout<<"Kuyruk kac elemanli olacak : ";
   cin>>n;
   Kuyruk item(n);
    
    do
	{
        cout<<"\n 1- Enqueue (Eleman Ekle) ...";
        cout<<"\n 2- Dequeue (Eleman Cikar) ...";
        cout<<"\n 3- Sirala";
        cout<<"\n 4- Cikis"<<endl;
        cout<<"Lutfen Secim Yapiniz : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Eklenmesini istediginiz elemani giriniz : ";
                cin>>n;
                temp=item.enQueue(n);
                break;
            case 2:
                temp=item.deQueue();
                item.QueueYazdir();
                break;
            case 3:
            	item.sirala();
            	break;
            case 4:
            		return -1;
            default:cout<<"Olmayan bir secenek girdiniz..!"	;	
            
        }

    }while(choice!=4);
    return 0;
}
