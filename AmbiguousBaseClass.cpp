#include <iostream>

class Animal {
	
	public:
		virtual void eat() { std::cout << "Animal has eaten." << std::endl; }
		virtual void sleep() { std::cout << "Animal is sleeping." << std::endl; }

};

class Dog: public virtual Animal {

	public:
		virtual void eat() { std::cout << "Dog has eaten." << std::endl; }

};

class Bird: public virtual Animal {

	public:
		virtual void eat() { std::cout << "Bird has eaten." << std::endl; }

};

class DogBird: public Dog, public Bird {

	public:
	using Dog::eat;
	//	virtual void eat() { Dog::eat(); }

};

int main(int argc, char** argv)
{
	DogBird db;
	db.eat();
	db.sleep();

	Dog d;
	d.eat();
	return 0;
}

