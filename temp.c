#include <signal.h>
#include <stdio.h>



void sig_quit(int signo)
{
	printf("caught SIGQUIT\n");
	if(signal(SIGQUIT,SIG_DFL) == SIG_ERR)
		return;

}

int main(void)
{
	sigset_t newmask,oldmask,pendmask;

	if(signal(SIGQUIT,sig_quit) == SIG_ERR)
	{

	}

	sigemptyset(&newmask);
	sigaddset(&newmask,SIGQUIT);
	if(sigprocmask(SIG_BLOCK,&newmask,&oldmask) < 0)
	{

	}

	sleep(5);

	if(sigpending(&pendmask) >= 0)
	{
		if(sigismember(&pendmask,SIGQUIT))
		{
			printf("\nSIGQUIT pending\n");
		}
	}


	if(sigprocmask(SIG_SETMASK,&oldmask,NULL) >=0)
	{
		printf("SIGQUIT unblocked\n");
	}

	sleep(5);

	return;
}

