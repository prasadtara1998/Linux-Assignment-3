#include<stdio.h>
#include<stdlib.h>

int globalVar1 = 10;
int globalVar2 = 5;

void *thread_add(void *arg)
{
	printf("addition =%d\n",globalVar1+globalVar2);
}

void *thread_sub(void *arg)
{
	printf("subtraction =%d\n",globalVar1-globalVar2);
}

int main()
{
	pthread_t thread1,thread2;

	
		pthread_create(&thread1,NULL,thread_add,NULL);
		pthread_create(&thread2,NULL,thread_sub,NULL);
	
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);

	printf("Var1 = %d\n",globalVar1);
	printf("Var2 = %d\n",globalVar2);
	return 0;
}
