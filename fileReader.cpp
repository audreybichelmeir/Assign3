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
    ++lineCounter;
  }
  inputStream.close();
}
 void fileReader::isBalanced(string& line, int& lineCounter, GenStack<char>& store, fstream& inputStream)
{
  cout << line << endl;
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
      // If current current character is not opening bracket, then it must be closing. So stack cannot be empty at this point.
      if (store.isEmpty()){
        //cout << "Missing an open delimeter of " << store.peek() << endl;
        continue;
        cout << "Missing an open delimiter at line " << lineCounter << endl;
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
        exit(1);
      }
    } // end of if right delimeter statement
    else{
      cout << "no delimeter to be found " << endl;
    }
  }
}
