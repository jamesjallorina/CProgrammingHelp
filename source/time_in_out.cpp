#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <vector>
#include <memory>
#include <unistd.h>

std::ostream &operator<<(std::ostream &os, std::chrono::system_clock::time_point &time)
{
	std::time_t now_c = std::chrono::system_clock::to_time_t(time);
	os << std::put_time(std::localtime(&now_c), "%F %T");
}

class student{
	using clock = std::chrono::system_clock;
public:
	student() : name{""}, time_in{clock::now()}, time_out{clock::now()} {}
	~student() = default;

	clock::time_point &getTimeIn()  { return time_in; }
	clock::time_point &getTimeOut()  { return time_out; }

	void setName(const std::string &n) { name = n; }
	void clock_in()  { time_in = clock::now(); }
	void clock_out() { time_out = clock::now(); }

	void display() {
		std::cout << "name: " << name << "\n";
		std::cout << "time_in: " << time_in << "\n";
		std::cout << "time_out: " << time_out << "\n";
		std::cout << "in hours: " << std::chrono::duration_cast<std::chrono::hours>(time_out - time_in).count()  << "\n";
		std::cout << "in minutes: " <<  std::chrono::duration_cast<std::chrono::minutes>(time_out - time_in).count() << "\n";
		std::cout << "in seconds: " << std::chrono::duration_cast<std::chrono::seconds>(time_out - time_in).count() << "\n";
	}

private:
	std::string name;
	clock::time_point time_in;
	clock::time_point time_out;
	double duration;
};

class timeManager{
public:
	timeManager() = default;
	~timeManager() = default;

	void insert(std::unique_ptr<student> s){
		studentList.push_back(std::move(s));
	}

	void show() const {
		for(const auto &p : studentList)
			p->display();
	}

private:
	std::vector<std::unique_ptr<student>> studentList;
};



int main(int argc, char **argv)
{
	std::unique_ptr<student> s1 = std::make_unique<student>();
	s1->setName("John Wick");
	s1->clock_in();
	sleep(5);		// sleep at 60s
	s1->clock_out();
	s1->display();

	return 0;
}