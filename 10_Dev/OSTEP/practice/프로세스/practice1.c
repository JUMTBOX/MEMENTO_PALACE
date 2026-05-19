#include <stdio.h>

int main () {
  int x = 1;
  int pid = fork();

  if(pid < 0) {
    // fork 실패
    return -1;
  } else if (pid == 0) {
    printf("자식 프로세스 실행 중... x의 값은 %d", x);
  } else {
    wait();
    printf("부모 프로세스 실행 중 자식 프로세스 PID: %d, x의 값은 %d", pid, x);
  }

  return 0;
}