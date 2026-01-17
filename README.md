# OOP-Cryptography-Project

Project for Object Orientation class

Cross-platform **Qt 6 + CMake** project using **VS Code**.  
Builds natively on **macOS** and **Windows** — no Docker or global Qt install required.

---

## 🚀 Quick Start

### Terminal Scripts

In order to run Command Line scripts for actions like "reconfigure", "build", "run":

- Copy the code in .vscode/launch.template.json
- Create new file -> .vscode/launch.json
- Paste and save
- \*\* Because this file generates local artifacts, Git is set to ignore this file
- In the root terminal, run:

```bash
chmod +x ./scripts/task
```

- Verify:

```bash
ls -l ./scripts/task
```

- Should see something like:

```bash
-rwxr-xr-x  1 calebberry  staff  1234 Nov 11 12:45 ./scripts/task
```

- Set up your alias (Mac):

```bash
alias task="./scripts/task"
source ~/.zshrc
```

- Alias (Windows -> In PowerShell)

```powershell
notepad $PROFILE # If this file doesn't exist, PowerShell will ask to make it: Choose 'Yes'
Set-Alias task "C:\path\to\MiniProject\scripts\task.ps1" # Paste at bottom of the file

# Save NotePad file, and close

. $PROFILE # Run in PowerShell

# Test
task help
task build
task run
```

- Commands:

```bash
task help # Shows all available commands
task reconfig # Runs CMake configuration - generates the build system (only need to run once)
task build # Compiles the project using the build directory
task start # Launches the compiled app
task run # Alias for task start, works the same way
task rebuild # Shortcut that runs 'reconfig' -> 'build' -> 'start' (full refresh)
task clean # Deletes the entire build directory for a clean rebuild
task lint # Runs qmllint (if installed) over all .qml files in src/ -> Non-fatal, shows warnings
```

### 🧩 macOS Setup

```bash
# 1. Install developer tools
xcode-select --install
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Verify
clang++ --version

# 2. Install dependencies
brew install cmake qt

# Verify
cmake --version
qmake -v

# 3. Clone the repo
git clone https://github.com/CalebBerry1/Mini-Project.git
cd MiniProject

# 4. Make a local build directory
mkdir build && cd build
cmake .. DCMAKE_PREFIX_PATH=$(brew --prefix qt)/lib/cmake
cmake --build

# 4. Build & run (Debug)
cmake --preset mac-debug
cmake --build --preset build-debug
./build/debug/MiniProject.app/Contents/MacOS/MiniProject

# 5. Or bundle a distributable .app
./deploy.sh              # mac-debug (default)
./deploy.sh mac-release  # or release build
```

### Windows Setup

- Run all commands in **Developer PowerShell for VS 2022**
- If PowerShell blocks any scripts, use:

```powershell
Set-ExecutionPolicy -Scope Process Bypass
```

```bash
# 1. Install Visual Studio C++ Tools
Go to -> https://visualstudio.microsoft.com/visual-cpp-build-tools/
Download Build Tools
Check Desktop development with C++
 - Select MSVC v143 build tools
 - Windows 10 or 11 SDK
 - C++ CMake tools for Windows
 - Optional (recommended) -> vcpkg package manager, C++ AddressSanitizer
Verify installation -> cmake --version

# 2. Install Qt
Go to -> qt.io/download-qt-installer
Download the installer
Create a Qt account
In the Component section choose Qt 6.10.0
 - Click the expansion arrow
 - Deselect MinGW and choose MSVC 2022 64-bit (msvc2022_64
Use default install path (C:\Qt)
Verify installation -> "C:\Qt\6.10.0\msvc2022_64\bin\qmake.exe" -v
Should show
  "QMake version 3.~"
  "Using Qt version 6.10.0 in C:/Qt/6.10.0/msvc2022_64/lib"

# 3. Clone Repository
Open VS Code
File -> Open Folder
Go to your C:\ drive
Create a new folder and name it "dev"
Select your new folder to open
Make sure that you are in the new directory you just made (C:/dev/)
If you aren't automatically in the correct directory, enter this command into the terminal -> cd dev
Clone the repo to the directory -> git clone https://github.com/CalebBerry1/Mini-Project.git

# 4. Configure CMake to find Qt
Navigate to \dev\Mini-Project -> cd \dev\Mini-Project
Make a new directory and name it build -> mkdir build
cd build
Show CMake where to find Qt -> cmake .. -DCMAKE_PREFIX_PATH="C:\Qt\6.10.0\msvc2022_64\lib\cmake"

# 5. Build Project
In the same \dev\Mini-Project\build directory -> cmake --build . --config Debug
You should now see a line that reads "C:\dev\Mini-Project\build\Debug\MiniProject.exe
```

### Troubleshooting

Windows:

#### 1. Verify your Qt installation

- Check that Qt6Config.cmake exists where you expect it:

```powershell
Test-Path "C:\Qt\6.10.0\msvc2022_64\lib\cmake\Qt6\Qt6Config.cmake"
```

- True -> Qt is installed correctly
- False -> Reinstall or correct CMAKE_PREFIX_PATH

#### 2. Clean old CMake caches

- If CMake gives a "cannot find Qt6Config.cmake" or version mismatch error:

```powershell
Remove-Item -Recurse -Force build\win-debug -ErrorAction SilentlyContinue
```

- Then reconfigure cleanly:

```powershell
cmake -S . -B build\win-debug -G "Ninja" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH="C:\Qt\6.10.0\msvc2022_64\lib\cmake"
```

#### 3. Confirm correct compiler architecture

- If you see this in the output:
- ```powershell
  Check for working CXX compiler: ...Hostx86/x86/cl.exe
  ```
- That means that you're in a 32-bit shell, but Qt is 64-bit
- Open x64 Native Tools Command Prompt for VS 2022 (or run in PowerShell)

```powershell
& "C:\Program Files\Microsoft Visual Studio\2022\BuildTools\Common7\Tools\Launch-VsDevShell.ps1" - Arch amd64 -HostPowerShell
```

- Confirm:

```powershell
where cl.exe
```

- The path should include Hostx64\x64

#### 4. Bypass PowerShell script restrictions

- If deploy.ps1 doesn't run and gives a policy warning:

```powershell
Set-ExecutionPolicy -Scope Process Bypass
```

- Then run:

```powershell
.\deploy.ps1 -Preset win-debug
```

#### 5. If .ps1 opens in Notepad

- You accidentally ran it in CMD instead of PowerShell
- Run from PowerShell, Developer PowerShell for VS 2022 (or explicitly call PowerShell)

```powershell
-ExecutionPolicy Bypass -File .\deploy.ps1 -Preset win-debug
```

#### 6. Missing Qt DLLs (e.g., "Qt6Core.dll not found")

- Bundle them automatically:

```powershell
"C:\Qt\6.10.0\msvc2022_64\bin\windeployqt.exe" --debug --compiler-runtime build\win-debug\MiniProject.exe
```

#### 7. Verify CMake cache points at correct Qt

- Check inside your build directory:

```powershell
findstr /I "Qt6_DIR CMAKE_PREFIX_PATH" build\win-debug\CMakeCache.txt
```

- Should show your Qt path (C:/Qt/6.10.0/msvc2022_64/lib/cmake)

#### 8. If something is really broken and all else fails:

```powershell
Remove-Item -Recurse -Force build -ErrorAction SilentlyContinue
cmake -S . -B build -G "Ninja" -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH="C:\Qt\6.10.0\msvc2022_64\lib\cmake"
cmake --build build
.\build\MiniProject.exe


```
