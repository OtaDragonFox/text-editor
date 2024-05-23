#include "text_editor.h"
#include <logger.h>


text_editor* text_editor::m_text_editor = nullptr;
bool text_editor::startup(){
	LOG(LTRACE, "Main / Call Test -> startup");
	application_window = new(app_window);
	
	if (!application_window->create_window("Hello World!")) {
		return false;
	}
	// TODO: Replace with proper boolean for keeping track of upstate
	while (true)
	{
		// calculate delta time properly with sleep shedule 30/60 fps? 
		application_window->on_tick(0.0f);
	}

}

void text_editor::shutdown()
{
	delete(application_window);
}
