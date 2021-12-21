#include <iostream>
#include <memory>

class B
{
	public:
	B(int b): m_b(b)
	{
		std::cout << "B Created!\n";
	}
	~B()
	{
		std::cout << "B Destroyed!\n";
	}
	int GetVal() const { return m_b; }
	private:
	int m_b;
};

class A
{
public:
	A(int x, int b)
		: m_x(x)
		, m_B(std::make_unique<B>(b))
	{
		std::cout << "A Created!\n";
	}
	~A() 
	{
		std::cout << "A Destroyed!\n"; 
	}
	void Modify(int x, B* b)						// caller can be raw pointer / unique_ptr.get() / std::move(raw pointer)
	{
		m_x = x;
		*m_B = *b;	// Assignment operator on B called
	}
	void Modify2(int x, std::unique_ptr<B> b)		// caller can be std::move(std::unique_ptr<B>) only
	{
		m_x = x;
		m_B = std::move(b);	// same effect as Modify()
	}
	void Modify3(int x, std::unique_ptr<B>& b)		// caller can be std::unique_ptr<B> only, not std::move(std::unique_ptr<B>)
	{
		m_x = x;
		m_B = std::move(b);
	}
	void Modify4(int x, B& b)						// caller can be raw pointer / unique_ptr.get() / std::move(raw pointer)
	{
		m_x = x;
		*m_B = b;	// Assignment operator on B called
	}
	void ModifyS(int x, std::shared_ptr<B> b)
	{
		m_x = x;
		*m_B = *b;	// Assignment operator on B called
	}
	void ModifyS2(int x, std::shared_ptr<B>& b)
	{
		m_x = x;
		*m_B = *b;	// Assignment operator on B called
	}
	friend std::ostream& operator<<(std::ostream& os, const A& obj)
	{
		os << obj.m_x << ", " << obj.m_B->GetVal() << "\n";
		return os;
	}
private:
	int m_x;
	std::unique_ptr<B> m_B;
};

int main()
{
	std::unique_ptr<A> obj = std::make_unique<A>(23, 45);

	//std::cout << *obj;
/*
	std::unique_ptr<B> bObj = std::make_unique<B>(72);
	//obj->Modify(2, bObj.get());
	//obj->Modify(2, std::move(bObj.get()));
	//obj->Modify2(2, std::move(bObj));
	//obj->Modify3(2, bObj);
	obj->Modify4(2, *bObj.get());
*/

	std::shared_ptr<B> bObj = std::make_shared<B>(72);
	obj->ModifyS2(2, bObj);

	std::cout << *obj;

	std::cin.get();
	return 0;
}