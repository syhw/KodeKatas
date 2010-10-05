#include <stdio.h>
#include <string>

using namespace std;

string input, output;

string wrap(const string& input, int cols)
{
	if (input.length() < cols)
		return input;
	else if (input[cols] == ' ')
		return input.substr(0, cols) + string("\n")
			+ wrap(input.substr(cols+1, input.length() - cols), cols);
	else
	{
		int ind = input.find_last_of(" ", cols);
		if (ind == string::npos)
			ind = cols;
		return input.substr(0, ind) + string("\n")
			+ wrap(input.substr(ind+1, input.length() - ind), cols);
	}
	return input;
}

int main(int argc, char* argv[])
{
	input = string("lala alal ala lala");
	printf("input:\n%s,\noutput:\n%s\n", input.c_str(), wrap(input, 5).c_str());
}
