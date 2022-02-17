#!/bin/sh
case "$1" in
    --popup)
        notify-send "🧠 Memory hogs" "$(ps axch -o cmd:10,pmem k -pmem | head | awk '$0=$0"%"' )"
        ;;
    *)
        echo " $(free -h --si | awk '/^Mem:/ {print $3}')"
        ;;
esac
