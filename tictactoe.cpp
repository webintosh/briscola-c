//gioco di tris
#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include "time.h"

#if defined(_WIN32)
    #define PLATFORM_NAME "windows" // Windows
#elif defined(_WIN64)
    #define PLATFORM_NAME "windows" // Windows
#elif defined(__CYGWIN__) && !defined(_WIN32)
    #define PLATFORM_NAME "windows" // Windows (Cygwin POSIX under Microsoft Window)
#elif defined(__ANDROID__)
    #define PLATFORM_NAME "android" // Android (implies Linux, so it must come first)
#elif defined(__linux__)
    #define PLATFORM_NAME "linux" // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
#elif defined(__unix__) || !defined(__APPLE__) && defined(__MACH__)
    #include <sys/param.h>
    #if defined(BSD)
        #define PLATFORM_NAME "bsd" // FreeBSD, NetBSD, OpenBSD, DragonFly BSD
    #endif
#elif defined(__hpux)
    #define PLATFORM_NAME "hp-ux" // HP-UX
#elif defined(_AIX)
    #define PLATFORM_NAME "aix" // IBM AIX
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR == 1
        #define PLATFORM_NAME "ios" // Apple iOS
    #elif TARGET_OS_IPHONE == 1
        #define PLATFORM_NAME "ios" // Apple iOS
    #elif TARGET_OS_MAC == 1
        #define PLATFORM_NAME "osx" // Apple OSX
    #endif
#elif defined(__sun) && defined(__SVR4)
    #define PLATFORM_NAME "solaris" // Oracle Solaris, Open Indiana
#else
    #define PLATFORM_NAME NULL
#endif
int tavolozza[3][3];

void dtavolo(){
	if(PLATFORM_NAME=="windows"){
		system("cls");
	}else system("clear");
printf("/t                              _        _        ");
printf("/t                             | |      (_)        ");
printf("/t  ___ _   _ _ __   ___ _ __  | |_ _ __ _ ___ ___ ");
printf("/t / __| | | | '_ \ / _ \ '__| | __| '__| / __/ __|");
printf("/t \__ \ |_| | |_) |  __/ |    | |_| |  | \__ \__ \ ");
printf("/t |___/\__,_| .__/ \___|_|     \__|_|  |_|___/___/");
printf("/t           | |                                   ");
printf("/t           |_|                                   ");


printf("%c%c%c|%c%c%c|%c%c%c\n");
printf("%c%c%c|%c%c%c|%c%c%c\n");
printf("%c%c%c|%c%c%c|%c%c%c\n");
printf("----------------------\n");
printf("%c%c%c|%c%c%c|%c%c%c\n");
printf("%c%c%c|%c%c%c|%c%c%c\n");
printf("%c%c%c|%c%c%c|%c%c%c\n");
printf("--------------------\n");
printf("%c%c%c|%c%c%c|%c%c%c\n");
printf("%c%c%c|%c%c%c|%c%c%c\n");
printf("%c%c%c|%c%c%c|%c%c%c\n");




	
	
}

