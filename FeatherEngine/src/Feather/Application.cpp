#include "ftpch.h"
#include "Application.h"
#include "Log.h"

namespace Feather {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application() {
	}

	void Application::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay) {
		m_LayerStack.PushOverlay(overlay);
	}

	void Application::OnEvent(Event& e) {

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(e);
			if (e.m_handled) {
				break;
			}
		}
	}

	void Application::Run() {
		FT_CORE_INFO("Run loop started");
		while (m_running) {

			for (Layer* layer : m_LayerStack) {
				layer->OnUpdate();
			}

			m_Window->OnUpdate();
		}
		FT_CORE_SUCCESS("Run loop exited");
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		FT_CORE_INFO("Target event: Window close event");
		m_running = false;
		return true;
	}

}