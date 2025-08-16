#include <stdio.h>

int binary(int x, int v[], int n) /* find x in v[0] ... v[n-1] */
{
  int low, high, mid;

  low = 0;
  high = n - 1;

  while (low <= high)
  {
    mid = (low+high) / 2;
    if (x < v[mid])
      high = mid - 1;

    else if (x > v[mid])
      low = mid + 1;

    else /* found match */
      return (mid);
  }

  return(-1);
}

int main()
{
  int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29};
  int size = sizeof(arr) / sizeof(arr[0]);
  int result = binary(5, arr, size);
  
  if (result != -1)
      printf("Found at index %d\n", result);
  else
      printf("Not found\n");

  return 0;
}