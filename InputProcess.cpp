/*
 #include <iostream>
 using namespace std;
 ...
 // numbers
 int n;
 while (cin >> n)
 {
 ...
 }
 // lines
 string line;
 while (getline(cin, line))
 {
 ...
 }
 // characters
 char c;
 while (cin.get(c))
 {
 ...
 }
 
 
 // Iterators
 // don't skip the whitespace while reading
 std::cin >> std::noskipws;
 // use stream iterators to copy the stream to a string
 std::istream_iterator<char> it(std::cin);
 std::istream_iterator<char> end;
 std::string results(it, end);
 std::cout << results;
 
 
 // Seperate input lines
 #include <iostream>
 #include <sstream>
 using namespace std;
 string buffer;
 getline(cin, buffer);
 istringstream buffer2(buffer);
 while (buffer2>>n) {}
 
*/
