#pragma once
struct GLFWwindow;
class app_window
{
public:
	bool create_window(const char* title);

	void on_tick(float delta_time);

	GLFWwindow* m_window;
};

