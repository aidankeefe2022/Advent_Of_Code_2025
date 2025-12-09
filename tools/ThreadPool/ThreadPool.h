//
// Created by aidankeefe on 12/5/25.
//

#ifndef ACO_THREADPOOL_H
#define ACO_THREADPOOL_H
#include <pthread.h>


#define MAX_THREAD_COUNT 128
#define MAX_QUEUE_SIZE  128

typedef struct Task {
    void (*func)(void *);
    void *arg;
}Task;

typedef struct ThreadPool {
    unsigned int numThreads;
    pthread_t threads[MAX_THREAD_COUNT];
    unsigned int numTasks;
    Task queue[MAX_QUEUE_SIZE];
    unsigned int activeWorkers;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    pthread_cond_t cond_empty;
    bool shutdown;
}ThreadPool ;

bool createThreadPool(ThreadPool* pool,unsigned int num_threads);
bool addTask(ThreadPool* pool, Task task);
bool waitThreadPool(ThreadPool *pool);
bool destroyThreadPool(ThreadPool *pool);




#endif //ACO_THREADPOOL_H