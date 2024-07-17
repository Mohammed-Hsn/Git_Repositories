#include <stdio.h>
 int main() {
 char processName[10][10];
 int arrivalTime[10], burstTime[10], startTime[10], 
 finishTime[10], turnAroundTime[10], waitingTime[10];
 int i, numberOfProcesses;
 int totalWaitingTime = 0, totalTurnAroundTime = 0;
 
 printf("Enter the number of processes: ");
 scanf("%d", &numberOfProcesses);
 
 for (i = 0; i < numberOfProcesses; i++) {
 printf("Enter the Process Name, Arrival Time & Burst Time: ");
 scanf("%s %d %d", processName[i], &arrivalTime[i], &burstTime[i]);
 }
 startTime[0] = arrivalTime[0];
 finishTime[0] = startTime[0] + burstTime[0];
 turnAroundTime[0] = finishTime[0] - arrivalTime[0];
 waitingTime[0] = startTime[0] - arrivalTime[0];
 
 for (i = 1; i < numberOfProcesses; i++) {
 startTime[i] = finishTime[i - 1];
 waitingTime[i] = startTime[i] - arrivalTime[i];
 finishTime[i] = startTime[i] + burstTime[i];
 turnAroundTime[i] = finishTime[i] - arrivalTime[i];
 }

 printf("\nPName ArrTime BurTime Start TAT Finish");
 
 for (i = 0; i < numberOfProcesses; i++) {
 printf("\n%s\t%6d\t%6d\t%6d\t%6d\t%6d", 
 processName[i], arrivalTime[i], burstTime[i], startTime[i], 
 turnAroundTime[i], finishTime[i]);
 totalWaitingTime += waitingTime[i];
 totalTurnAroundTime += turnAroundTime[i];
 }

printf("\nAverage Waiting Time: %.2f",(float)totalWaitingTime / numberOfProcesses);
printf("\nAverage Turn Around Time: %.2f",(float)totalTurnAroundTime / numberOfProcesses);
return 0;
}