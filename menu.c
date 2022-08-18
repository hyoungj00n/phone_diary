//메뉴 인터페이스 함수
#include<stdio.h>
#include "diary.h"
#include<ncurses.h>
#include<string.h>
#include<stdlib.h>

int menu(void){

	initscr();
        cbreak();
	noecho();//입력한값 안보이게 한다.
        int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax);

        WINDOW *my_win= newwin(6, yMax-12, 5, 5);

        WINDOW *my_win1= newwin(3, 30, 0, 0);


        box(my_win,0,0);//프로그램 이름 박스

        box(my_win1,0,0);//기능 넣을 박스
	refresh();
        mvwprintw(my_win1,1,3,"phone diary   (finish:F1)");
        wprintw(my_win, "function");
        wrefresh(my_win);
        wrefresh(my_win1);//화면에 나타내는 함수
	keypad(my_win, true);

        char *choices[4] ={"search","pirnt","delete","add"};//기능들
        int choice;
        int highlight = 0;

        while(1){

                for(int i = 0; i<4; i++){//커서가 있는 부분을 깜빡이는 기능 추가
                        if(i == highlight)
                                wattron(my_win,A_REVERSE);
                        mvwprintw(my_win,i+1,1,choices[i]);
                        wattroff(my_win,A_REVERSE);
                }
                choice = wgetch(my_win);

                switch(choice){
			case KEY_UP:
                                highlight--;
                                if(highlight==-1)//위로 올라가서 안보이지 않게 한다.
                                        highlight=0;
                                break;
                        case KEY_DOWN:
                                highlight++;
                                if(highlight==4)
                                        highlight=3;//아래로 내려가서 안보이지 않게한다.
                                break;
                        default:
                                break;
                        }
		if(choice==10){//Enter 입력하면 선택
                        break;
		}
		if(choice == KEY_F(1)){//F1누르면 종료
			highlight=10;
			break;
		}
	}

	endwin();//종료
	return highlight;

}