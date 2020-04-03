#include "fileReader.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{

string file = " ";
string error = "Looks like the user did not input a file name in the command line... Yikes";

  if(argc > 1){
    file = argv[1];
    fileReader *fr = new fileReader();
    fr->readAFile(file);
    delete fr;
  }
  else{
    cout << error << endl;

    fileReader *fr = new fileReader();
    fr->filePrompt(error);
    delete fr;


  }

  return 0;
}
