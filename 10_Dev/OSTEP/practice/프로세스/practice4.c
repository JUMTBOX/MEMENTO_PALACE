#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


/**
 * `fork()`를 호출하고 `/bin/ls`를 실행하기 위하여 `exec()` 계열의 함수를 호출하는 프로그램을 작성하라.
 *  `exec()` 의 변형 `execl()`, `execle()`, `execlp()`, `execv()`, `execvp()`, `execve()` 모두를 사용할 수 있는지 시도해 보라.
 *  기본적으로 동일한 기능을 수행하는 시스템 콜에 여러 변형이 존재하는 이유를 생각해 보라.
 *   -> 인자를 직접 나열하려면 l, 배열로 가지고 있으면 v 
 *   -> 쉘을 직접 구현하거나, 사용자 입력을 파싱해서 명령어를 실행하는 경우 -> vp
 *   -> 
 */
int main () {
    pid_t p = fork();

    if(p == 0) {
        printf("Child >>> \n");
        char *args[] = {"ls", "-l", NULL};
        execvp("ls", args);
    } else {
        printf("Parent >>> \n");
        waitpid(p, NULL, 0);
    }

    return 0;
}

/*
| 함수       | 인자 전달 방식   | 실행 파일 탐색 | 환경변수 전달  |
| --------   | -----------     | ---------     | --------      |
| `execl`    | list, 가변 인자  | 직접 경로     | 기존 환경 사용 |
| `execle`   | list, 가변 인자  | 직접 경로     | 직접 지정      |
| `execlp`   | list, 가변 인자  | `PATH` 검색   | 기존 환경 사용 |
| `execv`    | vector, 배열     | 직접 경로     | 기존 환경 사용 |
| `execvp`   | vector, 배열     | `PATH` 검색   | 기존 환경 사용 |
| `execve`   | vector, 배열     | 직접 경로     | 직접 지정      |
*/