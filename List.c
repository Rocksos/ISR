#include <stdlib.h>
#include "Checks.c"
#include "IList.c"

static struct Type_head head;
void CreateBD(){
	struct Type_head *temp = malloc(sizeof(struct Type_head));
	(*temp).count = 0;
	(*temp).first = 0;
	head =  (*temp);
}
void addlast(struct Type_item *item){
	struct Type_item *pt;
	if(head.count == 0){
		item->next=0;
		head.first = item;
		head.count = head.count + 1;
	}else{
		pt = head.first;
	while(pt->next != 0){
		pt = pt->next;
	}
		item->next=0;
		pt->next = item;
		head.count = head.count + 1;
	}
}
void AddNewItem(){
	struct  Type_item *item = malloc(sizeof(struct Type_item));
	printf("Введите дату и время вылета\n");
	strcpy((*item).DateStart,GetStrt(15));
	printf("Введите аэропорт вылета\n");
	strcpy((*item).AirPortNameStart,GetStrt(15));
	printf("Введите аэропорт прилета,\n");
	strcpy((*item).AirPortNameFinish,GetStrt(15));
	printf("Введите дата и время прилета\n");
	strcpy((*item).DateFinish,GetStrt(15));
	printf("Введите марка самолета\n");
	strcpy((*item).Mark,GetStrt(30));
	addlast(item);
}
void PrintTab(){
	struct Type_item *pt;
	pt = head.first;
	printf("|дата и время вылета|аэропорт вылета|аэропорт прилета|дата и время прилета|марка самолета|\n");
  	while(pt != 0) {
    printf("|%19s|%15s|%16s|%20s|%14s|\n",pt->DateStart,pt->AirPortNameStart,pt->AirPortNameFinish,pt->DateFinish,pt->Mark);
    pt = pt->next; // переход к следующему узлу
  	}
}
void Load(){
	struct Type_item *pt;
	FILE *fp;
	char *name = "save.dat";
	fp = fopen(name, "rb");
	CreateBD();
	int co = 0;
  	while (!feof(fp)){
  		co++;
  		pt = malloc(sizeof(struct Type_item));
  		fread(pt, sizeof(struct Type_item),  1, fp);
  		pt->next=0;
  		addlast(pt);
  	};
	fclose(fp);
}
void Save(){
	struct Type_item *pt;
	FILE *fp;
	char *name = "save.dat";
	fp = fopen(name, "wb");
	pt = head.first;
  	while (pt != 0) 
	{
  		fwrite(pt, sizeof(struct Type_item),  1, fp);
   		pt = pt->next; // переход к следующему узлу
  	};
	fclose(fp);
}
void DelNum(int Num){
	struct Type_item *pt,*p;
	head.count=head.count-1;
	pt = head.first;
	if(Num == 0)
	{
		p =	head.first->next;
		head.first = p;
	}
	else
	{
		for(int i=0;i<Num;i++) {
			p = pt;
			pt = pt->next; // переход к следующему узлу
		} 
		p->next = pt->next;
	}
}

void EditNum(int Num){
	if(Num <= head.count){
		struct Type_item *pt,*p;
			struct  Type_item *item = malloc(sizeof(struct Type_item));
			printf("Введите дату и время вылета\n");
			strcpy((*item).DateStart, GetStrt(15));
			printf("Введите аэропорт вылета\n");
			strcpy((*item).AirPortNameStart, GetStrt(15));
			printf("Введите аэропорт прилета,\n");
			strcpy((*item).AirPortNameFinish, GetStrt(15));
			printf("Введите дата и время прилета\n");
			strcpy((*item).DateFinish, GetStrt(15));
			printf("Введите марка самолета\n");
			strcpy((*item).Mark, GetStrt(30));
		if(Num == 0)
		{
			p =	head.first->next;
			item->next =p;
			head.first = item;
		}
		else
		{
			for(int i=0;i<Num;i++) {
				p = pt;
				pt = pt->next; // переход к следующему узлу
			} 
			item->next = pt->next;
			p->next = item;
		}
    }

}