## Введение
Данная программа реализует два метода решения систем линейных уравнений: метод простых итераций и метод Гаусса-Зейделя. Эти методы используются для нахождения приближенных решений систем линейных уравнений, особенно когда матрица коэффициентов является большой и разреженной.

## Метод простых итераций

### Описание
Метод простых итераций заключается в следующем:
1. Преобразуем систему уравнений к виду, который указан в методическом материале
2. Начинаем с начального приближения `x^(0)`.
3. Повторяем итерации, обновляя значения `x[i]` до тех пор, пока изменение значений не станет меньше заданного эпсилон.

### Алгоритм
1. Инициализируем начальное приближение `x`.
2. В цикле:
   - Вычисляем новые значения `x[i]`  на основе текущих значений.
   - Вычисляем ошибку как максимальное изменение значения `x[i]` .
   - Если ошибка меньше эпсилон, завершаем итерации.
3. Возвращаем найденное решение и количество итераций.

## Метод Гаусса-Зейделя

### Описание
Метод Гаусса-Зейделя улучшает метод простых итераций, используя сразу обновленные значения на текущей итерации:
1. Преобразуем систему уравнений к виду, который указан в методическом материале.
2. Начинаем с начального приближения `x^(0)` .
3. Повторяем итерации, обновляя значения `x[i]`  до тех пор, пока изменение значений не станет меньше заданного эпсилон.

### Алгоритм
1. Инициализируем начальное приближение x .
2. В цикле:
   - Вычисляем новые значения `x[i]`  на основе текущих и обновленных значений.
   - Вычисляем ошибку как максимальное изменение значения `x[i]` .
   - Если ошибка меньше эпсилон, завершаем итерации.
3. Возвращаем найденное решение и количество итераций.

## Важные замечания

* **Диагональное доминирование**: 

    Оба метода требуют, чтобы матрица коэффициентов была диагонально доминирующей или близкой к этому для гарантии сходимости.
* **Начальное приближение**: 

    Выбор начального приближения может существенно влиять на скорость сходимости.
* **Точность**: 

    Значение эпсилон следует выбирать тщательно, чтобы сбалансировать точность и эффективность вычислений.

## Пример использования в реальных задачах
Эти методы могут быть использованы в различных областях, таких как:

* **Моделирование физических процессов**: Решение систем дифференциальных уравнений.
* **Финансовые модели**: Оптимизация портфеля инвестиций.
* **Инженерные задачи**: Анализ напряжений и деформаций в конструкциях.