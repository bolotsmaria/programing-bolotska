#include "lib.h"
#include <math.h>

#define true 1
#define false 0

int isPrime(int x)  
{
    if (x > 1) {
        for (int i = 2; i < x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;           
    } else {                               
        return false;           
    }
}
