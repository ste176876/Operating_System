/**************************************************************************************************************************
			DO NOT CHANGE THE CONTENTS OF THIS FILE FOR YOUR COURSEWORK. ONLY WORK WITH THE OFFICIAL VERSION
**************************************************************************************************************************/

#include <sys/time.h>

// Duration of the time slice for the round robin algorithm
#define TIME_SLICE 5

// Number of processes to create
#define NUMBER_OF_JOBS 10

// maximum duration of the individual processes, in milli seconds. Note that the times themselves will be chosen at random in ]0,100]
#define MAX_BURST_TIME 50 

#define MAX_PRIORITY 32

#define MAX_BUFFER_SIZE 50

#define MAX_NUMBER_OF_JOBS 100

#define NUMBER_OF_PRODUCERS 1

#define NUMBER_OF_CONSUMERS 4

/* 
 * Definition of the structure containing the process characteristics. These should be sufficient for the full implementation of all tasks.
 */

struct process
{
	int iProcessId;
	struct timeval oTimeCreated;  // the moment that the process is created
	struct timeval oMostRecentTime; // most recent time the job finished running
	int iInitialBurstTime;  // 一开始
	int iPreviousBurstTime; // 前一段运行的（RR）
	int iRemainingBurstTime;    // 剩余的
	int iPriority;
};

// defined in Linux operating system
//struct timeval
//{
//__time_t tv_sec;        /* Seconds. from 1970.1.1 0:00 to present*/
//__suseconds_t tv_usec;  /* Microseconds. */
//};

// API
struct process * generateProcess();
long int getDifferenceInMilliSeconds(struct timeval start, struct timeval end);
void runProcess(int iBurstTime, struct timeval * oStartTime, struct timeval * oEndTime);
void runNonPreemptiveJob(struct process * oTemp, struct timeval * oStartTime, struct timeval * oEndTime);
void runPreemptiveJob(struct process * oTemp, struct timeval * oStartTime, struct timeval * oEndTime);

