//hashing with chaining


#include <bits/stdc++.h>

using namespace std;

class Hash
{
     int BUCKET;

     list<int> *table;

public:
     Hash(int V);

     void insertItem(int X);

     void deleteItem(int key);

     int hashfunction(int x) {
          return (x % BUCKET);
     }

     void displayHash();
};

Hash::Hash(int b) {
     BUCKET = b;
     table = new list <int>[BUCKET];
}

void Hash::insertItem(int x) {
     int index = hashfunction(x);
     table[index].push_back(x);
}

void Hash::deleteItem(int x) {
     int index = hashfunction(x);

     list <int> :: iterator i;
     for(i=table[index].begin(); i!= table[index].end(); i++) {
          if(*i == x)
               break;
     }
     if(i != table[index].end()) {
          table[index].erase(i);
     }
}

void Hash::displayHash() {
     for(int i=0;i<BUCKET;i++) {
          cout <<i;
          for (auto x : table[i]) {
               cout<<" --> " << x;
          }
          cout<< endl;
     }
}

int main() {

     int a[] = {15, 11, 27, 8, 12, 5, 7, 9, 8, 22};
     int n = sizeof(a)/sizeof(a[0]);

     // insert the keys into the hash table
     Hash h(7);   // 7 is count of buckets in
               // hash table
     for (int i = 0; i < n; i++)
     h.insertItem(a[i]);

     cout<< "Before deletion :"<< endl;
     h.displayHash();

     // delete 12 from hash table
     h.deleteItem(12);

     // display the Hash table
     cout<< "After deletion :"<< endl;
     h.displayHash();

     return 0;
}
