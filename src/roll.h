// see: https://dice.clockworkmod.com/ to check roll probability distribution

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int roll(int n, int sides){
    int total = 0;
    for ( int i=0; i<n; ++i ){
        total += rand() % sides;
    }
    return total;
}

/* 

The rand() function in <stdlib.h> returns a pseudo-random integer between 0 and RAND_MAX. You can use srand(unsigned int seed) to set a seed.

It's common practice to use the % operator in conjunction with rand() to get a different range (though bear in mind that this throws off the uniformity somewhat). 

*/


void rand_example(void){

    // srand(time(NULL));
    int r = rand();
    /* random int between 0 and 19 */
    int r2 = rand() % 20;

}

void sample_roll(int n, int s){
    
    int total = 0;
    int times = 200;
    printf("STANDARD %dd%d\n",n,s);
    int d;
    for (int i=0; i<times; ++i ){
        d = roll(n,s);
        // printf("result: %d\n",d);
        total += d;
    }
    double avg = (double)total / times;
    printf("roll total: %d\n", total);
    printf("roll average: %.2f\n", avg);

}

//see: https://stackoverflow.com/questions/11641629/generating-a-uniform-distribution-of-integers-in-c
int uniform_distribution(int rangeLow, int rangeHigh) {
    
    double myRand = rand()/(1.0 + RAND_MAX); // <-- replace rand() with something better like drand48()
    int range = rangeHigh - rangeLow + 1;
    int myRand_scaled = (myRand * range) + rangeLow;
    return myRand_scaled;

}

int rand_uniform_distribution(int rangeLow, int rangeHigh) {

    //double myRand = drand48()/(1.0 + RAND_MAX);
    double myRand = drand48();
    int range = rangeHigh - rangeLow + 1;
    int myRand_scaled = (myRand * range) + rangeLow;
    return myRand_scaled;

}

int roll_uniform(int n, int s) {

    int total = 0;
    for (int i=0;i<n;++i){
        total += rand_uniform_distribution(1,s);
    }
    return total;

}

void sample_roll_uniform(int n, int s){
    
    int total = 0;
    int trials = 200;

    printf("UNIFORM %dd%d\n",n,s);

    int d;
    for (int i=0; i<trials; ++i ){
        d = roll_uniform(n,s);
        // printf("result: %d\n",d);
        total += d;
    }
    double avg = (double)total / trials;
    printf("roll total: %d\n", total);
    printf("roll average: %.2f\n", avg);

}


void sample_roll_uniform2(int n, int s){
    
    int total = 0;
    int trials = 200;

    printf("UNIFORM2\n");

    int d;
    for (int i=0; i<trials; ++i ){
        d = roll_uniform(3,6);
        // printf("result: %d\n",d);
        total += d;
    }
    double avg = total / trials;
    printf("roll total: %d\n", total);
    printf("roll average: %.2f\n", avg);

}

#define BUF_SIZE 256

// see: https://stackoverflow.com/questions/40118509/read-random-line-from-txt-file

/* Returns a random line (w/o newline) from the file provided */
char* choose_random_line(const char *filename){
    FILE *f;
    size_t lineno = 0;
    size_t selectlen;
    char selected[BUF_SIZE]; /* Arbitrary, make whatever size is needed */
    char current[BUF_SIZE];
    selected[0] = '\0';

    f = fopen(filename,"r"); /* Add your own error checking */
    // char* fgets(char *str, int n, FILE *stream)

    while ( fgets(current, sizeof(current), f) ){
        if (drand48() < 1.0 / ++lineno)
            strcpy(selected,current);
    }

    fclose(f);
    selectlen = strlen(selected);
    if (selectlen > 0 && selected[selectlen-1] == '\n'){
        selected[selectlen-1] = '\0';
    }
    return strdup(selected);
}
