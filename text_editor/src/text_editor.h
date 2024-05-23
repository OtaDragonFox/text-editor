#pragma once
#include <rendering/app_window.h>

class text_editor
{
protected:
	text_editor() {

	}
	static text_editor* m_text_editor;
	
public:
	
	/*should not be cloneable!*/
	text_editor(text_editor& other) = delete;
	/*should not be assignable*/
	void operator=(const text_editor&) = delete;
		
	static text_editor* get_instance() {
		if (m_text_editor == nullptr) {
			m_text_editor = new text_editor;
		}

		return m_text_editor;
	};

	app_window* application_window;

public:
	bool startup();
	void shutdown();
};



#define EDITOR ::text_editor::get_instance()

