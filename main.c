/*
 * KakaoTalk Chat Window List MVP
 * Windows 10/11 x64, single native Win32 executable, no third-party runtime.
 *
 * At launch, list only currently visible, separately opened KakaoTalk chat
 * windows. Rooms can be moved into a user-selected room list. The right-side
 * message settings can store a clipboard image; each selected room receives that image
 * via paste and the image-send popup before configured text is typed without a
 * final Enter.
 */

typedef unsigned short wchar_t;
typedef void *HANDLE;
typedef HANDLE HGLOBAL;
typedef HANDLE HWND;
typedef HANDLE HINSTANCE;
typedef HANDLE HICON;
typedef HANDLE HCURSOR;
typedef HANDLE HBRUSH;
typedef HANDLE HDC;
typedef HANDLE HFONT;
typedef HANDLE HRSRC;
typedef HANDLE HMENU;
typedef HANDLE HINTERNET;
typedef const wchar_t *LPCWSTR;
typedef wchar_t *LPWSTR;
typedef unsigned int UINT;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef unsigned int DWORD;
typedef int BOOL;
typedef int LONG;
typedef unsigned long long WPARAM;
typedef long long LPARAM;
typedef long long LRESULT;
typedef LRESULT (*WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef BOOL (*WNDENUMPROC)(HWND, LPARAM);

typedef struct { LONG x; LONG y; } POINT;
typedef struct {
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    POINT pt;
    DWORD lPrivate;
} MSG;
typedef struct {
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;
} WNDCLASSW;
typedef struct { LONG left; LONG top; LONG right; LONG bottom; } RECT;
typedef struct {
    HDC hdc;
    BOOL fErase;
    RECT rcPaint;
    BOOL fRestore;
    BOOL fIncUpdate;
    BYTE rgbReserved[32];
} PAINTSTRUCT;
typedef struct {
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOHEADER;
typedef struct {
    UINT CtlType;
    UINT CtlID;
    UINT itemID;
    UINT itemAction;
    UINT itemState;
    HWND hwndItem;
    HDC hDC;
    RECT rcItem;
    unsigned long long itemData;
} DRAWITEMSTRUCT;
typedef char drawitem_layout_must_be_64_bytes[(sizeof(DRAWITEMSTRUCT) == 64) ? 1 : -1];
/* Matching Windows 64-bit INPUT layout: sizeof(INPUT) == 40. */
typedef struct {
    WORD wVk;
    WORD wScan;
    DWORD dwFlags;
    DWORD time;
    unsigned long long dwExtraInfo;
} KEYBDINPUT;
typedef struct {
    LONG dx;
    LONG dy;
    DWORD mouseData;
    DWORD dwFlags;
    DWORD time;
    unsigned long long dwExtraInfo;
} MOUSEINPUT;
typedef struct {
    DWORD type;
    union {
        KEYBDINPUT ki;
        MOUSEINPUT mi;
        BYTE raw[32];
    } data;
} INPUT;
typedef char input_layout_must_be_40_bytes[(sizeof(INPUT) == 40) ? 1 : -1];

__declspec(dllimport) HINSTANCE GetModuleHandleW(LPCWSTR);
__declspec(dllimport) void ExitProcess(UINT);
__declspec(dllimport) DWORD GetCurrentThreadId(void);
__declspec(dllimport) void Sleep(DWORD);
__declspec(dllimport) HANDLE OpenProcess(DWORD, BOOL, DWORD);
__declspec(dllimport) BOOL QueryFullProcessImageNameW(HANDLE, DWORD, LPWSTR, DWORD *);
__declspec(dllimport) BOOL CloseHandle(HANDLE);
__declspec(dllimport) HGLOBAL GlobalAlloc(UINT, unsigned long long);
__declspec(dllimport) void *GlobalLock(HGLOBAL);
__declspec(dllimport) BOOL GlobalUnlock(HGLOBAL);
__declspec(dllimport) unsigned long long GlobalSize(HGLOBAL);
__declspec(dllimport) HGLOBAL GlobalFree(HGLOBAL);
__declspec(dllimport) HRSRC FindResourceW(HINSTANCE, LPCWSTR, LPCWSTR);
__declspec(dllimport) HGLOBAL LoadResource(HINSTANCE, HRSRC);
__declspec(dllimport) void *LockResource(HGLOBAL);
__declspec(dllimport) DWORD SizeofResource(HINSTANCE, HRSRC);
__declspec(dllimport) unsigned short RegisterClassW(const WNDCLASSW *);
__declspec(dllimport) HWND CreateWindowExW(DWORD, LPCWSTR, LPCWSTR, DWORD, int, int, int, int, HWND, HANDLE, HINSTANCE, void *);
__declspec(dllimport) LRESULT DefWindowProcW(HWND, UINT, WPARAM, LPARAM);
__declspec(dllimport) BOOL EnumWindows(WNDENUMPROC, LPARAM);
__declspec(dllimport) BOOL EnumChildWindows(HWND, WNDENUMPROC, LPARAM);
__declspec(dllimport) DWORD GetWindowThreadProcessId(HWND, DWORD *);
__declspec(dllimport) int GetClassNameW(HWND, LPWSTR, int);
__declspec(dllimport) BOOL IsWindowVisible(HWND);
__declspec(dllimport) BOOL IsWindow(HWND);
__declspec(dllimport) BOOL IsIconic(HWND);
__declspec(dllimport) BOOL ShowWindow(HWND, int);
__declspec(dllimport) BOOL SetForegroundWindow(HWND);
__declspec(dllimport) BOOL AttachThreadInput(DWORD, DWORD, BOOL);
__declspec(dllimport) HWND SetFocus(HWND);
__declspec(dllimport) HWND GetFocus(void);
__declspec(dllimport) UINT SendInput(UINT, INPUT *, int);
__declspec(dllimport) HWND GetForegroundWindow(void);
__declspec(dllimport) BOOL IsWindowEnabled(HWND);
__declspec(dllimport) BOOL GetWindowRect(HWND, RECT *);
__declspec(dllimport) HWND GetWindow(HWND, UINT);
__declspec(dllimport) BOOL GetCursorPos(POINT *);
__declspec(dllimport) BOOL SetCursorPos(int, int);
__declspec(dllimport) int GetWindowTextW(HWND, LPWSTR, int);
__declspec(dllimport) LRESULT SendMessageW(HWND, UINT, WPARAM, LPARAM);
__declspec(dllimport) BOOL MoveWindow(HWND, int, int, int, int, BOOL);
__declspec(dllimport) BOOL GetClientRect(HWND, RECT *);
__declspec(dllimport) BOOL GetMessageW(MSG *, HWND, UINT, UINT);
__declspec(dllimport) BOOL TranslateMessage(const MSG *);
__declspec(dllimport) LRESULT DispatchMessageW(const MSG *);
__declspec(dllimport) void PostQuitMessage(int);
__declspec(dllimport) HCURSOR LoadCursorW(HINSTANCE, LPCWSTR);
__declspec(dllimport) BOOL OpenClipboard(HWND);
__declspec(dllimport) BOOL CloseClipboard(void);
__declspec(dllimport) BOOL EmptyClipboard(void);
__declspec(dllimport) BOOL IsClipboardFormatAvailable(UINT);
__declspec(dllimport) HANDLE GetClipboardData(UINT);
__declspec(dllimport) HANDLE SetClipboardData(UINT, HANDLE);
__declspec(dllimport) UINT RegisterClipboardFormatW(LPCWSTR);
__declspec(dllimport) BOOL InvalidateRect(HWND, const RECT *, BOOL);
__declspec(dllimport) HDC BeginPaint(HWND, PAINTSTRUCT *);
__declspec(dllimport) BOOL EndPaint(HWND, const PAINTSTRUCT *);
__declspec(dllimport) int FillRect(HDC, const RECT *, HBRUSH);
__declspec(dllimport) int DrawTextW(HDC, LPCWSTR, int, RECT *, UINT);
__declspec(dllimport) BOOL DrawFocusRect(HDC, const RECT *);
__declspec(dllimport) HANDLE GetStockObject(int);
__declspec(dllimport) HANDLE SelectObject(HDC, HANDLE);
__declspec(dllimport) HBRUSH CreateSolidBrush(DWORD);
__declspec(dllimport) HFONT CreateFontW(int, int, int, int, int, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, LPCWSTR);
__declspec(dllimport) BOOL DeleteObject(HANDLE);
__declspec(dllimport) int SetBkMode(HDC, int);
__declspec(dllimport) DWORD SetBkColor(HDC, DWORD);
__declspec(dllimport) DWORD SetTextColor(HDC, DWORD);
__declspec(dllimport) BOOL RoundRect(HDC, int, int, int, int, int, int);
__declspec(dllimport) HANDLE AddFontMemResourceEx(void *, DWORD, void *, DWORD *);
__declspec(dllimport) BOOL RemoveFontMemResourceEx(HANDLE);
__declspec(dllimport) int StretchDIBits(HDC, int, int, int, int, int, int, int, int, const void *, const void *, UINT, DWORD);
__declspec(dllimport) HMENU CreateMenu(void);
__declspec(dllimport) HMENU CreatePopupMenu(void);
__declspec(dllimport) BOOL AppendMenuW(HMENU, UINT, unsigned long long, LPCWSTR);
__declspec(dllimport) int MessageBoxW(HWND, LPCWSTR, LPCWSTR, UINT);
__declspec(dllimport) HINSTANCE ShellExecuteW(HWND, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, int);
__declspec(dllimport) HINTERNET WinHttpOpen(LPCWSTR, DWORD, LPCWSTR, LPCWSTR, DWORD);
__declspec(dllimport) HINTERNET WinHttpConnect(HINTERNET, LPCWSTR, WORD, DWORD);
__declspec(dllimport) HINTERNET WinHttpOpenRequest(HINTERNET, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR *, DWORD);
__declspec(dllimport) BOOL WinHttpSetTimeouts(HINTERNET, int, int, int, int);
__declspec(dllimport) BOOL WinHttpSendRequest(HINTERNET, LPCWSTR, DWORD, void *, DWORD, DWORD, unsigned long long);
__declspec(dllimport) BOOL WinHttpReceiveResponse(HINTERNET, void *);
__declspec(dllimport) BOOL WinHttpQueryOption(HINTERNET, DWORD, void *, DWORD *);
__declspec(dllimport) BOOL WinHttpCloseHandle(HINTERNET);

#define WS_OVERLAPPEDWINDOW   0x00CF0000u
#define WS_VISIBLE            0x10000000u
#define WS_CHILD              0x40000000u
#define WS_VSCROLL            0x00200000u
#define WS_TABSTOP            0x00010000u
#define WS_BORDER             0x00800000u
#define WS_CAPTION            0x00C00000u
#define WS_SYSMENU            0x00080000u
#define BS_GROUPBOX           0x0007u
#define BS_OWNERDRAW          0x000Bu
#define BS_AUTOCHECKBOX       0x0003u
#define SS_CENTER             0x0001u
#define SS_CENTERIMAGE        0x0200u
#define ES_MULTILINE          0x0004u
#define ES_AUTOVSCROLL        0x0040u
#define ES_AUTOHSCROLL        0x0080u
#define ES_READONLY           0x0800u
#define ES_WANTRETURN         0x1000u
#define ES_NUMBER             0x2000u
#define LBS_NOTIFY            0x0001u
#define LBS_NOINTEGRALHEIGHT  0x0100u
#define LBS_EXTENDEDSEL       0x0800u
#define WM_CREATE             0x0001u
#define WM_DESTROY            0x0002u
#define WM_SIZE               0x0005u
#define WM_PAINT              0x000Fu
#define WM_ERASEBKGND         0x0014u
#define WM_DRAWITEM           0x002Bu
#define WM_SETTEXT            0x000Cu
#define WM_COMMAND            0x0111u
#define WM_SETFONT            0x0030u
#define WM_CTLCOLOREDIT       0x0133u
#define WM_CTLCOLORLISTBOX    0x0134u
#define WM_CTLCOLORBTN        0x0135u
#define WM_CTLCOLORSTATIC     0x0138u
#define EM_SETLIMITTEXT       0x00C5u
#define EM_SETSEL             0x00B1u
#define EM_REPLACESEL         0x00C2u
#define EM_SETREADONLY        0x00CFu
#define EM_SCROLLCARET        0x00B7u
#define BM_GETCHECK           0x00F0u
#define LB_ADDSTRING          0x0180u
#define LB_DELETESTRING       0x0182u
#define LB_SETSEL             0x0185u
#define LB_GETTEXT            0x0189u
#define LB_GETCOUNT           0x018Bu
#define LB_GETSELCOUNT        0x0190u
#define LB_GETSELITEMS        0x0191u
#define LB_GETITEMDATA        0x0199u
#define LB_SETITEMDATA        0x019Au
#define LB_ERR                (-1)
#define LB_ERRSPACE           (-2)
#define LBN_DBLCLK            2u
#define BST_CHECKED           1u
#define SW_RESTORE            9
#define SW_SHOW               5
#define GW_OWNER              4u
#define INPUT_MOUSE           0u
#define INPUT_KEYBOARD        1u
#define MOUSEEVENTF_LEFTDOWN  0x0002u
#define MOUSEEVENTF_LEFTUP    0x0004u
#define KEYEVENTF_KEYUP       0x0002u
#define KEYEVENTF_UNICODE     0x0004u
#define VK_RETURN             0x0Du
#define VK_SHIFT              0x10u
#define VK_CONTROL            0x11u
#define VK_V                  0x56u
#define COLOR_WINDOW          5u
#define DEFAULT_GUI_FONT      17
#define WHITE_BRUSH           0
#define NULL_PEN              8
#define IDC_ARROW             32512u
#define PROCESS_QUERY_LIMITED_INFORMATION 0x1000u
#define GMEM_FIXED            0x0000u
#define GMEM_MOVEABLE         0x0002u
#define CF_DIB                8u
#define CF_DIBV5              17u
#define BI_RGB                0u
#define BI_BITFIELDS          3u
#define BI_ALPHABITFIELDS     6u
#define DIB_RGB_COLORS        0u
#define SRCCOPY               0x00CC0020u
#define DT_CENTER             0x00000001u
#define DT_VCENTER            0x00000004u
#define DT_SINGLELINE         0x00000020u
#define ODS_SELECTED          0x0001u
#define ODS_DISABLED          0x0004u
#define ODS_FOCUS             0x0010u
#define TRANSPARENT           1
#define FW_NORMAL             400
#define FW_SEMIBOLD           600
#define DEFAULT_CHARSET       1u
#define CLEARTYPE_QUALITY     5u
#define MF_STRING             0x0000u
#define MF_POPUP              0x0010u
#define MB_OK                 0x00000000u
#define MB_YESNO              0x00000004u
#define MB_ICONINFORMATION    0x00000040u
#define MB_ICONWARNING        0x00000030u
#define IDYES                 6
#define SW_SHOWNORMAL         1
#define WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY 4u
#define WINHTTP_FLAG_SECURE   0x00800000u
#define WINHTTP_OPTION_URL    34u
#define INTERNET_DEFAULT_HTTPS_PORT 443u
#define IDM_OPTIONS           1001u
#define IDM_CHECK_UPDATES     1002u
#define IDM_ABOUT             1003u
#define RT_RCDATA             10u
#define IDR_PRETENDARD_REGULAR_FONT  101u
#define IDR_PRETENDARD_SEMIBOLD_FONT 102u
#define RGB_COLOR(r, g, b)    ((DWORD)((BYTE)(r) | ((DWORD)(BYTE)(g) << 8) | ((DWORD)(BYTE)(b) << 16)))
#define APP_VERSION           L"v1.17"
#define APP_TITLE             L"비즈업클래스-카카오단톡 메시지 자동화 (v1.17)"
#define RELEASE_LATEST_URL    L"https://github.com/resumet/kakao-opentalk-manager/releases/latest"

static HWND listbox;
static HWND selected_listbox;
static HWND source_label;
static HWND selected_label;
static HWND input_label;
static HWND add_button;
static HWND remove_button;
static HWND message_edit;
static HWND mention_all_checkbox;
static HWND send_message_checkbox;
static HWND timing_button;
static HWND message_button;
static HWND settings_group;
static HWND image_label;
static HWND image_status;
static HWND image_paste_button;
static HWND image_clear_button;
static HWND log_label;
static HWND log_edit;
static HWND main_window;
static HWND timing_window;
static HWND timing_edits[5];
static HWND timing_apply_button;
static HWND timing_status;
static HGLOBAL stored_image;
static UINT stored_image_format;
static UINT png_clipboard_format;
static wchar_t prepared_text[4096];
static HBRUSH app_background_brush;
static HBRUSH surface_brush;
static HFONT app_font;
static HFONT section_font;
static HANDLE private_regular_font_handle;
static HANDLE private_semibold_font_handle;

typedef struct {
    DWORD image_paste_to_send;
    DWORD image_send_to_input;
    DWORD mention_after_at;
    DWORD mention_after_enter;
    DWORD next_room;
} TimingSettings;

static TimingSettings timings = {1000, 1000, 500, 500, 1500};

static int maximum(int a, int b) { return a > b ? a : b; }

static int wide_length(const wchar_t *text) {
    int length = 0;
    if (!text) return 0;
    while (text[length]) ++length;
    return length;
}

static BOOL append_wide(wchar_t *buffer, int capacity, const wchar_t *text) {
    int used;
    int index = 0;
    if (!buffer || capacity <= 0 || !text) return 0;
    used = wide_length(buffer);
    while (text[index]) {
        if (used + index + 1 >= capacity) return 0;
        buffer[used + index] = text[index];
        ++index;
    }
    buffer[used + index] = 0;
    return 1;
}

static const wchar_t *find_wide(const wchar_t *text, const wchar_t *needle) {
    const wchar_t *start;
    const wchar_t *left;
    const wchar_t *right;
    if (!text || !needle || !*needle) return text;
    for (start = text; *start; ++start) {
        left = start;
        right = needle;
        while (*left && *right && *left == *right) {
            ++left;
            ++right;
        }
        if (!*right) return start;
    }
    return (const wchar_t *)0;
}

static int compare_versions(const wchar_t *left, const wchar_t *right) {
    int component;
    unsigned int left_value;
    unsigned int right_value;
    if (*left == L'v' || *left == L'V') ++left;
    if (*right == L'v' || *right == L'V') ++right;
    for (component = 0; component < 4; ++component) {
        left_value = 0;
        right_value = 0;
        while (*left >= L'0' && *left <= L'9') {
            left_value = left_value * 10u + (unsigned int)(*left - L'0');
            ++left;
        }
        while (*right >= L'0' && *right <= L'9') {
            right_value = right_value * 10u + (unsigned int)(*right - L'0');
            ++right;
        }
        if (left_value < right_value) return -1;
        if (left_value > right_value) return 1;
        if (*left == L'.') ++left;
        if (*right == L'.') ++right;
    }
    return 0;
}

static void append_log(const wchar_t *text) {
    if (!log_edit || !text) return;
    SendMessageW(log_edit, EM_SETREADONLY, 0, 0);
    SendMessageW(log_edit, EM_SETSEL, (WPARAM)-1, (LPARAM)-1);
    SendMessageW(log_edit, EM_REPLACESEL, 0, (LPARAM)text);
    SendMessageW(log_edit, EM_SETREADONLY, 1, 0);
    SendMessageW(log_edit, EM_SCROLLCARET, 0, 0);
}

static void copy_bytes(BYTE *destination, const BYTE *source, unsigned long long size) {
    while (size) {
        *destination++ = *source++;
        --size;
    }
}

static HGLOBAL clone_global_memory(HGLOBAL source) {
    unsigned long long size;
    const BYTE *source_data;
    BYTE *destination_data;
    HGLOBAL destination;
    if (!source) return (HGLOBAL)0;
    size = GlobalSize(source);
    if (!size) return (HGLOBAL)0;
    source_data = (const BYTE *)GlobalLock(source);
    if (!source_data) return (HGLOBAL)0;
    destination = GlobalAlloc(GMEM_MOVEABLE, size);
    if (!destination) {
        GlobalUnlock(source);
        return (HGLOBAL)0;
    }
    destination_data = (BYTE *)GlobalLock(destination);
    if (!destination_data) {
        GlobalUnlock(source);
        GlobalFree(destination);
        return (HGLOBAL)0;
    }
    copy_bytes(destination_data, source_data, size);
    GlobalUnlock(destination);
    GlobalUnlock(source);
    return destination;
}

static void update_image_status(void) {
    if (!image_status) return;
    InvalidateRect(image_status, (const RECT *)0, 1);
}

static BOOL stored_dib_details(
    const BYTE *data,
    unsigned long long size,
    const BITMAPINFOHEADER **header_result,
    const BYTE **bits_result,
    int *width_result,
    int *height_result
) {
    const BITMAPINFOHEADER *header;
    unsigned long long offset;
    unsigned long long color_count;
    long long image_height;
    if (!data || size < sizeof(BITMAPINFOHEADER)) return 0;
    header = (const BITMAPINFOHEADER *)data;
    if (header->biSize < sizeof(BITMAPINFOHEADER) || header->biSize >= size) return 0;
    if (header->biWidth <= 0 || header->biHeight == 0 || header->biPlanes != 1) return 0;
    image_height = header->biHeight < 0 ? -(long long)header->biHeight : header->biHeight;
    if (image_height > 0x7FFFFFFF) return 0;
    offset = header->biSize;
    if (header->biSize == sizeof(BITMAPINFOHEADER)) {
        if (header->biCompression == BI_BITFIELDS) offset += 3u * sizeof(DWORD);
        if (header->biCompression == BI_ALPHABITFIELDS) offset += 4u * sizeof(DWORD);
    }
    if (offset > size) return 0;
    if (header->biClrUsed) {
        color_count = header->biClrUsed;
    } else if (header->biBitCount <= 8) {
        color_count = 1ull << header->biBitCount;
    } else {
        color_count = 0;
    }
    if (color_count > (size - offset) / 4u) return 0;
    offset += color_count * 4u;
    if (offset >= size) return 0;
    *header_result = header;
    *bits_result = data + offset;
    *width_result = header->biWidth;
    *height_result = (int)image_height;
    return 1;
}

static LRESULT image_preview_proc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) {
    if (message == WM_PAINT) {
        PAINTSTRUCT paint;
        RECT client;
        HDC dc = BeginPaint(hwnd, &paint);
        const wchar_t *status = L"이미지 없음";
        if (!dc) return 0;
        GetClientRect(hwnd, &client);
        FillRect(dc, &client, (HBRUSH)GetStockObject(WHITE_BRUSH));
        if (stored_image &&
            (stored_image_format == CF_DIB || stored_image_format == CF_DIBV5)) {
            unsigned long long size = GlobalSize(stored_image);
            const BYTE *data = (const BYTE *)GlobalLock(stored_image);
            const BITMAPINFOHEADER *header;
            const BYTE *bits;
            int image_width;
            int image_height;
            if (data && stored_dib_details(
                    data, size, &header, &bits, &image_width, &image_height)) {
                int available_width = maximum(0, client.right - client.left - 8);
                int available_height = maximum(0, client.bottom - client.top - 8);
                int draw_width = available_width;
                int draw_height = image_width ?
                    (int)((long long)draw_width * image_height / image_width) : 0;
                int draw_x;
                int draw_y;
                if (draw_height > available_height && image_height) {
                    draw_height = available_height;
                    draw_width = (int)((long long)draw_height * image_width / image_height);
                }
                draw_x = (client.right - draw_width) / 2;
                draw_y = (client.bottom - draw_height) / 2;
                if (draw_width > 0 && draw_height > 0) {
                    StretchDIBits(
                        dc, draw_x, draw_y, draw_width, draw_height,
                        0, 0, image_width, image_height,
                        bits, header, DIB_RGB_COLORS, SRCCOPY
                    );
                    GlobalUnlock(stored_image);
                    EndPaint(hwnd, &paint);
                    return 0;
                }
            }
            if (data) GlobalUnlock(stored_image);
            status = L"이미지 미리보기 실패";
        } else if (stored_image) {
            status = L"PNG 이미지 저장됨";
        }
        SelectObject(dc, GetStockObject(DEFAULT_GUI_FONT));
        DrawTextW(dc, status, -1, &client, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        EndPaint(hwnd, &paint);
        return 0;
    }
    return DefWindowProcW(hwnd, message, wparam, lparam);
}

static void clear_stored_image(BOOL write_log) {
    if (stored_image) GlobalFree(stored_image);
    stored_image = (HGLOBAL)0;
    stored_image_format = 0;
    update_image_status();
    if (write_log) append_log(L"[이미지] 저장된 이미지를 삭제했습니다.\r\n");
}

static BOOL capture_clipboard_image(void) {
    UINT format = 0;
    HGLOBAL source;
    HGLOBAL copy;
    if (!OpenClipboard(main_window)) return 0;
    if (IsClipboardFormatAvailable(CF_DIB)) {
        format = CF_DIB;
    } else if (IsClipboardFormatAvailable(CF_DIBV5)) {
        format = CF_DIBV5;
    } else if (png_clipboard_format && IsClipboardFormatAvailable(png_clipboard_format)) {
        format = png_clipboard_format;
    }
    if (!format) {
        CloseClipboard();
        return 0;
    }
    source = (HGLOBAL)GetClipboardData(format);
    copy = clone_global_memory(source);
    CloseClipboard();
    if (!copy) return 0;
    clear_stored_image(0);
    stored_image = copy;
    stored_image_format = format;
    update_image_status();
    return 1;
}

static BOOL publish_stored_image(void) {
    HGLOBAL copy;
    if (!stored_image || !stored_image_format) return 0;
    copy = clone_global_memory(stored_image);
    if (!copy) return 0;
    if (!OpenClipboard(main_window)) {
        GlobalFree(copy);
        return 0;
    }
    if (!EmptyClipboard() || !SetClipboardData(stored_image_format, copy)) {
        CloseClipboard();
        GlobalFree(copy);
        return 0;
    }
    CloseClipboard();
    return 1;
}

/* Only case-fold ASCII characters; the executable/class names are ASCII. */
static wchar_t ascii_lower(wchar_t c) {
    if (c >= 'A' && c <= 'Z') return (wchar_t)(c + ('a' - 'A'));
    return c;
}
static BOOL equals_ignore_ascii_case(const wchar_t *a, const wchar_t *b) {
    while (*a && *b) {
        if (ascii_lower(*a) != ascii_lower(*b)) return 0;
        ++a;
        ++b;
    }
    return *a == 0 && *b == 0;
}
static BOOL prefix_ignore_ascii_case(const wchar_t *s, const wchar_t *prefix) {
    while (*prefix) {
        if (!*s || ascii_lower(*s) != ascii_lower(*prefix)) return 0;
        ++s;
        ++prefix;
    }
    return 1;
}

static HMENU create_app_menu(void) {
    HMENU menu_bar = CreateMenu();
    HMENU settings_menu = CreatePopupMenu();
    HMENU help_menu = CreatePopupMenu();
    if (!menu_bar || !settings_menu || !help_menu) return (HMENU)0;
    AppendMenuW(settings_menu, MF_STRING, IDM_OPTIONS, L"옵션");
    AppendMenuW(help_menu, MF_STRING, IDM_CHECK_UPDATES, L"업데이트 확인");
    AppendMenuW(help_menu, MF_STRING, IDM_ABOUT, L"프로그램 정보");
    AppendMenuW(menu_bar, MF_POPUP, (unsigned long long)settings_menu, L"설정");
    AppendMenuW(menu_bar, MF_POPUP, (unsigned long long)help_menu, L"도움말");
    return menu_bar;
}

static void show_program_information(void) {
    MessageBoxW(
        main_window,
        L"비즈업클래스-카카오단톡 메시지 자동화\r\n"
        L"버전 v1.17\r\n\r\n"
        L"Windows 10/11 x64 단독 실행형",
        L"프로그램 정보",
        MB_OK | MB_ICONINFORMATION
    );
}

static BOOL fetch_latest_version(wchar_t *latest, int capacity) {
    HINTERNET session = (HINTERNET)0;
    HINTERNET connection = (HINTERNET)0;
    HINTERNET request = (HINTERNET)0;
    wchar_t final_url[1024];
    const wchar_t *marker = L"/releases/tag/";
    const wchar_t *version;
    DWORD url_bytes = (DWORD)sizeof(final_url);
    int index = 0;
    BOOL valid = 0;

    if (!latest || capacity < 4) return 0;
    latest[0] = 0;
    final_url[0] = 0;
    final_url[1023] = 0;

    session = WinHttpOpen(
        APP_TITLE, WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY,
        (LPCWSTR)0, (LPCWSTR)0, 0
    );
    if (!session) goto cleanup;
    WinHttpSetTimeouts(session, 5000, 5000, 5000, 5000);

    connection = WinHttpConnect(session, L"github.com", INTERNET_DEFAULT_HTTPS_PORT, 0);
    if (!connection) goto cleanup;
    request = WinHttpOpenRequest(
        connection, L"GET",
        L"/resumet/kakao-opentalk-manager/releases/latest",
        (LPCWSTR)0, (LPCWSTR)0, (LPCWSTR *)0, WINHTTP_FLAG_SECURE
    );
    if (!request) goto cleanup;
    if (!WinHttpSendRequest(request, (LPCWSTR)0, 0, (void *)0, 0, 0, 0)) goto cleanup;
    if (!WinHttpReceiveResponse(request, (void *)0)) goto cleanup;
    if (!WinHttpQueryOption(request, WINHTTP_OPTION_URL, final_url, &url_bytes)) goto cleanup;
    final_url[1023] = 0;

    version = find_wide(final_url, marker);
    if (!version) goto cleanup;
    version += wide_length(marker);
    while (*version && *version != L'/' && *version != L'?' && *version != L'#') {
        if (index + 1 >= capacity) goto cleanup;
        latest[index++] = *version++;
    }
    latest[index] = 0;
    if (index < 2 || (latest[0] != L'v' && latest[0] != L'V')) goto cleanup;
    for (index = 1; latest[index]; ++index) {
        if ((latest[index] < L'0' || latest[index] > L'9') && latest[index] != L'.') {
            goto cleanup;
        }
    }
    valid = 1;

cleanup:
    if (request) WinHttpCloseHandle(request);
    if (connection) WinHttpCloseHandle(connection);
    if (session) WinHttpCloseHandle(session);
    if (!valid) latest[0] = 0;
    return valid;
}

static void check_for_updates(void) {
    wchar_t latest[32];
    wchar_t message[512];
    int answer;
    append_log(L"[업데이트] GitHub 최신 Release를 확인합니다.\r\n");
    if (!fetch_latest_version(latest, 32)) {
        append_log(L"[실패] 업데이트 정보를 확인하지 못했습니다.\r\n");
        MessageBoxW(
            main_window,
            L"업데이트 정보를 확인하지 못했습니다.\r\n"
            L"인터넷 연결을 확인한 뒤 다시 시도해 주세요.",
            L"업데이트 확인",
            MB_OK | MB_ICONWARNING
        );
        return;
    }

    message[0] = 0;
    if (compare_versions(APP_VERSION, latest) < 0) {
        append_wide(message, 512, L"새 버전이 있습니다.\r\n\r\n현재 버전: ");
        append_wide(message, 512, APP_VERSION);
        append_wide(message, 512, L"\r\n최신 버전: ");
        append_wide(message, 512, latest);
        append_wide(message, 512, L"\r\n\r\n다운로드 페이지를 여시겠습니까?");
        append_log(L"[업데이트] 새 버전을 확인했습니다.\r\n");
        answer = MessageBoxW(
            main_window, message, L"업데이트 확인", MB_YESNO | MB_ICONINFORMATION
        );
        if (answer == IDYES &&
            (unsigned long long)ShellExecuteW(
                main_window, L"open", RELEASE_LATEST_URL,
                (LPCWSTR)0, (LPCWSTR)0, SW_SHOWNORMAL
            ) <= 32u) {
            append_log(L"[실패] 업데이트 다운로드 페이지를 열지 못했습니다.\r\n");
            MessageBoxW(
                main_window,
                L"업데이트 다운로드 페이지를 열지 못했습니다.",
                L"업데이트 확인",
                MB_OK | MB_ICONWARNING
            );
        }
        return;
    }

    append_wide(message, 512, L"현재 최신 버전을 사용 중입니다.\r\n\r\n현재 버전: ");
    append_wide(message, 512, APP_VERSION);
    append_wide(message, 512, L"\r\n최신 Release: ");
    append_wide(message, 512, latest);
    append_log(L"[업데이트] 현재 버전이 최신 Release와 같거나 더 높습니다.\r\n");
    MessageBoxW(
        main_window, message, L"업데이트 확인", MB_OK | MB_ICONINFORMATION
    );
}

/* KakaoTalk shows the clipboard confirmation in an untitled owned popup and
 * disables the room while that popup is active. Accept only the foreground
 * popup directly owned by the target room and belonging to the same process.
 * Its send row is centered 25 pixels above the popup bottom. Keep the prior
 * in-room overlay position as a fallback for KakaoTalk layouts without a
 * separate popup, then restore the user's cursor position after the click. */
static BOOL click_image_send_overlay(HWND target) {
    HWND foreground;
    HWND owner;
    DWORD target_process = 0;
    DWORD foreground_process = 0;
    RECT target_bounds;
    RECT bounds;
    POINT original_cursor;
    INPUT events[2] = {0};
    INPUT release_button = {0};
    UINT sent;
    int width;
    int height;
    int click_x;
    int click_y;
    if (!IsWindow(target) || !IsWindowVisible(target) ||
        !GetWindowRect(target, &target_bounds)) return 0;
    foreground = GetForegroundWindow();
    if (foreground == target) {
        if (!IsWindowEnabled(target)) return 0;
        bounds = target_bounds;
        click_y = bounds.top + (int)((long long)(bounds.bottom - bounds.top) * 78 / 100);
    } else {
        if (!foreground || !IsWindow(foreground) || !IsWindowVisible(foreground) ||
            !IsWindowEnabled(foreground)) return 0;
        GetWindowThreadProcessId(target, &target_process);
        GetWindowThreadProcessId(foreground, &foreground_process);
        owner = GetWindow(foreground, GW_OWNER);
        if (!target_process || foreground_process != target_process || owner != target ||
            !GetWindowRect(foreground, &bounds)) return 0;
        if (bounds.left < target_bounds.left || bounds.top < target_bounds.top ||
            bounds.right > target_bounds.right || bounds.bottom > target_bounds.bottom) return 0;
        click_y = bounds.bottom - 25;
    }
    width = bounds.right - bounds.left;
    height = bounds.bottom - bounds.top;
    if (width < 200 || height < 300 || !GetCursorPos(&original_cursor)) return 0;
    click_x = bounds.left + width / 2;
    if (click_y <= bounds.top || click_y >= bounds.bottom) return 0;
    if (!SetCursorPos(click_x, click_y)) return 0;
    events[0].type = INPUT_MOUSE;
    events[0].data.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    events[1].type = INPUT_MOUSE;
    events[1].data.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    sent = SendInput(2, events, (int)sizeof(INPUT));
    if (sent != 2) {
        release_button.type = INPUT_MOUSE;
        release_button.data.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        SendInput(1, &release_button, (int)sizeof(INPUT));
    }
    SetCursorPos(original_cursor.x, original_cursor.y);
    return sent == 2;
}

/* Verify the owning process by its executable filename, not by a window title. */
static BOOL owned_by_kakaotalk(HWND hwnd) {
    DWORD pid = 0;
    DWORD length = 520;
    wchar_t path[520];
    const wchar_t *base;
    const wchar_t *cursor;
    HANDLE process;
    BOOL ok;

    GetWindowThreadProcessId(hwnd, &pid);
    if (!pid) return 0;
    process = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, 0, pid);
    if (!process) return 0;
    ok = QueryFullProcessImageNameW(process, 0, path, &length);
    CloseHandle(process);
    if (!ok || length >= 520) return 0;
    path[length] = 0;
    base = path;
    for (cursor = path; *cursor; ++cursor) {
        if (*cursor == '\\' || *cursor == '/') base = cursor + 1;
    }
    return equals_ignore_ascii_case(base, L"KakaoTalk.exe");
}

typedef struct {
    BOOL has_edit;
    BOOL has_chat_list;
    BOOL has_legacy_scroll;
} ChatControls;

static BOOL inspect_child(HWND hwnd, LPARAM state_pointer) {
    ChatControls *state = (ChatControls *)state_pointer;
    wchar_t cls[96];
    if (!GetClassNameW(hwnd, cls, 96)) return 1;

    /* KakaoTalk uses RichEdit20W in older builds and RICHEDIT50W in newer ones. */
    if (prefix_ignore_ascii_case(cls, L"RichEdit")) state->has_edit = 1;
    if (prefix_ignore_ascii_case(cls, L"EVA_VH_ListControl")) state->has_chat_list = 1;
    if (equals_ignore_ascii_case(cls, L"_EVA_CustomScrollCtrl")) state->has_legacy_scroll = 1;
    return 1;
}

static BOOL looks_like_chat_window(HWND hwnd) {
    ChatControls state = {0, 0, 0};
    wchar_t title[512];
    wchar_t class_name[96];
    if (!IsWindowVisible(hwnd)) return 0;
    if (!GetWindowTextW(hwnd, title, 512)) return 0;

    /* Main window is not a room, regardless of language. */
    if (equals_ignore_ascii_case(title, L"카카오톡") ||
        equals_ignore_ascii_case(title, L"KakaoTalk") ||
        equals_ignore_ascii_case(title, L"カカオトーク")) return 0;

    if (!owned_by_kakaotalk(hwnd)) return 0;

    /* Require chat-specific child controls to exclude settings, profiles, etc.
       Unlike the older direct-child approach, EnumChildWindows walks nested
       descendants as well. */
    EnumChildWindows(hwnd, inspect_child, (LPARAM)&state);
    GetClassNameW(hwnd, class_name, 96);
    return state.has_edit ||
        (equals_ignore_ascii_case(class_name, L"#32770") &&
         state.has_chat_list && state.has_legacy_scroll);
}

static void layout_controls(HWND hwnd) {
    RECT rect;
    int width, height, list_width, list_height, center_x, right_x;
    int action_y, log_label_y, log_top, log_height;
    int settings_x, settings_width, lists_area_width, half_button_width;
    if (!GetClientRect(hwnd, &rect)) return;
    width = rect.right - rect.left;
    height = rect.bottom - rect.top;
    log_top = maximum(0, height - 130);
    log_height = maximum(0, height - log_top - 10);
    log_label_y = maximum(0, log_top - 24);
    action_y = maximum(0, log_label_y - 38);
    settings_x = maximum(510, width - 310);
    settings_width = maximum(0, width - settings_x - 10);
    lists_area_width = maximum(0, settings_x - 20);
    list_width = maximum(0, (lists_area_width - 130) / 2);
    list_height = maximum(0, log_label_y - 44);
    center_x = 20 + list_width;
    right_x = center_x + 110;
    half_button_width = maximum(0, (settings_width - 30) / 2);
    if (source_label) {
        MoveWindow(source_label, 10, 10, list_width, 20, 1);
    }
    if (selected_label) {
        MoveWindow(selected_label, right_x, 10, list_width, 20, 1);
    }
    if (listbox) {
        MoveWindow(listbox, 10, 34, list_width, list_height, 1);
    }
    if (selected_listbox) {
        MoveWindow(selected_listbox, right_x, 34, list_width, list_height, 1);
    }
    if (add_button) {
        MoveWindow(add_button, center_x, 64, 90, 30, 1);
    }
    if (remove_button) {
        MoveWindow(remove_button, center_x, 104, 90, 30, 1);
    }
    if (settings_group) {
        MoveWindow(settings_group, settings_x, 10, settings_width, maximum(0, action_y + 30), 1);
    }
    if (image_label) {
        MoveWindow(image_label, settings_x + 15, 38, maximum(0, settings_width - 30), 20, 1);
    }
    if (image_status) {
        MoveWindow(image_status, settings_x + 15, 62, maximum(0, settings_width - 30), 120, 1);
    }
    if (image_paste_button) {
        MoveWindow(image_paste_button, settings_x + 15, 192, half_button_width, 30, 1);
    }
    if (image_clear_button) {
        MoveWindow(
            image_clear_button,
            settings_x + 20 + half_button_width,
            192, half_button_width, 30, 1
        );
    }
    if (input_label) {
        MoveWindow(input_label, settings_x + 15, 238, maximum(0, settings_width - 30), 20, 1);
    }
    if (message_edit) {
        MoveWindow(message_edit, settings_x + 15, 262, maximum(0, settings_width - 30), 90, 1);
    }
    if (mention_all_checkbox) {
        MoveWindow(
            mention_all_checkbox,
            settings_x + 15, 360, maximum(0, settings_width - 30), 26, 1
        );
    }
    if (send_message_checkbox) {
        MoveWindow(
            send_message_checkbox,
            settings_x + 15, 388, maximum(0, settings_width - 30), 26, 1
        );
    }
    if (timing_button) {
        MoveWindow(timing_button, settings_x + 15, 422, maximum(0, settings_width - 30), 32, 1);
    }
    if (message_button) {
        MoveWindow(message_button, settings_x + 15, 462, maximum(0, settings_width - 30), 36, 1);
    }
    if (log_label) {
        MoveWindow(log_label, 10, log_label_y, maximum(0, width - 20), 20, 1);
    }
    if (log_edit) {
        MoveWindow(log_edit, 10, log_top, maximum(0, width - 20), log_height, 1);
    }
}

static BOOL collect_window(HWND hwnd, LPARAM list_handle) {
    wchar_t title[512];
    LRESULT index;
    if (hwnd == main_window || !looks_like_chat_window(hwnd)) return 1;
    if (!GetWindowTextW(hwnd, title, 512)) return 1;

    index = SendMessageW((HWND)list_handle, LB_ADDSTRING, 0, (LPARAM)title);
    if (index != LB_ERR && index != LB_ERRSPACE) {
        /* Item data preserves the exact HWND even if room titles are identical. */
        SendMessageW((HWND)list_handle, LB_SETITEMDATA, (WPARAM)index, (LPARAM)hwnd);
    }
    return 1;
}

/* Select the lowest visible, enabled RichEdit in the chosen chat window.
 * KakaoTalk has used RichEdit20W and RICHEDIT50W for its message editor.
 * Prefer the bottommost candidate when multiple RichEdit children exist. */
typedef struct {
    HWND editor;
    LONG bottom;
} InputCandidate;

static BOOL find_input_child(HWND hwnd, LPARAM data) {
    InputCandidate *candidate = (InputCandidate *)data;
    wchar_t cls[96];
    RECT bounds;

    if (!IsWindowVisible(hwnd) || !IsWindowEnabled(hwnd)) return 1;
    if (!GetClassNameW(hwnd, cls, 96)) return 1;
    if (!prefix_ignore_ascii_case(cls, L"RichEdit")) return 1;
    if (!GetWindowRect(hwnd, &bounds)) return 1;
    if (bounds.right <= bounds.left || bounds.bottom <= bounds.top) return 1;
    if (!candidate->editor || bounds.bottom > candidate->bottom) {
        candidate->editor = hwnd;
        candidate->bottom = bounds.bottom;
    }
    return 1;
}

/* Focus the bottommost visible RichEdit of the selected KakaoTalk room.
 * Return FALSE if Windows does not allow the target to take foreground/focus;
 * never type unless the destination has actually acquired keyboard focus. */
static BOOL focus_chat_input(HWND chat) {
    InputCandidate candidate = {0, 0};
    DWORD gui_thread;
    DWORD editor_thread;
    DWORD foreground_thread = 0;
    HWND foreground;
    BOOL attached_foreground = 0;
    BOOL attached_editor = 0;
    BOOL foreground_set;
    BOOL focused = 0;

    if (!IsWindow(chat) || !looks_like_chat_window(chat)) return 0;
    if (IsIconic(chat)) ShowWindow(chat, SW_RESTORE);
    EnumChildWindows(chat, find_input_child, (LPARAM)&candidate);
    if (!candidate.editor || !IsWindow(candidate.editor)) return 0;
    editor_thread = GetWindowThreadProcessId(candidate.editor, (DWORD *)0);
    gui_thread = GetCurrentThreadId();
    if (!editor_thread) return 0;

    /* After typing into the first room, that KakaoTalk window owns the
     * foreground input queue. Join it before activating the next room so
     * Windows does not reject the second SetForegroundWindow request. */
    foreground = GetForegroundWindow();
    if (foreground) {
        foreground_thread = GetWindowThreadProcessId(foreground, (DWORD *)0);
    }
    if (foreground_thread && foreground_thread != gui_thread) {
        attached_foreground = AttachThreadInput(gui_thread, foreground_thread, 1);
        if (!attached_foreground) return 0;
    }
    if (editor_thread != gui_thread && editor_thread != foreground_thread) {
        attached_editor = AttachThreadInput(gui_thread, editor_thread, 1);
        if (!attached_editor) {
            if (attached_foreground) {
                AttachThreadInput(gui_thread, foreground_thread, 0);
            }
            return 0;
        }
    }

    SetForegroundWindow(chat);
    foreground_set = GetForegroundWindow() == chat;
    if (foreground_set) {
        SetFocus(candidate.editor);
        focused = GetFocus() == candidate.editor;
    }

    if (attached_editor) AttachThreadInput(gui_thread, editor_thread, 0);
    if (attached_foreground) AttachThreadInput(gui_thread, foreground_thread, 0);
    return foreground_set && focused && GetForegroundWindow() == chat;
}

static HWND chat_window_at(HWND room_list, LRESULT index) {
    LRESULT item_data;
    HWND target;
    if (!room_list || index == LB_ERR) return (HWND)0;
    item_data = SendMessageW(room_list, LB_GETITEMDATA, (WPARAM)index, 0);
    if (item_data == LB_ERR) return (HWND)0;
    target = (HWND)item_data;
    /* A closed HWND can be reused, so recheck owner and chat controls. */
    if (!IsWindow(target) || !looks_like_chat_window(target)) return (HWND)0;
    return target;
}

static void move_selected_rooms(HWND from, HWND to) {
    wchar_t title[512];
    int *indices;
    LRESULT selected_count;
    LRESULT moved_count;
    LRESULT source_index;
    LRESULT new_index;
    LRESULT target_count;
    LRESULT item_data;
    LRESULT index;
    if (!from || !to) return;
    selected_count = SendMessageW(from, LB_GETSELCOUNT, 0, 0);
    if (selected_count == LB_ERR || selected_count <= 0) return;
    indices = (int *)GlobalAlloc(
        GMEM_FIXED, (unsigned long long)selected_count * sizeof(int)
    );
    if (!indices) {
        append_log(L"[실패] 선택한 대화방 목록을 준비하지 못했습니다.\r\n");
        return;
    }
    moved_count = SendMessageW(
        from, LB_GETSELITEMS, (WPARAM)selected_count, (LPARAM)indices
    );
    if (moved_count == LB_ERR || moved_count <= 0) {
        GlobalFree((HGLOBAL)indices);
        return;
    }

    target_count = SendMessageW(to, LB_GETCOUNT, 0, 0);
    if (target_count == LB_ERR) {
        GlobalFree((HGLOBAL)indices);
        return;
    }
    SendMessageW(to, LB_SETSEL, 0, (LPARAM)-1);
    for (index = 0; index < moved_count; ++index) {
        source_index = indices[index];
        item_data = SendMessageW(from, LB_GETITEMDATA, (WPARAM)source_index, 0);
        if (item_data == LB_ERR ||
            SendMessageW(from, LB_GETTEXT, (WPARAM)source_index, (LPARAM)title) == LB_ERR) {
            break;
        }
        new_index = SendMessageW(to, LB_ADDSTRING, 0, (LPARAM)title);
        if (new_index == LB_ERR || new_index == LB_ERRSPACE) break;
        if (SendMessageW(to, LB_SETITEMDATA, (WPARAM)new_index, item_data) == LB_ERR) {
            break;
        }
        SendMessageW(to, LB_SETSEL, 1, (LPARAM)new_index);
    }
    if (index != moved_count) {
        while (SendMessageW(to, LB_GETCOUNT, 0, 0) > target_count) {
            SendMessageW(to, LB_DELETESTRING, (WPARAM)target_count, 0);
        }
        append_log(L"[실패] 선택한 대화방을 목록 사이에서 이동하지 못했습니다.\r\n");
        GlobalFree((HGLOBAL)indices);
        return;
    }

    for (index = 0; index < moved_count; ++index) {
        title[0] = 0;
        SendMessageW(from, LB_GETTEXT, (WPARAM)indices[index], (LPARAM)title);
        append_log(to == selected_listbox ? L"[선택] " : L"[제외] ");
        append_log(title);
        append_log(L"\r\n");
    }
    for (index = moved_count; index > 0; --index) {
        SendMessageW(from, LB_DELETESTRING, (WPARAM)indices[index - 1], 0);
    }
    GlobalFree((HGLOBAL)indices);
}

/* Win32 SendInput KEYEVENTF_UNICODE generates WM_CHAR in the target editor,
 * avoiding reliance on a particular Korean keyboard/IME layout. */
static BOOL send_character(wchar_t ch) {
    INPUT events[2] = {0};
    events[0].type = INPUT_KEYBOARD;
    events[0].data.ki.wVk = 0;
    events[0].data.ki.wScan = (WORD)ch;
    events[0].data.ki.dwFlags = KEYEVENTF_UNICODE;
    events[1] = events[0];
    events[1].data.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
    return SendInput(2, events, (int)sizeof(INPUT)) == 2;
}

static BOOL send_enter(void) {
    INPUT events[2] = {0};
    events[0].type = INPUT_KEYBOARD;
    events[0].data.ki.wVk = VK_RETURN;
    events[1] = events[0];
    events[1].data.ki.dwFlags = KEYEVENTF_KEYUP;
    return SendInput(2, events, (int)sizeof(INPUT)) == 2;
}

static BOOL send_shift_enter(void) {
    INPUT events[4] = {0};
    INPUT release_keys[2] = {0};
    UINT sent;
    events[0].type = INPUT_KEYBOARD;
    events[0].data.ki.wVk = VK_SHIFT;
    events[1].type = INPUT_KEYBOARD;
    events[1].data.ki.wVk = VK_RETURN;
    events[2] = events[1];
    events[2].data.ki.dwFlags = KEYEVENTF_KEYUP;
    events[3] = events[0];
    events[3].data.ki.dwFlags = KEYEVENTF_KEYUP;
    sent = SendInput(4, events, (int)sizeof(INPUT));
    if (sent == 4) return 1;
    release_keys[0].type = INPUT_KEYBOARD;
    release_keys[0].data.ki.wVk = VK_RETURN;
    release_keys[0].data.ki.dwFlags = KEYEVENTF_KEYUP;
    release_keys[1].type = INPUT_KEYBOARD;
    release_keys[1].data.ki.wVk = VK_SHIFT;
    release_keys[1].data.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(2, release_keys, (int)sizeof(INPUT));
    return 0;
}

static BOOL send_paste(void) {
    INPUT events[4] = {0};
    INPUT release_control = {0};
    UINT sent;
    events[0].type = INPUT_KEYBOARD;
    events[0].data.ki.wVk = VK_CONTROL;
    events[1].type = INPUT_KEYBOARD;
    events[1].data.ki.wVk = VK_V;
    events[2] = events[1];
    events[2].data.ki.dwFlags = KEYEVENTF_KEYUP;
    events[3] = events[0];
    events[3].data.ki.dwFlags = KEYEVENTF_KEYUP;
    sent = SendInput(4, events, (int)sizeof(INPUT));
    if (sent == 4) return 1;
    release_control.type = INPUT_KEYBOARD;
    release_control.data.ki.wVk = VK_CONTROL;
    release_control.data.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &release_control, (int)sizeof(INPUT));
    return 0;
}

