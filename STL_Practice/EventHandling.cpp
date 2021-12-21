#include <iostream>
#include <vector>

class Response
{
	public:
	void ChildrenResponse()
	{
		std::cout << "Joy!\n";
	}
	void AgedResponse()
	{
		std::cout << "Doesn't Matter.\n";
	}
};

typedef void (Response::*FnPtr)();

struct Functor_Base
{
	virtual void operator() () = 0;
};

template<typename T, typename U>
struct Functor: public Functor_Base
{
	Functor(T* t, U u):m_t(t), m_u(u){}
	virtual void operator() ()
	{
		(m_t->*m_u)();
	}
	T* m_t;
	U m_u;
};

class RainEvent
{
	public:	
	void Register(Functor_Base* func)
	{
		m_vCallbacks.push_back(func);
	}	
	void Handle()
	{
		for(int i=0;i<m_vCallbacks.size(); i++)
		{
			Functor_Base* f = m_vCallbacks[i];			
			(*f)();
		}
	}
/*	virtual ~RainEvent()
	{
		for(int i=0;i<m_vCallbacks.size(); i++)
			delete m_vCallbacks[i];
	}*/
	private:
	std::vector<Functor_Base*> m_vCallbacks;					// <- this is how you get a template member variable inside a non-template class
};

int main()
{
	Response r;
	RainEvent rainEvt;
	rainEvt.Register(new Functor<Response, FnPtr>(&r, &Response::ChildrenResponse));
	rainEvt.Register(new Functor<Response, FnPtr>(&r, &Response::AgedResponse));
	rainEvt.Handle();
	return 0;
}



/*
// Older version - template member variables only allowed inside template class

#include <iostream>
#include <vector>

class Response
{
	public:
	void ChildrenResponse()
	{
		std::cout << "Joy!\n";
	}
	void AgedResponse()
	{
		std::cout << "Look for the items lying outside, and save them from rain.\n";
	}
};

typedef void (Response::*FnPtr)();

template<typename T, typename U>
struct Functor
{
	Functor(T* t, U u):m_t(t), m_u(u){}
	void operator() ()
	{
		(m_t->*m_u)();
	}
	T* m_t;
	U m_u;
};

template<typename T, typename U>
class RainEvent
{
	public:	
	void Register(Functor<T, U> func)
	{
		m_vCallbacks.push_back(func);
	}	
	void Handle()
	{
		for(int i=0;i<m_vCallbacks.size(); i++)
		{
			Functor<T, U> f = m_vCallbacks[i];			
			(f.m_t->*f.m_u)();
		}
	}
	private:
	std::vector<Functor<T, U> > m_vCallbacks;
	T* m_t;
};

int main()
{
	Response r;
	//RainEvent rainEvt;
	//rainEvt.Register(Functor<Response, FnPtr>(&r, &Response::ChildrenResponse));
	//rainEvt.Register(Functor<Response, FnPtr>(&r, &Response::AgedResponse));
	//rainEvt.Handle();
	return 0;
}

*/