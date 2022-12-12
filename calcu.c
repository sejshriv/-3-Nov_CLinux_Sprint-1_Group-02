#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define _MAX_EVENTS 10 // 10 Events Max
#define _MAX_DESCRIPTION 101 // 100 Character Description Max

typedef struct { // typedef a struct called event

    int hour; // Store the hour / HH
    int minute; // Store the minute / MM
    char description[_MAX_DESCRIPTION]; // Store the event description

} event;

// Print the menu selection
void printMenu() {

    puts("+------ SCHEDULER ------+\n"
        "|  1. New Event         |\n"
        "|  2. Delete Event      |\n"
        "|  3. Display Schedule  |\n"
        "|  4. Save Schedule     |\n"
        "|  5. Load Schedule     |\n"
        "|  6. Exit              |\n"
        "+-----------------------+\n");

}

// Return true if an event is NULL, false otherwise
bool isNull(const event *e) { return e == NULL; }

// Allocate memory for and initialize an event
event *initEvent() {
    event *e = (event*)malloc(sizeof(event));

    e->hour = 0;
    e->minute = 0;
    strcpy(e->description, "");

    return e;
}

// Take user input until value is between min and max inclusive, return the input
int inputRange(const int min, const int max) {

    int input = 0;
    char temp[21];
    char *prompt = "| Enter a number between %d and %d: ";

    printf(prompt, min, max);

    fgets(temp, 21, stdin);
    input = atoi(temp);

    while (input > max || input < min) { // Data validation
        printf(prompt, min, max);
        fgets(temp, 21, stdin);
        input = atoi(temp);
    }

    return input;

}

// Setup a new event with user input and return a pointer to the same event
event* newEvent(event *e) {

    if (isNull(e)) { // If e is NULL
        e = initEvent(); // Initialize it
    }

    char *seperator = "+--------------------------------+";

    printf("\n%s\n|           NEW EVENT            |\n%s\n\n", seperator, seperator);

    puts("+---------- EVENT TIME ----------+");

    e->hour = inputRange(0, 23);
    e->minute = inputRange(0, 59);

    puts(seperator);

    puts("\n+--- EVENT DESCRIPTION ---+");

    printf("%s", "| Enter a description: ");

    fgets(e->description, _MAX_DESCRIPTION, stdin);

    puts("+-------------------------+\n");

    puts("| Event successfully added.\n");

    return e;

}

// Add an event to an event list at a specified index
void addEventAtIndex(event list[], const event e, const int i) {

    if (isNull(&e)) { // if our event is NULL, return
        return;
    }

    list[i].hour = e.hour;
    list[i].minute = e.minute;
    strcpy(list[i].description, e.description);

}

// Insertion sort by swapping struct members
void sort(event list[], const int size) {

    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0 && (list[j - 1].hour > list[j].hour || (list[j - 1].hour == list[j].hour && list[j - 1].minute > list[j].minute)); j--) {
            int hourJ = list[j].hour;
            int minuteJ = list[j].minute;
            char descriptionJ[_MAX_DESCRIPTION];
            strcpy(descriptionJ, list[j].description);

            int hourJMinus1 = list[j - 1].hour;
            int minuteJMinus1 = list[j - 1].minute;
            char descriptionJMinus1[_MAX_DESCRIPTION];
            strcpy(descriptionJMinus1, list[j - 1].description);

            list[j].hour = hourJMinus1;
            list[j].minute = minuteJMinus1;
            strcpy(list[j].description, descriptionJMinus1);

            list[j - 1].hour = hourJ;
            list[j - 1].minute = minuteJ;
            strcpy(list[j - 1].description, descriptionJ);
        }
    }

}

// Add an event to an event list by sorting it into position
void sortInsert(event list[], int *size, event e) {

    addEventAtIndex(list, e, *size); // Add event to the end of the list

    (*size)++; // Increment size

    // Insertion Sort
    sort(list, *size);

}