static BOOL type_content_to_chat(
    HWND target,
    const wchar_t *text,
    BOOL mention_all,
    BOOL complete_message
) {
    BOOL has_text = text && *text;
    if (!target) return 0;
    if (stored_image && !publish_stored_image()) {
        append_log(L"[실패] 저장된 이미지를 클립보드에 복사하지 못했습니다.\r\n");
        return 0;
    }
    if (!focus_chat_input(target)) return 0;
    if (stored_image) {
        if (GetForegroundWindow() != target || !send_paste()) {
            append_log(L"[실패] 이미지 붙여넣기 키 입력에 실패했습니다.\r\n");
            return 0;
        }
        append_log(L"[진행] 이미지를 채팅 입력칸에 붙여넣었습니다.\r\n");
        Sleep(timings.image_paste_to_send);
        if (!click_image_send_overlay(target)) {
            append_log(L"[실패] 클립보드 이미지 전송 오버레이의 전송 영역을 누르지 못했습니다.\r\n");
            return 0;
        }
        append_log(L"[성공] 클립보드 이미지 전송 오버레이의 전송 영역을 눌렀습니다.\r\n");
        Sleep(timings.image_send_to_input);
        if ((*text || mention_all) && !focus_chat_input(target)) {
            append_log(L"[실패] 이미지 전송 후 메시지 입력칸에 포커스를 설정하지 못했습니다.\r\n");
            return 0;
        }
    }
    if (mention_all) {
        if (GetForegroundWindow() != target || !send_character(L'@')) return 0;
        Sleep(timings.mention_after_at);
        if (GetForegroundWindow() != target || !send_enter()) return 0;
        Sleep(timings.mention_after_enter);
        append_log(L"[진행] 모두를 멘션하기 입력을 적용했습니다.\r\n");
    }
    while (*text) {
        if (*text == L'\r' || *text == L'\n') {
            if (*text == L'\r' && text[1] == L'\n') ++text;
            if (GetForegroundWindow() != target || !send_shift_enter()) return 0;
            ++text;
            continue;
        }
        if (GetForegroundWindow() != target || !send_character(*text)) return 0;
        ++text;
    }
    if (complete_message && has_text) {
        if (GetForegroundWindow() != target || !send_enter()) return 0;
        append_log(L"[진행] 메시지 전송을 완료했습니다.\r\n");
    }
    return 1;
}

