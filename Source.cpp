#include<iostream>
#include<ctime>

class Array
{
	int* arr;
	int size = 0;
	
public:
	Array()
	{
		size = 1;
		arr = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}
	Array(int size)
	{
		this->size = size;
		arr = new int[size];
		SetArray();
	}	
	Array(const Array& source) //конструктор копирования
	{
		size = source.size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = source.arr[i];
	}
	void SetArray()
	{
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = rand() % 20 - 10;
		}
	}
	void ShowArray()
	{
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
	void Sort()
	{
		int tmp;
		for (size_t i = 0; i < size; i++)
		{
			tmp = arr[i];
			for (size_t j = 0; j < size; j++)
			{
				if (tmp > arr[j]) 
				{
					tmp = arr[j];
					arr[j] = arr[i];
					arr[i] = tmp;
				}
			}
		}
	}
	int MinElem()
	{
		Sort();
		return arr[size - 1];
	}
	int MaxElem()
	{
		Sort();
		return arr[0];
	}
	
	~Array()
	{
		delete[] arr;
	}
};
int main()
{
	srand(static_cast<int>(time(0)));

	int SIZE;
	std::cout << "Enter size of array: ";
	std::cin >> SIZE;

	Array array1(SIZE);

	

	std::cout << "Array:" << std::endl;
	array1.ShowArray();

	Array array2(array1);
	std::cout << "Copied array: " << std::endl;
	array2.ShowArray();

	array1.Sort();
	std::cout << "Sorted array: " << std::endl;
	array1.ShowArray();

	std::cout << "Min element of array: " << array1.MinElem() << std::endl;
	std::cout << "Max element of array: " << array1.MaxElem() << std::endl;

	
	return 0;
}
