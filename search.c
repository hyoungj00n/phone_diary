//search기능 함수
#include<stdio.h>
#include "diary.h"
#include<ncurses.h>
#include<string.h>
#include<stdlib.h>
int search(void){
	
	initscr();
        cbreak();
	echo();//입력한 값 화면에 보이게 한다.
	int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax);//화면 최대길이 얻기

        WINDOW *my_win= newwin(yMax, xMax, 0, 0);

        box(my_win,0,0);//인터페이스 박스 그리기
	
	refresh();
	mvwprintw(my_win,5,5, "Enter what you are looking for: ");
        wrefresh(my_win);
	
	
	FILE *fp;
	char arr[100],arr1[100];
	char* token;
	int count=0;
	
	mvwscanw(my_win,5,37,"%s",arr1);//찾을 값 입력받기
	if(fp ==NULL)
		return -1;
	fp = fopen("data.txt","r");//파일 열기

	while(1){
		fgets(arr,sizeof(arr),fp);//한줄 읽기
		int i=0;
		if(feof(fp)==1)
			break;
		if(strstr(arr,arr1)!=NULL){
			token=strtok(arr,":");//':' 기준으로 자르기

			while(token!=NULL){
				//찾는 내용 있으면 구조체에 저장
				if(i==0){
                                strcpy(pd[count].name,token);
                        }
                        else if(i==1){
                                strcpy(pd[count].phone,token);
                        }
                        else if(i==2){
                                strcpy(pd[count].memo,token);
                        }
                        i++;
                        token = strtok(NULL,":");// : 구분자 뒤에서 다시 시작
                }
			count++;
		}

       
	}
	for(int i=0; i<count;i++){
	mvwprintw(my_win,i+7,15,pd[i].name);
	mvwprintw(my_win,i+7,35,pd[i].phone);
	mvwprintw(my_win,i+7,55,pd[i].memo);
 }
	if(count ==0)//찾은 경우
		mvwprintw(my_win,20,10,"No match found  (Exit:Enter)\n");
	else//못 찾은 경우
		mvwprintw(my_win,20,10,"match found  (Exit:Enter)\n");
	refresh();
	wrefresh(my_win);
	fclose(fp);//파일 닫기
	getch();
	endwin();//인터페이스 종료
	return 0;
	
}