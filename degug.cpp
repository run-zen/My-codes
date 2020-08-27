#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>


long long MaxPairwiseProductFast(std::vector<int>& numbers) {
  long long result = 0;
  int n = numbers.size();

  int index1 = -1;
  for(int i = 0;i<n;i++){
    if((index1 == -1)||(numbers[i] > numbers[index1]))
      index1 = i;
  }
  result = numbers[index1];
  numbers[index1] = 0;
  int index2 = -1;

  for(int j=0;j<n;j++){
    if((j != index1)&&((index2 == -1)||(numbers[j]>numbers[index2])))
      index2 = j;
  }
  std::cout<<"\n"<<result<<"  "<<numbers[index2]<<"  "<<index2<<"\n";
  result = result*numbers[index2];
  return result;
}

int main(){
  int n;
  std::cin >> n;
  std::vector<int> numbers(n);
  for (int i = 0; i < n; ++i) {
      std::cin >> numbers[i];
  }

  long long result = MaxPairwiseProductFast(numbers);
  std::cout << result << "\n";
  return 0;
}
