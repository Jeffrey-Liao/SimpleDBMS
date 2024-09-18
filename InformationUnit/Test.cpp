#include"Infor.h"
#include "FatalException.h"
using namespace liaoInfor;
class Test
{
public:
	void testFunction()
	{
		Infor infor(InforType::Debug);
		for (int n = 0; n < 10; ++n)
			infor.when(n == 10).send(THISFUNC, "yes", true);
		infor.send(THISFUNC,"nothing",true);
		infor.send("test case",true);
		throw new FatalException(THISFUNC,"error",THISFILE,THISTLINE);
	}
};
int main()
{
	try
	{
		Test test;
		test.testFunction();
	}
	catch (LiaoException* e)
	{
		e->printAll();
	}

}