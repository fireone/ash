# ash
ash (namned after the droid in Alien) is an autonomous lawn mower project.

![Ash himself](https://static.wikia.nocookie.net/alienanthology/images/6/62/Alien_Ian_Holm1.jpg/revision/latest?cb=20210323150713)

# Features

## Perimeter free!
For navigation ash will utilize an uBlox ZED-F9R (onboard) and an uBlox ZED-F9P (base station). The ZED-F9P will send RTCM data to the ZED-F9R and together with the integrated IMU this should be enough to suffice without perimeter wire.

The ZED-F9R and ZED-F9P will communicate with eachother using two XBEE devices configured as a transparent p2p uart link. This is tested on devkits and is fully functional.

## Wireless charging
ash will use wireless charging. No more cumbersome docking.

## New scope: Let's Simulate!
A strategic decision has been made, in order to develop coverage planning and more ash will include a simulator. 
