#include<iostream>
using namespace std;

#include"elapsed_time.h"

void recursion(int n)
{
  double x = 2 * 3;
  for ( int i = 0; i < n; ++i ) {
    for ( int j = 0; j < n/2; ++j ) {
      for ( int k = 0; k < n; ++k ) {
        x = 5*x - 4;
      }
    }
  }
 
  if (n > 0)
    recursion(n/3);
}


int main(){
    int n = 100;
    
    start_timer(); // this function is from elapsed_time.h
    recursion(n);
    double cycles = elapsed_time();  // also from elapsed_time.h

    cout << " Total cycles: " << cycles << endl;
    return 0;
}
