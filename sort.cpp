#include <iostream>


void QS(int list[], int head, int tail)
{
	if (head >= tail)
		return;
	int i = head, j = tail;
	int pivot = list[head];
	while (i < j)
	{
		while (i < j and list[j] >= pivot)
			j--;
		list[i] = list[j];
		while (i < j and list[i] <= pivot)
			i++;
		list[j] = list[i];
	}

	list[i] = pivot;

	QS(list, head, i - 1);
	QS(list, j + 1, tail);
}

void BS(int list[], int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		for (int j = 0; j < length - 1 - i; ++j)
		{
			if (list[j] > list[j + 1])
			{
				int temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}

void IS(int list[], int length)
{
	int temp, j;
	for (int i = 1; i < length; ++i)
	{
		temp = list[i];
		j = i - 1;
		for (; j >= 0 and list[j] > temp; j--)
		{
			list[j + 1] = list[j];
		}
		list[j + 1] = temp;
	}
}

void SS(int list[], int length)
{
	int min;

	for (int i = 0; i < length; ++i)
	{
		min = i;
		for (int j = i + 1; j < length; ++j)
		{
			if (list[j] < list[min])
			{
				min = j;
			}
			int temp = list[i];
			list[i] = list[min];
			list[min] = temp;
		}
	}
}

int main(int argc, char const *argv[])
{
	int list[] = {1, 3, 6, 5, 4, 2, 0, 8, 9};
	int length = sizeof(list) / sizeof(*list);
	SS(list, length);
	for (int item1 : list)
	{
		std::cout << item1 << std::endl;
	}
	return 0;
}