/* Apply the prepared image and text to every manually selected room in list
 * order. A stored image is pasted and its confirmation button is clicked before the text is
 * typed. When requested, one Enter is appended after non-empty text. */
static void type_message_to_selected_rooms(void) {
    LRESULT count;
    LRESULT index;
    HWND target;
    BOOL mention_all;
    BOOL complete_message;
    wchar_t title[512];
    if (!message_edit || !selected_listbox) return;
    prepared_text[0] = 0;
    GetWindowTextW(message_edit, prepared_text, 4096);
    mention_all = mention_all_checkbox &&
        SendMessageW(mention_all_checkbox, BM_GETCHECK, 0, 0) == BST_CHECKED;
    complete_message = send_message_checkbox &&
        SendMessageW(send_message_checkbox, BM_GETCHECK, 0, 0) == BST_CHECKED;
    if (!prepared_text[0] && !stored_image && !mention_all) {
        append_log(L"[중단] 이미지, 메시지와 모두를 멘션하기가 비어 있습니다.\r\n");
        return;
    }
    count = SendMessageW(selected_listbox, LB_GETCOUNT, 0, 0);
    if (count == LB_ERR || count <= 0) {
        append_log(L"[중단] 선택된 오픈톡방이 없습니다.\r\n");
        return;
    }
    append_log(L"[시작] 선택된 오픈톡방 목록 입력을 시작합니다.\r\n");
    for (index = 0; index < count; ++index) {
        title[0] = 0;
        SendMessageW(selected_listbox, LB_GETTEXT, (WPARAM)index, (LPARAM)title);
        append_log(L"[진행] ");
        append_log(title);
        append_log(L": 설정 내용을 적용 중...\r\n");
        target = chat_window_at(selected_listbox, index);
        if (!target || !type_content_to_chat(
                target, prepared_text, mention_all, complete_message
            )) {
            append_log(L"[실패] ");
            append_log(title);
            append_log(L": 대상 또는 포커스를 확인할 수 없어 중단했습니다.\r\n");
            return;
        }
        append_log(L"[성공] ");
        append_log(title);
        append_log(L": 설정 내용 적용 완료.\r\n");
        if (index + 1 < count) {
            append_log(L"[대기] 설정된 시간 후 다음 방으로 이동합니다.\r\n");
            Sleep(timings.next_room);
        }
    }
    append_log(L"[완료] 선택된 모든 방의 입력을 완료했습니다.\r\n");
}

