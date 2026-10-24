/*
 * KakaoTalk Chat Window List MVP
 * Windows 10/11 x64, single native Win32 executable, no third-party runtime.
 *
 * At launch, list only currently visible, separately opened KakaoTalk chat
 * windows. Rooms can be moved into a user-selected room list. Select one and
 * click focus to activate its message editor. The fixed key-sequence button
 * focuses that editor and sends @, Enter, then 가나다. A separate text field
 * types its content into each selected room without sending a final Enter.
 */

typedef unsigned short wchar_t;
typedef void *HANDLE;
typedef HANDLE HWND;
typedef HANDLE HINSTANCE;
typedef HANDLE HICON;
typedef HANDLE HCURSOR;
typedef HANDLE HBRUSH;
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
/* Matching Windows 64-bit INPUT layout: sizeof(INPUT) == 40. */
typedef struct {
    WORD wVk;
    WORD wScan;
    DWORD dwFlags;
    DWORD time;
    unsigned long long dwExtraInfo;
} KEYBDINPUT;
typedef struct {
    DWORD type;
    union {
        KEYBDINPUT ki;
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
__declspec(dllimport) int GetWindowTextW(HWND, LPWSTR, int);
__declspec(dllimport) LRESULT SendMessageW(HWND, UINT, WPARAM, LPARAM);
__declspec(dllimport) BOOL MoveWindow(HWND, int, int, int, int, BOOL);
__declspec(dllimport) BOOL GetClientRect(HWND, RECT *);
__declspec(dllimport) BOOL GetMessageW(MSG *, HWND, UINT, UINT);
__declspec(dllimport) BOOL TranslateMessage(const MSG *);
__declspec(dllimport) LRESULT DispatchMessageW(const MSG *);
__declspec(dllimport) void PostQuitMessage(int);
__declspec(dllimport) HCURSOR LoadCursorW(HINSTANCE, LPCWSTR);
__declspec(dllimport) HANDLE GetStockObject(int);

#define WS_OVERLAPPEDWINDOW   0x00CF0000u
#define WS_VISIBLE            0x10000000u
#define WS_CHILD              0x40000000u
#define WS_VSCROLL            0x00200000u
#define WS_TABSTOP            0x00010000u
#define WS_BORDER             0x00800000u
#define ES_AUTOHSCROLL        0x0080u
#define LBS_NOTIFY            0x0001u
#define LBS_NOINTEGRALHEIGHT  0x0100u
#define WM_CREATE             0x0001u
#define WM_DESTROY            0x0002u
#define WM_SIZE               0x0005u
#define WM_COMMAND            0x0111u
#define WM_SETFONT            0x0030u
#define EM_SETLIMITTEXT       0x00C5u
#define LB_ADDSTRING          0x0180u
#define LB_DELETESTRING       0x0182u
#define LB_SETCURSEL          0x0186u
#define LB_GETCURSEL          0x0188u
#define LB_GETTEXT            0x0189u
#define LB_GETCOUNT           0x018Bu
#define LB_GETITEMDATA        0x0199u
#define LB_SETITEMDATA        0x019Au
#define LB_ERR                (-1)
#define LB_ERRSPACE           (-2)
#define LBN_SELCHANGE         1u
#define SW_RESTORE            9
#define INPUT_KEYBOARD        1u
#define KEYEVENTF_KEYUP       0x0002u
#define KEYEVENTF_UNICODE     0x0004u
#define VK_RETURN             0x0Du
#define COLOR_WINDOW          5u
#define DEFAULT_GUI_FONT      17
#define IDC_ARROW             32512u
#define PROCESS_QUERY_LIMITED_INFORMATION 0x1000u

static HWND listbox;
static HWND selected_listbox;
static HWND active_listbox;
static HWND source_label;
static HWND selected_label;
static HWND input_label;
static HWND add_button;
static HWND remove_button;
static HWND focus_button;
static HWND keys_button;
static HWND message_edit;
static HWND message_button;
static HWND main_window;
static wchar_t prepared_text[4096];

static int maximum(int a, int b) { return a > b ? a : b; }

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
    if (!GetClientRect(hwnd, &rect)) return;
    width = rect.right - rect.left;
    height = rect.bottom - rect.top;
    list_width = maximum(0, (width - 150) / 2);
    list_height = maximum(0, height - 144);
    center_x = 20 + list_width;
    right_x = center_x + 110;
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
    if (focus_button) {
        MoveWindow(focus_button, 10, maximum(0, height - 92), 110, 30, 1);
    }
    if (keys_button) {
        MoveWindow(keys_button, 130, maximum(0, height - 92), 110, 30, 1);
    }
    if (input_label) {
        MoveWindow(input_label, 10, maximum(0, height - 48), 70, 24, 1);
    }
    if (message_edit) {
        MoveWindow(message_edit, 80, maximum(0, height - 54), maximum(0, width - 250), 30, 1);
    }
    if (message_button) {
        MoveWindow(message_button, maximum(0, width - 160), maximum(0, height - 54), 150, 30, 1);
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
    BOOL attached;
    BOOL focused;

    if (!IsWindow(chat) || !looks_like_chat_window(chat)) return 0;
    if (IsIconic(chat)) ShowWindow(chat, SW_RESTORE);
    SetForegroundWindow(chat);
    if (GetForegroundWindow() != chat) return 0;

    EnumChildWindows(chat, find_input_child, (LPARAM)&candidate);
    if (!candidate.editor || !IsWindow(candidate.editor)) return 0;
    editor_thread = GetWindowThreadProcessId(candidate.editor, (DWORD *)0);
    gui_thread = GetCurrentThreadId();
    if (!editor_thread) return 0;
    if (gui_thread == editor_thread) {
        SetFocus(candidate.editor);
        return GetFocus() == candidate.editor && GetForegroundWindow() == chat;
    }

    attached = AttachThreadInput(gui_thread, editor_thread, 1);
    if (!attached) return 0;
    SetFocus(candidate.editor);
    focused = GetFocus() == candidate.editor;
    AttachThreadInput(gui_thread, editor_thread, 0);
    return focused && GetForegroundWindow() == chat;
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

static HWND selected_chat_window(void) {
    HWND room_list = active_listbox ? active_listbox : listbox;
    LRESULT index;
    if (!room_list) return (HWND)0;
    index = SendMessageW(room_list, LB_GETCURSEL, 0, 0);
    return chat_window_at(room_list, index);
}

static void move_selected_room(HWND from, HWND to) {
    wchar_t title[512];
    LRESULT index;
    LRESULT item_data;
    LRESULT new_index;
    if (!from || !to) return;
    index = SendMessageW(from, LB_GETCURSEL, 0, 0);
    if (index == LB_ERR) return;
    item_data = SendMessageW(from, LB_GETITEMDATA, (WPARAM)index, 0);
    if (item_data == LB_ERR) return;
    if (SendMessageW(from, LB_GETTEXT, (WPARAM)index, (LPARAM)title) == LB_ERR) return;
    new_index = SendMessageW(to, LB_ADDSTRING, 0, (LPARAM)title);
    if (new_index == LB_ERR || new_index == LB_ERRSPACE) return;
    SendMessageW(to, LB_SETITEMDATA, (WPARAM)new_index, item_data);
    SendMessageW(from, LB_DELETESTRING, (WPARAM)index, 0);
    SendMessageW(to, LB_SETCURSEL, (WPARAM)new_index, 0);
    active_listbox = to;
}

static void focus_selected_window(void) {
    HWND target = selected_chat_window();
    if (target) focus_chat_input(target);
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

/* The button itself steals foreground focus. Restore the selected chat editor
 * before sending real keyboard input. If foreground changed, abort early. */
static void type_sequence_to_selected(void) {
    HWND target = selected_chat_window();
    const wchar_t *suffix = L"가나다";
    if (!target || !focus_chat_input(target)) return;

    if (GetForegroundWindow() != target || !send_character(L'@')) return;
    Sleep(150);  /* Allow KakaoTalk to process @ / mention UI. */
    if (GetForegroundWindow() != target || !send_enter()) return;
    Sleep(150);  /* Allow KakaoTalk to process Enter before further typing. */
    if (GetForegroundWindow() != target) return;
    while (*suffix) {
        if (GetForegroundWindow() != target || !send_character(*suffix)) return;
        ++suffix;
    }
}

static BOOL type_text_to_chat(HWND target, const wchar_t *text) {
    if (!target || !focus_chat_input(target)) return 0;
    while (*text) {
        if (GetForegroundWindow() != target || !send_character(*text)) return 0;
        ++text;
    }
    return 1;
}

/* Type the prepared text into every manually selected room in list order.
 * No Enter is appended, so this action does not intentionally send a message.
 * Stop the entire traversal if any target or focus verification fails. */
static void type_message_to_selected_rooms(void) {
    LRESULT count;
    LRESULT index;
    HWND target;
    if (!message_edit || !selected_listbox) return;
    if (!GetWindowTextW(message_edit, prepared_text, 4096)) return;
    count = SendMessageW(selected_listbox, LB_GETCOUNT, 0, 0);
    if (count == LB_ERR || count <= 0) return;
    for (index = 0; index < count; ++index) {
        target = chat_window_at(selected_listbox, index);
        if (!target || !type_text_to_chat(target, prepared_text)) return;
        if (index + 1 < count) Sleep(1500);
    }
}

static void set_default_font(HWND control) {
    if (control) {
        SendMessageW(control, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), 1);
    }
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
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_TABSTOP | LBS_NOTIFY | LBS_NOINTEGRALHEIGHT,
            0, 0, 100, 100,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        selected_listbox = CreateWindowExW(
            0, L"LISTBOX", L"",
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_TABSTOP | LBS_NOTIFY | LBS_NOINTEGRALHEIGHT,
            0, 0, 100, 100,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        add_button = CreateWindowExW(
            0, L"BUTTON", L"선택 →",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP,
            0, 0, 90, 30,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        remove_button = CreateWindowExW(
            0, L"BUTTON", L"← 제외",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP,
            0, 0, 90, 30,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        focus_button = CreateWindowExW(
            0, L"BUTTON", L"포커스 이동",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP,
            0, 0, 110, 30,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        keys_button = CreateWindowExW(
            0, L"BUTTON", L"지정 키 입력",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP,
            0, 0, 110, 30,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        input_label = CreateWindowExW(
            0, L"STATIC", L"입력 내용",
            WS_CHILD | WS_VISIBLE,
            0, 0, 70, 24,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        message_edit = CreateWindowExW(
            0, L"EDIT", L"",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER | ES_AUTOHSCROLL,
            0, 0, 100, 30,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        message_button = CreateWindowExW(
            0, L"BUTTON", L"목록에 내용 입력",
            WS_CHILD | WS_VISIBLE | WS_TABSTOP,
            0, 0, 150, 30,
            hwnd, (HANDLE)0, instance, (void *)0
        );
        if (listbox) {
            EnumWindows(collect_window, (LPARAM)listbox);
        }
        active_listbox = listbox;
        if (message_edit) SendMessageW(message_edit, EM_SETLIMITTEXT, 4095, 0);
        set_default_font(source_label);
        set_default_font(selected_label);
        set_default_font(listbox);
        set_default_font(selected_listbox);
        set_default_font(add_button);
        set_default_font(remove_button);
        set_default_font(focus_button);
        set_default_font(keys_button);
        set_default_font(input_label);
        set_default_font(message_edit);
        set_default_font(message_button);
        layout_controls(hwnd);
        return 0;
    }
    if (message == WM_SIZE) {
        layout_controls(hwnd);
        return 0;
    }
    if (message == WM_COMMAND) {
        if (((wparam >> 16) & 0xFFFFu) == LBN_SELCHANGE &&
            ((HWND)lparam == listbox || (HWND)lparam == selected_listbox)) {
            active_listbox = (HWND)lparam;
            return 0;
        }
        if (((wparam >> 16) & 0xFFFFu) == 0) {
            if ((HWND)lparam == add_button) {
                move_selected_room(listbox, selected_listbox);
                return 0;
            }
            if ((HWND)lparam == remove_button) {
                move_selected_room(selected_listbox, listbox);
                return 0;
            }
            if ((HWND)lparam == focus_button) {
                focus_selected_window();
                return 0;
            }
            if ((HWND)lparam == keys_button) {
                type_sequence_to_selected();
                return 0;
            }
            if ((HWND)lparam == message_button) {
                type_message_to_selected_rooms();
                return 0;
            }
        }
    }
    if (message == WM_DESTROY) {
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, message, wparam, lparam);
}

void app_entry(void) {
    HINSTANCE instance = GetModuleHandleW((LPCWSTR)0);
    WNDCLASSW wc;
    HWND hwnd;
    MSG msg;

    wc.style = 0;
    wc.lpfnWndProc = window_proc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = instance;
    wc.hIcon = (HICON)0;
    wc.hCursor = LoadCursorW((HINSTANCE)0, (LPCWSTR)(unsigned long long)IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(unsigned long long)(COLOR_WINDOW + 1);
    wc.lpszMenuName = (LPCWSTR)0;
    wc.lpszClassName = L"WindowListMVP";
    RegisterClassW(&wc);

    hwnd = CreateWindowExW(
        0, wc.lpszClassName, L"카카오톡 대화창 목록",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        (int)0x80000000u, (int)0x80000000u, 820, 560,
        (HWND)0, (HANDLE)0, instance, (void *)0
    );
    if (!hwnd) ExitProcess(1);
    while (GetMessageW(&msg, (HWND)0, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    ExitProcess((UINT)msg.wParam);
}
