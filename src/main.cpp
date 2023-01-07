#include <chrono>
#include "gui.h"
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")  // Hide windows console. 


using namespace std;


int main() {
	gui::create_window("Imgui example");
	gui::create_device();
	gui::create_imgui();

	while (gui::is_running) {
		gui::begin_render();
		gui::render();
		gui::end_render();

		this_thread::sleep_for(std::chrono::milliseconds(5));
	}

	gui::destroy_imgui();
	gui::destroy_device();
	gui::destroy_window();

	return 0;
}
