#include<stdio.h>

int main() {
     int arr[9] = {0};

     for(int i=0;i<9;i++) {
          if (i%3 == 0)
               printf("\n");
          printf("%d  ", arr[i]);
     }

     return 0;
}
