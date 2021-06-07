#include<sys/sem.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<semaphore.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<assert.h>

#define BSIZE 20

typedef struct 
{
    char buf[BSIZE];
    int occupied;
    int nextin;
    int nextout;
    pthread_mutex_t mutex;
    pthread_cond_t less;
    pthread_cond_t more;
}buffer_t ;
buffer_t buff;

struct args
{
    buffer_t * b;
    char item;
};

void * producer(void * input)
{
    pthread_mutex_lock(&(((args *)input)->b)->mutex);
    while(((args *)input)->b->occupied>=BSIZE)
        pthread_cond_wait(&(((args *)input)->b)->less,&(((args *)input)->b)->mutex);
    
    assert(((args *)input)->b->occupied<BSIZE);

    ((args *)input)->b->buf[((args *)input)->b->nextin++] = ((args *)input)->item;
    ((args *)input)->b->nextin %= BUFSIZ;
    ((args *)input)->b->occupied ++;
    printf("Now in producer!");

    pthread_cond_signal(&(((args *)input)->b)->more);
    pthread_mutex_unlock(&(((args *)input)->b)->mutex);
}


void * consumer(void * input)
{
    buffer_t * b = (buffer_t *) input;
    char item;
    pthread_mutex_lock(&b->mutex);
    while(b->occupied<=0)
        pthread_cond_wait(&b->more,&b->mutex);
    
    assert(b->occupied>0);

    item = b->buf[b->nextout++];
    b->nextout %= BUFSIZ;
    b->occupied--;
    printf("Now in consumer!");

    pthread_cond_signal(&b->less);
    pthread_mutex_unlock(&b->mutex);
}


int main(int argc, char * argvs[])
{
    pthread_t cthread1,cthread2;
    args paras;
    paras.item = 'a';
    paras.b = &buff;
    pthread_create(&cthread1,NULL,producer,&paras);
    pthread_create(&cthread2,NULL,consumer,&buff);

    return 0;
}