static void set_control_font(HWND control, HFONT font) {
    if (control && font) SendMessageW(control, WM_SETFONT, (WPARAM)font, 1);
}

static void draw_modern_button(const DRAWITEMSTRUCT *item) {
    wchar_t text[128];
    RECT bounds;
    RECT focus_bounds;
    HBRUSH brush;
    HANDLE previous_brush;
    HANDLE previous_pen;
    HANDLE previous_font;
    DWORD background;
    DWORD foreground;
    BOOL primary;
    if (!item || !item->hDC || !item->hwndItem) return;
    primary = item->hwndItem == add_button || item->hwndItem == message_button ||
        item->hwndItem == timing_apply_button;
    if (item->itemState & ODS_DISABLED) {
        background = RGB_COLOR(218, 222, 229);
        foreground = RGB_COLOR(122, 130, 143);
    } else if (primary) {
        background = (item->itemState & ODS_SELECTED) ?
            RGB_COLOR(29, 78, 216) : RGB_COLOR(37, 99, 235);
        foreground = RGB_COLOR(255, 255, 255);
    } else {
        background = (item->itemState & ODS_SELECTED) ?
            RGB_COLOR(214, 220, 229) : RGB_COLOR(232, 236, 242);
        foreground = RGB_COLOR(31, 41, 55);
    }
    bounds = item->rcItem;
    brush = CreateSolidBrush(background);
    previous_brush = SelectObject(item->hDC, brush);
    previous_pen = SelectObject(item->hDC, GetStockObject(NULL_PEN));
    RoundRect(
        item->hDC,
        bounds.left, bounds.top, bounds.right, bounds.bottom,
        10, 10
    );
    SelectObject(item->hDC, previous_pen);
    SelectObject(item->hDC, previous_brush);
    DeleteObject(brush);
    previous_font = SelectObject(item->hDC, app_font);
    SetBkMode(item->hDC, TRANSPARENT);
    SetTextColor(item->hDC, foreground);
    text[0] = 0;
    GetWindowTextW(item->hwndItem, text, 128);
    DrawTextW(
        item->hDC, text, -1, &bounds,
        DT_CENTER | DT_VCENTER | DT_SINGLELINE
    );
    SelectObject(item->hDC, previous_font);
    if (item->itemState & ODS_FOCUS) {
        focus_bounds = bounds;
        focus_bounds.left += 4;
        focus_bounds.top += 4;
        focus_bounds.right -= 4;
        focus_bounds.bottom -= 4;
        DrawFocusRect(item->hDC, &focus_bounds);
    }
}

