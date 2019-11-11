/* program can be found at: http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/create.html */


/*   fork2.c similiar to fork1.c but demonstrates the return values of the 
     fork function: return 1 for the child and pid of child to the parent */
 



#include  <stdio.h>
#include<unistd.h>
#include  <sys/types.h>

#define   MAX_COUNT  20 

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid;

     pid = fork();  // fork creates a copy of the current process 
        
     if (pid < 0)
	printf("error unable to fork process; ending program");
    
     if (pid == 0)
          ChildProcess();
     else 
     {	
         printf("the fork command returns the PID of the child: %d\n",pid);
         ParentProcess();
      }	
}

void  ChildProcess(void)
{
     int   i,x, pid1, pid2;
     
     pid1 = getpid();    // get PID of the parent process

     for (i = 1; i <= MAX_COUNT; i++){
          printf("\tThis line is from child (pid number %d) the pid of the childs parent is %d, value = %d\n",pid1,pid2, i);
          for (x=0; x<1000000;x++);  // code to slow the process
     }		
     printf("   *** Child process is done ***\n");
}

void  ParentProcess(void)
{
     int   i,x, pid1;

     pid1= getpid();	
     
     for (i = 1; i <= MAX_COUNT; i++){
          printf("This line is from parent (Pid %d), value = %d\n",pid1, i);
          for(x=0; x<1000000;x++); // code to slow process 
    }		
     printf("*** Parent is done ***\n");
}

