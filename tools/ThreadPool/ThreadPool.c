//
// Created by aidankeefe on 12/5/25.
//

#include "ThreadPool.h"

#include <stdio.h>

Task popTask(ThreadPool* pool) {
    Task t = pool->queue[0];
    for (int i = 0; i < pool->numTasks; i++) {
        pool->queue[i] = pool->queue[i + 1];
    }
    pool->numTasks--;
    return t;
}


bool addTask(ThreadPool* pool, Task task) {
    pthread_mutex_lock(&(pool->mutex));
    if (pool->numTasks >= MAX_QUEUE_SIZE) {
        pthread_mutex_unlock(&(pool->mutex));
        return false;
    }
    pool->queue[pool->numTasks] = task;
    pool->numTasks++;
    pthread_mutex_unlock(&(pool->mutex));
    pthread_cond_signal(&(pool->cond));
    return true;
}


void startThread(ThreadPool *pool) {
    while (true) {
        Task t = (Task){};
        pthread_mutex_lock(&(pool->mutex));


        while (!pool->shutdown && pool->numTasks == 0) {
            pthread_cond_wait(&(pool->cond), &(pool->mutex));
        }

        if (pool->shutdown) {
            pthread_mutex_unlock(&(pool->mutex));
            return;
        }

        t = popTask(pool);
        pool->activeWorkers++;
        pthread_mutex_unlock(&(pool->mutex));



        if (t.func ) {
            t.func(t.arg);
        }

        pthread_mutex_lock(&(pool->mutex));
        pool->activeWorkers--;
        if (pool->numTasks == 0 && pool->activeWorkers == 0) {
            pthread_cond_broadcast(&(pool->cond_empty));
        }
        pthread_mutex_unlock(&(pool->mutex));

    }
}

bool createThreadPool(ThreadPool *pool, unsigned int num_threads) {
    if (num_threads >= MAX_THREAD_COUNT)
        return false;
    *pool = (ThreadPool) {
    .numThreads = num_threads,
    .numTasks = 0,
        .activeWorkers = 0,
    .shutdown = false};
    pthread_mutex_init(&(pool->mutex), nullptr);
    pthread_cond_init(&(pool->cond), nullptr);
    pthread_cond_init(&(pool->cond_empty), nullptr);
    for (int i = 0; i < pool->numThreads; i++) {
        pthread_create(&pool->threads[i], nullptr, (void*)startThread, pool);
    }

    return true;
}

bool waitThreadPool(ThreadPool *pool) {
    pthread_mutex_lock(&(pool->mutex));
    while (pool->numTasks > 0) {
        pthread_cond_wait(&(pool->cond_empty), &(pool->mutex));
    }
    pthread_mutex_unlock(&(pool->mutex));
    return true;
}



bool destroyThreadPool(ThreadPool *pool) {
    // 1. Tell threads to stop
    pthread_mutex_lock(&(pool->mutex));
    pool->shutdown = true;
    pthread_cond_broadcast(&(pool->cond));
    pthread_mutex_unlock(&pool->mutex);
    // 2. Join all threads so we *know* they are gone
    for (int i = 0; i < pool->numThreads; i++) {
        pthread_join(pool->threads[i], nullptr);
    }
    // 3. Now it is safe to destroy sync primitives
    pthread_mutex_destroy(&pool->mutex);
    pthread_cond_destroy(&pool->cond);
    pthread_cond_destroy(&pool->cond_empty);
    // 4. Free other resources (threads array, job queue, etc.)
    return true;
}