static DWORD *timing_value_at(int index) {
    if (index == 0) return &timings.image_paste_to_send;
    if (index == 1) return &timings.image_send_to_input;
    if (index == 2) return &timings.mention_after_at;
    if (index == 3) return &timings.mention_after_enter;
    if (index == 4) return &timings.next_room;
    return (DWORD *)0;
}

static void format_delay(DWORD value, wchar_t *buffer) {
    wchar_t reverse[16];
    int count = 0;
    int index;
    do {
        reverse[count++] = (wchar_t)(L'0' + value % 10u);
        value /= 10u;
    } while (value && count < 15);
    for (index = 0; index < count; ++index) buffer[index] = reverse[count - index - 1];
    buffer[count] = 0;
}

static BOOL read_delay(HWND edit, DWORD *result) {
    wchar_t text[16];
    DWORD value = 0;
    int index;
    int length;
    if (!edit || !result) return 0;
    length = GetWindowTextW(edit, text, 16);
    if (length <= 0 || length >= 16) return 0;
    for (index = 0; index < length; ++index) {
        if (text[index] < L'0' || text[index] > L'9') return 0;
        value = value * 10u + (DWORD)(text[index] - L'0');
        if (value > 600000u) return 0;
    }
    *result = value;
    return 1;
}

static void populate_timing_edits(void) {
    wchar_t text[16];
    int index;
    DWORD *value;
    for (index = 0; index < 5; ++index) {
        value = timing_value_at(index);
        if (timing_edits[index] && value) {
            format_delay(*value, text);
            SendMessageW(timing_edits[index], WM_SETTEXT, 0, (LPARAM)text);
        }
    }
}

