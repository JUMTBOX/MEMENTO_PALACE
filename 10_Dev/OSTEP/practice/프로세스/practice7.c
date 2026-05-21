#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 *  자식 프로세스를 생성하고 자식 프로세스가 표준 출력(STDOUT_FILENO)을 닫는 프로그램을 작성하라.
 *  자식이 설명자를 닫은 후에 아무거나 출력하기 위하여 `printf()`를 호출하면 무슨 일이 생기는가?
 */
int main () {
    pid_t p = fork();
    
    if(p == 0) {
        // todo 표준 출력 닫기

        printf("무슨 일이 일어나나요? \n");
    } else {
        printf("으음... 부모");
    }
 
    return 0;
}