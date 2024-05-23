#include <logger.h>
#include "text_editor.h"

int main() {

	LOGGER().setup();

	if (!EDITOR->startup()) {
		LOG(LFATAL, "Couldnt generate window!!!");
	}
	EDITOR->shutdown();

	return true;
}