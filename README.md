<img width="1536" height="1024" alt="DisableSearch" src="https://github.com/user-attachments/assets/74c53483-f94d-4102-bb8c-717c4f821104" />
# 🚀 Disable Windows 11 Web Search | C++ Registry Utility

> **A lightweight, open-source Windows 11 utility to disable web search results in the Windows Search experience using the Windows Registry API.**

Perfect for users who prefer **local search only** without web search integration.

---

## ✨ Features

* 🚀 One-click executable
* 🔐 Automatically requests Administrator privileges (UAC)
* ⚡ Lightweight (native Win32 C++)
* 🪟 Uses the official Windows Registry API
* 📦 Precompiled executable available in the **Releases** section
* 🔧 Full C++ source code included
* ❌ No background services
* ❌ No scheduled tasks
* ❌ No third-party dependencies

---

# 📸 Preview

```text
Launch EXE
      │
      ▼
Checks Administrator Privileges
      │
      ▼
Requests UAC Elevation (if required)
      │
      ▼
Creates Registry Key
      │
      ▼
Writes Registry Value
      │
      ▼
Operation Complete
      │
      ▼
Restart Windows
```

---

# 📥 Download

The easiest way to use this project is through the **Releases** page.

```
Releases
└── DisableSearch.exe
```

Simply download the latest executable.

No installation required.

---

# 🚀 How to Use

## Method 1 — Pre-built Executable (Recommended)

1. Download **DisableSearch.exe** from **Releases**.
2. Double-click the executable.
3. Accept the **User Account Control (UAC)** prompt.
4. Wait until the program reports **Success**.
5. Restart your computer.
6. Open Windows Search and verify the changes.

---

## Method 2 — Build from Source

### Visual Studio [Open X64 Native tool command prompt]

```bat
cl /EHsc /O2 /MT /std:c++17 main.cpp
```

### MinGW

```bat
g++ main.cpp -o DisableSearch.exe -static -static-libgcc -static-libstdc++
```

---

# 🔧 How It Works

The application performs the following steps:

* Detects whether it is running with Administrator privileges.
* Automatically requests elevation through Windows UAC if necessary.
* Creates the required Windows Registry path.
* Writes the registry value used by supported Windows 11 builds.
* Reports Windows error codes if an operation fails.

No system files are modified.

No Windows binaries are patched.

Only the registry is updated.

---

# 📂 Registry Location

```text
HKEY_CURRENT_USER
└── Software
    └── Policies
        └── Microsoft
            └── Windows
                └── Explorer

DisableSearchBoxSuggestions = 1 (DWORD)
```

---

# 🖥 Supported Operating Systems

This project is designed for **Windows 11**.

| Windows Version                   | Status                                                          |
| --------------------------------- | --------------------------------------------------------------- |
| Windows 11 22H2                   | ✅ Supported                                                     |
| Windows 11 23H2                   | ✅ Supported                                                     |
| Windows 11 24H2                   | ✅ Supported                                                     |
| Windows 11 Insider (Build 26200+) | ⚠ Registry value may be ignored by newer Search implementations |

> **Note**
>
> Microsoft periodically changes Windows Search through feature updates. While this utility successfully writes the registry value, newer Insider builds may no longer honor that policy.

---

# 📁 Project Structure

```
.
├── main.cpp
├── README.md
└── Releases
    └── DisableSearch.exe
```

---

# ❗ Troubleshooting

## Error 5 (Access Denied)

Possible reasons:

* Administrator permission was not granted.
* UAC prompt was cancelled.
* Security software blocked registry modification.
* Windows Group Policy prevented changes.

---

## Registry Updated Successfully But Nothing Changed

Some recent Windows 11 Insider builds no longer respect the legacy registry policy used by this utility.

This is a Microsoft operating system behavior rather than an application issue.

---

# ❓ Frequently Asked Questions

### Does this uninstall anything?

No.

---

### Does this modify Windows system files?

No.

Only a registry value is written.

---

### Does this run in the background?

No.

The application exits immediately after completing its task.

---

### Is a restart required?

Yes.

Restarting Windows is the recommended way to ensure the Search process reloads the updated policy.

---

# 🤝 Contributing

Contributions are welcome.

If you discover a Windows build where the registry policy behaves differently, please include:

* Windows Edition
* Windows Build Number
* Error Code (if any)
* Steps to reproduce

---

# ⚠ Disclaimer

This project modifies Windows Registry settings.

Create a System Restore Point or export the registry before making system configuration changes.

Microsoft may change the behavior of Windows Search in future Windows updates, which can affect whether this registry policy remains supported.

This project is provided **"as is"** without warranty of any kind.

---

# ⭐ Support the Project

If you found this project useful:

* ⭐ Star the repository
* 🍴 Fork it
* 🐛 Report issues
* 💡 Suggest improvements

Your support helps improve the project and makes it easier for others to discover.
