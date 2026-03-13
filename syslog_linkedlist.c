#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 1. VERI YAPISI TANIMI */
// Her bir Syslog mesajını temsil eden Bağlı Liste Düğümü
struct LogNode {
    char timestamp[30]; 
    char level[15];     
    char message[100];  
    struct LogNode* next; // Bir sonraki düğümün adresi (Bağlı Liste mantığı)
};

/* 2. LOG EKLEME FONKSIYONU (Sona Ekleme) */
// Syslog verileri kronolojik olduğu için yeni veriler sona eklenir.
void addLog(struct LogNode** head, const char* level, const char* msg) {
    // Bellekte yeni bir düğüm oluştur (Dinamik Bellek Yönetimi)
    struct LogNode* newLog = (struct LogNode*)malloc(sizeof(struct LogNode));
    if (newLog == NULL) {
        printf("Bellek hatasi!\n");
        return;
    }

    // Zaman damgasını sistemden otomatik al
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(newLog->timestamp, sizeof(newLog->timestamp), "%b %d %H:%M:%S", tm);

    // Verileri düğüme kopyala
    strncpy(newLog->level, level, sizeof(newLog->level));
    strncpy(newLog->message, msg, sizeof(newLog->message));
    newLog->next = NULL;

    // Eğer liste boşsa, yeni düğüm listenin başı (head) olur
    if (*head == NULL) {
        *head = newLog;
    } else {
        // Liste boş değilse, son düğümü bulana kadar ilerle (Traversal)
        struct LogNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newLog; // Son düğümün 'next'ini yeni düğüme bağla
    }
}

/* 3. LOGLARI LISTELEME FONKSIYONU */
void displayLogs(struct LogNode* head) {
    printf("\n================ LINUX SYSLOG (LINKED LIST) ================\n");
    printf("%-20s | %-10s | %-s\n", "ZAMAN", "SEVIYE", "MESAJ");
    printf("------------------------------------------------------------\n");

    struct LogNode* current = head;
    while (current != NULL) {
        printf("%-20s | %-10s | %-s\n", current->timestamp, current->level, current->message);
        current = current->next;
    }
    printf("============================================================\n");
}

/* 4. BELLEK TEMIZLEME */
// Program kapanırken ayrılan bellek iade edilmelidir.
void freeLogs(struct LogNode* head) {
    struct LogNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/* ANA PROGRAM */
int main() {
    struct LogNode* mySyslog = NULL; // Listenin başlangıcı (Head)

    // Örnek log kayıtları ekleyelim
    addLog(&mySyslog, "KERNEL", "Disk drive sda1 checked successfully.");
    addLog(&mySyslog, "AUTH", "User 'admin' logged in from 192.168.1.10.");
    addLog(&mySyslog, "ERROR", "Failed to start Apache Web Server.");
    addLog(&mySyslog, "CRON", "Daily backup script executed.");

    // Logları ekrana yazdır
    displayLogs(mySyslog);

    // Belleği serbest bırak
    freeLogs(mySyslog);

    printf("\nSistem gunlukleri basariyla islendi. Cikmak icin bir tusa basin...");
    getchar();
    return 0;
}
