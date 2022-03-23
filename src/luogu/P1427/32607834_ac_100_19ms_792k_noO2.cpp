#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template<typename T>
class Mstack {
private:
	vector<T> a;
public:
	Mstack<T>(){};
	~Mstack<T>(){};
	void pop() {
		this->a.pop_back();
	}
	void push(T &a) {
		this->a.push_back(a);
	}
	size_t size() const {
		return (size_t)this->a.size();
	}
	bool empty() const {
		return this->a.empty();
	}
	T top() const {
		return this->a.back();
	}
} ;

int main() {
	Mstack<int > a;
	int x;
	while(cin >> x && x) a.push(x);
	while(!a.empty()) cout << a.top() << ' ', a.pop();
	return 0;
}