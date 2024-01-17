#include <algorithm>
#include <iostream>
#include <random>
#include <unistd.h>

using namespace std;

template <typename T> void embaralhamento(T a[], int n) {
  random_device rd;
  mt19937 g(rd());
  shuffle(a, a + n, g);
  return;
}

int main() {

  int a[] = {1, 2, 3, 4, 5};
  string b[] = {"Christian", "Kern", "Pires", "dos", "Santos"};
  float c[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  double d[] = {1.11, 2.22, 3.33, 4.44, 5.55};
  char e[] = {'a', 'b', 'c', 'd', 'e'};
  long long f[] = {1, 2, 3, 4, 5};
  int n = 5;
  cout << "Embaralhado:... " << endl;
  sleep(3);
  embaralhamento(a, 5);
  embaralhamento(b, 5);
  embaralhamento(c, 5);
  embaralhamento(d, 5);
  embaralhamento(e, 5);
  embaralhamento(f, 5);

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < n; i++) {
    cout << c[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < n; i++) {
    cout << d[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < n; i++) {
    cout << e[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < n; i++) {
    cout << f[i] << " ";
  }
  cout << endl;

  return 0;
}
