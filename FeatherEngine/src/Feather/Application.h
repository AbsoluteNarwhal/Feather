#pragma once

#include "Core.h"
#include "Events/ApplicationEvent.h"
#include "Window/Window.h"
#include "Layer/LayerStack.h"

namespace Feather {

	class FEATHER_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_running = true;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();

}