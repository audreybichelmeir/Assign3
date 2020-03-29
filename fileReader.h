#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Genstack.h"

class fileReader{
public:
  fileReader();
  ~fileReader();
  string readAFile(string file);
  bool isBalanced(string& line, int& lineCounter, GenStack<char>& store, fstream& inputStream);
  GenStack<char> store; // Stack to store the lefts as they occur

private:
  const char LEFT_ROUND_PARENTHESIS = '(';
  const char RIGHT_ROUND_PARENTHESIS = ')';
  const char LEFT_CURLY_BRACKETS = '{';
  const char RIGHT_CURLY_BRACKETS = '}';
  const char LEFT_SQUARE_BRACKETS = '[';
  const char RIGHT_SQUARE_BRACKETS = ']';
};
