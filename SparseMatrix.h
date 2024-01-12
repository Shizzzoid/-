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

	std::vector<Element> elements;//������ ��� �������� ��������� ��������� �������

    int numRows;
    int numCols;

public: 
    //������������
	SparseMatrix();//�� ��������� 
	SparseMatrix(const std::vector<std::vector<int>>& matrix);//� �����������
	SparseMatrix(const SparseMatrix& other);//�����

	~SparseMatrix();//���������� 

	void printMatrix();//����� �� �����

    //���������
    SparseMatrix& operator=(const SparseMatrix& other);//������������
   
    SparseMatrix operator+(const SparseMatrix& other) const;//�������� ���������
    SparseMatrix operator-(const SparseMatrix& other) const;
    SparseMatrix operator*(int scalar) const;
    SparseMatrix operator/(int divisor) const;
    
    SparseMatrix& operator+=(const SparseMatrix& other);//���������� � �����������
    SparseMatrix& operator-=(const SparseMatrix& other);
    
    SparseMatrix operator++();    // ���������� �����
    SparseMatrix operator++(int); // ����������� �����
    SparseMatrix operator--();    // ���������� �����
    SparseMatrix operator--(int); // ����������� �����
    
    bool operator<(const SparseMatrix& other) const;//���������� ��������� 
    bool operator>(const SparseMatrix& other) const;
    bool operator==(const SparseMatrix& other) const;
    bool operator!=(const SparseMatrix& other) const;

    int& operator()(int row, int col);//��������� ������� �������� 
    const int& operator()(int row, int col) const;

    operator int() const;//��������� �������������� ����

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

	std::vector<Element> elements;//������ ��� �������� ��������� ��������� �������

    int numRows;
    int numCols;

public: 
    //������������
	SparseMatrix();//�� ��������� 
	SparseMatrix(const std::vector<std::vector<int>>& matrix);//� �����������
	SparseMatrix(const SparseMatrix& other);//�����

	~SparseMatrix();//���������� 

	void printMatrix();//����� �� �����

    //���������
    SparseMatrix& operator=(const SparseMatrix& other);//������������
   
    SparseMatrix operator+(const SparseMatrix& other) const;//�������� ���������
    SparseMatrix operator-(const SparseMatrix& other) const;
    SparseMatrix operator*(int scalar) const;
    SparseMatrix operator/(int divisor) const;
    
    SparseMatrix& operator+=(const SparseMatrix& other);//���������� � �����������
    SparseMatrix& operator-=(const SparseMatrix& other);
    
    SparseMatrix operator++();    // ���������� �����
    SparseMatrix operator++(int); // ����������� �����
    SparseMatrix operator--();    // ���������� �����
    SparseMatrix operator--(int); // ����������� �����
    
    bool operator<(const SparseMatrix& other) const;//���������� ��������� 
    bool operator>(const SparseMatrix& other) const;
    bool operator==(const SparseMatrix& other) const;
    bool operator!=(const SparseMatrix& other) const;

    int& operator()(int row, int col);//��������� ������� �������� 
    const int& operator()(int row, int col) const;

    operator int() const;//��������� �������������� ����

};

#endif // SPARSEMATRIX_H