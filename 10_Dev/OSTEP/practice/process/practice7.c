#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/**
 *  자식 프로세스를 생성하고 자식 프로세스가 표준 출력(STDOUT_FILENO)을 닫는 프로그램을 작성하라.
 *  자식이 설명자를 닫은 후에 아무거나 출력하기 위하여 `printf()`를 호출하면 무슨 일이 생기는가?
 *   -> Bad file descriptor 에러 발생..., 부모 프로세스는 정상 출력
 */
int main () {
    pid_t p = fork();
    
    if(p == 0) {
        // todo 표준 출력 닫기
        close(STDOUT_FILENO);
        printf("무슨 일이 일어나나요? \n");
        perror("에러데스");
    } else {
        printf("으음... 부모");
    }
 
    return 0;
}

/*
파일 디스크립터 테이블

fd 번호     연결된 대상
--------------------------------
0           표준 입력  stdin   보통 키보드/터미널 입력
1           표준 출력  stdout  보통 터미널 화면
2           표준 에러  stderr  보통 터미널 화면
3           open()으로 연 파일
4           pipe/socket 등
...
*/