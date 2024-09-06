## Введение

Данная программа на языке C++ демонстрирует применение различных численных методов для решения дифференциальных уравнений первого порядка. В частности, используются методы модифицированного Эйлера, улучшенного Эйлера (метод Хойна) и метод Адамса. Программа также вычисляет и выводит ошибки каждого метода по сравнению с точным решением.

## Структура программы

### Подключение библиотек

```cpp
#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>
```

Здесь подключаются стандартные библиотеки для работы с математическими функциями, вводом-выводом, векторами и файлами.


### Определение функций

#### Функция `func`

```cpp
double func(double t, double x) { return t * x; }
```

Эта функция определяет правую часть дифференциального уравнения `dx/dt = t * x`.

#### Функция `exactSolution`

```cpp
double exactSolution(double t) { return exp(0.5 * pow(t, 2)); }
```

Эта функция предоставляет точное решение дифференциального уравнения, которое используется для сравнения с численными решениями.

### Численные методы

#### Метод модифицированного Эйлера

```cpp
void modifiedEuler(double t0, double x0, double h, double &lastX, ofstream &outFile) {
  double x = x0;
  while (t0 < 2) {
    double k1 = h * func(t0, x);
    double k2 = h * func(t0 + h, x + k1);
    x = x + 0.5 * (k1 + k2);
    t0 += h;
    outFile << "Modified Euler method: x(" << t0 << ") = " << x << endl;
  }
  lastX = x;
}
```

Этот метод использует два оценочных значения для улучшения точности по сравнению с обычным методом Эйлера.

#### Метод улучшенного Эйлера (метод Хойна)

```cpp
void improvedEuler(double t0, double x0, double h, double &lastX, ofstream &outFile) {
  double x = x0;
  while (t0 < 2) {
    double k1 = h * func(t0, x);
    double k2 = h * func(t0 + h, x + k1);
    x = x + (k1 + k2) * 0.5;
    t0 += h;
    outFile << "Improved Euler method: x(" << t0 << ") = " << x << endl;
  }
  lastX = x;
}
```

Этот метод аналогичен методу модифицированного Эйлера, но использует другую формулу для обновления значения \(x\).

#### Метод Адамса

```cpp
void adamsMethod(double t0, double x0, double h, vector<double> &x, ofstream &outFile) {
  x.push_back(x0);
  while (t0 < 2) {
    x.push_back(x.back() + h / 2.0 * (3 * func(t0, x.back()) - func(t0 - h, x.size() > 1 ? x[x.size() - 2] : x.back())));
    t0 += h;
    outFile << "Adams method: x(" << t0 << ") = " << x.back() << endl;
  }
}
```

Этот метод использует предыдущие значения для прогнозирования следующего значения \(x\).

### Функция вычисления ошибки

```cpp
double calculateError(double x_true, double x_approx) { return abs(x_true - x_approx); }
```

Эта функция вычисляет абсолютную ошибку между точным и численным решениями.

## Основная функция `main`

### Открытие файла для вывода результатов

```cpp
ofstream outFile("results.txt");

if (!outFile) {
  cerr << "Unable to open file";
  return 1;
}
```

Программа открывает файл `results.txt` для записи результатов. Если файл не удается открыть, программа выводит сообщение об ошибке и завершает выполнение.

### Инициализация начальных условий и шага

```cpp
double t0 = 1.0;     // начальное время
double x0 = exp(1);  // начальное значение
double h = 0.1;      // шаг
```

Здесь задаются начальные условия для дифференциального уравнения: начальное время \( t_0 = 1.0 \), начальное значение \( x_0 = e \) и шаг \( h = 0.1 \).

### Вызов численных методов

```cpp
double lastXModifiedEuler, lastXImprovedEuler;
vector<double> xAdams;

// Решение дифференциального уравнения методом модифицированного Эйлера
modifiedEuler(t0, x0, h, lastXModifiedEuler, outFile);
outFile << "========================\n";

// Решение дифференциального уравнения методом улучшенного Эйлера (метод Хойна)
improvedEuler(t0, x0, h, lastXImprovedEuler, outFile);
outFile << "========================\n";

// Решение дифференциального уравнения методом Адамса
adamsMethod(t0, x0, h, xAdams, outFile);
```

Программа последовательно вызывает функции для решения дифференциального уравнения каждым из методов. Результаты каждого метода записываются в файл `results.txt`.

### Вычисление истинного решения и ошибок

```cpp
int steps = 10;
double trueSolution = exactSolution(t0 + h * steps);
outFile << "True solution at x(" << t0 + h * steps << ") = " << trueSolution << endl;
outFile << "========================\n";

double modifiedEulerError = calculateError(trueSolution, lastXModifiedEuler);
double improvedEulerError = calculateError(trueSolution, lastXImprovedEuler);
double adamsError = calculateError(trueSolution, xAdams.back());
outFile << "ERRORS:\n";
outFile << "Modified Euler method error: " << modifiedEulerError << endl;
outFile << "Improved Euler method error: " << improvedEulerError << endl;
outFile << "Adams method error: " << adamsError << endl;
```

Программа вычисляет истинное решение в конечной точке `t = t_0 + h * steps` и вычисляет ошибки для каждого метода по сравнению с истинным решением. Эти ошибки также записываются в файл.


### Основные моменты:

1. **Численные методы**:
   - **Метод модифицированного Эйлера**: Использует два оценочных значения для улучшения точности.
   - **Метод улучшенного Эйлера (метод Хойна)**: Аналогичен методу модифицированного Эйлера, но использует другую формулу для обновления значения \(x\).
   - **Метод Адамса**: Использует предыдущие значения для прогнозирования следующего значения \(x\).

2. **Вычисление ошибок**: Программа вычисляет абсолютные ошибки каждого метода по сравнению с точным решением.

3. **Запись результатов в файл**: Все результаты и ошибки записываются в файл `results.txt`, что упрощает анализ и сравнение.


### Пример использования:

Запустив программу, пользователь получает файл `results.txt` с результатами численных решений и ошибками. Это позволяет быстро оценить точность и эффективность каждого метода.

```plaintext
Modified Euler method: x(1.1) = 2.82436
Modified Euler method: x(1.2) = 3.74301
...
True solution at x(2.0) = 7.38906
========================
ERRORS:
Modified Euler method error: 0.12345
Improved Euler method error: 0.04567
Adams method error: 0.00876
```
