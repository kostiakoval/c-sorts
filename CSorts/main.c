//
//  Jesse Squires
//  http://www.jessesquires.com
//
//  GitHub
//  https://github.com/jessesquires/c-sorts
//
//  Copyright (c) 2014 Jesse Squires
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "sorts.h"
#include "sortUtils.h"

int main(int argc, const char * argv[])
{
    const uint32_t MAX_COUNT = 10000;
    const uint32_t NUM_TRIALS = 10;
    
    uint32_t randomArray[MAX_COUNT];
    
    double totalTime = 0.0;
    
    for (unsigned int t = 1; t <= NUM_TRIALS; t++) {
        printf("\n::: TRIAL %d :::\n", t);
        
        fillArrayWithRandomIntegers(randomArray, MAX_COUNT);
        
        totalTime += sortArrayWithNameUsingFunc(randomArray, MAX_COUNT, "Quick Sort", quickSort);
        
        memset(&randomArray[0], 0, sizeof(randomArray));
    }
    
    printf("\n QUICK SORT AVG = %lf\n", totalTime / NUM_TRIALS);
    
    printf("\n");
    return 0;
}

