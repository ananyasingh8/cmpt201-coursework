#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  char *user_input = NULL;
  size_t len = 0;

  while (1) {
    printf("Enter programs to run.\n> ");
    getline(&user_input, &len, stdin);
    user_input[strlen(user_input) - 1] = '\0';

    pid_t pid = fork();

    if (pid == 0) {
      execl(user_input, user_input, NULL);
      printf("Exec failure\n");
    } else if (pid > 0) {
      waitpid(pid, NULL, 0);
    }
  }
  free(user_input);
}
