//파일 내용 붙여 넣어주는 함수
#include "diary.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int filecopy(char *ifp, char *ofp){

	FILE *fexist, *fanew;
	char buffer[LENGTH];

	if((fexist =fopen(ifp,"r"))==NULL)//읽기 모드로 열기
		printf("파일 생성 안됨\n");

	if((fanew= fopen(ofp,"w"))==NULL)// 쓰기 모드로 열기
			printf("파일 생성 안됨\n");



	while(fgets(buffer,LENGTH,fexist)!=NULL)//한줄 읽기
		fputs(buffer,fanew);//붙여넣기

	//파일 닫기
	fclose(fexist);
	fclose(fanew);


}