//phone_diary 헤더파일
#include<ncurses.h>

struct phone_diary{
	char name[30];
        char phone[20];
        char memo[40];
};
struct phone_diary pd[100];
int menu(void);
int search(void);
int sortprint(void);
int delete(void);
int add(void);
int filecopy(char*, char*);
void mysort(char*[], int, int);
#define LEN 100
#define LENGTH 200