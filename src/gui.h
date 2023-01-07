#pragma once
#include <d3d9.h>
#pragma comment(lib, "d3d9.lib")

#include "../lib/imgui/imgui.h"
#include "../lib/imgui/imgui_impl_dx9.h"
#include "../lib/imgui/imgui_impl_win32.h"
#include "../lib/imgui/imgui_internal.h"


LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam); // Forward declare message handler from imgui_impl_win32.cpp


namespace gui {
	const int window_width = 600;
	const int window_height = 400;
	inline bool is_running = true;
	inline POINTS position = { };

	inline HWND window = nullptr;
	inline WNDCLASSEX windowClass = { };
	
	void create_window(const char* windowName) noexcept;
	void destroy_window() noexcept;

	// DirectX state:
	inline PDIRECT3D9 d3d = nullptr;
	inline LPDIRECT3DDEVICE9 device = nullptr;
	inline D3DPRESENT_PARAMETERS preset_params = { };

	// handle DirectX device creation and destruction:
	bool create_device() noexcept;
	void reset_device() noexcept;
	void destroy_device() noexcept;

	// handle ImGui creation and destruction:
	void create_imgui() noexcept;
	void destroy_imgui() noexcept;

	void begin_render() noexcept;
	void end_render() noexcept;
	void render() noexcept;
}
