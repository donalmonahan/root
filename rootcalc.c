/*==================================================================
 *
 *               University College Dublin
 *          EEEN20010 - Computer Engineering I
 *
 * File Name	:	rootcalc.c
 *
 * Description	:   Program to estimate one root of a quadratic
 *                  function. The program calculates values for
 *                  f(x) between -100 <= x <= 100and estimates the
 *                  root to be the value of x for which f(x) is
 *                  closest to 0.
 *
 * Author		:	Donal C. Monahan
 *
 * Date			:	06-10-22
 *
 *==================================================================*/

#include <stdio.h>

/* function prototype */
float quad_root(float, float, float);

int main(void) {

    /* declare variables */
    float a, b, c;            /* quadratic coefficients */
    char yes_no;            /* instruction by user to repeat or not */

    /* print intro message explaining program */
    printf("************************************************\n");
    printf("*                                              *\n");
    printf("*   Welcome to the quadratic root estimator.   *\n");
    printf("*   This estimates the value of one root of    *\n");
    printf("*             f(x) = ax^2 + bx + c.            *\n");
    printf("*                                              *\n");
    printf("************************************************\n");

    /* do-while loop that executes program as long as user wants*/
    do {

        /* prompt user to input a, b and c */
        printf("Enter the coefficients in the form 'a b c':\n");
        scanf("%f %f %f", &a, &b, &c);

        /* print error message if roots are not real */
        if(b * b < 4 * a * c) {

            printf("Complex Roots - cannot estimate with this program.\n");

        }

        else {

            /* print value returned by quad_func */
            printf("There is a root at x = %.3f\n", quad_root(a, b, c));

        }

        /* ask user to repeat loop */
        printf("Do you wish to try another quadratic [y/n]: ");
        scanf(" %c", &yes_no);

    } while(yes_no == 'y');

    return 0;

}

/* function that returns estimate of root */
float quad_root(float a, float b, float c) {

    /* declare variables */
    float x, f;             /* x = quadratic input; f = quadratic output */
    float x0, f0 = 1000;    /* x0 = root estimate; f0 = value of f closest to 0 (initialised to high value) */

    /* loop over values for x from -100 to 100 */
    for(x = -100; x <= 100; x++) {

        /* calculate value of f for each value of x */
        f = a * (x * x) + b * x + c;

        /* if f calculated in this iteration is closer to 0 than f from previous iterations */
        if(f * f < f0 * f0) {   /* f and f0 are squared so both are positive; lesser of two squares is closer to 0 */

            f0 = f;             /* value of f stored in f0 */
            x0 = x;             /* value of x stored in x0 */

        }

    }

    return x0;

}
