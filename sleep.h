// Fonction nous permettant de faire l'animation de chargement
#ifdef _WIN32
#include <windows.h>

void sleep(unsigned milliseconds) {
    Sleep(milliseconds);
}
#else
#include <unistd.h>

void sleep(unsigned milliseconds) {
    usleep(milliseconds * 1000);
}
#endif