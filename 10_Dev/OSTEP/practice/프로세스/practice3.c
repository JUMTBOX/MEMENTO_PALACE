#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * `fork()`를 사용하는 다른 프로그램을 작성하라. 
 *  자식 프로세스는 "hello"를 출력하고 부모 프로세스는 "goodbye"를 출력해야 한다. 
 *  항상 자식 프로세스가 먼저 출력하게 하라. 
 *  부모가 `wait()`를 호출하지 않고 할 수 있는가? 
 *    -> IPC를 사용하여야 한다고 함... 가령 pipe, signal, semaphore 같은 동기화 수단들...
 */

/**
 * pipe()는 부모-자식 사이에 작은 통신 통로를 만드는 방식입니다. 
 * pipefd[0]은 읽기용, pipefd[1]은 쓰기용입니다. 부모는 읽기용 fd에서 read()를 호출하고 기다립니다.
 * 이때 pipe 안에 데이터가 없으면 부모는 막힙니다.
 * 자식이 "x" 같은 1바이트를 write()하면 부모의 read()가 풀리고 그다음에 goodbye를 출력합니다.
 * pipe()는 단방향 데이터 채널을 만들고, fork 이후 부모와 자식이 해당 fd들을 상속해서 IPC에 사용할 수 있습니다.
 *  */ 
int main () {
    int pipeBuffer[2];

    if(pipe(pipeBuffer) == -1) {

    }

    pid_t p = fork();

    if(p == 0) {
        close(pipeBuffer[0]);

        printf("자식: Hello \n");

        write(pipeBuffer[1], "x", 1);
        close(pipeBuffer[1]);
    } else if(p > 0) {
        char buf;

        close(pipeBuffer[1]);

        read(pipeBuffer[0], &buf, 1);
        close(pipeBuffer[0]);

        printf("부모: goodBye \n");
    } else {
        return -1;
    }

    return 0;
}