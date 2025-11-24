/*---------------------------*/
/* --o0o-- LIBRARIES --o0o-- */
/*---------------------------*/

#include <stdio.h>
#include <stdlib.h>


/*----------------------------*/
/* --o0o-- PROTOTYPES --o0o-- */
/*----------------------------*/

int *QS(int *arr_arg, int f_arg, int l_arg);       /* # Quicksort algorithm.  # */
int val(char *str_arg, int *arr_arg, int con_arg); /* # Validation (CL args). # */


/*----------------------*/
/* --o0o-- MAIN --o0o-- */
/*----------------------*/

int main(int argc, char **argv){

    int *arr, i; /* # Array declaration & loop count. # */

    /* ## Validation against CL args < 2. ## */

    if(argc < 3){
        fprintf(stderr, "ERR00 - Unexpected number of arguments.\n");
        exit(1);
    }

    arr = (int *)calloc((argc - 1), sizeof(int)); /* # !! Heap allocation. !! # */

    /* ## Assignment loop & ERRmsg case. ## */

    for(i = 1; i < (argc); i++){

        if(val(argv[i], arr, i - 1) != 1){
            arr[i - 1] = atoi(argv[i]);
            continue;
        }
        fprintf(stderr, "ERR01 - Arguments are invalid or redundant.\n");
        exit(1);
    }

    arr = QS(arr, 0, (argc - 2));

    /* ## Sorted array output. ## */

    fprintf(stdout, "# Sorted arguments: #\n");
    for(i = 1; i < argc; i++){
        fprintf(stdout, "%d\n", arr[i - 1]);
    }

    free(arr); /* # !! Allocation liberated. !! # */

    return 0;
}


/*--------------------------*/
/* --o0o-- ROUTINES --o0o-- */
/*--------------------------*/

/* ## Quicksort rout. ## */

int *QS(int *arr_arg, int f_arg, int l_arg){

    int p1, p2, pvt, tmp; /* # Pointers, pivot & temp. # */

    if (f_arg < l_arg){
        p1 = f_arg;
        p2 = l_arg;
        pvt = arr_arg[(p1 + p1) / 2];

    /* ## Pointer traversal (0, 1) & swapping (2). ## */

        do{
            while(arr_arg[p1] < pvt){
                p1++;                   /* # 0 */
            }
            while(arr_arg[p2] > pvt){
                p2--;                   /* # 1 */
            }

            if(p1 != p2){
                tmp = arr_arg[p1];
                arr_arg[p1] = arr_arg[p2];
                arr_arg[p2] = tmp;         /* # 2 */
            }
        }
        while(arr_arg[p1] != arr_arg[p2]);

    /* ## Recursive partitioning (0, 1). ## */

        QS(arr_arg, f_arg, (p1 - 1)); /* # 0 */
        QS(arr_arg, (p2 + 1), l_arg); /* # 1 */
    }

    return arr_arg;
}

/* ## Validation rout. ## */

int val(char *str_arg, int *arr_arg, int con_arg){

    int j, len = 0; /* # Loop value and string len. # */

    /* ## Type validation for (char * --> int). ## */

    for(j = 0; str_arg[j] != '\0'; j++){

    /* ## Exclude '-' in len (0) & assess digits (1). ## */

        if(str_arg[0] == '-' && j == 0)continue;           /* # 0 */
        if(str_arg[j] < '0' || str_arg[j] > '9') return 1; /* # 1 */
        len++;
    }

    /* ## Range (-999-999) (0) & redundancy validation. (1). ## */

    if(len > 3) return 1;                                         /* # 0 */
    for(j = 0; j < (con_arg); j++){
        if(atoi(str_arg) == arr_arg[j] && con_arg != 1) return 1; /* # 1 */
    }

    return 0;
}