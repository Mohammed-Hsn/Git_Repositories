#include <stdio.h>
#include <string.h>
 int main() {
 int processNumber[10], burstTime[10], numberOfProcesses,waitingTime[10], temp = 0, i, j, turnAroundTime[10];
 float totalWaitingTime = 0, totalTurnAroundTime = 0;
 printf("\nEnter the number of processes: ");
 scanf("%d", &numberOfProcesses);
 printf("\nEnter the burst time of each process:");
 
 for (i = 0; i < numberOfProcesses; i++) {
 printf("\nProcess p%d: ", i);
 scanf("%d", &burstTime[i]);
 processNumber[i] = i;
 }
 
 // Sorting burst times and corresponding process numbers using selection sort
 for (i = 0; i < numberOfProcesses - 1; i++) {
 for (j = i + 1; j < numberOfProcesses; j++) {
 if (burstTime[i] > burstTime[j]) {
 // Swap burst time
 temp = burstTime[i];
 burstTime[i] = burstTime[j];
 burstTime[j] = temp;
 // Swap process number
 temp = processNumber[i];
 processNumber[i] = processNumber[j];
 processNumber[j] = temp;
 }
 }
 }

 waitingTime[0] = 0; // First process has no waiting time

 // Calculating waiting time for each process
 for (i = 1; i < numberOfProcesses; i++) { 
 waitingTime[i] = burstTime[i - 1] + waitingTime[i - 1];
 totalWaitingTime += waitingTime[i];
 }
 printf("\nProcess No\tBurst Time\tWaiting Time\tTurn Around Time\n");
 
 for (i = 0; i < numberOfProcesses; i++) {
 turnAroundTime[i] = burstTime[i] + waitingTime[i];
 totalTurnAroundTime += turnAroundTime[i];
 printf("\nP%d\t\t%d\t\t%d\t\t%d", processNumber[i], 
 burstTime[i], waitingTime[i], turnAroundTime[i]);
 }
 printf("\n\nAverage Waiting Time: %.2f", totalWaitingTime / numberOfProcesses);
 printf("\nAverage Turn Around Time: %.2f", totalTurnAroundTime / numberOfProcesses);
 return 0;
}
