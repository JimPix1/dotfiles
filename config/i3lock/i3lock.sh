#!/bin/bash

# set the icon and bg image variable

icon="$HOME/.config/i3lock/icons/lock-screen.png"
tmpbg="/tmp/lockscreen.png"
overlay="$HOME/.config/i3lock/overlays/overlay01.png"

# takes screenshot

scrot -z "$tmpbg"

# adds blur

convert -scale 10% -blur 0x4 -resize 1000% "$tmpbg" "$tmpbg"

# adding overlay

#convert "$tmpbg" "$overlay" -gravity southeast -composite "$tmpbg"

# Add a lock icon and text to the center of an image

convert "$tmpbg" -font Hack -fill white -pointsize 16 -draw "text 570,470 'Hello! Please enter your password.'" "$icon" -gravity center -composite "$tmpbg"

# lock the screen with the blurred screenshot

i3lock -i "$tmpbg" -u -e

rm "$tmpbg"
