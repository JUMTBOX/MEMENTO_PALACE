#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

/**
 * 두 개의 자식 프로세스를 생성하고 `pipe()`시스템 콜을 사용하여 
 * 한 자식의 표준 출력을 다른 자식의 입력으로 연결하는 프로그램을 작성하라.
 */
int main () {
    /**
     * pipefd[0] = read end
     * pipefd[1] = write end
     */
    int fdArr[2];
    int file_descriptor = pipe(fdArr);
    
    pid_t p = fork();

    if(p == 0) {
        // read end 닫기
        close(fdArr[0]);
        const char *message = "HI";
        if(write(fdArr[1], message, strlen(message)) == -1 ) {
            perror("ERROR::: ");
        }
    } else if (p > 0) {
        // write end 닫기
        close(fdArr[1]);
        char rbuf[2];
        ssize_t r = read(fdArr[0], rbuf, sizeof(rbuf));
        printf("자식으로 부터 받은 메시지... \n %s", r);
    } else {
        return -1;
    }

    perror("뭐가 문제냐 ㅡㅡ");
    return 0;
}