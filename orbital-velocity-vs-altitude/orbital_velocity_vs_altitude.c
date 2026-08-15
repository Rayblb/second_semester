#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define G 6.6743e-11
#define M 5.972e24
#define R 6371000

double vc(int Hc)
{                             // вычислить круговую скорость
    double mu = G * M;        // вычисляем стандартный гравитационный параметр
    double r = R + Hc * 1000; // вычислить расстояние от центра Земли
    return sqrt(mu / r);      // верните круговую скорость, используя уравнение vis-viva
}

double vomega(int H, int i)
{ // вычислить скорость конца геоцентрического радиус-вектора
    double a = R + H;
    double n = sqrt(G * M / pow(a, 3));
    double vi = n * a * cos(i * M_PI / 180);
    double vomega = n * a * sin(i * M_PI / 180);
    return sqrt(pow(vi, 2) + pow(vomega, 2));
}

int main()
{
    int Hc[61];
    double Vc[61];
    double Vw[61];
    int i;
    // Loop для расчета круговой скорости и скорости конца геоцентрического радиус-вектора для разных высот.
    for (i = 0; i <= 60; i++)
    {
        Hc[i] = i * 1000;
        Vc[i] = vc(Hc[i]);
        Vw[i] = vomega(Hc[i], 45);
    }
    // Создаем канал gnuplot и пишем необходимые команды для графика.
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    fprintf(gnuplotPipe, "set xlabel 'Height above the Earth''s surface (km)'\n");
    fprintf(gnuplotPipe, "set ylabel 'Orbital speed (m/s)'\n");
    fprintf(gnuplotPipe, "set title 'Graph of the speed of a satellite in circular orbit and the velocity of the end of the geocentric radius vector at 45 deg inclination'\n");
    fprintf(gnuplotPipe, "plot '-' with lines title 'Circular Orbit', '-' with lines title 'Velocity of End of Geocentric Radius Vector'\n");
    // Записываем точки данных в канал gnuplot для графика.
    for (i = 0; i <= 60; i++)
    {
        fprintf(gnuplotPipe, "%d %f\n", Hc[i], Vc[i]);
    }
    // Завершаем поток данных и очищаем буфер для круговой орбиты.
    fprintf(gnuplotPipe, "e\n");
    for (i = 0; i <= 60; i++)
    {
        fprintf(gnuplotPipe, "%d %f\n", Hc[i], Vw[i]);
    }
    // Завершаем поток данных и очищаем буфер для скорости конца геоцентрического радиус-вектора.
    fprintf(gnuplotPipe, "e\n");
    fflush(gnuplotPipe);
    pclose(gnuplotPipe);
    return 0;
}
