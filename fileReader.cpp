#include <iostream>
#include "fileReader.h"

fileReader::fileReader(){

}

fileReader::~fileReader(){

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
        //cout << "a: " << line << endl;
        isBalanced(line, lineCounter, store, inputStream);
        ++lineCounter;
        //cout << "b: " << lineCounter << endl;

      }
    inputStream.close();
}
bool fileReader::isBalanced(string& line, int& lineCounter, GenStack<char>& store, fstream& inputStream)
{
  char x;
  // cout << "c: " << line.size() << endl;
  // cout << "d: " << lineCounter << endl;
  // cout << "e: " << line << endl;
  // Traversing the Expression
  	for (int i = 0; i < line.size(); ++i)
  	{
      // cout << "wtfff" << endl;
      // cout << "f: " << line[i] << endl;
      if (line[i] ==  LEFT_ROUND_PARENTHESIS || line[i] ==  LEFT_SQUARE_BRACKETS || line[i] ==  LEFT_CURLY_BRACKETS)
  		{
        cout << "g: " << line[i] << endl;
        // Push the element in the stack
        store.push(line[i]);
  			continue;
  		}

      // IF current current character is not opening
      // bracket, then it must be closing. So stack
      // cannot be empty at this point.
      if (store.isEmpty())
      return false;

      if(line[i] == RIGHT_ROUND_PARENTHESIS){
        x = store.peek();
  			store.pop();
  			if (x == LEFT_CURLY_BRACKETS || x == LEFT_SQUARE_BRACKETS)
        //error statement should be here
  				return false;
      }

      if(line[i] == RIGHT_SQUARE_BRACKETS){
        x = store.peek();
  			store.pop();
  			if (x == LEFT_ROUND_PARENTHESIS || x == LEFT_CURLY_BRACKETS)
  				return false;
  			break;
      }

      if(line[i] == RIGHT_CURLY_BRACKETS){
        x = store.peek();
        store.pop();
        if (x == LEFT_ROUND_PARENTHESIS || x == LEFT_SQUARE_BRACKETS)
  				return false;
  			break;
      }

    }
    // Check Empty Stack
    return (store.isEmpty());
}
