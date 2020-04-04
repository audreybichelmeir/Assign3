#include <iostream>
#include "fileReader.h"

fileReader::fileReader(){

}

fileReader::~fileReader(){

}

string fileReader::filePrompt(string error)
{

  string fileChecker = " ";
  bool isGood = false;

  while(!isGood)
  {
    cout << "Enter file name:" << endl;
    cin >> fileChecker;
    if(fileChecker.length() > 0){
      isGood = true;
    }
  }
  readAFile(fileChecker);
}

string fileReader::readAFile(string file){
  fileReader fr;
  string line = " ";
  int lineCounter = 1; //beginning of a file starts at 1
  fstream inputStream;

  inputStream.open(file);

  if (!inputStream)
  {
    cout << file << " does not exist. " << endl;
    exit(1);
  }

  while(getline(inputStream, line))
  {
    isBalanced(line, lineCounter, store, inputStream);
    //isBalanced(line, lineCounter, store, inputStream, LEFT_ROUND_PARENTHESIS, RIGHT_ROUND_PARENTHESIS, LEFT_CURLY_BRACKETS, RIGHT_CURLY_BRACKETS, LEFT_SQUARE_BRACKETS, RIGHT_SQUARE_BRACKETS);
    ++lineCounter;
  }
  inputStream.close();
}
 void fileReader::isBalanced(string& line, int& lineCounter, GenStack<char>& store, fstream& inputStream)
//void fileReader::isBalanced(string& line, int& lineCounter, GenStack<char>& store, fstream& inputStream, char& LEFT_ROUND_PARENTHESIS, char& RIGHT_ROUND_PARENTHESIS, char& LEFT_CURLY_BRACKETS, char& RIGHT_CURLY_BRACKETS, char& LEFT_SQUARE_BRACKETS, char& RIGHT_SQUARE_BRACKETS)
{
  //cout << line << endl;
  for (int i = 0; i < line.length(); ++i)
  {
    if (line[i] ==  LEFT_ROUND_PARENTHESIS || line[i] ==  LEFT_SQUARE_BRACKETS || line[i] ==  LEFT_CURLY_BRACKETS)
    {
      // Push the element in the stack
      store.push(line[i]);
      continue;
    } // end of if left delimeter statement

    else if (line[i] ==  RIGHT_ROUND_PARENTHESIS || line[i] ==  RIGHT_SQUARE_BRACKETS || line[i] ==  RIGHT_CURLY_BRACKETS)
    {
      //If current current character is not opening bracket, then it must be closing. So stack cannot be empty at this point.
      if (store.isEmpty()){
        cout << "There is an unmatched delimeter at line: " << lineCounter << endl;
          cout << "At position " << i << " " << line[i] << endl;
        exit(1);
      } // end of if isEmpty()
      if(line[i] ==  RIGHT_ROUND_PARENTHESIS && store.peek() == LEFT_ROUND_PARENTHESIS && (!store.isEmpty())){
        store.pop();

        continue;
      }// end of if statement - ()
      else if (line[i] ==  RIGHT_CURLY_BRACKETS && store.peek() == LEFT_CURLY_BRACKETS && (!store.isEmpty())){
        store.pop();

        continue;
      } // end of if statement - {}
      else if (line[i] ==  RIGHT_SQUARE_BRACKETS && store.peek() == LEFT_SQUARE_BRACKETS && (!store.isEmpty())){
        store.pop();

        continue;
      } // end of if statement - []
      else
      {
        cout << "There is an unmatched delimeter at line: " << lineCounter << endl;
        cout << "At position " << i << " is a " << line[i] << " should be a " << Pair(store.peek()) << " instead." << endl;
        exit(1);
      }
    } // end of if right delimeter statement
    // else{
    //   cout << "no delimeter to be found" << endl;
    // }
  }
  if(store.isEmpty()){
    cout << "Perfectly balanced, as things should be" << endl;
  }
  else{
    cout << "End of file: Missing a " << Pair(store.pop()) << endl;
  }
}// end of isBalanced()

char fileReader::Pair(char c){
  if (c == LEFT_ROUND_PARENTHESIS){
    return RIGHT_ROUND_PARENTHESIS;
  }
  if (c == LEFT_SQUARE_BRACKETS){
    return RIGHT_SQUARE_BRACKETS;
  }
  if (c == LEFT_CURLY_BRACKETS){
    return RIGHT_CURLY_BRACKETS;
  }
}
