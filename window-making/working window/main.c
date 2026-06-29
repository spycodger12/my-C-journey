#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

// 01-  window protocol
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT: {
            PAINTSTRUCT ps;
            // 01.1 Start drawing and get canva
            HDC hdc = BeginPaint(hwnd, &ps);

            // 01.2 Define text to display. Unicode with L
            const wchar_t texto[] = L"Hello world from the Windows API";

            // 01.3 Set text color (RGB: Red, Green, Blue)
            // (R=0, V=50, A=200) dark blue
            SetTextColor(hdc, RGB(0, 50, 200));

            // 01.4 set transparent background in text
            SetBkMode(hdc, TRANSPARENT);

            // 01.5 Draw the text on the screen
            // Parameters: hdc, X position, Y position, text, text length
            TextOut(hdc, 50, 50, texto, lstrlen(texto));

            // 01.6 finish draw to free resources
            EndPaint(hwnd, &ps);
            return 0;
        }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


// 02-  universal entry for MinGW
int main(int argc, char** argv) {
    // get identifier from running instance
    HINSTANCE hInstance = GetModuleHandle(NULL);
    
    // TEXT() for unicode compat.
    const wchar_t CLASS_NAME[] = L"MyWindowClass";
    
    WNDCLASSEX wc = {0};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = CLASS_NAME;

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, L"Error registering window class", L"Error", MB_ICONERROR);
        return 0;
    }

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"Compatible window 8.1/10/11",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}


// compiled with "gcc main.c -o window.exe -mwindows"