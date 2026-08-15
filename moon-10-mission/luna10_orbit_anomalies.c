#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define the constants for the Luna 10 mission
double r_p = 2088 ;  // periapsis distance in km
double r_a =  2738 ;  // apoapsis distance in km
double a = (r_p + r_a) / 2;  // semi-major axis in km
double e = (r_a - r_p) / (2* a);  // eccentricity
double tau = 0;  // time of periapsis passage in seconds
double M_pl = 0.073 * pow(10, 24);  // mass of the moon in kg

double phi(double E, double M) {
    return E*sin(E) - M;
}

// Define the functions for the anomalies
double true_anomaly(double E, double e) {
    return 2 * atan(sqrt((1 + e) / (1 - e)) * tan(E / 2));
}

double eccentric_anomaly(double M, double e) {
    double E = M;  
    double E_prev;

    do {
        E_prev = E;
        E = E_prev - (E_prev - e * sin(E_prev) - M) / (1 - e * cos(E_prev));
    } while (fabs(E - E_prev) > 1e-6);  

    return E;
}

double mean_anomaly(double t, double mu, double a, double Tp) {
    double n = sqrt(mu / pow(a, 3));  
    return n * (t - Tp);
}

int main() {
    double T = 10683;  // period of one revolution
    double dt = T / 1000;  // time step
    double t;

    FILE *data = fopen("moonmission.txt", "w");
    if (data == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (t = 0; t <= T; t += dt) {
        double M = mean_anomaly(t, M_pl, a, tau);
        double E = eccentric_anomaly(M, e);
        double theta = true_anomaly(E, e);
        fprintf(data, "%f %f %f %f\n", t, theta, E, M);
    }

    fclose(data);

    // Open gnuplot
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    if (gnuplot == NULL) {
        printf("Error opening gnuplot!\n");
        return 1;
    }

    // Plot the data using gnuplot
    fprintf(gnuplot, "set title 'Anomalies as a function of time'\n");
    fprintf(gnuplot, "set xlabel 'Time'\n");
    fprintf(gnuplot, "set ylabel 'Anomaly'\n");
    fprintf(gnuplot, "plot 'data.txt' using 1:2 title 'True anomaly' with lines, \
                     'data.txt' using 1:3 title 'Eccentric anomaly' with lines, \
                     'data.txt' using 1:4 title 'Mean anomaly' with lines\n");

    fflush(gnuplot);

    return 0;
}