static void apply_timing_edits(void) {
    DWORD values[5];
    DWORD *target;
    int index;
    for (index = 0; index < 5; ++index) {
        if (!read_delay(timing_edits[index], &values[index])) {
            SendMessageW(
                timing_status, WM_SETTEXT, 0,
                (LPARAM)L"0~600000 사이의 정수(ms)를 입력해 주세요."
            );
            return;
        }
    }
    for (index = 0; index < 5; ++index) {
        target = timing_value_at(index);
        if (target) *target = values[index];
    }
    SendMessageW(timing_status, WM_SETTEXT, 0, (LPARAM)L"현재 실행에 시간 설정을 적용했습니다.");
    append_log(L"[설정] 개별 시간 설정을 적용했습니다.\r\n");
}

static LRESULT timing_window_proc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) {
    static const wchar_t *labels[5] = {
        L"이미지 붙여넣기 후 전송 클릭",
        L"이미지 전송 클릭 후 @/메시지",
        L"전체 멘션: @ 입력 후",
        L"전체 멘션: Enter 입력 후",
        L"다음 방 이동 전"
    };
    HINSTANCE instance;
    HWND label;
    int index;
    if (message == WM_CREATE) {
        timing_window = hwnd;
        instance = GetModuleHandleW((LPCWSTR)0);
        for (index = 0; index < 5; ++index) {
            label = CreateWindowExW(
                0, L"STATIC", labels[index], WS_CHILD | WS_VISIBLE,
                16, 18 + index * 38, 270, 26,
                hwnd, (HANDLE)0, instance, (void *)0
            );
            timing_edits[index] = CreateWindowExW(
                0, L"EDIT", L"",
                WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER | ES_NUMBER | ES_AUTOHSCROLL,
                292, 16 + index * 38, 110, 26,
                hwnd, (HANDLE)0, instance, (void *)0
            );
            set_control_font(label, app_font);
            set_control_font(timing_edits[index], app_font);
            SendMessageW(timing_edits[index], EM_SETLIMITTEXT, 6, 0);
        }
        timing_status = CreateWindowExW(
            0, L"STATIC", L"단위: ms (0~600000)", WS_CHILD | WS_VISIBLE,
            16, 210, 386, 22,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        timing_apply_button = CreateWindowExW(
            0, L"BUTTON", L"적용",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_OWNERDRAW,
            292, 242, 110, 34,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        set_control_font(timing_status, app_font);
        set_control_font(timing_apply_button, app_font);
        populate_timing_edits();
        return 0;
    }
    if (message == WM_COMMAND && ((wparam >> 16) & 0xFFFFu) == 0 &&
        (HWND)lparam == timing_apply_button) {
        apply_timing_edits();
        return 0;
    }
    if (message == WM_DRAWITEM) {
        draw_modern_button((const DRAWITEMSTRUCT *)lparam);
        return 1;
    }
    if (message == WM_ERASEBKGND && app_background_brush) {
        RECT client;
        if (GetClientRect(hwnd, &client)) {
            FillRect((HDC)wparam, &client, app_background_brush);
            return 1;
        }
    }
    if (message == WM_CTLCOLORSTATIC || message == WM_CTLCOLORBTN) {
        SetBkMode((HDC)wparam, TRANSPARENT);
        SetTextColor((HDC)wparam, RGB_COLOR(31, 41, 55));
        return (LRESULT)app_background_brush;
    }
    if (message == WM_CTLCOLOREDIT) {
        SetBkColor((HDC)wparam, RGB_COLOR(255, 255, 255));
        SetTextColor((HDC)wparam, RGB_COLOR(31, 41, 55));
        return (LRESULT)surface_brush;
    }
    if (message == WM_DESTROY) {
        timing_window = (HWND)0;
        timing_apply_button = (HWND)0;
        timing_status = (HWND)0;
        for (index = 0; index < 5; ++index) timing_edits[index] = (HWND)0;
        return 0;
    }
    return DefWindowProcW(hwnd, message, wparam, lparam);
}

static void show_timing_settings(void) {
    HINSTANCE instance;
    if (timing_window && IsWindow(timing_window)) {
        ShowWindow(timing_window, SW_SHOW);
        SetForegroundWindow(timing_window);
        return;
    }
    instance = GetModuleHandleW((LPCWSTR)0);
    timing_window = CreateWindowExW(
        0, L"TimingSettingsMVP", L"시간 설정 (ms)",
        WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
        (int)0x80000000u, (int)0x80000000u, 430, 320,
        main_window, (HANDLE)0, instance, (void *)0
    );
}

static LRESULT window_proc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) {
    HINSTANCE instance;
    if (message == WM_CREATE) {
        main_window = hwnd;
        instance = GetModuleHandleW((LPCWSTR)0);
        source_label = CreateWindowExW(
            0, L"STATIC", L"검색된 카톡창 목록",
            WS_CHILD | WS_VISIBLE,
            0, 0, 100, 20,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        selected_label = CreateWindowExW(
            0, L"STATIC", L"선택된 오픈톡방 목록",
            WS_CHILD | WS_VISIBLE,
            0, 0, 100, 20,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        listbox = CreateWindowExW(
            0, L"LISTBOX", L"",
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_TABSTOP | WS_BORDER |
                LBS_NOTIFY | LBS_NOINTEGRALHEIGHT | LBS_EXTENDEDSEL,
            0, 0, 100, 100,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        selected_listbox = CreateWindowExW(
            0, L"LISTBOX", L"",
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_TABSTOP | WS_BORDER |
                LBS_NOTIFY | LBS_NOINTEGRALHEIGHT | LBS_EXTENDEDSEL,
            0, 0, 100, 100,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        add_button = CreateWindowExW(
            0, L"BUTTON", L"선택 →",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_OWNERDRAW,
            0, 0, 90, 30,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        remove_button = CreateWindowExW(
            0, L"BUTTON", L"← 제외",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_OWNERDRAW,
            0, 0, 90, 30,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        settings_group = CreateWindowExW(
            0, L"BUTTON", L"메시지 설정",
            WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
            0, 0, 100, 100,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        image_label = CreateWindowExW(
            0, L"STATIC", L"클립보드 이미지",
            WS_CHILD | WS_VISIBLE,
            0, 0, 100, 20,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        image_status = CreateWindowExW(
            0, L"ImagePreviewMVP", L"",
            WS_CHILD | WS_VISIBLE | WS_BORDER,
            0, 0, 100, 120,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        image_paste_button = CreateWindowExW(
            0, L"BUTTON", L"이미지 붙여넣기",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_OWNERDRAW,
            0, 0, 120, 30,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        image_clear_button = CreateWindowExW(
            0, L"BUTTON", L"이미지 지우기",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_OWNERDRAW,
            0, 0, 120, 30,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        input_label = CreateWindowExW(
            0, L"STATIC", L"메시지",
            WS_CHILD | WS_VISIBLE,
            0, 0, 70, 24,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        message_edit = CreateWindowExW(
            0, L"EDIT", L"",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_VSCROLL | WS_BORDER |
                ES_MULTILINE | ES_AUTOVSCROLL | ES_WANTRETURN,
            0, 0, 100, 90,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        mention_all_checkbox = CreateWindowExW(
            0, L"BUTTON", L"모두를 멘션하기",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_AUTOCHECKBOX,
            0, 0, 150, 26,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        send_message_checkbox = CreateWindowExW(
            0, L"BUTTON", L"메시지 전송완료하기",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_AUTOCHECKBOX,
            0, 0, 180, 26,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        timing_button = CreateWindowExW(
            0, L"BUTTON", L"시간 설정",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_OWNERDRAW,
            0, 0, 150, 32,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        message_button = CreateWindowExW(
            0, L"BUTTON", L"목록에 내용 입력",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_OWNERDRAW,
            0, 0, 150, 30,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        log_label = CreateWindowExW(
            0, L"STATIC", L"진행 로그",
            WS_CHILD | WS_VISIBLE,
            0, 0, 100, 20,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        log_edit = CreateWindowExW(
            0, L"EDIT", L"",
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_BORDER |
                ES_MULTILINE | ES_AUTOVSCROLL | ES_READONLY,
            0, 0, 100, 100,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        if (listbox) {
            EnumWindows(collect_window, (LPARAM)listbox);
        }
        png_clipboard_format = RegisterClipboardFormatW(L"PNG");
        if (message_edit) SendMessageW(message_edit, EM_SETLIMITTEXT, 4095, 0);
        set_control_font(source_label, section_font);
        set_control_font(selected_label, section_font);
        set_control_font(listbox, app_font);
        set_control_font(selected_listbox, app_font);
        set_control_font(add_button, app_font);
        set_control_font(remove_button, app_font);
        set_control_font(settings_group, section_font);
        set_control_font(image_label, section_font);
        set_control_font(image_status, app_font);
        set_control_font(image_paste_button, app_font);
        set_control_font(image_clear_button, app_font);
        set_control_font(input_label, section_font);
        set_control_font(message_edit, app_font);
        set_control_font(mention_all_checkbox, app_font);
        set_control_font(send_message_checkbox, app_font);
        set_control_font(timing_button, app_font);
        set_control_font(message_button, app_font);
        set_control_font(log_label, section_font);
        set_control_font(log_edit, app_font);
        append_log(L"[준비] 카카오톡 대화창 검색을 완료했습니다.\r\n");
        layout_controls(hwnd);
        return 0;
    }
    if (message == WM_SIZE) {
        layout_controls(hwnd);
        return 0;
    }
    if (message == WM_ERASEBKGND && app_background_brush) {
        RECT client;
        if (GetClientRect(hwnd, &client)) {
            FillRect((HDC)wparam, &client, app_background_brush);
            return 1;
        }
    }
    if (message == WM_DRAWITEM) {
        DRAWITEMSTRUCT *item = (DRAWITEMSTRUCT *)lparam;
        if (item && item->hwndItem != settings_group) {
            draw_modern_button(item);
            return 1;
        }
    }
    if (message == WM_CTLCOLORSTATIC || message == WM_CTLCOLORBTN) {
        if ((HWND)lparam == log_edit) {
            SetBkColor((HDC)wparam, RGB_COLOR(255, 255, 255));
            SetTextColor((HDC)wparam, RGB_COLOR(31, 41, 55));
            return (LRESULT)surface_brush;
        }
        SetBkMode((HDC)wparam, TRANSPARENT);
        SetTextColor((HDC)wparam, RGB_COLOR(31, 41, 55));
        return (LRESULT)app_background_brush;
    }
    if (message == WM_CTLCOLOREDIT || message == WM_CTLCOLORLISTBOX) {
        SetBkColor((HDC)wparam, RGB_COLOR(255, 255, 255));
        SetTextColor((HDC)wparam, RGB_COLOR(31, 41, 55));
        return (LRESULT)surface_brush;
    }
    if (message == WM_COMMAND) {
        if (((wparam >> 16) & 0xFFFFu) == 0 && !(HWND)lparam) {
            UINT command_id = (UINT)(wparam & 0xFFFFu);
            if (command_id == IDM_OPTIONS) {
                show_timing_settings();
                return 0;
            }
            if (command_id == IDM_CHECK_UPDATES) {
                check_for_updates();
                return 0;
            }
            if (command_id == IDM_ABOUT) {
                show_program_information();
                return 0;
            }
        }
        if (((wparam >> 16) & 0xFFFFu) == LBN_DBLCLK) {
            if ((HWND)lparam == listbox) {
                move_selected_rooms(listbox, selected_listbox);
                return 0;
            }
            if ((HWND)lparam == selected_listbox) {
                move_selected_rooms(selected_listbox, listbox);
                return 0;
            }
        }
        if (((wparam >> 16) & 0xFFFFu) == 0) {
            if ((HWND)lparam == add_button) {
                move_selected_rooms(listbox, selected_listbox);
                return 0;
            }
            if ((HWND)lparam == remove_button) {
                move_selected_rooms(selected_listbox, listbox);
                return 0;
            }
            if ((HWND)lparam == image_paste_button) {
                if (capture_clipboard_image()) {
                    append_log(L"[이미지] 클립보드 이미지를 저장했습니다.\r\n");
                } else {
                    append_log(L"[실패] 클립보드에서 지원되는 이미지를 찾지 못했습니다.\r\n");
                }
                return 0;
            }
            if ((HWND)lparam == image_clear_button) {
                clear_stored_image(1);
                return 0;
            }
            if ((HWND)lparam == timing_button) {
                show_timing_settings();
                return 0;
            }
            if ((HWND)lparam == message_button) {
                type_message_to_selected_rooms();
                return 0;
            }
        }
    }
    if (message == WM_DESTROY) {
        clear_stored_image(0);
        if (section_font && section_font != app_font) DeleteObject(section_font);
        if (app_font && app_font != GetStockObject(DEFAULT_GUI_FONT)) DeleteObject(app_font);
        if (private_semibold_font_handle) RemoveFontMemResourceEx(private_semibold_font_handle);
        if (private_regular_font_handle) RemoveFontMemResourceEx(private_regular_font_handle);
        if (surface_brush) DeleteObject(surface_brush);
        if (app_background_brush) DeleteObject(app_background_brush);
        section_font = (HFONT)0;
        app_font = (HFONT)0;
        private_semibold_font_handle = (HANDLE)0;
        private_regular_font_handle = (HANDLE)0;
        surface_brush = (HBRUSH)0;
        app_background_brush = (HBRUSH)0;
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, message, wparam, lparam);
}

void app_entry(void) {
    HINSTANCE instance = GetModuleHandleW((LPCWSTR)0);
    WNDCLASSW wc;
    WNDCLASSW preview_class;
    WNDCLASSW timing_class;
    HMENU app_menu;
    HWND hwnd;
    MSG msg;
    HRSRC regular_font_resource;
    HRSRC semibold_font_resource;
    HGLOBAL regular_font_resource_data;
    HGLOBAL semibold_font_resource_data;
    void *regular_font_bytes;
    void *semibold_font_bytes;
    DWORD regular_font_size;
    DWORD semibold_font_size;
    DWORD font_count = 0;
    LPCWSTR font_face;

    regular_font_resource = FindResourceW(
        instance,
        (LPCWSTR)(unsigned long long)IDR_PRETENDARD_REGULAR_FONT,
        (LPCWSTR)(unsigned long long)RT_RCDATA
    );
    semibold_font_resource = FindResourceW(
        instance,
        (LPCWSTR)(unsigned long long)IDR_PRETENDARD_SEMIBOLD_FONT,
        (LPCWSTR)(unsigned long long)RT_RCDATA
    );
    regular_font_resource_data = regular_font_resource ?
        LoadResource(instance, regular_font_resource) : (HGLOBAL)0;
    semibold_font_resource_data = semibold_font_resource ?
        LoadResource(instance, semibold_font_resource) : (HGLOBAL)0;
    regular_font_bytes = regular_font_resource_data ?
        LockResource(regular_font_resource_data) : (void *)0;
    semibold_font_bytes = semibold_font_resource_data ?
        LockResource(semibold_font_resource_data) : (void *)0;
    regular_font_size = regular_font_resource ? SizeofResource(instance, regular_font_resource) : 0;
    semibold_font_size = semibold_font_resource ? SizeofResource(instance, semibold_font_resource) : 0;
    if (regular_font_bytes && regular_font_size) {
        private_regular_font_handle = AddFontMemResourceEx(
            regular_font_bytes, regular_font_size, (void *)0, &font_count
        );
    }
    font_count = 0;
    if (semibold_font_bytes && semibold_font_size) {
        private_semibold_font_handle = AddFontMemResourceEx(
            semibold_font_bytes, semibold_font_size, (void *)0, &font_count
        );
    }
    font_face = private_regular_font_handle ? L"Pretendard" : L"Segoe UI";

    app_background_brush = CreateSolidBrush(RGB_COLOR(245, 247, 250));
    surface_brush = CreateSolidBrush(RGB_COLOR(255, 255, 255));
    app_font = CreateFontW(
        -17, 0, 0, 0, FW_NORMAL, 0, 0, 0,
        DEFAULT_CHARSET, 0, 0, CLEARTYPE_QUALITY, 0, font_face
    );
    section_font = CreateFontW(
        -17, 0, 0, 0, FW_SEMIBOLD, 0, 0, 0,
        DEFAULT_CHARSET, 0, 0, CLEARTYPE_QUALITY, 0, font_face
    );
    if (!app_font) app_font = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
    if (!section_font) section_font = app_font;

    preview_class.style = 0;
    preview_class.lpfnWndProc = image_preview_proc;
    preview_class.cbClsExtra = 0;
    preview_class.cbWndExtra = 0;
    preview_class.hInstance = instance;
    preview_class.hIcon = (HICON)0;
    preview_class.hCursor = LoadCursorW((HINSTANCE)0, (LPCWSTR)(unsigned long long)IDC_ARROW);
    preview_class.hbrBackground = surface_brush ? surface_brush :
        (HBRUSH)(unsigned long long)(COLOR_WINDOW + 1);
    preview_class.lpszMenuName = (LPCWSTR)0;
    preview_class.lpszClassName = L"ImagePreviewMVP";
    RegisterClassW(&preview_class);

    timing_class.style = 0;
    timing_class.lpfnWndProc = timing_window_proc;
    timing_class.cbClsExtra = 0;
    timing_class.cbWndExtra = 0;
    timing_class.hInstance = instance;
    timing_class.hIcon = (HICON)0;
    timing_class.hCursor = LoadCursorW((HINSTANCE)0, (LPCWSTR)(unsigned long long)IDC_ARROW);
    timing_class.hbrBackground = app_background_brush ? app_background_brush :
        (HBRUSH)(unsigned long long)(COLOR_WINDOW + 1);
    timing_class.lpszMenuName = (LPCWSTR)0;
    timing_class.lpszClassName = L"TimingSettingsMVP";
    RegisterClassW(&timing_class);

    wc.style = 0;
    wc.lpfnWndProc = window_proc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = instance;
    wc.hIcon = (HICON)0;
    wc.hCursor = LoadCursorW((HINSTANCE)0, (LPCWSTR)(unsigned long long)IDC_ARROW);
    wc.hbrBackground = app_background_brush ? app_background_brush :
        (HBRUSH)(unsigned long long)(COLOR_WINDOW + 1);
    wc.lpszMenuName = (LPCWSTR)0;
    wc.lpszClassName = L"WindowListMVP";
    RegisterClassW(&wc);

    app_menu = create_app_menu();
    hwnd = CreateWindowExW(
        0, wc.lpszClassName, APP_TITLE,
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        (int)0x80000000u, (int)0x80000000u, 1120, 700,
        (HWND)0, (HANDLE)app_menu, instance, (void *)0
    );
    if (!hwnd) ExitProcess(1);
    while (GetMessageW(&msg, (HWND)0, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    ExitProcess((UINT)msg.wParam);
}
