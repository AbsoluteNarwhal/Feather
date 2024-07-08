#include <FeatherEngine.h>

class ExampleLayer : public Feather::Layer {
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override {

	}

	void OnEvent(Feather::Event& event) override {
		
	}
};

class ExampleApp : public Feather::Application {
public:
	ExampleApp() {}
	~ExampleApp() {}
};

Feather::Application* Feather::CreateApplication() {
	return new ExampleApp();
}