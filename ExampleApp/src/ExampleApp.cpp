#include <FeatherEngine.h>

class ExampleApp : public Feather::Application {

public:
	ExampleApp() {
	
	}

	~ExampleApp() {
	
	}
};

Feather::Application* Feather::CreateApplication() {
	return new ExampleApp();
}