#include "fileReader.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  string error = "error";
  string file = " ";
  if (argc > 1)
  {
    file = argv[1];
    fileReader *fr = new fileReader();
    fr->readAFile(file);
    delete fr;
  }
  else{
    fileReader *fr = new fileReader();
    fr->filePrompt(error);
    delete fr;
  }

  while (true)
  {
    string user = " ";
    string input = " ";
    cout << "Do you want to enter another file (Y/N)" << endl;
    cin >> user;
    if (user != "Y")
    {
      break;
    }
    else
    {
      cout << "Please enter a filename: " << endl;
      cin >> input;
      fileReader *fr = new fileReader();
      fr->readAFile(input);
      delete fr;
    }
  }
  return 0;
}
