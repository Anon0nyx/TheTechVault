#include <iostream>

using namespace std;

class Node {
	int foobar = 69; // This is private to the class, can also be established with private:
	public:
		// class attributes are very easy
		int *parentNode;
		int *rightNode;
		int *leftNode;

		// Methods are also very easy
		void HelloWorld() {
			cout << "Hello, Friend." << endl;
		}

		// This neat this will have the name of the class, constructor acts as an init basically
		/*Node() {
			cout << "Node has been established" << endl;
		}*/
		// Notice that this one executes first as it happens when the class is established
		
		// Lets give that private variable outside of scope with a getter() method
		int getVariable() {
			return foobar;
		}

		// We can also make a setter to change this value during execution
		int setVariable(int num) {
			foobar = num;
			return 0;
		}


};

class SubNode: public Node {
	public:
		string var = "This is gettings confusing but SubNode can access Node's methods and attributes";
};


int main() {
	Node newNode;
	
	SubNode funNode; 
	cout << funNode.getVariable() << endl;
	
	

	return 0;
}
