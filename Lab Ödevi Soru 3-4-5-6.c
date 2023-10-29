#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Student isimli Struct Oluþturma ve Gerekli Bilgileri Yazma
struct student{
	char name[40];
	int age;
	int number;
	struct student *next;
	
};
typedef struct student node;
node *head, *newnode;

//Ogrenci Listesi Oluþturma
struct student *creatList(){
	node *head ,*p;
	int n,i;
	printf("Kac tane ogrenci eklemek istersiniz:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		if(i==0){
			head=(node*)malloc(sizeof(node));
			p=head;
		}
		else{
			p->next=(node*)malloc(sizeof(node));
			p=p->next;
		}
		printf("Ogrencinin ismini giriniz:");
		scanf("%s",&p->name);
		printf("Ogrencinin yasini giriniz:");
		scanf("%d",&p->age);
		printf("Ogrencinin numarasini giriniz:");
		scanf("%d",&p->number);
	}
	p->next=NULL;
	return head;
}
//Listede Gezinme ve Ogrenci Bilgilerini Yazdýrma
void traverseList(node* head)
{
	int counter=1;
	node *p;
	p=head;
	
	while(p!=NULL)
	{
		printf("%d %s %d %d\n",counter,p->name,p->age,p->number);
		p=p->next;
		counter++;
	
	}
	
}
//Listede Arama Yapma
void search(node *head){
	int counter=1;
	char searchName[40];
	node *p=head;
	
	printf("Aramak istediginiz ismi giriniz:");
	scanf("%s",searchName);
	while(p!=NULL)
	{
	
		if(strcmp(p->name, searchName)==0){
			printf("Aradiginiz isim %d. dugumdedir",counter);
			
		}

			p=p->next;
		    counter++;
	}
}
//Listedeki Düðümü Silme
void deleted(node *head){
	
	char searchName[40];
	node *p=head;
	node *q;
	printf("Aramak istediginiz ismi giriniz:");
	scanf("%s",searchName);
	while(p!=NULL){
		if(strcmp(p->name,searchName)==0){
			
		    node *temp=p->next;
			p->next=temp->next;
			free(temp);
		}
		q=p;
		p=p->next;
	
	}
	
}
//Listedeki en uzun ismi Bulma
char* longName(node *head) {
    

    char *longestName = head->name; 
    node *p = head->next;
    
    while (p!= NULL) {
        if (strlen(p->name) > strlen(longestName)) {
            longestName = p->name; 
            
        }
         p=p->next;
    }
    printf("En uzun isim: %s, Uzunluk: %d",longestName,strlen(longestName));

    return longestName;
}
//Main Fonksiyonu Ýçinde Fonksiyonlarý Yazdýrma
int main()
{
	node* head=NULL;
	int secim;
	head=creatList();

	printf("Lutfen seciminizi giriniz(1-4):");
	scanf("%d",&secim);
	
    switch(secim)
    {
    	case 1:
    		traverseList(head);
    		break;
    	case 2:
    		search(head);
    		break;
    	case 3:
    		deleted(head);
    		break;
    	case 4:
    		longName(head);
    		break;
    			
	}
	node* p = head;
    while (p != NULL) {
         node* temp = p;
         p = p->next;
        free(temp);
    }


}

