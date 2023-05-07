#include <iostream>
#include <cassert>

int const* array_max_sum_segment(int const * begin, int const * end, unsigned segment_length);

bool test1() {
  unsigned const size = 10;
	int arr[size] = {1, 2, 3, 2, 4, -2, 1, 0, 5, 1};
  unsigned const segment_length = 4;
  int *expected = arr + 1;
  auto actual = array_max_sum_segment(arr, arr + size, segment_length);
  return expected == actual;
}

bool test2() {
	unsigned const size = 10;
	int arr[size] = {1, 1, 1, 2, 1, 1, 2, 1, 1, 2};
  unsigned const segment_length = 4;
  int *expected = arr + 3;
  auto actual = array_max_sum_segment(arr, arr + size, segment_length);
  return expected == actual;
}

bool test3() {
	unsigned const size = 10;
	int arr[size] = {-1, -3, -1, -2, -3, -1, -2, -3, -1, -2};
  unsigned const segment_length = 4;
  int *expected = arr;
  auto actual = array_max_sum_segment(arr, arr + size, segment_length);
  return expected == actual;
}

int const* array_max_sum_segment(int const * begin, int const * end, unsigned segment_length)
{
    int sum = 0;
    
    for (unsigned i = 0; i < segment_length; i++)
    {
        sum += begin[i];
    }
    
    int const * left = begin;
    int const* right = begin + segment_length;
    
    int max_sum = sum;
    int const* current = left;
    
    for (unsigned i = segment_length; begin + i < end; i++)
    {
        sum += *right++;
        sum -= *left++;
        
        if (sum > max_sum)
        {
            current = left;
            max_sum = sum;
        }
        
    }
    return current;
}

int main() {
  assert(test1());
  assert(test2());
  assert(test3());
	return 0;
}