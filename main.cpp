#include <iostream>
#include "Doubly_Linked_List.h"
using namespace std;

int main() {
	Bag a;
	a.insert(3);
	a.insert(2);
	a.insert(1);
	a.sort();
	a.insert(3);
	a.insert(5);
	a.erase_one(3);
	a.count(5);
	a.insert(5);
	a.count(5);
	a.count(1);


	Bag b(a);
	b.show_contents();

	Bag c;
	c += a;

	c.show_contents();


	a.sort();
}
