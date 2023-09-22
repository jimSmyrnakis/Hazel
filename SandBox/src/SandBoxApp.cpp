#include <Hazel.h>


class SandBox : public Hazel::Application
{
public:
	SandBox(void)
	{

	}
	~SandBox(void)
	{

	}
};

Hazel::Application* Hazel::CreateApplication(void)
{
	return new SandBox();
}