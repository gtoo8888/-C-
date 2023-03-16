#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 10

// 1.进程间共享缓冲区
// 假设有两个进程需要共享一个缓冲区，一个进程负责写入数据，另一个进程负责读取数据。为了避免读写冲突，需要使用信号量进行同步和互斥。下面是一个使用sem_t实现的例子：

int buf[BUF_SIZE];
sem_t empty, full, mutex;

void* producer(void* arg) {
    int item = 0;
    while (1) {
        // 等待空闲缓冲区
        sem_wait(&empty);

        // 互斥访问缓冲区
        sem_wait(&mutex);
        buf[item] = rand() % 100;
        printf("Producer produced item %d: %d\n", item, buf[item]);
        item = (item + 1) % BUF_SIZE;
        sem_post(&mutex);

        // 通知有新数据可用
        sem_post(&full);

        sleep(rand() % 3 + 1);
    }
}

void* consumer(void* arg) {
    int item = 0;
    while (1) {
        // 等待有新数据可用
        sem_wait(&full);

        // 互斥访问缓冲区
        sem_wait(&mutex);
        printf("Consumer consumed item %d: %d\n", item, buf[item]);
        buf[item] = 0;
        item = (item + 1) % BUF_SIZE;
        sem_post(&mutex);

        // 通知有空闲缓冲区
        sem_post(&empty);

        sleep(rand() % 3 + 1);
    }
}

int main() {
    // 初始化信号量
    sem_init(&empty, 0, BUF_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    // 创建生产者和消费者线程
    pthread_t tid_producer, tid_consumer;
    pthread_create(&tid_producer, NULL, producer, NULL);
    pthread_create(&tid_consumer, NULL, consumer, NULL);

    // 等待线程结束
    pthread_join(tid_producer, NULL);
    pthread_join(tid_consumer, NULL);

    // 销毁信号量
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}
