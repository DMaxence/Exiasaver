#!/bin/sh
gcc ../static/*.c ../common/*.c ../launcher/getTerminalSize.c -o exiasaver1
gcc ../dynamic/*.c ../common/*.c ../launcher/getTerminalSize.c -o exiasaver2
gcc ../interactive/*.c ../common/*.c ../launcher/getTerminalSize.c -o exiasaver3
gcc ../launcher/*.c -o launcher
