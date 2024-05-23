#pragma once
// this defines the base class to create ui elemnts.
// this class carrys the general basic logic and is equivilant
// to  a "canvas" holding up all the sub components
#include "types.h"

class ui_face
{
public:

	// on event handles all events like clicked from the child classes
	void on_event(const char* identifier[10], f_ui8 id,  ui_event_data);
	virtual void handle_press_event(const  char* identifier[10], bool pressed) = 0;
	
	// implement custom event callback
	void out_message(const char* message);

};

