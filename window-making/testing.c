// display window using win32 API dll

//    typedef struct WINDCLASSEXA
//    {
//        UINT cbSize;
//        UINT style;
//        WNDPROC lpfnWndProc;
//        int cbClsExtra;
//          int cbWndExtra;
//        HINSTANCE hInstance;
//        HICON hIcon;
//        Hcursor hCursor;
//        HBRUSH hbrBackground;
//        LPCSTR lpsczClassName;
//        HICON hIconSm;
//    } WINDCLASSEXA, *PWNDCLASSEXA, *NPWNDCLASSEXA, *LPWNDCLASSEXA;

#include <windows.h>


// 01- Window event management
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0); // closes the app
            return 0;
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps); //add code to draw inside the window

            EndPaint(hwnd, &ps);
            return 0;
        }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


// 02- Entry point for windows application
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    const char CLASS_NAME[] = "MyWindowClass";
    
    // 03- Start and config. structure WNDCLASSEX
    WNDCLASSEX wc = {0};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW +1);
    wc.lpszClassName = CLASS_NAME;

    // 04- Window class register
    HWND hwnd = CreateWindowEx
    (
        0,                              // extended style
        CLASS_NAME,                     // Class name registered
        "My first window in C",         // Window title 
        WS_OVERLAPPEDWINDOW,            // window style standard
        CW_USEDEFAULT, CW_USEDEFAULT,   // initial position (X Y)
        800, 600,                       // dimensions (Width, Height)
        NULL,                           // parent window
        NULL,                           // menu
        hInstance,                      // app instance
        NULL                            // aditional parameters
    );
    if (hwnd == NULL)
    {
        return 0;
    }
    // 06- show and update on screen window
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // 07- message bucle. Keep window alive and listen to events
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}


// compile with "gcc main.c -o mi_ventana.exe -mwindows" -- GCC/MinGW