// Display an event in a readable format: [ID] HH:MM - DESCRIPTION
void printEvent(const event e) {

    char h1 = { (e.hour / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
    char h2 = { (e.hour - (e.hour / 10) * 10) + '0' }; // Extract the second digit and convert to char

    char m1 = { (e.minute / 10) + '0' };
    char m2 = { (e.minute - (e.minute / 10) * 10) + '0' };

    printf("%c%c:%c%c - %s", h1, h2, m1, m2, e.description);

}

// Display all events in an event list
void printEventList(const event list[], const int size) {

    if (size == 0) {
        puts("\n| You have no events scheduled!\n");
        return;
    }

    char *seperator = "+--------------------------------+";

    printf("\n%s\n|          MY SCHEDULE           |\n%s\n\n", seperator, seperator);

    for (int i = 0; i < size; i++) {
        printf("| [%d] ", i);
        printEvent(list[i]);

    }

    putchar('\n');

}

// Delete an event from an event list
void deleteEvent(event list[], int *size) {

    if (*size == 0) { // If list is empty
        puts("\n| Event list already empty.\n");
        return;
    }

    char temp[21];
    int id;

    char *seperator = "\n+--------------------------------+";
    printf("%s\n|          DELETE EVENT          |%s\n\n", seperator, seperator);

    for (int i = 0; i < *size; i++) { // Display the event list so the user can see which event to delete
        printf("| [%d] ", i);
        printEvent(list[i]);
    }

    printf("%s", "\n| Enter the ID of an event to delete: ");

    fgets(temp, 21, stdin);
    id = atoi(temp);

    if (id > *size - 1) {
        printf("\n| No event located at %d\n", id);
        return;
    }

    printf("| Event [%d] deleted successfully.\n\n", id);

    // Set hour and minute to some trivially large value for sorting purposes
    list[id].hour = 99;
    list[id].minute = 99;
    strcpy(list[id].description, "");

    if (id != (*size - 1)) { // If the event to remove is already last, there's no need to sort it to last
        sort(list, *size);
    }

    (*size)--; // Decrement the size of the list

}

// Replace all spaces in a string with an underscore
char *encode(char *s) {

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ' ') {
            s[i] = '_';
        }
    }

    return s;

}

// Replace all underscores in a string with an spaces
char *decode(char *s) {

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '_') {
            s[i] = ' ';
        }
    }

    return s;

}

// Save an event list to file
void saveEventList(char *filename, event list[], int size) {

    FILE *f = fopen(filename, "w");

    if (f == NULL) { // If our file is NULL, return
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(f, "%d %d %s", list[i].hour, list[i].minute, encode(list[i].description)); // Encode the description (replace spaces with underscores) before saving it into the file
    }

    printf("\n| %d %s successfully saved into \"%s\".\n\n", size, (size == 1) ? "event" : "events", filename); // Tenary expression to make sure we're grammatically correct

    fclose(f);

}

// Load an event list from file
void loadEventList(char *filename, event list[], int *size) {

    FILE *f = fopen(filename, "r");
    char temp[6 + _MAX_DESCRIPTION]; // ## ## MAX_DESCRIPTION_LENGTH

    if (f == NULL) {
        printf("\n| File \"%s\" not found.\n\n", filename);
        return;
    }

    *size = 0; // Set size to 0

    while (fgets(temp, sizeof(temp), f)) {

        char *word = strtok(temp, " "); // Use space as the token delimiter, get the first token (hour)
        list[*size].hour = atoi(word); // Store the token into the list

        word = strtok(NULL, " "); // Get the second token (minute)
        list[*size].minute = atoi(word);

        word = strtok(NULL, " "); // Get the third token (description)
        strcpy(list[*size].description, decode(word)); // Decode our word before copying it (remove underscores)

        (*size)++; // Increment size with each line (event) added

    }

    printf("\n| %d %s successfully loaded from \"%s\".\n", *size, (*size == 1) ? "event" : "events", filename);

    printEventList(list, *size); // Display the event list when finished, show the user what's been loaded

}

int main() {

    event list[_MAX_EVENTS];
    int index = 0; // Number of elements in list
    int selection = 0;
    char file[FILENAME_MAX];
    char response = 'Y';
    char temp[21];

    while (selection != 6) {

        printMenu(); // Print the menu

        printf("%s", "| Please select an option: "); // Prompt for input
        fgets(temp, 21, stdin);
        selection = atoi(temp); // Convert string input to int

        switch (selection) {

        case 1: // New Event
            if (index + 1 > _MAX_EVENTS) {
                printf("| You can only have %d active events at one time!\n\n", index);
                break;
            }
            sortInsert(list, &index, *newEvent(&list[index]));
            break;
        case 2: // Delete Event
            deleteEvent(list, &index);
            break;
        case 3: // Display Schedule
            printEventList(list, index);
            break;
        case 4: // Save Schedule
            if (index == 0) { // No events, don't save anything
                puts("| You have no events in your schedule!\n");
            }
            else {
                printf("%s", "| Please enter a \"filename.txt\": ");
                fgets(file, FILENAME_MAX, stdin);
                strtok(file, "\n"); // Strip newline from filename
                saveEventList(file, list, index);
            }
            break;
        case 5: // Load Schedule
            if (index > 0) {
                printf("%s", "| Are you sure you want to discard your current schedule? (Y/N): ");
                response = toupper(getc(stdin));
                char c;
                while (((c = getchar()) != '\n') && (c != EOF)); // Clear buffer, from getc();
            }
            if (response == 'Y') {
                printf("%s", "| Please enter a \"filename.txt\": ");
                fgets(file, FILENAME_MAX, stdin);
                strtok(file, "\n"); // Strip newline from filename
                loadEventList(file, list, &index);
            }
            break;
        case 6: // Exit Program
            puts("\n| Thank you!\n");
            break;
        default: // Error
            puts("\n| Error in selection\n");
            break;

        }

    }

}
