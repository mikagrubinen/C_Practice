/* Code for testing "look-up table"
   first line in main will initialize first 5 members of array 
   with -1, 0, 1, 1, 2 and all other with 0 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int table[10] = {-1, 0, 1, 1, 2};

    for(int i=0; i<=9; i++){
        printf("%d\n",table[i]);
    }

    printf("Table[32] = %d\n", table[32]);

    return 0;
}
