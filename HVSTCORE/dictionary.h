#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_
#include "list.h"

//todo: Implement a clear() method

template <class T, class U>
class dictionary
{
public:
	dictionary(){};
	~dictionary(){};

	void append(T index, U data)
	{
		this->data.add(data);
		this->index.add(index);
		
	}

	void clear(bool clean)
	{
		if (clean)
		{
			for (int i = 0; i < data.count(); i++)
				data.cleanNode(i);

			data.clear();
			index.clear();
		}
	}

	List<T> & Keys()
	{
		return index;
	}

	void remove(T index)
	{
		int index1 = 0, index2 = 0;

		index1 = this->index.indexOf(index);
		this->index.removeAt(index1);
		data.removeAt(index1);
	}

	U & operator[] (T i)
	{
		int index = this->index.indexOf(i);
		return data[index];
	}

	int count()
	{
		return index.count();
	}

private:
	List<U> data;
	List<T> index;

};


#endif