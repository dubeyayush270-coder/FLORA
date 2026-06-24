#include <FLORA.h>

class SandBox : public FLORA::Application
{
public:
	SandBox()
	{

	}
	~SandBox()
	{

	}
};

FLORA::Application* FLORA::CreateApplication()
{
	return new SandBox();
}