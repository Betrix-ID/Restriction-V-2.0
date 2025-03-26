#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#define SCRIPT_VERSION "2.0 [ System Performance Optimization ]"

// Fungsi untuk menampilkan notifikasi di sistem
void shell(const char *message) {
    char command[512];
    snprintf(command, sizeof(command),
             "cmd notification post -S bigtext -t '♨️ Restriction ' 'Tag' '%s' > /dev/null 2>&1",
             message);
    system(command);
}

void optimizeSystem() {
    printf("\nDescription:\n");
    printf("  This function optimizes system performance by reducing background processes\n");
    printf("  and freeing up system resources. It performs maintenance tasks such as\n");
    printf("  stopping unnecessary services, clearing logs, and restricting background\n");
    printf("  execution of certain apps. This improves device speed, responsiveness, and\n");
    printf("  overall performance.\n\n");

    system("cmd activity idle-maintenance > /dev/null 2>&1");
    system("cmd activity untrack-associations > /dev/null 2>&1");
    system("cmd deviceidle whitelist -com.google.android.gms > /dev/null 2>&1");
    system("cmd deviceidle sys-whitelist -com.google.android.gms > /dev/null 2>&1");
    system("cmd shortcut reset-all-throttling > /dev/null 2>&1");
    system("cmd package compile -m quicken -f com.android.systemui > /dev/null 2>&1");
    system("cmd appops set com.google.android.gms RUN_IN_BACKGROUND deny");
    system("cmd appops set com.google.android.gms RUN_ANY_IN_BACKGROUND deny");
    system("cmd appops set com.google.android.gms START_FOREGROUND deny");
    system("cmd activity clear-watch-heap all");
    system("pkill -f logcat");
    system("logcat -c");
    system("eval \"$(seq 16 | sed 's/^/logcat -G /;s/$/kB/')\" >/dev/null 2>&1");
    system("eval \"$(seq 300 | sed 's/^/service call restrictions /g' | sed 's/$/ i32 1/g')\" > /dev/null 2>&1");
    system("setprop persist.log.tag S");
    system("cmd activity kill-all");
    system("sync");

    shell("System Optimization Applied Successfully");
    printf("  Success: Restriction settings System Optimization.\n");
    
}

void clearCache() {
    printf("\nDescription:\n");
    printf("  This function clears application cache to free up storage and improve\n");
    printf("  app responsiveness. It scans installed applications, excluding specific\n");
    printf("  protected apps, and removes their temporary cache files. Additionally,\n");
    printf("  it optimizes storage usage by executing system-level cache management\n");
    printf("  commands.\n\n");

    FILE *fp;
    char package[256];

    fp = popen("pm list package -3 | cut -f2 -d:", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return;
    }

    while (fgets(package, sizeof(package), fp) != NULL) {
        package[strcspn(package, "\n")] = 0;

        if (strcmp(package, "com.mobile.legends") != 0 && strcmp(package, "com.tencent.ig") != 0) {
            char command[512];
            snprintf(command, sizeof(command), "rm -rf /sdcard/Android/data/%s/cache", package);
            system(command);
            snprintf(command, sizeof(command), "cmd activity profile stop --user 0 %s", package);
            system(command);
            system("cmd activity set-stop-user-on-switch false >/dev/null 2>&1");
            system("cmd package trim-caches 500M internal");
            system("sm idle-maint run");
            printf("  Cache cleared for %s\n", package);
        }
    }

    pclose(fp);
    shell("Cache Cleared Successfully");
}

void Reset() {
    printf("\nDescription:\n");
    printf("  This function resets all system configurations modified by the optimization\n");
    printf("  processes back to their default state. It allows services and apps that were\n");
    printf("  restricted to run normally again. This is useful if optimizations cause\n");
    printf("  unintended issues, ensuring that system settings are restored safely.\n\n");

    char commands[512];
    snprintf(commands, sizeof(commands),
    
         "cmd appops set com.google.android.gms RUN_IN_BACKGROUND allow && "
         "cmd appops set com.google.android.gms RUN_ANY_IN_BACKGROUND allow && "
         "cmd appops set com.google.android.gms START_FOREGROUND allow && "
         "cmd deviceidle whitelist -com.google.android.gms && "
         "sm idle-maint abort");

    int result = system(commands);
    if (result != 0) {
        printf("  Error: Failed to reset system settings.\n");
        return;
    }

    shell("Restriction scripting success Reset");
    printf("  Success: Restriction settings reset to default.\n");
}

void Usage() {
    printf("Restriction %s - System Performance Optimization Utility\n", SCRIPT_VERSION);
    printf("Usage: Restriction [OPTION]\n\n");
    printf("Options:\n");
    printf("  -O           Optimize system performance (Reduce background activity, free resources)\n");
    printf("  -C           Clear app caches (Free up storage and improve responsiveness)\n");
    printf("  -R           Restore all codes to default (Select this to revert to the default code settings)\n");
    printf("  -h, --help   Display this help message and exit\n\n");
    printf("Description:\n");
    printf("  Restriction is a lightweight system optimization tool designed to dynamically\n");
    printf("  enhance device performance by managing background processes and clearing\n");
    printf("  unnecessary app caches. This improves system speed, stability, and efficiency.\n\n");
    printf("Examples:\n");
    printf("  Apply system optimizations:\n");
    printf("      Restriction -O\n\n");
    printf("  Clear application caches:\n");
    printf("      Restriction -C\n\n");
    printf("  Reset code to default:\n");
    printf("      Restriction -R\n\n");
    printf("System Requirements:\n");
    printf("  - Root access may be required for modifying system properties.\n");
    printf("  - Compatible with Android devices running background management commands.\n\n");
    printf("For more information, visit:\n");
    printf("  Android Debugging Guide: https://developer.android.com/studio/command-line/adb\n\n");
    printf("For community support and discussions, visit:\n");
    printf("  XDA Developers Forum: https://forum.xda-developers.com\n");
    printf("  Stack Overflow (Android Development Questions): https://stackoverflow.com/questions/tagged/android\n\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        Usage();
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-O") == 0) {
            sleep(1);
            printf("- Applying System Optimization\n");
            optimizeSystem();
        } else if (strcmp(argv[i], "-C") == 0) {
            sleep(1);
            clearCache();
        } else if (strcmp(argv[i], "-R") == 0) {
            sleep(1);
            printf("- Reset kode Restriction to default \n");
            Reset();
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            Usage();
        } else {
            printf("Unknown option: %s\n", argv[i]);
            Usage();
        }
    }

    sleep(1);
    printf("\n");
    printf(" ⚠️ This module is protected by copyright and is\n");
    printf(" intended for use by regular users only. Any use of\n");
    printf(" this module, including its code, design, or features,\n");
    printf(" by other developers without written permission from\n");
    printf(" the copyright owner is strictly prohibited.\n");
    printf("______________________________________________(+)\n\n");  

    return 0;
}