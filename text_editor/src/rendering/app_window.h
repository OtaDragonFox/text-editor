#pragma once
#include <glm/ext/vector_float3.hpp>
struct GLFWwindow;
using namespace glm;

class app_window
{
public:
	bool create_window(const char* title);

	void on_tick(float delta_time);

	void create_test_mesh();

	// for vertex testing 
	vec3 verticies[3]{
		vec3(-0.5,-0.5,0.0),
		vec3(0.5,-0.5,0.0),
		vec3(0.0,0.5,0.0)
	};
	unsigned int VBO,VAO, EBO;

	unsigned int program_id;

	GLFWwindow* m_window;
};

