#ifndef PRODUCT_H
#define PRODUCT_H
// git
#include <stdio.h>
#include <string.h>

typedef struct {
	char name[20];
	char infor[20];
	char weight[20];
	int price;
	int deliver;
} Product;

int create(Product *plist); // 제품 정보를 생성
void read(Product plist); // 하나의 제품 출력 함수
int update(Product *plist); // 상품 정보 업데이트(수정)
void search(Product *plist, int count); // 제품 이름 검색

#endif
