#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <unistd.h>

/**
 * 5번째 문제에서 작성한 프로그램을 수정하여 `wait()` 대신 `waitpid()`를 사용하라.
 *  어떤 경우에 `waitpid()`를 사용하는 것이 좋은가?
 *  -> 특정 자식 프로세스만 골라서 기다려야 할 때
 *  -> WNOHANG 옵션을 주면 non-blocking 
 */
int main () {
    pid_t pid = fork();
    int wstatus;
    
    if(pid < 0) {
        /* fork 실패 */
        return -1;
    } else if (pid == 0) {
        /* 자식 process */
        printf("자식 프로세스여 \n");
        sleep(10);
        // exit(42); -> 정상 종료
        printf("??????? 10초 sleep 안함?");
        // kill(getpid(), SIGKILL);
    } else {
        printf("부모 프로세스여 \n");
        /* 부모 process */    
        waitpid(pid, &wstatus, WNOHANG);
        
        printf("블로킹 되는지 검증 \n");
        
        if(WIFEXITED(wstatus)) {
            printf("자식 프로세스 정상 종료. 반환 값: %d \n", WEXITSTATUS(wstatus));        
        } else if (WIFSIGNALED(wstatus)) {
            printf("시그널을 받아 자식 프로세스 종료. 시그널 번호: %d \n", WTERMSIG(wstatus));        
        }
    }

    return 0;
}