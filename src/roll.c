// see: https://dice.clockworkmod.com/ to check roll probability distribution

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int roll(int n, int sides){
    int total = 0;
    for (int i=0; i<n; ++i ){
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
    printf("STANDARD\n");
    int d;
    for (int i=0; i<times; ++i ){
        d = roll(n,s);
        // printf("result: %d\n",d);
        total += d;
    }
    double avg = total / times;
    printf("roll total: %d\n", total);
    printf("roll average: %f\n", avg);

}

//see: https://stackoverflow.com/questions/11641629/generating-a-uniform-distribution-of-integers-in-c
int uniform_distribution(int rangeLow, int rangeHigh) {
    
    double myRand = rand()/(1.0 + RAND_MAX); 
    int range = rangeHigh - rangeLow + 1;
    int myRand_scaled = (myRand * range) + rangeLow;
    return myRand_scaled;

}


void sample_roll_uniform(int n, int s){
    
    int total = 0;
    int trials = 200;

    printf("UNIFORM\n");

    int d;
    for (int i=0; i<trials; ++i ){
        d = uniform_distribution(1,s);
        // printf("result: %d\n",d);
        total += d;
    }
    double avg = total / trials;
    printf("roll total: %d\n", total);
    printf("roll average: %f\n", avg);

}



void main(void){
    
    // PRNG needs to be seeded once before any calls to rand()
    srand(time(0));

    for(;;){
        sample_roll(3,6);
        sample_roll_uniform(3,6);

        printf("\n");
        
        sleep(2);
    }


}