#include <iostream>
#include <list>

using namespace std;


class Base
{
public:
	Base() {}
	virtual ~Base() {}

public:
	virtual void Run() = 0;

private:

};

class Child : public Base
{
public:
	Child() { SetNum(1); }
	virtual ~Child() {}

public:
	virtual int GetNum() const { return m_Num; }
	virtual void SetNum(int val) { m_Num = val; }

	virtual void Run() { cout << "Child: " << GetNum() << endl; }
	
private:
	int m_Num;
};

class GrantChild : public Child
{
public:
	GrantChild() { SetNum(2);  }
	virtual ~GrantChild() {}

public:
	virtual int GetNum() const { return m_Num; }
	virtual void SetNum(int val) { m_Num = val; }

	virtual void Run() { cout << "GrantCihld: " << GetNum() << ", its Child: " << Child::GetNum() << endl; }

private:
	int m_Num;

};

int main()
{
	list<Base*> listFamily;

	Base* child = new Child;
	Base* grantChild = new GrantChild;

	listFamily.push_back(child);
	listFamily.push_back(grantChild);

	list<Base*>::iterator ite;
	for (ite = listFamily.begin(); ite != listFamily.end(); ++ite)
	{
		(*ite)->Run();
	}

	return 0;
}