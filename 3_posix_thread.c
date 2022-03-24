#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/mman.h>

void* Proc(void* param)
{
	sleep(2);
	return 0;
}

int main()
{
	pthread_attr_t Attr;
	pthread_t Id;
	void  *Stk;
	size_t Siz;
	int err;

	size_t my_stksize = 300000;
	void * my_stack;

	pthread_attr_init(&Attr);
	pthread_attr_getstacksize(&Attr, &Siz);
	pthread_attr_getstackaddr(&Attr, &Stk);

	printf("Default: Addr=%08x default size=%d\n",Stk,Siz);
	my_stack = (void*)malloc(my_stksize);

	pthread_attr_setstack(&Attr,my_stack,my_stksize);
	pthread_create(&Id,&Attr,Proc,NULL);
	pthread_attr_getstack(&Attr,&Stk,&Siz);

	printf("newly defined stack : Addr=%08x and Size=%d\n",Stk,Siz);

	sleep(3);
	pthread_attr_destroy(&Attr);
	return(0);
}


