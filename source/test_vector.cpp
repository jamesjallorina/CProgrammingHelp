#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class Base
{
	public:
		Base() { cout << "base constructor " << endl; }
		~Base() { cout << "base destructor " << endl; }
};


int main(int argc, char **argv)
{
	std::vector<Base *> vcontainer;
	vcontainer.push_back(new Base);
	vcontainer.push_back(new Base);
	vcontainer.push_back(new Base);

	cout << "vector size: " << vcontainer.size() << endl;
	cout << "check if dynamically allocated is managed by vector container " << endl;

	for(std::vector<Base *>::iterator it = vcontainer.begin(); it != vcontainer.end(); ++it)
	{
		(*it)->~Base();
	}

	vcontainer.pop_back();
	vcontainer.pop_back();
	vcontainer.pop_back();
	
	cout << "vector size: " << vcontainer.size() << endl;
	return 0;
}
