/*********************************************************************************************/ /**
* Peer-graded Assignment: 
* Week 4 Assignment: Arrays
**************************************************************************************************/

/*********************************************************************************************/ /**
* Includes 
**************************************************************************************************/
#include <stdio.h>   // Standard I/O Interface
#include <stdlib.h>  // Standard Library
#include <string.h> 

/*********************************************************************************************/ /**
* Function and vaiables declaration
**************************************************************************************************/
void read_file (FILE *ifp, int SIZE, int d[]);
void max_number (int SIZE, int d[], int *max_no);
void average_calc (int SIZE, int d[], double *avg_calc);
void write_to_file (FILE *ifp, FILE *ofp, int SIZE, int DATA[], double avg, int max);
/*********************************************************************************************/ /**
* The main method
**************************************************************************************************/
int main (int argc, char *argv[])
{
    FILE *ifp, *ofp;
    int i, SIZE, max = 0;
    double avg = 0;

    if(argc != 2)
    {
        printf("\n\nWrong argument, please specify input file \"data.txt\" \n\n");
        exit(1);
    }
  
    ifp = fopen(argv[1], "r");
    ofp = fopen("answer-hw3", "w+");    

    fscanf(ifp, "%d", &SIZE);
    int DATA [SIZE];

    read_file (ifp, SIZE, DATA);
    
    printf("\n\nThe array of %d elements are: ", SIZE);
    for (i=0; i < SIZE; i++)
    {
        printf("%d ", DATA[i]);
    }

    average_calc (SIZE, DATA, &avg);
    max_number (SIZE, DATA, &max);

    write_to_file (ifp, ofp, SIZE, DATA, avg, max);
    printf("\n\n");

    fclose(ifp);
    fclose(ofp);

    return 0;
}
/*********************************************************************************************/ /**
* Function definition: Read file
**************************************************************************************************/
void read_file (FILE *ifp, int SIZE, int d[])
{
    for(int i = 0; i < SIZE; i++)
    {
        fscanf(ifp, "%d", &d[i]);
    }
}
/*********************************************************************************************/ /**
* Function definition: Max number
**************************************************************************************************/
void max_number (int SIZE, int d[], int *max_no)
{
    if (SIZE < 1)
    {
        printf("File is empty");
        exit(1);
    }

    int MAX = d[0];

    for (int i = 0; i < SIZE; i++)
    {
        if(d[i] > MAX)
        {
            MAX = d[i];
        }
    }

    printf("\n\nMax number = %d", MAX);

    *max_no = MAX;
    
}
/*********************************************************************************************/ /**
* Function definition: Average calc
**************************************************************************************************/
void average_calc (int SIZE, int d[], double *avg_calc)
{
	double avg = 0.0;

	for(int i = 0; i < SIZE; i++)
    {
		avg += d[i];
	}

    printf("\n\nAvg value = %lf", avg/SIZE);

    *avg_calc = avg/SIZE;
}
/*********************************************************************************************/ /**
* Function definition: Write to file
**************************************************************************************************/
void write_to_file (FILE *ifp, FILE *ofp, int SIZE, int DATA[], double avg, int max)
{
    fprintf (ofp, "The array of %d elements are: ", SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        fprintf(ofp, "%d ", DATA[i]);

        if ((i + 1) % 8 == 0)
        {
          fprintf(ofp, "\n");
        }
    }   

    fprintf (ofp, "\n\nAvg value = %.6lf", avg);
    fprintf (ofp, "\n\nMax number = %d", max);
}
/*********************************************************************************************/ /**
* Compile:      $ gcc -o arrays_option_1.out arrays_option_1.c
* Run:          $ ./arrays_option_1.out data.txt
*
* Peer-graded Assignment: Arrays
* Input file: data.txt  4  1  2  3  4
* Test Output for "arrays_option_1.c"
* ************************************************************************************************
* The array of 4 elements are: 1 2 3 4
* 
* Avg value = 2.500000
* 
* Max number = 4
**************************************************************************************************/