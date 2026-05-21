#include <stdio.h>
#include <fcntl.h>

/**
 * `open()` 시스템 콜을 사용하여 파일을 여는 프로그램을 작성하고
 *  새 프로세스를 생성하기 위하여 `fork()`를 호출하라. 
 *  자식과 부모가 `open()`에 의해 반환된 파일 디스크립터에 접근할 수 있는가? 
 *  부모와 자식 프로세스가 동시에 파일에 쓰기 작업을 할 수 있는가?
 */
int main () {
    int file_descriptor = open("test.txt", 2);

    return 0;
}