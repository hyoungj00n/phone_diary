//sortprint 기능 함수
#include <ncurses.h>
#include<stdio.h>
#include<string.h>
#include "diary.h"
#include<stdlib.h>

int sortprint(void){

	initscr();
        cbreak();
        echo();//입력한 값 화면에 보이게 한다.
        int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax);

        WINDOW *my_win1= newwin(yMax, xMax, 0, 0);

        box(my_win1,0,0);//인터페이스 박스 생성

        refresh();

	mvwprintw(my_win1,5,5, "phone diary list  (Exit : Enter) ");
        wrefresh(my_win1);//화면에 보이게 한다.


        FILE *fp;
	char* token;
	int count =0;
        fp = fopen("data.txt","r");//파일 열기
	if(fp==NULL)
		return -1;
	char *list[LEN];
	char *list2;
	int count2=0;
	//파일에 있는 내용 리스트에 저장
												while(!feof(fp)){
			//공간 할당
			list2 = (char*)malloc(sizeof(char) *LEN);
			fgets(list2,LEN,fp);
			list[count2]=list2;
			count2++;

		}
		//문자열 정렬
		mysort(list,0,count2-1);
		for(int j=0;j<count2-1;j++){
			token=strtok(list[j],":");// : 찾으면 \0으로 바꿔준다.
			int i=0;
                        while(token!=NULL){
			//전화번호부 구조체에 저장
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
		//전화번호부 출력
		 for(int i=0; i<count;i++){
			mvwprintw(my_win1,i+7,10,"%d.",i+1);
        		mvwprintw(my_win1,i+7,15,pd[i].name);
        		mvwprintw(my_win1,i+7,35,pd[i].phone);
        		mvwprintw(my_win1,i+7,55,pd[i].memo);
 }
	refresh();
        wrefresh(my_win1);
        fclose(fp);//파일 닫기
        getch();//사용자가 한번 볼 수 있게한다.
        endwin();//인터페이스 종료
        return 0;


}