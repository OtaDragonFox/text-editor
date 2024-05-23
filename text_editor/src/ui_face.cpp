#include "ui_face.h"
#include <iostream>


void ui_face::on_event(const char* identifier[10], f_ui8 id, ui_event_data)
{
	switch (id)
	{
	case 1:
		return;
	}

	out_message("event was passed the wrong id.");
	return;
}



void ui_face::out_message(const char* message)
{
	// default handeling of messages
	std::cout << message << std::endl;
}
