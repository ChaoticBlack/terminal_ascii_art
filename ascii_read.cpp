#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
#include <array>
#include <map>
#include <regex> 
#include <iterator> 
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


void clearScreen(void) {
  // Tested and working on Ubuntu and Cygwin
  #if defined(OS_WIN)
    HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = { 0, 0 };

    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    GetConsoleScreenBufferInfo( hStdOut, &csbi );
    cellCount = csbi.dwSize.X *csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    FillConsoleOutputCharacter(hStdOut, (TCHAR) ' ', cellCount, homeCoords, &count);

    /* Fill the entire buffer with the current colors and attributes */
    FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count);

    SetConsoleCursorPosition( hStdOut, homeCoords );

  #elif defined(OS_LINUX) || defined(OS_MAC)
    cout << "\033[2J;" << "\033[1;1H"; // Clears screen and moves cursor to home pos on POSIX systems
  #endif

}

int main()
{
	char n;
	cout<<"Select the pattern you want to see: Kaleidoscope or Liquid Fireworks"<<endl;
	cout<<"Press 1 for Kaleidoscope, press 2 for Liquid Fireworks"<<endl;
	cin>>n;
	if(n=='1')
	{
		int i =0;
		while(1)
		{
			string fileNumber = to_string(i);
			string filename = "Kaleidoscope/"+fileNumber+".txt";
			ifstream file(filename);
			string word;
			while(getline(file,word))
			{
				cout<<word<<endl;
			}
			usleep(100000);
	        clearScreen();
			//i++;
			if(i==30)
				i=0;
			i++;
		}
	}
	else if(n== '2')
	{
		int i =0;
		while(1)
		{
			string fileNumber = to_string(i);
			string filename = "Liquid_Fireworks/"+fileNumber+".txt";
			ifstream file(filename);
			string word;
			while(getline(file,word))
			{
				cout<<word<<endl;
			}
			usleep(100000);
        	clearScreen();
			//i++;
			if(i==37)
				i=0;
			i++;
		}
	}
	else
		cout<<"You Trickster, next time, please enter a valid input!"<<endl;
	return 0;
}




	// int i =0;
	// while(1)
	// {
	// 	string fileNumber = to_string(i);
	// 	string filename = "pattern/"+fileNumber+".txt";
	// 	ifstream file(filename);
	// 	string word;
	// 	while(getline(file,word))
	// 	{
	// 		cout<<word<<endl;
	// 	}
	// 	usleep(100000);
 //        clearScreen();
	// 	//i++;
	// 	if(i==30)
	// 		i=0;
	// 	i++;
	// }

//loop the folder to open each file
