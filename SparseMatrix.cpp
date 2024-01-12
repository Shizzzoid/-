#include "SparseMatrix.h"
#include <iostream>

// Конструктор по умолчанию
SparseMatrix::SparseMatrix() {}

// Конструктор с параметрами

SparseMatrix::SparseMatrix(const std::vector<std::vector<int>>& matrix) 
    :numRows(matrix.size()), numCols(matrix[0].size())
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; ++j)
        {
            if (matrix[i][j] != 0)
            {
                Element element;
                element.row = i;
                element.col = j;
                element.value = matrix[i][j];
                elements.push_back(element);
            }
        }
    }
}

// Конструктор копии
SparseMatrix::SparseMatrix(const SparseMatrix& other) 
{
    elements = other.elements;
}

// Деструктор
SparseMatrix::~SparseMatrix() {}

// Функция вывода на экран
void SparseMatrix::printMatrix()
{
    for (const auto& element : elements)
    {
        std::cout << "(" << element.row << ", " << element.col << "): " << element.value << "\n";
    }
    
    std::cout << std::endl;
}

// Оператор присваивания
SparseMatrix& SparseMatrix::operator=(const SparseMatrix& other) 
{
    if (this != &other) 
    {
        elements.clear();
        elements = other.elements;
    }
    
    return *this;
}

// Оператор сложения
SparseMatrix SparseMatrix::operator+(const SparseMatrix& other) const 
{
    SparseMatrix result;
   
    result.elements = elements;
    result.elements.insert(result.elements.end(), other.elements.begin(), other.elements.end());

    return result;
}

// Оператор вычитания
SparseMatrix SparseMatrix::operator-(const SparseMatrix& other) const 
{
    SparseMatrix result;

    result.elements = elements; 

    for (const auto& elem : other.elements)
    {
        Element negElem = elem;
        negElem.value = -negElem.value;
        result.elements.push_back(negElem);
    }
    
    return result;
}

// Оператор умножения
SparseMatrix SparseMatrix::operator*(int scalar) const 
{
    SparseMatrix result;

    for (const auto& elem : elements)
    {
        Element scaledElem = elem;
        scaledElem.value *= scalar;
        result.elements.push_back(scaledElem);
    }
    
    return result;
}

// Оператор деления на число
SparseMatrix SparseMatrix::operator/(int divisor) const 
{
    if (divisor == 0)
    {
        throw std::invalid_argument("Деление на число невозможно.");
    }
    
    SparseMatrix result; 
    
    for (const auto& elem : elements)
    {
        Element scaledElem = elem;
        scaledElem.value /= divisor;
        result.elements.push_back(scaledElem);
   }
    
    return result;
}

// Оператор сложения с накоплением
SparseMatrix& SparseMatrix::operator+=(const SparseMatrix& other) 
{
    elements.insert(elements.end(), other.elements.begin(), other.elements.end());

    return *this;
}

// Оператор вычитания с накоплением
SparseMatrix& SparseMatrix::operator-=(const SparseMatrix& other) 
{
    for (const auto& elem : other.elements)
    {
        Element negElem = elem;
        negElem.value = -negElem.value;
        elements.push_back(negElem);
    }

    return *this;
}

// Префиксная форма оператора инкремента
SparseMatrix SparseMatrix::operator++() 
{
    for (auto& elem : elements)
    {
        ++elem.value;
    }

    return *this;
}

// Постфиксная форма оператора инкремента
SparseMatrix SparseMatrix::operator++(int) 
{
    SparseMatrix temp(*this);

    for (auto& elem : elements)
    {
        ++elem.value;
    }

    return temp;
}

// Префиксная форма оператора декремента
SparseMatrix SparseMatrix::operator--()
{
    for (auto& elem : elements)
    {
        --elem.value;
    }

    return *this;
}

// Постфиксная форма оператора декремента
SparseMatrix SparseMatrix::operator--(int) 
{
    SparseMatrix temp(*this);

    for (auto& elem : elements)
    {
        --elem.value;
    }

    return temp;
}

// Оператор "меньше"
bool SparseMatrix::operator<(const SparseMatrix& other) const
{
    int sumThis = 0;
    int sumOther = 0;

    for (const auto& elem : elements)
    {
        sumThis += elem.value;
    }

    for (const auto& elem : other.elements)
    {
        sumOther += elem.value;
    }

    return sumThis < sumOther;
}

// Оператор "больше"
bool SparseMatrix::operator>(const SparseMatrix& other) const 
{
    int sumThis = 0;
    int sumOther = 0;

    for (const auto& elem : elements)
    {
        sumThis += elem.value;
    }
    
    for (const auto& elem : other.elements)
    {
        sumOther += elem.value;
    }

    return sumThis > sumOther;
}

// Оператор "равно"
bool SparseMatrix::operator==(const SparseMatrix& other) const 
{
    return elements == other.elements;
}

// Оператор "не равно"
bool SparseMatrix::operator!=(const SparseMatrix& other) const 
{
    return !(operator==(other));
}

// Оператор взятия элемента 
int& SparseMatrix::operator()(int row, int col)
{
    for (auto& elem : elements)
    {
        if (elem.row == row && elem.col == col)
        {
            return elem.value;
        }
    }

    Element newElem;
    newElem.row = row;
    newElem.col = col;
    newElem.value = 0;

    elements.push_back(newElem);

    return elements.back().value;
}

// Оператор взятия элемента для константного объекта
const int& SparseMatrix::operator()(int row, int col) const 
{
    for (const auto& elem : elements)
    {
        if (elem.row == row && elem.col == col)
        {
            return elem.value;
        }
    }

    return 0;
}

// Оператор преобразования к базовому типу 
SparseMatrix::operator int() const 
{
    int sum = 0;
    for (const auto& elem : elements)
    {
        sum += elem.value;
    }

    return sum;
}