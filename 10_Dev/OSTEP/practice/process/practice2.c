#include <stdio.h>
#include <fcntl.h> // 파일 컨트롤 헤더 파일
#include <sys/stat.h> // mode_t, 권한 상수
#include <unistd.h> // UNIX standard... unix계열에서 시스템 프로그래밍시 필수

/**
 * `open()` 시스템 콜을 사용하여 파일을 여는 프로그램을 작성하고
 *  새 프로세스를 생성하기 위하여 `fork()`를 호출하라. 
 *  자식과 부모가 `open()`에 의해 반환된 파일 디스크립터에 접근할 수 있는가? -> ㅇㅇ 둘 다 접근 가능
 *  부모와 자식 프로세스가 동시에 파일에 쓰기 작업을 할 수 있는가? -> ㅇㅇ 둘다 쓰기 됨
 *   
 *  open이후 fork를 호출하면, 자식 프로세스도 부모가 열어 둔 파일 디스크립터의 복사본을 상속 받는다.
 *  부모와 자식의 fd 값은 같을 수 있으며, 둘 다 같은 open file description을 가리킨다.
 *  따라서 둘다 해당 파일에 write 할 수 있다. 또한 file offset도 공유된다.
 */
int main () {
    int file_descriptor = open("./practice_build/test.txt", O_WRONLY | O_CREAT, 0644);
    pid_t p = fork();

    if(p == 0) {
        printf("C PROCESS \n");
        printf("자식은 파일 디스크립터에 접근 ㄱㄴ? %d \n", file_descriptor);
        
        char buf[1] = {"C"};
        write(file_descriptor, buf, sizeof(buf));
    } else if (p > 0) {
        printf("P PROCESS \n");
        printf("부모는 접근 ㄱㄴ? %d \n", file_descriptor);
        
        char buf[1] = {"P"};
        write(file_descriptor, buf, sizeof(buf));
    } else {
        return -1;
    }

    close(file_descriptor);
    return 0;
}