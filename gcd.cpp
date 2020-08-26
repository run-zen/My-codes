#include <iostream>
//#include <cstdlib>

/*long long gcd_naive(long long a, long long b) {
  long long current_gcd = 1;
  if(a==0 && b==0) 
    return 0;
  long long c= a+b;
  for (int d = 2; d <= c; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}*/
long long gcd_fast(long long a, long long b)  {
  if (b== 0)
    return a;
  else
  {
    a = a%b;
    return gcd_fast(b,a);
  }
  
}
int main() {
  /*while(true) {
      long long a = rand()%10;
      long long b = rand()%10;
      std::cout <<a<<"  "<<b<< std::endl;
      long long rs1 = gcd_naive(a,b);
      long long rs2 = gcd_fast(a,b);
      if (rs1!=rs2){
        std::cout<<"wrong answer: "<<rs1<<" "<<rs2<< std::endl;
        break;      
      }
      else
      {
        std::cout<<"OK"<<std::endl;
      }
      
  } */ 
  long long a, b;
  std::cin >> a >> b;
  //std::cout << gcd_naive(a, b) << std::endl;
  std::cout <<gcd_fast(a,b)<< std::endl;
  system("pause");
  return 0;
}
