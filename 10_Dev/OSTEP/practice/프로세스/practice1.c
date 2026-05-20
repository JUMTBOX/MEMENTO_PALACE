#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main () {
  int x = 1;
  
  printf("fork() 호출 전 메인 프로세스에서의 x값: %d \n", x);

  pid_t pid = fork();
  
  if(pid < 0) {
    // fork 실패
    return -1;
  } else if (pid == 0) {
    printf("자식 프로세스 실행 중... x의 값은 %d \n", x);
    x = 2;
  } else {
    wait(NULL);
    printf("부모 프로세스 실행 중 자식 프로세스 PID: %d, x의 값은 %d \n", pid, x);
  }

  return 0;
}