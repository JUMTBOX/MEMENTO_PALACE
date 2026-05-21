#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/** 
 * `wait()`를 사용하여 자식 프로세스가 종료되기를 기다리는 프로그램을 작성하라.
 * `wait()`가 반환하는 것은 무엇인가?  => 종료된 자식 프로세스의 PID를 반환
 *  자식 프로세스가 `wait()`를 호출하면 어떤 결과가 발생하는가? => 자식 프로세스가 없다면 -1을 반환하며 errno는 ECHILD
*/
int main () {
   
   pid_t p = fork();
   
   if(p == 0) {
    printf("자식이어유 \n");
    wait(NULL);
    exit(10);
   } else if (p > 0) {
    pid_t w = wait(NULL);

    printf("누구냐 넌 wait의 반환 값: %d", w);
   } else {
    return -1;
   } 

   return 0;
}