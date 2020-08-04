#include<iostream>

using namespace std;

int lengthOfArray = 0;
 
class Stack
{
    private:
        int top;
        int size;
        int *stack;
    public:
		Stack(int boy);    
        int push(int);
        int pop();
        int isEmpty();
        void displayItems();
        void SelectionSortRecursion(int dizi[], int startIndex);
        void SelectionSort(int stack[],int n);
};

Stack::Stack(int boy)
{
	   top=-1;
       size=boy;
       stack = new int [boy];
}
 
int Stack::isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;   
}
 
int Stack::push(int n){
    if(top==size-1)
              cout<<"Stackte yeterli alan yok..."<<endl;
    else{
      ++top;
      stack[top]=n;}
    return n;
}
 
int Stack::pop(){
    int temp;
    if(isEmpty())
        return 0;
    temp=stack[top];
    --top;
    return temp;
     
}

void Stack::SelectionSortRecursion(int stack[], int startIndex) {
    if(startIndex >= lengthOfArray - 1) {
        return;
    }
    int min_index;
    min_index = startIndex;
    for(int index = startIndex + 1; index < lengthOfArray; index++) {
        if(stack[index] < stack[min_index]) {
            min_index = index;
        }
    }
    int temp = stack[startIndex];
    stack[startIndex] = stack[min_index];
    stack[startIndex] = temp;
    SelectionSortRecursion(stack, startIndex + 1);
}
 
void Stack::SelectionSort (int dizi[], int elemanSayisi)
{
     int i, j, enKucuk, temp;
     for (i=0; i<elemanSayisi-1; i++)
     {
         enKucuk = i;
         for (j=i+1; j<elemanSayisi; j++)
         {
             if (dizi[j] < dizi [enKucuk])
             enKucuk = j;
         }
         temp = dizi[i];
         dizi[i] = dizi[enKucuk];
         dizi[enKucuk] = temp;
     }
}   
 
void Stack::displayItems(){

    int choice;
	cout<<"Non-Recursive icin 1,Recursive icin 2'yi seciniz..'";
	cin>>choice;
	
	switch(choice){
		case 1 :
			SelectionSort(stack,size); 
            break;
		case 2:
			SelectionSortRecursion(stack,size);
            break;  
		
		default: cout<<"Bilinmeyen bir deger girdiniz!..";	
	}

  
  for(int i=0;i<size;i++){
   cout<<stack[i];//Ekrana yazdýrýyoruz.
  }
}
 
int main(){
    //Stack stk;
    int choice,temp,n;
    
    int x;
    cout<<"Stack kac elemanli olacak : ";
    cin>>x;
    Stack item(x);
     
    do
    {
        cout<<"\n1 - Push (Eleman ekleme)"<<endl;
        cout<<"2 - Pop (Eleman cikarma)"<<endl;
        cout<<"3 - Ekrana Yazdýr"<<endl;
        cout<<"4 - Cikis."<<endl;
        cout<<"Lutfen secim yapiniz : ";
        cin>>choice;
         
        switch(choice){
            case 1:
                cout<<"Eklenmesini istediginiz elemani giriniz : ";
                cin>>n;
                temp=item.push(n);
                break;
            case 2:
                item.pop();
                if(temp==0)
                    cout<<"Stack bos"<<endl;
                else
                    cout<<temp<<" silindi(cikarildi)"<<endl;
                break;
            case 3:
                item.displayItems();
                break;
            case 4: 
			    break;    
            default:
                cout<<"Olmayan bir secenek girdiniz.."<<endl;
        }   
    }while(choice!=4);
 
    return 0;
     
}
