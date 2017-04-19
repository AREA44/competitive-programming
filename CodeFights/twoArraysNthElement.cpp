// Given two sorted arrays of integers and an integer n, find the nth (0-based) element of their sorted union.
// Example
// * For array1 = [1, 3, 4], array2 = [2, 6, 8] and n = 5, the output should be
// twoArraysNthElement(array1, array2, n) = 8.

typedef std::vector<int> vect;

int twoArraysNthElement(vect array1, vect array2, int n) {

  struct Helper {
    int lowerBound(vect arr, int elem) {
      int l = -1;
      int r = arr.size();
      while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (arr[mid] <= elem) {
          l = mid;
        }
        else {
          r = mid;
        }
      }
      return l;
    }
  };

  int l = -1;
  int r = array1.size();

  Helper h;

  while (l + 1 < r) {
    int mid = (l + r) / 2;
    int pos = h.lowerBound(array2, array1[mid]);

    if (mid + pos + 1 <= n) {
      l = mid;
    }
    else {
      r = mid;
    }
  }

  if (l > -1 && l + h.lowerBound(array2, array1[l]) + 1 == n) {
    return array1[l];
  }
  return twoArraysNthElement(array2, array1, n);
}
