#include <stdio.h>
#include <string>
#include <iostream>

#define WRAP_WIDTH 5

using namespace std;

string input, output;

string wrap(const string& input, int cols)
{
	if (input.length() < cols)
		return input;
	else if (input[cols - 1] == ' ')
		return input.substr(0, cols) + string("\n")
			+ wrap(input.substr(cols, input.length() - cols), cols);
	else
	{
		int ind = input.find_last_of(" ", cols);
		if (ind == string::npos)
            ind = cols;
        if (ind != cols)
            ++ind;
        return input.substr(0, ind) + string("\n")
            + wrap(input.substr(ind, input.length() - ind), cols);
	}
	return input;
}

int main(int argc, char* argv[])
{
    while(cin) {
        getline(cin, input);
        printf("input:\n%s,\noutput:\n%s\n", input.c_str(), 
                wrap(input, WRAP_WIDTH).c_str());
    }
}
