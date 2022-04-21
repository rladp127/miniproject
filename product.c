#include "product.h"
// 함수 정의, 메인 구현

int selectMenu(){
	int menu;
	printf("1. read\n");
	printf("2. create\n");
	printf("3. update\n");
	printf("0. exit\n");
	scanf("%d", &menu);
	return menu;
}

int main(){
	Product p;
	int count = 0, menu;

	while(1){
		menu = selectMenu();
		if (menu == 0) break;

		if (menu == 1||menu == 3)
			if (count == 0) continue;

		if (menu == 1) read(p);

		if (menu == 2){
		       	count++;
			create(&p);
		}

		if (menu == 3) update(&p);
	}	
	printf("종료됨!\n");
	return 0;
}


int create(Product *p){
printf("name: ");
scanf("%s", p->name);

printf("infor: ");
scanf("%s", p->infor);

printf("weight: ");
scanf("%s", p->weight);

printf("price: ");
scanf("%d", &p->price);

printf("deliver(1:새벽배송/2:택배배송): ");
scanf("%d", &p->deliver);
}

void read(Product p){
printf("%7s %5s %4s %d %d\n", p.name, p.infor, p.weight, p.price, p.deliver); 
}

int update(Product *p){
printf("new name: ");
scanf("%s", p->name);

printf("new infor: ");
scanf("%s", p->infor);

printf("new weight: ");
scanf("%s", p->weight);

printf("new price: ");
scanf("%d", &p->price);

printf("new deliver(1:새벽배송/2:택배배송): ");
scanf("%d", &p->deliver);

printf("=> update success\n");
return 1;
}
