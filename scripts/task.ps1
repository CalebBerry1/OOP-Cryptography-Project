param(
    [Parameter(Position=0)]
    [string]$cmd = "help"
)

$SRC_DIR = (Get-Item $PSScriptRoot).Parent.FullName
$BUILD_DIR = Join-Path $SRC_DIR "build\win-debug"
$APP_PATH = Join-Path $BUILD_DIR "Debug\CryptographyProject.exe"

switch ($cmd) {
    "reconfig" {
        Write-Host "🔧 Configuring CMake..."
        cmake --preset win-debug
    }
    "build" {
        Write-Host "🏗️  Building..."
        cmake --build $BUILD_DIR --parallel
    }
    "start" {
        Write-Host "🚀  Starting..."
        if (-Not (Test-Path $APP_PATH)) {
            Write-Host "App not built yet. Building..."
            cmake --build $BUILD_DIR --parallel
        }
        & $APP_PATH
    }
    "rebuild" {
        & $PSCommandPath "reconfig"
        & $PSCommandPath "build"
        & $PSCommandPath "start"
    }
    "clean" {
        Write-Host "🧹  Cleaning build directory..."
        Remove-Item -Recurse -Force $BUILD_DIR -ErrorAction SilentlyContinue
    }
    default {
        Write-Host @"
Usage: task <command>

Commands:
  reconfig   Configure CMake
  build      Build the app
  start      Run the built app
  rebuild    Reconfigure + build + start
  clean      Delete build dir
"@
    }
}