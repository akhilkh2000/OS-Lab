#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include <unistd.h>

#define Thinking 0
#define Hungry 1
#define Eating 2
#define N 5
#define Left (p_num+4)%N
#define Right (p_num+1)%N

sem_t mutex;
sem_t S[N];

int state_t[N];
int ph_num[] = {0, 1, 2, 3, 4};

void test_t(int p_num)
{
    if (state_t[p_num] == Hungry && state_t[Left] != Eating && state_t[Right] != Eating)
    {
        state_t[p_num] = Eating;
        sleep(2);
        printf("Philosopher %d takes chopstick %d and %d\n", p_num + 1, Left + 1, p_num + 1);
        printf("Philosopher %d is Eating\n", p_num + 1);
        sem_post(&S[p_num]);
    }
}

void t_fork(int p_num)
{
    sem_wait(&mutex);
    state_t[p_num] = Hungry;
    printf("Philosopher %d is Hungry\n", p_num + 1);
    test_t(p_num);
    sem_post(&mutex);
    sem_wait(&S[p_num]);
    sleep(1);
}

void p_fork(int p_num)
{
    sem_wait(&mutex);
    state_t[p_num] = Thinking;
    printf("Philosopher %d putting chopstick %d and %d down\n", p_num + 1, Left + 1, p_num + 1);
    printf("Philosopher %d is thinking\n", p_num + 1);
    test_t(Left);
    test_t(Right);
    sem_post(&mutex);
}

void *phil(void *val)
{
    while (1)
    {
        int *j = val;
        sleep(1);
        t_fork(*j);
        sleep(0);
        p_fork(*j);
    }
}

int main()
{
    pthread_t thread_ID[N];
    sem_init(&mutex, 0, 1);
    for (int i = 0; i < N; i++)
        sem_init(&S[i], 0, 0);
    for (int i = 0; i < N; i++)
    {
        pthread_create(&thread_ID[i], NULL, phil, &ph_num[i]);
        printf("Philosopher %d is thinking\n", i + 1);
    }
    for (int i = 0; i < N; i++)
        pthread_join(thread_ID[i], NULL);
}

