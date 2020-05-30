#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
	ifstream in(argv[1]);
	stringstream out;
	string line, temp;
	int replace_count = 0;

	while (getline(in, line))
	{
		istringstream in_line_stream(line);
		ostringstream out_line_stream;
		while (in_line_stream >> temp)
		{
			if (temp == argv[2])
			{
				temp = argv[3];
				++replace_count;
			}
			out_line_stream << temp << ' ';
		}
		out << out_line_stream.str() << endl;
	}

	in.close();
	ofstream out_file(argv[1], ofstream::trunc);
	out_file << out.str();

	cout << replace_count << " words have been replaced." << endl;

	return 0;
}