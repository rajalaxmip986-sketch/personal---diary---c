#include <stdio.h>
#include <stdlib.h>

void addNote() {
    FILE *fp = fopen("diary.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char note[500];
    printf("\nWrite your note:\n");
    getchar();
    fgets(note, 500, stdin);

    fputs(note, fp);
    fputs("\n", fp);

    fclose(fp);
    printf("✔ Note saved successfully!\n");
}

void viewNotes() {
    FILE *fp = fopen("diary.txt", "r");
    if (fp == NULL) {
        printf("No notes found! Add a note first.\n");
        return;
    }

    char ch;
    printf("\n------ Your Notes ------\n\n");

    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);
}

void clearNotes() {
    FILE *fp = fopen("diary.txt", "w");
    if (fp == NULL) {
        printf("Error clearing notes!\n");
        return;
    }

    fclose(fp);
    printf("🗑 All notes deleted successfully!\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n===== PERSONAL DIARY APP =====\n");
        printf("1. Add Note\n");
        printf("2. View Notes\n");
        printf("3. Clear All Notes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addNote(); break;
            case 2: viewNotes(); break;
            case 3: clearNotes(); break;
            case 4: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
