#include<iostream>
using namespace std;
#include<stdlib.h>
#include <list>
#include"elapsed_time.h"

int main()
{
  int n = 1000;
  int i = 0;
  std::list<int> List;
  while(i < n){
      List.push_back(rand()%1000000000);
      i++;
  }
  std::list<int> sorted;
  int i = 0;
  list<int>::iterator iter = List.begin();
  while(iter != List.end()){
      if(*iter % 2 == 1){
          sorted.push_back(*iter);
          }
      else{
          sorted.push_front(*iter);
      }
        iter++;
    }
    return 0;
    int num_iters;
    cin >> num_iters;

    start_timer(); // this function is from elapsed_time.h
    double a = 1.0;
    for ( int i = 0; i < num_iters; ++i ) a += 2.0;
    double cycles = elapsed_time();  // also from elapsed_time.h

    cout << " Total cycles: " << cycles << endl;
}
