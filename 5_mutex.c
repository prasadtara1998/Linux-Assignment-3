#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

pthread_mutex_t my_mutex;

void *thread_fun1(void *arg)
{
	pthread_mutex_lock(&my_mutex);
	printf("Inside function1\n");
	sleep(3);
	pthread_mutex_unlock(&my_mutex);
}

void *thread_fun2(void *arg)
{
	pthread_mutex_lock(&my_mutex);
	printf("Inside function2\n");
	sleep(3);
	pthread_mutex_unlock(&my_mutex);
}

int main()
{
	pthread_t thread1, thread2;
	pthread_mutex_init(&my_mutex,NULL);
	pthread_create(&thread1,NULL,thread_fun1,NULL);
	pthread_create(&thread2,NULL,thread_fun2,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	printf("End of main Program\n");
	return 0;
}
