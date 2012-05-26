#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "list.h"

template <class T>
class matrixNode
{
public:
	matrixNode()
	{
		bottom = 0;
		top = 0;
		left = 0;
		right = 0;
		data = 0;
	}
	matrixNode(T & data, bool shallow = false)
	{
		bottom = 0;
		top = 0;
		left = 0;
		right = 0;
		if (!shallow)
		{
			this->data = new T;
			this->*data = data; 
		}
		else
			this->data = data;

		_shallow = shallow;
	}

	~matrixNode()
	{
		if (_shallow)
			delete data;
	}

	matrixNode<T> * bottom;
	matrixNode<T> *  top;
	matrixNode<T> *  left;
	matrixNode<T> *  right;
	T * data;

private:
	bool _shallow;
};

template <class T>
class matrix
{
public:
	matrix()
	{
		_firstNode = 0;
		_currentNode = 0;
		_lastNode = 0;
		_m = 0;
		_n = 0;
	}
	matrix(int m, int n)
	{
		_firstNode = 0;
		_currentNode = 0;
		_lastNode = 0;
		_m = m;
		_n = n;
	}
	~matrix(){};

	void add(T &data, int m, int n)
	{
		_currentNode = _firstNode;
		for (int x = 0; x < n; x++)
		{
			_currentNode = _currentNode->right;
		}

		for (int y = 0; y < m; y++)
		{
			_currentNode = _currentNode->bottom;
		}

		if (_currentNode != 0)
			_currentNode->data = data;
	}

	
private:
	int _m;
	int _n;

	//first and last nodes refer to the first row
	matrixNode<T> * _firstNode;
	matrixNode<T> * _currentNode;
	matrixNode<T> * _lastNode;
	

};

#endif