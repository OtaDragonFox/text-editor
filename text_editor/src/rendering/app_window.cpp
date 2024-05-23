#include "app_window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <logger.h>
#include <i_o/file.h>


void compile_shader_element(const char* in_shader_data,unsigned int& in_index, bool is_frag_shader) {

	if (is_frag_shader) {
		in_index = glCreateShader(GL_FRAGMENT_SHADER);
	}
	else {
		in_index = glCreateShader(GL_VERTEX_SHADER);
	}

	LOG(LTRACE, "%s, ", in_shader_data);

	glShaderSource(in_index, 1, &in_shader_data, NULL);
	glCompileShader(in_index);
	int success;
	char infolog[512];
	glGetShaderiv(in_index, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(in_index, 512, NULL, infolog);
		LOG(LERROR, "Shader compilation error : %s", infolog);
	}
}

void compile_shader(const char* in_vert_data, const char* in_frag_data, unsigned int& in_program_id) {
	unsigned int vert, fragment;
	compile_shader_element(in_frag_data, fragment,true);
	compile_shader_element(in_vert_data, vert,false);
	in_program_id = glCreateProgram();
	glAttachShader(in_program_id, vert);
	glAttachShader(in_program_id, fragment);
	glLinkProgram(in_program_id);
	
	int success;
	char infolog[512];
	glGetProgramiv(in_program_id, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(in_program_id, 512, NULL, infolog);
		LOG(LERROR, "Program compilation error : %s", infolog);
	}
}




bool app_window::create_window(const char* title){
	if (!glfwInit()) {
		LOG(LERROR, "Couldnt create GLFW!");
		return false;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
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

	create_test_mesh();

	return true;
}

void app_window::on_tick(float delta_time){
	
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(program_id);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

void app_window::create_test_mesh(){
	// generate buffer for VBO - Vertex buffer object 
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	// set the Vertex buffer object to the provided vertex array
	// GL_STREAM_DRAW -Set once and used by gpu a few times
	// GL_STATIC_DRAW - set only once and used many times
	//GL_DYNAMIC_DRAW - Data changes alot -> good for procedural meshes
	
	load_text_file("shaders/shader.v");
	compile_shader(load_text_file("shaders/shader.v").c_str(), load_text_file("shaders/shader.f").c_str(), program_id);


	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glUseProgram(program_id);
}
