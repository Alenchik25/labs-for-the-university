#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <unistd.h>
#include <stdbool.h>

double func(double x) { // функция для вычисления значения уравнения
    return cos(x)-pow((x + 2), 0.5) + 1; // возвращаем значение уравнения для заданного x
}

double derivative(double x) { // функция для вычисления производной функции
    return -sin(x)-1/(2*sqrt(x + 2)); // возвращаем значение производной для заданного x
}

void RybakovMethod(double a, double b, double epsilon){
  int iterations = 0;
  double x, x0, f, f0;
  do {
    x0 = a;
    f0 = func(x0);
    x = (a * func(b) - b * func(a)) / (func(b) - func(a));
    if (func(a) * func(x) < 0) {
      b = x;
    } else {
      a = x;
    }
    f = func(x);
    iterations++;
  } while (fabs(x - x0) >= epsilon && fabs(f - f0) >= epsilon);
    printf("--------------------------------------------------");
    printf("\nРешение уравнения cos(x)-(x + 2)^(1/2) + 1 = 0: \n%.4lf \nметодом Рыбакова с точностью %lf", x, epsilon);
    printf("\nКоличество интервалов разбиения: \n%d\n", iterations);
    printf("--------------------------------------------------");
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "rus");
    double a = 0, b = 10, c, epsilon; // a - левая граница интервала, b - правая граница интервала, c - середина отрезка, epsilon - точность
    int count = 0; // кол-во произведенных интервалов разбиения
    int choose; // переменная для выбора метода
    int countView = 1; // нумерация итераций
    double x; // переменная для хранения временного значения корня (метод хорд и Ньютона)

    printf("Выберите метод:\n(1)Дихотомия(1)\n(2)Хорд(2)\n(3)Ньютона(3)\n(4)Рыбакова(4)\n");
    scanf("%d", &choose);

    switch(choose){
        case 1:
            printf("Выбран метод дихотомии\n");
            printf("Введите значение точности (через запятую): ");
            scanf("%lf", &epsilon);
            while ((b - a) > epsilon) { // начинаем цикл метода дихотомии, который будет прерван при достижении заданной точности
                c = (a + b) / 2; // определяем середину отрезка [a, b]
                printf("%d: %.4lf\n", countView, c);
                if (func(c) * func(a) < 0) {
                    b = c;
                } else {
                    a = c;
                }
                count++;
                countView++;
            }
            printf("--------------------------------------------------");
            printf("\nРешение уравнения cos(x)-(x + 2)^(1/2) + 1 = 0: \n%.4lf \nметодом дихотомии с точностью %lf", c, epsilon);
            printf("\nКоличество интервалов разбиения: \n%d\n", count);
            printf("--------------------------------------------------");
            printf("\n");
            main();
            break;
        case 2:
            printf("Выбран метод хорд\n");
            printf("Введите значение точности (через запятую): ");
            scanf("%lf", &epsilon);
            while (true) { // начинаем бесконечный цикл, который будет прерываться при достижении необходимой точности
                x = (a * func(b) - b * func(a)) / (func(b) - func(a)); // находим новое приближение корня методом хорд
                printf("%d: %.4lf\n", countView, x);
                if (fabs(func(x)) < epsilon) // проверяем, достигнута ли необходимая точность
                    break; // если достигнута, выходим из цикла
                if ((func(a) * func(x)) < 0) // обновляем границы интервала в соответствии с результатом метода хорд
                    b = x;
                else
                    a = x;
                count++;
                countView++;
            }
            printf("--------------------------------------------------");
            printf("\nРешение уравнения cos(x)-(x + 2)^(1/2) + 1 = 0: \n%.4lf \nметодом хорд с точностью %lf", x, epsilon);
            printf("\nКоличество интервалов разбиения: \n%d\n", count);
            printf("--------------------------------------------------");
            printf("\n");
            main();
            break;
        case 3:
            printf("Выбран метод Ньютона\n");
            printf("Введите значение точности (через запятую): ");
            scanf("%lf", &epsilon);
            while (fabs(func(x)) > epsilon) { // начинаем цикл метода Ньютона, который будет прерван при достижении заданной точности
                x = x - func(x) / derivative(x); // используем формулу метода Ньютона для нахождения нового значения
                printf("%d: %.4lf\n", countView, x);
                count++;
                countView++;
            }
            printf("--------------------------------------------------");
            printf("\nРешение уравнения cos(x)-(x + 2)^(1/2) + 1 = 0: \n%.4lf \nметодом Ньютона с точностью %lf", x, epsilon);
            printf("\nКоличество интервалов разбиения: \n%d\n", count);
            printf("--------------------------------------------------");
            printf("\n");
            main();
            break;
        case 4:
            printf("Выбран метод Рыбакова\n");
            printf("Введите значение точности (через запятую): ");
            scanf("%lf", &epsilon);
            RybakovMethod(a, b, epsilon);
            printf("\n");
            main();
            break;
        default:
            printf("Ошибка, выход из программы\n");
            sleep(1);
            system("taskkill /IM cb_console_runner.exe /F");
            break;
    }
}
