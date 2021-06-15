#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/wait.h>


//example for pipe between father process and child process
void pipe_test()
{
    int fd[2];
    int ret = pipe(fd);//read from fd[0]. write into fd[1]

    if(ret==-1) 
    {
        perror("error when pipe!");
        exit(1);
    }

    pid_t pid = fork();
    if(pid==0)
    {
        close(fd[0]);
        char * child = "I am child!";
        int i=0;
        while(i<5)
        {
            write(fd[1],child,strlen(child)+1);
            sleep(2);
            i++;
        }
    }
    else if(pid>0)
    {
        close(fd[1]);
        char buffer[100];
        int i=0;

        while(i<5)
        {
            memset(buffer,'\0',strlen(buffer));
            ssize_t s = read(fd[0],buffer,sizeof(buffer));
            if(s>0)
            {
                buffer[s-1] = '\0';
            }
            printf("%s\n",buffer);
            i++;
        }
    }else
    {
        perror("error when fork!");
        exit(1);
    }
}


//how big the pipe
void writeonlypipe()
{
    int fd[2];
    int ret = pipe(fd);//read from fd[0]. write into fd[1]

    if(ret==-1) 
    {
        perror("error when pipe!");
        exit(1);
    }

    pid_t pid = fork();
    if(pid==0)
    {
        close(fd[0]);
        char * child = "I am child!";
        int i=0;
        while(++i)
        {
            write(fd[1],child,strlen(child)+1);
            printf("pipe capacity: %d\n",i*(strlen(child)+1));
        }
    }
    else if(pid>0)
    {
        close(fd[1]);
        waitpid(pid,NULL,0);
    }else
    {
        perror("error when fork!");
        exit(1);
    }
}


int main()
{
    pipe_test();
    //writeonlypipe();

    return 0;
}
