
#ifndef __Plot1_H__
#define __Plot1_H__


int  plot1(double (&Precision)[100],double (&Recall)[100])
{


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#define NUM_POINTS 100
#define NUM_COMMANDS 4

double xvals[NUM_POINTS];
double yvals[NUM_POINTS];
double xvals1[NUM_POINTS];
double yvals1[NUM_POINTS];

FILE *pFile;
	//int i=0,j=0;


int A =1;

    pFile = fopen ("/home/fabiano/My_Project/Centrist/Date1.temp","w");

while(A)
{


               for(int f=0;f<100;f++)
                {
                    xvals[f]= Precision[f];
                    yvals[f]= Recall[f];
                    fprintf(pFile,"%f  %f\n",Precision[f],Recall[f]);

                }
                A=0;
}

 fclose(pFile);



    char * commandsForGnuplot[]{"set title \"CURVE Precision & Recall\"","set xlabel 'Precision'", "set ylabel 'Recall'","plot 'Date1.temp' with points",};

    //float xvals[NUM_POINTS] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9 ,1.0};
    //float yvals[NUM_POINTS] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9 ,1.0};
    FILE * temp = fopen("Date.temp", "w");
    /*Opens an interface that one can use to send commands as if they were typing into the
     *     gnuplot command line.  "The -persistent" keeps the plot open even after your
     *     C program terminates.
     */
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    int i;
    for (i=0; i < NUM_POINTS; i++)
    {
    fprintf(temp, "%lf %lf \n", xvals[i], yvals[i]); //Write the data to a temporary file

    }


    for (i=0; i < NUM_COMMANDS; i++)
    {
    fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
    }
    //return 0;




    return 0;
}

#endif //__Plot1_H__


