#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//Listede rastgele 100 sayý üretilen ve bu sayýlarý büyüktenküçüðe sýralayan ve ekrana yazan c kodu
struct node{
	int data;
	struct node *next;
};



struct node *add(struct node *head){
	int key;

	srand(time(NULL));
	int i=0;

	
	while(i<100){
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		key=1+rand()%100;
		temp->data=key;
	    temp->next=head;
	   
	
		 if (head == NULL || temp->data >= head->data) {
            head = temp;
        } else {
            struct node *temp2= head;
            while (temp2->next != NULL && temp->data < temp2->next->data) {
                temp2 = temp2->next;
            }
            temp->next = temp2->next;
            temp2->next = temp;
        }
		i++;
	}
return head;
	
}
void listinfo(struct node *head){
	while (head!=NULL){
		printf("Listenin son hali: %d\n",head->data);
		head=head->next;
	}
	
}
int main()
{
	struct node *head=NULL;


	head=add(head);
	listinfo(head);
	
	while(head!=NULL){
		struct node *temp=head;
		head=head->next;
		free(temp);
		
	}
	return 0;
	
}
