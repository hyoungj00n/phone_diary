#include "diary.h"
#include<ncurses.h>
#include<string.h>


int add(void){

	initscr();
        cbreak();
	echo();//화면에 입력한 값 보이게한다.
        int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax);

        WINDOW *my_win1= newwin(yMax, xMax, 0, 0);

        box(my_win1,0,0);//인터페이스 박스 생성

        refresh();

	mvwprintw(my_win1,5,17, "What to add?");
        
	mvwprintw(my_win1,2,20,"ex)name:phone number:memo");
	
	wrefresh(my_win1);//화면에 박스 보이게한다.

	FILE* fp;
	char ar[100];
	char add;
	fp=fopen("data.txt","a");//전화번호부 데이터 가져오기
	
	if(fp==NULL)
		return -1;
	
	mvwscanw(my_win1,5,30,"%s",ar);//추가할 값 데이터 입력받기

	mvwprintw(my_win1,7,5,"add?[Y/N]:");
	
	mvwscanw(my_win1,7,17,"%c",&add);
	
	if(add=='Y'||add =='y'){
		fwrite(ar,strlen(ar),1,fp);//파일에 옮겨 적기
		fputs("\n",fp);
	}
	fclose(fp);
	refresh();
	wrefresh(my_win1);
        endwin();//인터페이스 종료
        return 0;

}