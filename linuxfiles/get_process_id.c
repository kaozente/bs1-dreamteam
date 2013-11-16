#include <stdio.h>
#include <syscall.h>
#include <unistd.h>
#include <sys/types.h>


int main ()
{
	int sys_pid = syscall(__NR_getpid);
	int api_pid = getpid();
	printf (" syscall: %d,\t\tusermode-API: %d \n\n", sys_pid, api_pid );
	return 0;
}


