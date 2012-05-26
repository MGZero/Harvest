#ifndef _graph_h_
#define _graph_h_

#include "list.h"


template <class T>
class graphNode
{
public:
	graphNode(T data)
	{
		_data = data;
	}

	virtual ~graphNode()
	{
		for (int i = 0; i < _neighbors.count(); i++)
		{
			_neighbors.cleanNode(i);
		}

		_neighbors.clear();
	}

	void addNeighbor(graphNode<T>* neighbor)
	{
		_neighbors.add(neighbor);
	}

	graphNode * popNeighbor(int index)
	{
		graphNode<T> * temp = _neighbors[index];
		_neighbors.remove(index);
		return temp;
	}

	void removeNeighbor(int index)
	{
		_neighbors.remove(index);
	}

	void removeNeighbor(graphNode<T>* neighbor)
	{
		_neighbors.remove(neighbor);
	}

	graphNode * getNeighbor(int index)
	{
		return _neighbors[index];
	}

	int neighborCount()
	{
		return _neighbors.count();
	}

private:
	List<graphNode<T>*> _neighbors;
	T _data;

};

template <class T>
class graph
{
public:
	graph()
	{
		_root = 0;
		current = 0;
		_nodeCount = 0;
	}

	virtual ~graph()
	{
		current = 0;
		delete _root;
	}

	void initGraph(graphNode<T> * root)
	{
		_root = root;
		current = root;
		_nodeCount = 1;
	}

	graphNode<T> * current;

private:
	graphNode<T> * _root;
	int _nodeCount;



};


#endif