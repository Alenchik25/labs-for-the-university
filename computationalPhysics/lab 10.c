#include <stdio.h>
#include <locale.h>

// Вычисление разделенных разностей
double divided_difference(double x[], double y[], int n, int i, int j) {
    if (j == i) {
        return y[i];
    } else {
        return (divided_difference(x, y, n, i, j - 1) - divided_difference(x, y, n, i + 1, j)) / (x[j] - x[i]);
    }
}

// Вычисление интерполирующего многочлена Ньютона
double newton_interpolation(double x[], double y[], int n, double z) {
    double p = y[n];
    for (int i = n - 1; i >= 0; i--) {
        double term = divided_difference(x, y, n, i, n);
        for (int j = i; j < n; j++) {
            term *= (z - x[j]);
        }
        p += term;
    }
    return p;
}

// Линейная интерполяция
double linear_interpolation(double x[], double y[], int n, double z) {
    int i = 0;
    while (i < n && z > x[i]) {
        i++;
    }
    if (i == 0) {
        return y[0];
    } else if (i == n) {
        return y[n - 1];
    } else {
        return y[i - 1] + (y[i] - y[i - 1]) * (z - x[i - 1]) / (x[i] - x[i - 1]);
    }
}

// Квадратичная интерполяция
double quadratic_interpolation(double x[], double y[], int n, double z) {
    int i = 0;
    while (i < n - 1 && z > x[i]) {
        i++;
    }
    if (i == 0) {
        return y[0] + (y[1] - y[0]) * (z - x[0]) / (x[1] - x[0]) + (y[2] - y[0] - y[1] + y[0]) * (z - x[0]) * (z - x[1]) / ((x[2] - x[0]) * (x[1] - x[0]));
    } else if (i == n - 1) {
        return y[n - 1] + (y[n - 1] - y[n - 2]) * (z - x[n - 1]) / (x[n - 1] - x[n - 2]) + (y[n - 1] - y[n - 2] - y[n - 2] + y[n - 3]) * (z - x[n - 1]) * (z - x[n - 2]) / ((x[n - 1] - x[n - 3]) * (x[n - 2] - x[n - 3]));
    } else {
        return y[i - 1] + (y[i] - y[i - 1]) * (z - x[i - 1]) / (x[i] - x[i - 1]) + (y[i + 1] - y[i] - y[i - 1] + y[i - 2]) * (z - x[i - 1]) * (z - x[i]) / ((x[i + 1] - x[i - 1]) * (x[i] - x[i - 1]));
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    // Данные
    double x[] = {0.0,0.3, 0.7};
    double y[] = {2.0, 2.5, 2.9};
    int n = sizeof(x) / sizeof(x[0]);

    // Вычисление значений для x от 0,3 до 0,7 с шагом 0,01
    double z = 0.0;
    while (z <= 0.7) {
        // Вычисление интерполированных значений
        double p = newton_interpolation(x, y, n, z);
        double l = linear_interpolation(x, y, n, z);
        double q = quadratic_interpolation(x, y, n, z);

        // Вывод результатов
        //printf("Значение интерполирующего многочлена Ньютона для x = %lf: y = %lf\n", z, p);
        printf("Линейный x = %lf: y = %lf\n", z, l);
        printf("Квадратичный x = %lf: y = %lf\n", z, q);
        printf("\n");

        // Увеличение значения z
        z += 0.1;
    }

    return 0;
}
