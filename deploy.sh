#!/usr/bin/env bash
set -euo pipefail

# ---- Config ---------------------------------------------------------------
APP_NAME="MiniProject"                 # CMake target / .app name
PRESET="${1:-mac-debug}"               # pass mac-debug or mac-release
BUILD_PRESET="build-${PRESET#mac-}"    # build-debug or build-release
QT_BIN="$(brew --prefix qt)/bin"       # Homebrew Qt bin dir
APP_DIR="build/${PRESET#mac-}/${APP_NAME}.app"
# --------------------------------------------------------------------------

echo "==> Clean old app bundle (if any): ${APP_DIR}"
rm -rf "${APP_DIR}"

echo "==> Configure: ${PRESET}"
cmake --preset "${PRESET}"

echo "==> Build: ${BUILD_PRESET}"
cmake --build --preset "${BUILD_PRESET}"

echo "==> Bundle frameworks with macdeployqt"
"${QT_BIN}/macdeployqt" "${APP_DIR}" -verbose=3 -always-overwrite

echo "==> Clear quarantine flags (Gatekeeper)"
xattr -dr com.apple.quarantine "${APP_DIR}" || true

echo "==> Ad-hoc codesign (recursive)"
codesign --force --deep -s - "${APP_DIR}"

echo "==> Verify codesign"
codesign --verify --deep --strict --verbose=2 "${APP_DIR}" || true

echo "==> Open app…"
open "${APP_DIR}"

echo "✅ Done."