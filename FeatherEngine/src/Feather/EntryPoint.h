#pragma once

#include "Core.h"
#include "Application.h"

#ifdef _WIN64

extern Feather::Application* Feather::CreateApplication();

int main(int argc, char** argv) {

	auto app = Feather::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif