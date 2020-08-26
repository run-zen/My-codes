#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd_fast(long long  a ,long long b)  {
  if (b== 0)
    return a;
  else
  {
    a = a % b;
    return gcd_fast(b,a);
  }
  
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << ((long long)a*b)/gcd_fast(a,b) << std::endl;
  system("pause");
  return 0;
}
