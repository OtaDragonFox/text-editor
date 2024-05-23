#pragma once

#include "types.h"

class ui_face;
enum alignment {
	CENTER,
	LEFT,
	RIGHT
};

class ui_block
{	
	ui_block(ui_face* in_owner,  
		bool in_clickable,
		alignment in_alignment,
		bool  in_greedy_fill,
		float fill_precent);
	

	bool click_check(float x, float y);

	virtual void on_event() = 0;

public:
	// General properties for the item itself
	// If the elemt should greedily fill the remaining space.
	bool greedy_fill = false;
	
	alignment justification;
	element_type ui_type = element_type::ELEMENT;
	// In a vertical box the element will take up the entire
	// Avaible vertical space / horizontal space .
	// Fill percent will take care of the secound half of that part
	// meaning it will from 0-1 determine how much space it should take.
	// if all elements together in the box are more then 1 they will be split up
	// if they are less and the alignment differ they will be. 
	// Center sticky. Left sticky or right Sticky
	float fill_percent;


	// Percentual padding means that instead of flat percentages its a relative elemnt size from 0-1
	// TODO: Future ota will have to figure out in the future on how to do this :p 
	float use_percentual_padding;

	bool can_be_clicked;
	float padding_top;
	float padding_bottom;
	float padding_left;
	float padding_right;
	
	// Visibilitie
	bool is_visible;
	bool is_clickable;
	bool pass_input_to_child;

	bool is_container = false;

	private:
	

	//corners;
	//top Left		//top right
	//bottom_left	//bottom right
	vec2 corners[4];

	ui_face* owner_class;
	
	ui_block* owning_element;

};

