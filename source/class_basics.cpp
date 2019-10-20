#include <iostream>
#include <iomanip>
#include <memory>

/* concrete class math operations */
class mathOperation {
public: 
	mathOperation() = default;
	mathOperation(const int x,const int y){
		this->x = x;
		this->y = y;
	}
	~mathOperation() = default;
	void setX(int x){ this->x = x; }
	void setY(int y){ this->y = y; }

	const int getX() const { return x; }
	const int getY() const { return y; }

	const int add() const  { return x + y; }
	const int sub() const  { return x - y; }
	const int mul() const  { return x * y; }
	const int div() const  { return x / y; }

private:
	int x;
	int y;
};

/* abstract base class for math operations */
class basicOperation {
public:
	basicOperation() : x{0}, y{0} {}
	virtual ~basicOperation() = default;

	void setX(int x){ this->x = x; }
	void setY(int y){ this->y = y; }

	virtual const int getX() const = 0;
	virtual const int getY() const = 0;

	virtual const int add() const = 0;
	virtual const int sub() const = 0;
	virtual const int mul() const = 0;
	virtual const int div() const = 0;


protected:
	int x;
	int y;
};

class basicMath : public basicOperation {

public: 
	basicMath() : basicOperation() { }
	virtual ~basicMath() = default;

	virtual const int getX() const override;
	virtual const int getY() const override;

	virtual const int add() const override { return x + y; }
	virtual const int sub() const override { return x - y; }
	virtual const int mul() const override { return x * y; }
	virtual const int div() const override { return x / y; }
};

const int basicMath::getX() const {
	return x;
}

const int basicMath::getY() const{
	return y;
}

int main(int argc, char **argv)
{
	basicMath basicMathObj;
	basicMathObj.setX(10);
	basicMathObj.setY(20);

	std::cout << basicMathObj.getX() << "\n";
	std::cout << basicMathObj.getY() << "\n";

	/* use of base class basic */
	std::unique_ptr<basicOperation> pb = std::make_unique<basicMath>();

	pb->setX(30);
	pb->setY(40);

	std::cout << pb->getX() << "\n";
	std::cout << pb->getY() << "\n";
	std::cout << "add x + y: " << pb->add() << "\n";

	mathOperation mobj;
	mobj.setX(50);
	mobj.setY(60);
	std::cout << mobj.getX() << "\n";
	std::cout << mobj.getY() << "\n";
	std::cout << mobj.add() << "\n";
	std::cout << mobj.sub() << "\n";
	std::cout << mobj.mul() << "\n";
	std::cout << mobj.div() << "\n";
	return 0;
}