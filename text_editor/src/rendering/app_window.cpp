#include "app_window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <logger.h>


bool app_window::create_window(const char* title)
{
	if (!glfwInit()) {
		LOG(LERROR, "Couldnt create GLFW!");
		return false;
	}
	m_window = glfwCreateWindow(600, 400, title, nullptr, nullptr);
	if (!m_window) {
		LOG(LERROR, "GLFW couldnt create window!");
		return false;
	}
	glfwMakeContextCurrent(m_window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		LOG(LERROR, "Glad couldnt load proc address!");
		return false;
	}
}

void app_window::on_tick(float delta_time)
{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(m_window);
		glfwPollEvents();
}
