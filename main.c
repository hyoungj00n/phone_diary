//phone diary 프로그램
#include <ncurses.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "diary.h"


struct phone_diary pd[100];

int main(void){

	
	while(1){

		int choice = menu();//메뉴 선택

		if(choice ==0){//찾기
			erase();//지우기
			search();//번호 찾는 함수
			erase();
			continue;
		}
		else if(choice ==1){//출력
			erase();
			sortprint();//정렬 후 출력 함수
			erase();
			continue;
		}
		else if(choice==2){//삭제
			erase();
			delete();
			erase();//번호 지우는 함수
			continue;
		}
		else if(choice==3){//더하기
			erase();
			add();//번호 추가 함수
			erase();
			continue;
		}
		else if(choice ==10)//끝내기
			break;
	}
	

	return 0;
}