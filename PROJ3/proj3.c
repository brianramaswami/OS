/*
Class: CPSC 346-01 & CPSC 346-02
Team Member 1: Paul De Palma
Team Member 2: N/A 
GU Username of project lead: depalma
Pgm Name: proj3.c 
Pgm Desc: exploraiton of the proc file system 
Usage: 1) standard:  ./a.out -s 
Usage: 2) history:  ./a.out -h 
Usage: 3) load:  ./a.out -l 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>

void standard();
void history();
void load();

int main(int argc, char* argv[])
{
 if (argc != 2)
  {
   fprintf(stderr, "Error: Options required\n"); 
   fprintf(stderr, "usage: ./a.out -s|-h|-l\n\n"); 
   exit(EXIT_FAILURE);
  }
  
 if (!strcmp(argv[1],"-s"))
  standard();
 if (!strcmp(argv[1],"-h"))
  history();
 if (!strcmp(argv[1],"-l"))
  load();
}
/*
pre: none
post: displays CPU vendor_id, model name, and OS version
*/
void standard()
{
 char ch;
 FILE* ifp;
 char str[80];

 /*
 I've deliberately used two different mechanisms for writing to the console.  
 Use whichever suits you.
 strstr locates a substring
 */

 ifp = fopen("/proc/cpuinfo","r");
 while (fgets(str,80,ifp) != NULL)
  if (strstr(str,"vendor_id") || strstr(str,"model name"))
   puts(str); 
 fclose (ifp);

 ifp = fopen("/proc/version","r");
 while ((ch = getc(ifp)) != EOF)
  putchar(ch);
 fclose (ifp);
}

/*
pre: none
post: displays time since the last reboot (DD:HH:MM:SS), time when the system was last 
      booted, number of processes that have been creates since the last reboot 
      Hint: strftime could be useful
*/


void history()
{
 char ch;
int index = 0;
 FILE* ifp;
 char str[80];
int time;
float H;
int M;
int S;


 ifp = fopen("/proc/uptime","r");
 while ((ch = getc(ifp)) != ' '){
 str[index] = ch;
 index++;

 // putchar(ch);
 }
 printf("%s", str);
 printf("\n");
 time = atoi(str);
 printf("%i", time);
 H = time / (24*60*60);
 M = time / 60*60;
 S = M % 60; 
 S = S/60;
 printf("%s", "seconds");
 printf("%i", S);
 printf("\n");
 printf("\n");
 printf("%i","%i","%i",H,M,S);

 printf("\n");
 printf("%f", H);
 
 fclose (ifp);


 ifp = fopen("/proc/stat","r");
 printf("\n");
 while (fgets(str,80,ifp) != NULL)
  if (strstr(str,"btime") || strstr(str,"processes"))
   puts(str); 
 fclose (ifp);

}


/*
pre: none
post: displays total memory, available memory, load average (avg. number of processes over the last minute) 
*/
void load()
{
 char ch;
 FILE* ifp;
 char str[80];

 ifp = fopen("/proc/meminfo","r");
 while (fgets(str,80,ifp) != NULL)
  if (strstr(str,"MemTotal") || strstr(str,"MemAvailable"))
   puts(str); 
 fclose (ifp);

 ifp = fopen("/proc/loadavg","r");
 while ((ch = getc(ifp)) != ' ')
  putchar(ch);
printf("\n");
 fclose (ifp);
}










