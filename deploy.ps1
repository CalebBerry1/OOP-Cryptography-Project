# Build + bundle a Qt app on Windows (MSVC + Ninja)
param(
  [string]$Preset = "win-release"   # use "win-debug" or "win-release"
)

$ErrorActionPreference = "Stop"

# ---- Config ---------------------------------------------------------------
$AppName    = "MiniProject"  # CMake target/exe name
$BuildPreset = if ($Preset -eq "win-debug") { "build-win-debug" } else { "build-win-release" }

# Change this if your Qt path differs (adjust version/kit as needed)
$QtRoot = "C:\Qt\6.10.0\msvc2022_64"
$QtBin  = Join-Path $QtRoot "bin"

# Output exe path based on preset
$BinDir = if ($Preset -eq "win-debug") { "build\win-debug" } else { "build\win-release" }
$ExePath = Join-Path $BinDir "$AppName.exe"
# --------------------------------------------------------------------------

# Ensure MSVC environment is loaded (run in "x64 Native Tools Command Prompt for VS 2022")
if (-not (Get-Command cl.exe -ErrorAction SilentlyContinue)) {
  Write-Error "MSVC environment not detected. Open 'x64 Native Tools Command Prompt for VS 2022' and run this script."
}

Write-Host "==> Configure: $Preset"
cmake --preset $Preset

Write-Host "==> Build: $BuildPreset"
cmake --build --preset $BuildPreset

if (-not (Test-Path $ExePath)) {
  Write-Error "Expected exe not found at $ExePath"
}

Write-Host "==> Running windeployqt"
& (Join-Path $QtBin "windeployqt.exe") $ExePath --compiler-runtime | Write-Host

Write-Host "==> Launching app…"
Start-Process $ExePath

Write-Host "✅ Done."