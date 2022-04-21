#include "manager.h"
// 함수 정의, 메인 구현
// git
int create(Product *plist){
printf("name: ");
scanf("%s", plist->name);

printf("infor: ");
scanf("%s", plist->infor);

printf("weight: ");
scanf("%s", plist->weight);

printf("price: ");
scanf("%d", &plist->price);

printf("deliver(1:새벽배송/2:택배배송): ");
scanf("%d", &plist->deliver);
printf("\n");
return 1;
}

void read(Product plist){
printf("%7s %5s %4s %d %d\n",
	  	plist.name, plist.infor, plist.weight, plist.price, plist.deliver); 
}

int update(Product *plist){
printf("new name: ");
scanf("%s", plist->name);

printf("new infor: ");
scanf("%s", plist->infor);

printf("new weight: ");
scanf("%s", plist->weight);

printf("new price: ");
scanf("%d", &plist->price);

printf("new deliver(1:새벽배송/2:택배배송): ");
scanf("%d", &plist->deliver);

printf("=> update success");
printf("\n");
return 1;
}

void listProduct(Product *plist, int count){
	printf("================\n");
	for (int i=0; i<count; i++){
		if (plist[i].price == -1) continue;
		printf("%2d ", i+1);
		read(plist[i]);
	}
	printf("\n");
}	
int selectDataNo(Product *plist, int count){
	int no;
	listProduct(plist, count);
	printf("번호는? (취소 : 0) ");
	scanf("%d", &no);
	return no;
}

void saveData(Product *plist, int count){
	FILE *fp = fopen("product.txt", "wt");

	for (int i=0; i<count; i++){
		if(plist[i].price  == -1) continue;
		fprintf(fp, "%s %s %s %d %d \n", plist[i].name, plist[i].infor,
		plist[i].weight, plist[i].price, plist[i].deliver);
	}
	fclose(fp);
	printf("=> 저장됨! \n");
}

int loadData(Product *plist){
	int i = 0;
	FILE *fp;
	fp = fopen("product.txt", "rt");

	for (; i<100; i++){
		fscanf(fp, "%s", plist[i].name);
		if (feof(fp)) break;
		fscanf(fp, "%s", plist[i].infor);
		fscanf(fp, "%s", plist[i].weight);
		fscanf(fp, "%d", plist[i].price);
		fscanf(fp, "%d", plist[i].deliver);;
	}
	fclose(fp);
	printf("=> loading success!\n");
	return i;
}

void search(Product *plist, int count){
	int scnt = 0;
	char search[20];

	printf("search name? ");
	scanf("%s", search);

	for (int i=0; i<count; i++){
		if (plist[i].price == -1) continue;
		if (strstr(plist[i].name, search)){
			printf("%2d", i+1);
			read(plist[i]);
			scnt++;
		}
	}
	if (scnt == 0) printf("no data!\n");
}
