#pragma once
#include <string>
#include <fstream>
#include <logger.h>
using namespace std;

const string load_text_file(const char* path) {
	ifstream m_file(path);
	if (!m_file.is_open())
	{
		LOG(LERROR, "FAILED TO OPEN FILE %s, ", path);
		return {};
	}
	LOG(LTRACE, "opened file, %s", path);

	string string_iter;
	string out_string;
	while (getline(m_file, string_iter)) {
		out_string.append(string_iter);
		out_string.append("\n");
	}
	
	LOG(LTRACE, "file data: %s", out_string.c_str());
	m_file.close();
	return out_string;
}


