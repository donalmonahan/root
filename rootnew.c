/*==================================================================
 *
 *               University College Dublin
 *          EEEN20010 - Computer Engineering I
 *
 * File Name	:	rootnew.c
 *
 * Description	:   Program to find the roots of a cubic function
 *                  based on coefficients supplied by user, using
 *                  bisection method.
 *
 * Author		:	Donal C. Monahan
 *
 * Date			:	12-10-22
 *
 *==================================================================*/

#include <stdio.h>

#define TOL 0.001          /* minimum distance allowed between x_lo and x_hi */

/* cube_root function prototypes */
float cube_root(float, float, float, float);
float cube_func(float, float, float, float, float);

int main(void) {

    /* declare variables */
    float a, b, c, d;       /* cubic coefficients */
    char yes_no;            /* instruction by user to repeat or not */

    /* print intro message explaining program */
    printf("************************************************\n");
    printf("*                                              *\n");
    printf("*     Welcome to the cubic root estimator.     *\n");
    printf("*   This estimates the value of one root of    *\n");
    printf("*         f(x) = ax^3 + bx^2 + bx + c.         *\n");
    printf("*                                              *\n");
    printf("************************************************\n");

    /* do-while loop executes program as long as user wants */
    do {

        /* prompt user to input a, b, c and d */
        printf("\nEnter the coefficients in the form 'a b c d': ");
        scanf("%f %f %f %f", &a, &b, &c, &d);

        /* call cube_root function */
        printf("There is a root at %.3f\n", cube_root(a, b, c, d));

        /* ask user to repeat loop */
        printf("Do you wish to try another cubic [y/n]: ");
        scanf(" %c", &yes_no);

    } while(yes_no == 'y');

    return 0;

}

/* function that returns estimate of root */
float cube_root(float a, float b, float c, float d) {

    /* declare limits of x, midpoint of limits, and f at those points */
    float x_lo = 0, x_hi = 0, x_mid; /* x_lo and x_hi initialised to 0 */
    float f_lo = cube_func(x_lo, a, b, c, d), f_hi = cube_func(x_hi, a, b, c, d), f_mid; /* f_lo and f_hi initialised to f(0) */

    /* while f_lo and f_hi do not have opposite signs; THIS STEP ENSURES THAT A ROOT WILL FALL WITHIN INTERVAL */
    while(f_lo * f_hi >= 0) {

        /* widen interval */
        x_lo--;
        x_hi++;

        /* recalculate f_lo and f_hi */
        f_lo = cube_func(x_lo, a, b, c, d);
        f_hi = cube_func(x_hi, a, b, c, d);

    }

    /* do-while loop executes while (x_hi - x_lo) is greater than tolerance (TOL = 0.001) */
    do {

        x_mid = 0.5 * (x_lo + x_hi);  /* halfway between x_lo and x_hi */

        /* f(x) calculated at x_lo, x_hi and x_mid */
        f_lo = cube_func(x_lo, a, b, c, d);
        f_hi = cube_func(x_hi, a, b, c, d);
        f_mid = cube_func(x_mid, a, b, c, d);

        /* if f_lo and f_mid have the same sign, x_lo is stored in x_mid */
        if(f_lo * f_mid > 0)

            x_lo = x_mid;

        /* if f_lo and f_mid have opposite signs, x_hi is stored in x_mid */
        else

            x_hi = x_mid;

    } while(x_hi - x_lo > TOL);

    return x_mid;

}

/* function to calculate value of cubic function */
float cube_func(float x, float a, float b, float c, float d) {

    float f = a * (x * x * x) + b * (x * x) + c * (x) + d;

    return f;

}
