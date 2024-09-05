//Name: Tadeo Gomez
//Date: 9/4/2024
//CMPS 455 Compiler Design
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	fstream myFile;
	myFile.open("Lexical.txt", ios::in);  // ios::in is for read only and ios::out is to write in a file
	if (myFile.is_open())
	{

		string word = "", line;
		while (getline(myFile, line))
		{
			for (char letter : line) // for each charcter in a line of text
			{
				if (isalnum(letter)) //if the char is a letter add to word
				{
					word += letter;
				}
				else
				{
					if (!word.empty()) //if the char is no longer a letter and word is not empty, then display the word
					{
						cout << word << endl;
						word.clear();  //delete the letters in word (reset)
					}
					if (!isspace(letter))//char is not a letter so check to see if it is a space
					{
						cout << letter << endl; // if its not a space we display that charcter
					}

				}


			}
			if (!word.empty())
			{
				cout << word << endl;
				word.clear();
			}
		}
		myFile.close();
	}
	system("pause");
	return 0;
}