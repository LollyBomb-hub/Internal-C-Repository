#include <stdio.h>
#include <vector>

#define V vector

using namespace std;

template<typename T>
class BST
{
	public:
		void insert(T value, int index);
		int search(T value);
	private:
		int index;
		T self;
		BST<T> *left;
		BST<T> *right;
};

int main(void)
{
	return 0;
}
