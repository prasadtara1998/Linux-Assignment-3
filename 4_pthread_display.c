#include<stdio.h>
#include<pthread.h>
#include<unistd.h>



void *thread_fun(void *threadid)
{
	int thread = (int)(threadid);
	printf("\n Thread Id : %u\n",thread);
	int x = getppid();
	printf("\n Process PID: %d\n",x);
}

int main()
{
	pthread_t thread;
	pthread_create(&thread,NULL,thread_fun,thread);
	
	pthread_join(thread,NULL);
}
