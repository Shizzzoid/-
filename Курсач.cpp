#include "SparseMatrix.h"
#include <iostream>
#include <locale>

int main() {
    
    setlocale(LC_ALL, "Rus");

    // Создаем объекты матриц
    SparseMatrix matrix1(
        {
            {0, 0, 3, 0, 4},
            {0, 0, 5, 7, 0},
            {0, 0, 0, 0, 0},
            {0, 2, 6, 0, 0}
        });

    SparseMatrix matrix2(
        {
            {0, 1, 0, 0, 0},
            {2, 0, 0, 0, 3},
            {0, 0, 4, 0, 0},
            {0, 0, 0, 0, 5}
        });

    // Выводим матрицы
    std::cout << "Matrix 1:" << std::endl;
    matrix1.printMatrix();

    std::cout << "\nMatrix 2:" << std::endl;
    matrix2.printMatrix();

    // Взаимодействие с пользователем
    int sumMatrix1;
    int choice;
    SparseMatrix result;

    do {
        // Вывод меню
        std::cout << "\nВыберите действие:\n";
        std::cout << "1. Сложить матрицы\n";
        std::cout << "2. Вычесть матрицы\n";
        std::cout << "3. Умножить матрицу на число\n";
        std::cout << "4. Поделить матрицу на число\n";
        std::cout << "5. Сравнить матрицы\n";
        std::cout << "6. Префиксный инкремент матрицы 1\n";
        std::cout << "7. Постфиксный инкремент матрицы 1\n";
        std::cout << "8. Префиксный декремент матрицы 2\n";
        std::cout << "9. Постфиксный декремент матрицы 2\n";
        std::cout << "10. Сравнить сумму элементов матрицы 1 и матрицы 2\n";
        std::cout << "11. Получить и изменить элемент матрицы 1\n";
        std::cout << "12. Преобразовать матрицу 1 в сумму элементов\n";
        std::cout << "13. Выйти из программы\n";
        std::cout << "Введите номер выбранного действия: ";

        // Ввод выбора пользователя
        std::cin >> choice;

        // Выполнение выбранной операции
        switch (choice) 
        {
        case 1:
            result = matrix1 + matrix2;
            std::cout << "\nМатрица 1 + Матрица 2:" << std::endl;
            result.printMatrix();
            break;

        case 2:
            result = matrix1 - matrix2;
            std::cout << "\nМатрица 1 - Матрица 2:" << std::endl;
            result.printMatrix();
            break;

        case 3:
            int scalar;
            std::cout << "Введите число для умножения: ";
            std::cin >> scalar;
            result = matrix1 * scalar;
            std::cout << "\nМатрица 1 * " << scalar << ":" << std::endl;
            result.printMatrix();
            break;

        case 4:
            int divisor;
            std::cout << "Введите число для деления: ";
            std::cin >> divisor;
            try {
                result = matrix2 / divisor;
                std::cout << "\nМатрица 2 / " << divisor << ":" << std::endl;
                result.printMatrix();
            }
            catch (const std::invalid_argument& e) {
                std::cerr << "Ошибка: " << e.what() << std::endl;
            }
            break;

        case 5:
            if (matrix1 < matrix2) {
                std::cout << "\nМатрица 1 меньше Матрицы 2." << std::endl;
            }
            else if (matrix1 > matrix2) {
                std::cout << "\nМатрица 1 больше Матрицы 2." << std::endl;
            }
            else {
                std::cout << "\nМатрица 1 равна Матрице 2." << std::endl;
            }
            break;

        case 6:
            std::cout << "\nПрефиксный инкремент Матрицы 1: " << std::endl;
            ++matrix1;
            matrix1.printMatrix();
            break;

        case 7:
            std::cout << "\nПостфиксный инкремент Матрицы 1: " << std::endl;
            result = matrix1++;
            result.printMatrix();
            break;

        case 8:
            std::cout << "\nПрефиксный декремент Матрицы 2: " << std::endl;
            --matrix2;
            matrix2.printMatrix();
            break;

        case 9:
            std::cout << "\nПостфиксный декремент Матрицы 2:" << std::endl;
            result = matrix2--;
            result.printMatrix();
            break;

        case 10:
            if (static_cast<int>(matrix1) < static_cast<int>(matrix2)) 
            {
                std::cout << "\nСумма элементов Matrix 1 меньше суммы элементов Matrix 2." << std::endl;
            }
            else if (static_cast<int>(matrix1) > static_cast<int>(matrix2)) 
            {
                std::cout << "\nСумма элементов Matrix 1 больше суммы элементов Matrix 2." << std::endl;
            }
            else 
            {
                std::cout << "\nСумма элементов Matrix 1 равна сумме элементов Matrix 2." << std::endl;
            }
            break;

        case 11:
            int row, col;
            std::cout << "\nВведите координаты элемента (строка и столбец): ";
            std::cin >> row >> col;
            std::cout << "\nЭлемент Matrix 1 с координатами (" << row << ", " << col << "): " << matrix1(row, col) << std::endl;
            matrix1(row, col) = 10; // Изменение значения элемента
            std::cout << "\nОбновленная Matrix 1:" << std::endl;
            matrix1.printMatrix();
            break;

        case 12:
            sumMatrix1 = static_cast<int>(matrix1);
            std::cout << "\nСумма всех элементов Matrix 1: " << sumMatrix1 << std::endl;
            break;

        case 13:
            std::cout << "Выход из программы." << std::endl;
            break;

        default:
            std::cout << "Неверный выбор. Повторите ввод." << std::endl;
            break;
        }

    } while (choice != 13);

    return 0;
}
