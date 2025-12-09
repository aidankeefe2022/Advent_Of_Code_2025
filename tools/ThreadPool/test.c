//
// Created by aidankeefe on 12/7/25.
//
#include "ThreadPool.c"
#include <unistd.h>
#include <assert.h>

void TestThreadPoolCreate() {
    ThreadPool *pool = &(ThreadPool) {};
    assert(createThreadPool(pool, 4));
    assert(pool);
    assert(destroyThreadPool(pool));
}

typedef struct arg{
    int a;
    int b;
}arg;

void add(void* a) {
    const arg* y = a;
    sleep(2);
    printf("add %d to %d get %d\n", y->a, y->b, y->a + y->b);
}


void TestThreadPoolTask() {
    ThreadPool *pool = &(ThreadPool) {};
    assert(createThreadPool(pool, 3));
    assert(pool);
    arg* a = &(arg){
        1,
        2,
    };
    Task task = {
        .func = add,
        .arg = a,
    };
    addTask(pool,task);
    addTask(pool,task);
    waitThreadPool(pool);
    destroyThreadPool(pool);
}


int main(void) {
    TestThreadPoolTask();
}