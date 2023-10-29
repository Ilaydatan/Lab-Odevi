#include<stdio.h>
#include<stdlib.h>
//Klavyeden -1 girilinceye kadar girilen tüm tek sayýlarý listenin baþýna çift sayýlarý ise listenin sonuna ekleyen fonksiyon
struct node{
	int data;
	struct node *next;
};
//Listeye Eleman Ekleme
struct node *add(struct node *head){

	
	printf("Listeye Eleman Ekleyiniz:");
	int key;
	scanf("%d",&key);
	while(key!=-1){
	struct node *temp=(struct node*)malloc(sizeof(struct node));

		
		temp->data=key;
		temp->next=NULL;
		if(key%2!=0){
			
			temp->next=head;
			
			head=temp;
			//return head;
		}
		else{
			if(head==NULL){
				head=temp;
			}
			else{
			
			struct node*temp2=(struct node*)malloc(sizeof(struct node));
			temp2=head;
			while(temp2->next!=NULL){
				temp2=temp2->next;
			}
			temp2->next=temp;
			//eturn head;
		}
	}
		scanf("%d",&key);
	}
	return head;
} 
void listinfo(struct node *head)
{
	
	while(head!=NULL)
	{
		printf("Listenin son hali: %d\n",head->data);
		head=head->next;
	
	}
	
}
int main(){
	struct node *head=NULL;

	head=add(head);
	listinfo(head);
	
	 while (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

	return 0;
}

