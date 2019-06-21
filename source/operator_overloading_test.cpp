#include <iostream>
#include <fstream>

class streamIt
{
	public:
	streamIt() 
	{ 
		ofs.open("test.txt"); 
		if(ofs.is_open())
		{
			std::cout << "file is okay to write" << std::endl;
		}
		else
		{
			std::cout << "file is not okay write" << std::endl; 
		}

	}
	~streamIt() {}

	template <typename T> friend std::ofstream &operator <<(streamIt &s, T val)
	{
		s.ofs << val;
		return s.ofs;
	}
	private:
	std::ofstream ofs;
};


int main(int argc, char **argv)
{
	streamIt s;
	s << "test";
	return 0;

}
