#pragma once
#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <iostream>
#include <vector>

class SparseMatrix
{
private:
	struct Element
	{
		int row;
		int col;
		int value;

        bool operator==(const Element& other) const
        {
            return row == other.row && col == other.col && value == other.value;
        }

        bool operator!=(const Element& other) const
        {
            return !(*this == other);
        }

    };

	std::vector<Element> elements;//вектор для хранения ненулевых элементов матрицы

    int numRows;
    int numCols;

public: 
    //конструкторы
	SparseMatrix();//по умолчанию 
	SparseMatrix(const std::vector<std::vector<int>>& matrix);//с параметрами
	SparseMatrix(const SparseMatrix& other);//копии

	~SparseMatrix();//деструктор 

	void printMatrix();//вывод на экран

    //операторы
    SparseMatrix& operator=(const SparseMatrix& other);//присваивания
   
    SparseMatrix operator+(const SparseMatrix& other) const;//бинарные опираторы
    SparseMatrix operator-(const SparseMatrix& other) const;
    SparseMatrix operator*(int scalar) const;
    SparseMatrix operator/(int divisor) const;
    
    SparseMatrix& operator+=(const SparseMatrix& other);//арифметика с накоплением
    SparseMatrix& operator-=(const SparseMatrix& other);
    
    SparseMatrix operator++();    // префиксная форма
    SparseMatrix operator++(int); // постфиксная форма
    SparseMatrix operator--();    // префиксная форма
    SparseMatrix operator--(int); // постфиксная форма
    
    bool operator<(const SparseMatrix& other) const;//логические операторы 
    bool operator>(const SparseMatrix& other) const;
    bool operator==(const SparseMatrix& other) const;
    bool operator!=(const SparseMatrix& other) const;

    int& operator()(int row, int col);//операторы взязтия элемента 
    const int& operator()(int row, int col) const;

    operator int() const;//операторы преобразования типа

};

#endif // SPARSEMATRIX_H#pragma once
#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <iostream>
#include <vector>

class SparseMatrix
{
private:
	struct Element
	{
		int row;
		int col;
		int value;
	};

	std::vector<Element> elements;//вектор для хранения ненулевых элементов матрицы

    int numRows;
    int numCols;

public: 
    //конструкторы
	SparseMatrix();//по умолчанию 
	SparseMatrix(const std::vector<std::vector<int>>& matrix);//с параметрами
	SparseMatrix(const SparseMatrix& other);//копии

	~SparseMatrix();//деструктор 

	void printMatrix();//вывод на экран

    //операторы
    SparseMatrix& operator=(const SparseMatrix& other);//присваивания
   
    SparseMatrix operator+(const SparseMatrix& other) const;//бинарные опираторы
    SparseMatrix operator-(const SparseMatrix& other) const;
    SparseMatrix operator*(int scalar) const;
    SparseMatrix operator/(int divisor) const;
    
    SparseMatrix& operator+=(const SparseMatrix& other);//арифметика с накоплением
    SparseMatrix& operator-=(const SparseMatrix& other);
    
    SparseMatrix operator++();    // префиксная форма
    SparseMatrix operator++(int); // постфиксная форма
    SparseMatrix operator--();    // префиксная форма
    SparseMatrix operator--(int); // постфиксная форма
    
    bool operator<(const SparseMatrix& other) const;//логические операторы 
    bool operator>(const SparseMatrix& other) const;
    bool operator==(const SparseMatrix& other) const;
    bool operator!=(const SparseMatrix& other) const;

    int& operator()(int row, int col);//операторы взязтия элемента 
    const int& operator()(int row, int col) const;

    operator int() const;//операторы преобразования типа

};

#endif // SPARSEMATRIX_H