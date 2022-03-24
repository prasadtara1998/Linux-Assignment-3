#include<stdio.h>
#include<pthread.h>
#include<unistd.h>



void *thread_fun(void *threadid)
{
	printf("\nLinux Assignment\n");
	while(1);
}

int main()
{
	pthread_t thread;
	int t=0;
	printf("Creating thread......\n");
	pthread_create(&thread,NULL,thread_fun,NULL);

	sleep(3);
	t = pthread_cancel(thread);
	if(t==0)
		printf("\ncancel thread.....\n");

	printf("Thread Id %u cancelled successfully\n",thread);
}
