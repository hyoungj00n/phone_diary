//delete 기능 함수
#include <ncurses.h>
#include<stdio.h>
#include<string.h>
#include "diary.h"
#include<stdlib.h>

int delete(void){
	
	initscr();
        cbreak();
        echo();//화면에 입력한 값 보이게한다.
        int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax);

        WINDOW *my_win1= newwin(yMax, xMax, 0, 0);

        box(my_win1,0,0);//인터페이스 박스 생성

        refresh();

        mvwprintw(my_win1,5,8, "What to delete? ");
        wrefresh(my_win1);//화면에 보이게 한다.

	FILE* fp;
	FILE* fp2;
	int del;
	int count1=1,flag=0;
	char arr[100],arr1[100],arr2[100];
	
	fp=fopen("data.txt","r");//전화번호부 데이터
        fp2=fopen("copy.txt","w");

	mvwscanw(my_win1,5,25,"%s",arr1);//삭제할 내용 입력받기

	while(1){
		fgets(arr,sizeof(arr),fp);
	
		if(feof(fp)==1)
			break;
		if(strstr(arr,arr1)!=NULL){//데이터 있는지 확인
			mvwprintw(my_win1,8+count1,10,"%d %s",count1,arr);
			count1++;
			flag=1;
		}
	}
	fclose(fp);
	fp=fopen("data.txt","r");
	
	if(count1!=1){//삭제할지 확인
		mvwprintw(my_win1,15,10,"which one?");
		mvwscanw(my_win1,15,23,"%d",&del);
	}
	count1=1;
	while(1){//데이터 삭제한것처럼 카피본에 적기
		fgets(arr2,sizeof(arr2),fp);
	if(feof(fp)==1)
		break;
	if(strstr(arr2,arr1)!=NULL){//데이터 있는 부분 찾기

		if(del!=count1){
			fwrite(arr2,strlen(arr2),1,fp2);//옮겨적기
		}
		count1++;
	}else{
		fwrite(arr2,strlen(arr2),1,fp2);//옮겨적기
	}
	}
	char c;
	if(flag==0){//delete기능 종료
		mvwprintw(my_win1,10,5,"NO data (Exit : Enter)");
		mvwscanw(my_win1, 12,5,"%c",&c);

	}
	refresh();
        wrefresh(my_win1);
        fclose(fp);
	fclose(fp2);//파일 닫기
	filecopy("copy.txt","data.txt");//copy본에 삭제된 데이터 덮어쓰기
        endwin();//인터페이스 종료
        return 0;

}