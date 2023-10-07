// 5.3-1(2).cpp 


#include <iostream>
using namespace std;

class smart_array {
private:
	int* a;
	int null;
	int size;
public:
	smart_array(int s) {
		a = new int[s];
		null = 0;
		size = s;
	}

	void add_element(int num) {
		if (null >= size) throw runtime_error("array is full");

		else {
			a[null] = num;
			null++;
		}
	}

	int get_element(int i) {
		if (i >= null) throw runtime_error("this element doesn't exist");

		return a[i];
	}

	~smart_array() {
		delete[] a;
	}

	smart_array(const smart_array&) = delete;
	smart_array& operator=(const smart_array&) = delete;
};
int main() {
	try {
		smart_array arr(5);

		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);

		cout << "array[" << 1 << "] = " << arr.get_element(1) << endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}