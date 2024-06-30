#include "Header.h"

int main()
{
	linkList<string, int> list;
	
	list.insert("abc1", "74389759", "23/jan/2002", 50000, 50);
	list.insert("abc2", "85490338", "23/jun/2002", 40000, 40);
	list.insert("abc3", "92304924", "22/jan/2005", 90000, 20);
	list.insert("abc4", "23439530", "23/july/2003", 30000, 30);
	list.print();
	int max = list.MaxSalary();
	cout << "max salary is: " << max << endl;
	list.search("abc3");
	list.UpdateSalary("abc4", 839434);
	list.print();
}