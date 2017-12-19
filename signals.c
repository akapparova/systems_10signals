#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>


static void signalhandler(int signo){
  if(SIGINT==signo) {
    int fd = open("file.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    char oput[] = "Exited - SIGINT \n";
    write(fd, oput, sizeof(oput));
    close(fd);
    exit(1);
  }


  
  if(SIGUSR1==signo){
    printf("Parent PID is %d\n",getppid());
  }
}


int main(){
  signal(SIGINT,signalhandler);
  signal(SIGUSR1,signalhandler);

  while(1){
    printf("PID is %d\n", getpid());
    sleep(1);
  }



  return 87;
}
