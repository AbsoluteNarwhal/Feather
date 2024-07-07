#pragma once

#include "Core.h"
#include "Application.h"
#include "Log.h"

#ifdef _WIN64

extern Feather::Application* Feather::CreateApplication();

int main(int argc, char** argv) {

	Feather::Log::Init();
	FT_CORE_SUCCESS("Initialized Log!");

	auto app = Feather::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif