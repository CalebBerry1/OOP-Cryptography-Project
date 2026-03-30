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
        Write-Host "Usage:  task <command>"
        Write-Host ""
        Write-Host "Commands:"
        Write-Host " reconfig   Configure CMake"
        Write-Host " build      Build the app"
        Write-Host " start      Run the build app"
        Write-Host " rebuild    Reconfigure + build + start"
        Write-Host " clean      Delete build dir"
    }
}