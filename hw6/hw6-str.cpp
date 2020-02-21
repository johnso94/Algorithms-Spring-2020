#include<iostream>
using namespace std;
int main(){
    string s = "hi hi";
    cout << s[1] << endl;  
    cout << "size " << s.size() << endl;
    s = s + " ok";
    cout << s << endl; 
    string s2 = "ji ji";
    cout << (s < s2) << endl;
    return 0;
}
//The + is simply adding to the string. The < operator I think is just
//comparing the first character from each and seeing which has a higher ascii
//value. It returned 1 because j > h so the 1 is true.