TOP_DIR="${ANDROID_BUILD_TOP:-.}"
CAMERA_APK="$TOP_DIR/vendor/xiaomi/camera/proprietary/system/priv-app/MiuiCamera/MiuiCamera.apk"
if [ ! -f "$CAMERA_APK" ]; then
    cat "$TOP_DIR"/vendor/xiaomi/camera/proprietary/system/priv-app/MiuiCamera/MiuiCamera.apk.part* > "$CAMERA_APK"
fi

# Fix front camera video HAL crash by disabling front EIS and SIGABRT
CAMX_SETTINGS="$TOP_DIR/vendor/xiaomi/renoir/proprietary/vendor/etc/camera/camxoverridesettings.txt"
if [ -f "$CAMX_SETTINGS" ] && ! grep -q "algoEISSupportedValue" "$CAMX_SETTINGS"; then
    echo "Patching camxoverridesettings for front camera video stabilization..."
    sed -i '/raiserecoverysigabrt/a raisesigabrt=FALSE\nalgoEISSupportedValue=0:16|1:0|21:16|G:0' "$CAMX_SETTINGS"
fi
