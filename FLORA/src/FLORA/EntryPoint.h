#pragma once

#ifdef FL_PLATFORM_WINDOWS

extern FLORA::Application* FLORA::CreateApplication();

int main(int argc, char** argv)
{
	FLORA::Log::Init();
	FL_CORE_WARN("Initialized Log!");
	int a = 5;
	FL_INFO("Hello! Var={0}", a);
	
	auto app = FLORA::CreateApplication();
	app->Run();
	delete app;
}

#endif