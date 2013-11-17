/*
 * gaussiannoise.cc
 *
 *  Created on: Nov 7, 2013
 *      Author: quannt
 */

#include "gaussiannoise.h"
#include <stdlib.h>
#include <math.h>

GaussianNoise::GaussianNoise(double muy, double sigma)
{
    this->muy = muy;
    this->sigma = sigma;
}

/*
 * Generate Next Gaussian using Box Muller transform
 * x ~ N(muy, sigma^2)
 * s,t ~ Uniform distribution: [0; 1]
 */
double GaussianNoise::nextNoise()
{
    double x = 0, s, t;
    do {
        s = (double) rand() / (double) RAND_MAX;
        t = (double) rand() / (double) RAND_MAX;
    } while (s == 0);

    x = muy + sigma * sqrt(-2 * log(s)) * cos(2 * M_PI * t);
    return x;
}
