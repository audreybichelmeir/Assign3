#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "GenStack.h"

class fileReader{
public:
  fileReader();
  ~fileReader();
  char Pair(char c);
  void filePrompt(string error);
  void readAFile(string file);
  void isBalanced(string& line, int& lineCounter, GenStack<char>& store, fstream& inputStream);
  //void isBalanced(string& line, int& lineCounter, GenStack<char>& store, fstream& inputStream, char& LEFT_ROUND_PARENTHESIS, char& RIGHT_ROUND_PARENTHESIS, char& LEFT_CURLY_BRACKETS, char& RIGHT_CURLY_BRACKETS, char& LEFT_SQUARE_BRACKETS, char& RIGHT_SQUARE_BRACKETS);
  GenStack<char> store; // Stack to store the lefts as they occur

private:
  static const char LEFT_ROUND_PARENTHESIS = '(';
  static const char RIGHT_ROUND_PARENTHESIS = ')';
  static const char LEFT_CURLY_BRACKETS = '{';
  static const char RIGHT_CURLY_BRACKETS = '}';
  static const char LEFT_SQUARE_BRACKETS = '[';
  static const char RIGHT_SQUARE_BRACKETS = ']';

  // const char LEFT_ROUND_PARENTHESIS = '(';
  // const char RIGHT_ROUND_PARENTHESIS = ')';
  // const char LEFT_CURLY_BRACKETS = '{';
  // const char RIGHT_CURLY_BRACKETS = '}';
  // const char LEFT_SQUARE_BRACKETS = '[';
  // const char RIGHT_SQUARE_BRACKETS = ']';
  //
  // static  char LEFT_ROUND_PARENTHESIS = '(';
  // static  char RIGHT_ROUND_PARENTHESIS = ')';
  // static  char LEFT_CURLY_BRACKETS = '{';
  // static  char RIGHT_CURLY_BRACKETS = '}';
  // static  char LEFT_SQUARE_BRACKETS = '[';
  // static  char RIGHT_SQUARE_BRACKETS = ']';

  // char LEFT_ROUND_PARENTHESIS = '(';
  // char RIGHT_ROUND_PARENTHESIS = ')';
  // char LEFT_CURLY_BRACKETS = '{';
  // char RIGHT_CURLY_BRACKETS = '}';
  // char LEFT_SQUARE_BRACKETS = '[';
  // char RIGHT_SQUARE_BRACKETS = ']';


};
