#!/bin/bash

ffmpeg -i source -ss 0:00:23 -t 30 output
ffmpeg -i source -ss 0:00:22 -to 0:00:34 output
ffmpeg -i inputfile -vf reverse -af areverse -preset superfast reversed #reverse video
ffmpeg -i input -an -filter:v "setpts=0.5*PTS" output #playrate for video
ffmpeg -i input -filter:a "atempo=2.0" -vn output #playrate for audio
ffmpeg -f concat -i filelist.txt -c copy output #concate
ffmpeg -ss 0:00:00 -t 12 -i source  -c:v libx264 -c:a aac -strict experimental -b:a 98k out #clip file accurately

ffmpeg -i outvideo3.mp4 -vf “crop=iw/2:ih:0:0,split[left][tmp];[tmp]hflip[right];[left][right] hstack” -acodec copy -qscale 4 -vcodec mpeg4  outvideo4.mp4