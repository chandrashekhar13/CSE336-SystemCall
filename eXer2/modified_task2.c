#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>
///This function executes the count.c file which modifies the value of num.txt
void getCount(int pid)
{
        execl("./count.out","./count.out", NULL);    
        //prints to user that execl failed
        printf("Process[%d]: Failed to execute execl()\n",pid);
}
int main ()
{
	pid_t pid_0, pid_1, pid_2, pid_3;
	pid_0=10; pid_1=10; pid_2=10; pid_3=10;
	int status;

	//The parent process creates a child process
	pid_1 = fork();
	//The parent process tests whether fork() failed or not, if it did, the process exits.
	if (pid_1 < 0)  goto X;
    if(pid_1==0){
        getCount(getpid());
    }
    else if(pid_1!=0&&pid_2!=0&&pid_3!=0){
        pid_0 = wait(&status);
		printf("Parent[%d]: child %d has terminated (status=%d)\n",getpid(),pid_0,WIFEXITED(status));
    }
    //The parent process creates a child process
    if(pid_1 != 0) pid_2 = fork();
    //The parent process tests whether fork() failed or not, if it did, the process exits.
    if (pid_2 < 0)  goto X;
    if(pid_1!=0&&pid_2==0){
        getCount(getpid());
    }
    else if(pid_1!=0&&pid_2!=0&&pid_3!=0){
        pid_0 = wait(&status);
		printf("Parent[%d]: child %d has terminated (status=%d)\n",getpid(),pid_0,WIFEXITED(status));
    }
    if((pid_1 != 0) && (pid_2 != 0)) pid_3 = fork();
    
    if (pid_3 < 0)  goto X;
    if(pid_3==0&&pid_1!=0&&pid_2!=0){
        getCount(getpid());
    }
    else if(pid_1!=0&&pid_2!=0&&pid_3!=0){
        pid_0 = wait(&status);
		printf("Parent[%d]: child %d has terminated (status=%d)\n",getpid(),pid_0,WIFEXITED(status));
    }

	

X: return 0;

}
