#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 2. 控制进程顺序执行
// 假设有三个进程A、B、C，需要按照A->B->C的顺序执行，可以使用信号量控制进程的执行顺序。下面是一个使用sem_t实现的例子：


// 在这个例子中，三个线程都需要等待前一个线程执行完毕才能继续执行。`sem_A`的初始值为0，保证了线程A会先执行。当线程A执行完毕后，通过`sem_post(&sem_A)`通知线程B可以开始执行。线程B执行完毕后，通过`sem_post(&sem_B)`通知线程C可以开始执行。线程C等待`sem_B`信号量，保证了线程B已经执行完毕。

sem_t sem_A, sem_B, sem_C;

void* thread_A(void* arg) {
    printf("Thread A is running\n");
    sleep(rand() % 3 + 1);
    sem_post(&sem_A);
    return NULL;
}

void* thread_B(void* arg) {
    sem_wait(&sem_A);
    printf("Thread B is running\n");
    sleep(rand() % 3 + 1);
    sem_post(&sem_B);
    return NULL;
}

void* thread_C(void* arg) {
    sem_wait(&sem_B);
    printf("Thread C is running\n");
    sleep(rand() % 3 + 1);
    return NULL;
}

int main() {
    // 初始化信号量
    sem_init(&sem_A, 0, 0);
    sem_init(&sem_B, 0, 0);
    sem_init(&sem_C, 0, 0);
    // 创建三个线程
    pthread_t tid_A, tid_B, tid_C;
    pthread_create(&tid_A, NULL, thread_A, NULL);
    pthread_create(&tid_B, NULL, thread_B, NULL);
    pthread_create(&tid_C, NULL, thread_C, NULL);

    // 等待线程结束
    pthread_join(tid_A, NULL);
    pthread_join(tid_B, NULL);
    pthread_join(tid_C, NULL);

    // 销毁信号量
    sem_destroy(&sem_A);
    sem_destroy(&sem_B);
    sem_destroy(&sem_C);

    return 0;
}
