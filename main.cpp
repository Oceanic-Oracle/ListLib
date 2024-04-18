#include "MyList.cpp"

int main() 
{
	mylist::MyList<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.print();
	std::cout << " " << l.size() << std::endl;

	l.pop_front();
	l.print();
	std::cout << " " << l.size() << std::endl;

	l.push_front(1);
	l.print();
	std::cout << " " << l.size() << std::endl;

	l.pop_back();
	l.print();
	std::cout << " " << l.size() << std::endl;
	
	std::cout << l[0] << std::endl;

	l.insert(3, 5);
	l.print();
	std::cout << " " << l.size() << std::endl;
	return 0;
}