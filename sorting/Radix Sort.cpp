#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
void radixsort(int a[], int n)
{
	int count[10];
	int output[n];

	//memset converts the value ch to unsigned char
	//and copies it into each of the first n characters
	memset(output, 0, sizeof(output));
	memset(count, 0, sizeof(count));
	int max = 0;

	// Obtaining the maximum value from the given array
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	//finds the max digits in the max value element
	int maxdigits = 0;
	while (max)
	{
		maxdigits++;
		max /= 10;
	}

	for (int j = 0; j < maxdigits; j++)
	{
		//storing count of recurrences in count[]
		for (int i = 0; i < n; i++)
		{
			int t = pow(10, j);
			count[(a[i] % (10 * t)) / t]++;
		}

		int k = 0;

		//rearranging the elements to its exact index position
		//according to the radix and repeats this step upto n times
		//n is maxdigits (maximum number of digit in a element)
		for (int p = 0; p < 10; p++)
		{
			for (int i = 0; i < n; i++)
			{
				int t = pow(10, j);
				if ((a[i] % (10 * t)) / t == p)
				{
					output[k] = a[i];
					k++;
				}
			}
		}
		memset(count, 0, sizeof(count));
		//copy the output[] array to a[]
		for (int i = 0; i < n; ++i)
		{
			a[i] = output[i];
		}

		//now a[] is array with sorted elements
	}
}

//a utility function to print the final sorted list
void print(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

//driver code
int main(int argc, char const *argv[])
{
	//initialize a random array a[]
	int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
	int n = sizeof(a) / sizeof(a[0]);

	//function call
	radixsort(a, n);
	print(a, n);
	return 0;
}
