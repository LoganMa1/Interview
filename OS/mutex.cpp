#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>


class FE
{
private:
    pthread_mutex_t mutex;
    int fd;
    int i;
public:
    FE(const  char * path = "./test.log",int i=0):i(0){fd = open(path,O_CREAT,O_RDWR);}
    ~FE(){close(fd);}
    void lock(){pthread_mutex_lock(&mutex);}
    void unlock(){pthread_mutex_unlock(&mutex);}
    int Getfd() const{return fd;}
    int Geti() const{return i;}
    void iplus(){i++;}
};


void * _write(void * input)
{
    FE* p = (FE*)input;
    p->lock();
    char buff[14] = "hello world!";
    write(p->Getfd(),buff,14);
    printf("the %d has write!",p->Geti());
    p->iplus();
    p->unlock();
}


int main()
{
    FE fe;
    pthread_t pth[10];
    for(int i=0;i<10;i++)
    {
        pthread_create(&pth[i],NULL,_write,&fe);
    }
    for(auto &i:pth) pthread_join(i,nullptr);
    return 0;
}
