#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//Additional Sections

void printColoredText(const char* text, const char* color) {
    printf("%s%s\033[0m", color, text);  // Reset to default after the colored text
}



void login();
void busfile();
void busadd();
void busedit();
void busdel();
void busdisplay();
void pfile();
void padd();
void pedit();
void pdel();
void pdisplay();
void reservation();
void radd();
void redit();
void rdelete();
void rdisplay();

struct busf
{
    int b_id;
    char b_name[20];
    char b_from[20];
    char b_to[20];
    int b_seats;
    int b_fare;
} bus;

struct passenger
{
    int p_id;
    char p_name[20];
    char p_address[40];
} pr;

struct reservation
{
    int r_id;
    int b_id;
    int p_id;
    int r_date;
    int r_seats;
} re;

FILE *fp;

void login() {
    system("cls");

    const char* red = "\033[1;31m";  // Red color
    const char* green = "\033[1;32m";  // Green color
    const char* blue = "\033[1;34m";  // Blue color
    const char* yellow = "\033[1;33m";  // Yellow color
    const char* white = "\033[1;37m";  // White color
    
    
    char passUser[10] = "user";
    char passWord[10] = "macfast";
    char matchPass[10];
    char matchUser[10];
    int value1, value2;
    printColoredText("\n\n=====================================================\n",white);
    printColoredText("\n==== WELCOME TO ONLINE BUS RESERVATION BY MACFAST ====",yellow);
    printColoredText("\n\n=====================================================\n\n",white);

    do {
        printColoredText("\n\nUserName: ",yellow);
        gets(matchUser);
        printColoredText("\nPassWord: ",yellow);
        gets(matchPass);

        value1 = strcmp(passWord, matchPass);
        value2 = strcmp(passUser, matchUser);

        if (value1 != 0 || value2 != 0) {
            printColoredText("\nINVALID DETAILS TRY AGAIN...\n",red);
        }
        else {
            printColoredText("\nLOGGED IN SUCCESSFULLY...\n",red);
        }
    } while (value1 != 0 || value2 != 0);
}

int main() {
    // Use different colors for various parts of the text
    const char* red = "\033[1;31m";  // Red color
    const char* green = "\033[1;32m";  // Green color
    const char* blue = "\033[1;34m";  // Blue color
    const char* yellow = "\033[1;33m";  // Yellow color
    const char* white = "\033[1;37m";  // White color


    int exit_flag = 0, num;
    login();
    do {  
        system("cls");
        printColoredText("\n\n=====================================================\n",white);
        printColoredText("\n====", green);
        printColoredText(" WELCOME", yellow);
        printColoredText(" TO ONLINE BUS RESERVATION", yellow);
        printColoredText(" BY MACFAST ", yellow);
        printColoredText("====", green);
        printColoredText("\n\n=====================================================\n\n",white);
        printColoredText("----------------- MAIN MENU-----------------------\n\n",white);
        printColoredText(" [1] Bus \n\n",green);
        printColoredText(" [2] Passenger\n\n",blue);
        printColoredText(" [3] Reservation\n\n",yellow);
        printColoredText(" [4] Exit\n\n",red);
        printColoredText("=====================================================\n\n",white);
        printColoredText(" ENTER YOUR CHOICE: ",white);
        scanf("%d", &num);
        switch (num) {
            case 1:
                busfile();
                break;
            case 2:
                pfile();
                break;
            case 3:
                reservation();
                break;
            case 4:
                exit_flag = 1;
                printColoredText("\nThank you for using this bus reservation system\n",green);
                break;
            default:
                printColoredText("\nInvalid choice\n",red);
        }
    } while (!exit_flag);
    printColoredText("\n=====================================================\n\n",white);
    printColoredText(" Bye :) \n",yellow);
    printColoredText("\n=====================================================\n\n",white);
    getch();
    return 0;
}

void busfile() {
    system("cls");

    const char* red = "\033[1;31m";  // Red color
    const char* green = "\033[1;32m";  // Green color
    const char* blue = "\033[1;34m";  // Blue color
    const char* yellow = "\033[1;33m";  // Yellow color
    const char* white = "\033[1;37m";  // White color

    int ch;
    do {      
        printColoredText("\n\n 1. ADD NEW BUS DETAILS\n\n 2. EDIT BUS DETAILS\n\n 3. DELETE BUS DETAILS\n\n 4. DISPLAY BUS DETAILS\n\n 5. EXIT\n\n",yellow);
        printColoredText("ENTER YOUR CHOICE : ",white);
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                busadd();
                break;
            case 2:
                busedit();
                break;
            case 3:
                busdel();
                break;
            case 4:
                busdisplay();
                break;
            case 5:
                break;
            default:
                printColoredText("Invalid choice\n",red);
        }
    } while (ch != 5);
}
void busadd() {
    const char* red = "\033[1;31m";  // Red color
    const char* green = "\033[1;32m";  // Green color
    const char* blue = "\033[1;34m";  // Blue color
    const char* yellow = "\033[1;33m";  // Yellow color
    const char* white = "\033[1;37m";  // White color


    fp = fopen("bus.txt", "ab+");
    if (fp == NULL) {
        printColoredText("\nError opening file!",red);
        return;
    }
    printColoredText("\nEnter Bus ID: ",yellow);
    scanf("%d", &bus.b_id);
    printColoredText("\nEnter Bus name: ",yellow);
    scanf("%s", bus.b_name);
    printColoredText("\nEnter Bus From: ",yellow);
    scanf("%s", bus.b_from);
    printColoredText("\nEnter Bus To: ",yellow);
    scanf("%s", bus.b_to);
    printColoredText("\nEnter Number of Seats: ",yellow);
    scanf("%d", &bus.b_seats);
    printColoredText("Enter Bus Fare: ",yellow);
    scanf("%d", &bus.b_fare);

    fwrite(&bus, sizeof(bus), 1, fp);
    fclose(fp);

    printColoredText("Bus Added Successfully\n",green);
}

void busdisplay() {
    const char* red = "\033[1;31m";  // Red color
    const char* green = "\033[1;32m";  // Green color
    const char* blue = "\033[1;34m";  // Blue color
    const char* yellow = "\033[1;33m";  // Yellow color
    const char* white = "\033[1;37m";  // White color


    fp = fopen("bus.txt", "r");
    if (fp == NULL) {
        printColoredText("\nError opening file!",red);
        return;
    }

    while (fread(&bus, sizeof(struct busf), 1, fp) == 1) {
        printf("\nBus ID: %d\nBus Name: %s\nBus From: %s\nBus To: %s\nNumber of seats: %d\nBus Fare: %d\n", bus.b_id, bus.b_name, bus.b_from, bus.b_to, bus.b_seats, bus.b_fare);
    }

    fclose(fp);
    getch();
}

void busedit() {
    const char* red = "\033[1;31m";  // Red color
    const char* green = "\033[1;32m";  // Green color
    const char* blue = "\033[1;34m";  // Blue color
    const char* yellow = "\033[1;33m";  // Yellow color
    const char* white = "\033[1;37m";  // White color

    int f = 0, rec;
    fp = fopen("bus.txt", "rb+");
    if (fp == NULL) {
        printColoredText("\nError opening file!",red);
        return;
    }

    printColoredText("\nEnter the Bus ID: ",white);
    scanf("%d", &rec);

    while (fread(&bus, sizeof(struct busf), 1, fp) == 1 && f == 0) {
        if (bus.b_id == rec) {
            f = 1;

            printColoredText("\nEnter new Bus ID: ",yellow);
            scanf("%d", &bus.b_id);
            printColoredText("\nEnter Bus name: ",yellow);
            scanf("%s", bus.b_name);
            printColoredText("\nEnter Bus From: ",yellow);
            scanf("%s", bus.b_from);
            printColoredText("\nEnter Bus To: ",yellow);
            scanf("%s", bus.b_to);
            printColoredText("\nEnter Number of Seats: ",yellow);
            scanf("%d", &bus.b_seats);
            printColoredText("Enter Bus Fare: ",yellow);
            scanf("%d", &bus.b_fare);

            fseek(fp, -sizeof(struct busf), SEEK_CUR);
            fwrite(&bus, sizeof(struct busf), 1, fp);

            printColoredText("\nBus Details Updated successfully",green);
            break;
        }
    }

    fclose(fp);

    if (f == 0) {
        printColoredText("\nNo item found",red);
    }

    getch();
}

void busdel() {
    const char* red = "\033[1;31m";  // Red color
    const char* green = "\033[1;32m";  // Green color
    const char* blue = "\033[1;34m";  // Blue color
    const char* yellow = "\033[1;33m";  // Yellow color
    const char* white = "\033[1;37m";  // White color

    FILE *fp1;
    int f = 0, c = 0, rec;
    fp = fopen("bus.txt", "r");
    if (fp == NULL) {
        printColoredText("\nError opening file!",red);
        return;
    }

    fp1 = fopen("temp.txt", "a+");
    if (fp1 == NULL) {
        printColoredText("\nError creating temporary file!",red);
        fclose(fp);
        return;
    }

    printColoredText("\nEnter the Bus ID for deletion: ",white);
    scanf("%d", &rec);

    while (fread(&bus, sizeof(struct busf), 1, fp) == 1) {
        if (bus.b_id != rec) {
            fwrite(&bus, sizeof(bus), 1, fp1);
            c++;
        }
        else {
            f = 1;
            printColoredText("\nRecord deleted successfully",green);
        }
    }

    if (f == 0) {
        printColoredText("\nNo records found.",red);
    }

    fclose(fp);
    fclose(fp1);
    remove("bus.txt");
    rename("temp.txt", "bus.txt");

    if (c == 0) {
        remove("bus.txt");
    }

    getch();
}
void pfile() {
    const char* red = "\033[1;31m";  // Red color
    const char* green = "\033[1;32m";  // Green color
    const char* blue = "\033[1;34m";  // Blue color
    const char* yellow = "\033[1;33m";  // Yellow color
    const char* white = "\033[1;37m";  // White color

    int ch;

    do {
        system("cls");
        printColoredText("\n1. Add Passenger\n",yellow);
        printColoredText("2. Edit Passenger Details\n",yellow);
        printColoredText("3. Delete Passenger Details\n",yellow);
        printColoredText("4. View Passenger Details\n",yellow);
        printColoredText("5. EXIT\n",red);
        printColoredText("\nENTER YOUR CHOICE : ",white);
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                padd();
                break;
            case 2:
                pedit();
                break;
            case 3:
                pdel();
                break;
            case 4:
                pdisplay();
                break;
            case 5:
                break;
            default:
                printColoredText("\nInvalid choice",red);
        }
    } while (ch != 5);
}

void padd() {
    const char* red = "\033[1;31m";  // Red color
    const char* green = "\033[1;32m";  // Green color
    const char* blue = "\033[1;34m";  // Blue color
    const char* yellow = "\033[1;33m";  // Yellow color
    const char* white = "\033[1;37m";  // White color



    fp = fopen("pass.txt", "ab+");
    if (fp == NULL) {
        printColoredText("\nError opening file!",red);
        return;
    }

    printColoredText("\nEnter Passenger ID: ",yellow);
    scanf("%d", &pr.p_id);
    printColoredText("\nEnter Passenger name: ",yellow);
    scanf("%s", pr.p_name);
    printColoredText("\nEnter Passenger Address: ",yellow);
    scanf("%s", pr.p_address);

     if (fwrite(&pr, sizeof(pr), 1, fp) != 1) {
        printColoredText("\nError writing to file!",red);
        fclose(fp);
        return;
    }
    fclose(fp);

    printColoredText("\nPassenger Added Successfully\n",green);
    getch();
}

void pdisplay() {
    const char* red = "\033[1;31m";  // Red color
    const char* green = "\033[1;32m";  // Green color
    const char* blue = "\033[1;34m";  // Blue color
    const char* yellow = "\033[1;33m";  // Yellow color
    const char* white = "\033[1;37m";  // White color


    fp = fopen("pass.txt", "r");
    if (fp == NULL) {
        printColoredText("\nError opening file!",red);
        return;
    }

    while (fread(&pr, sizeof(struct passenger), 1, fp) == 1) {
        printf("\nPassenger ID: %d\nPassenger Name: %s\nPassenger Address: %s\n", pr.p_id, pr.p_name, pr.p_address);
    }

    fclose(fp);
    getch();
}

void pedit() {
    const char* red = "\033[1;31m";  // Red color
    const char* green = "\033[1;32m";  // Green color
    const char* blue = "\033[1;34m";  // Blue color
    const char* yellow = "\033[1;33m";  // Yellow color
    const char* white = "\033[1;37m";  // White color

    int f = 0, rec;
    fp = fopen("pass.txt", "rb+");
    if (fp == NULL) {
        printColoredText("\nError opening file!",red);
        return;
    }

    printColoredText("\nEnter the Passenger ID: ",white);
    scanf("%d", &rec);

    while (fread(&pr, sizeof(struct passenger), 1, fp) == 1 && f == 0) {
        if (pr.p_id == rec) {
            f = 1;

            printColoredText("\nEnter Passenger ID: ",yellow);
            scanf("%d", &pr.p_id);
            printColoredText("\nEnter Passenger name: ",yellow);
            scanf("%s", pr.p_name);
            printColoredText("\nEnter Passenger Address: ",yellow);
            scanf("%s", pr.p_address);

            fseek(fp, -sizeof(pr), SEEK_CUR);
            fwrite(&pr, sizeof(pr), 1, fp);

            printColoredText("\nPassenger Details Updated successfully",green);
        }
    }

    if (f == 0) {
        printColoredText("\nNo item found",red);
    }

    fclose(fp);
    getch();
}

void pdel() {

    const char* red = "\033[1;31m";  // Red color
    const char* green = "\033[1;32m";  // Green color
    const char* blue = "\033[1;34m";  // Blue color
    const char* yellow = "\033[1;33m";  // Yellow color
    const char* white = "\033[1;37m";  // White color


    FILE *fp1;
    int f = 0, c = 0, rec;
    fp = fopen("pass.txt", "r");
    if (fp == NULL) {
        printColoredText("\nError opening file!",red);
        return;
    }

    fp1 = fopen("temp.txt", "a+");
    if (fp1 == NULL) {
        printColoredText("\nError creating temporary file!",red);
        fclose(fp);
        return;
    }

    printColoredText("\nEnter the Passenger ID for deletion: ",yellow);
    scanf("%d", &rec);

    while (fread(&pr, sizeof(struct passenger), 1, fp) == 1) {
        if (pr.p_id != rec) {
            fwrite(&pr, sizeof(pr), 1, fp1);
            c++;
        } else {
            f = 1;
            printColoredText("\nRecord deleted successfully",green);
        }
    }

    if (f == 0) {
        printColoredText("\nNo records found.",red);
    }

    fclose(fp);
    fclose(fp1);
    remove("pass.txt");
    rename("temp.txt", "pass.txt");

    if (c == 0) {
        remove("pass.txt");
    }

    getch();
}

void reservation() {
    const char* red = "\033[1;31m";  // Red color
    const char* green = "\033[1;32m";  // Green color
    const char* blue = "\033[1;34m";  // Blue color
    const char* yellow = "\033[1;33m";  // Yellow color
    const char* white = "\033[1;37m";  // White color

    int ch;

    do {
        system("cls");
        printColoredText("\n1. Add Reservation Record\n",yellow);
        printColoredText("2. Edit Reservation Record\n",yellow);
        printColoredText("3. Delete Reservation Record\n",yellow);
        printColoredText("4. Display Reservation Record\n",yellow);
        printColoredText("5. EXIT\n",red);
        printColoredText("\nENTER YOUR CHOICE : ",white);
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                radd();
                break;
            case 2:
                redit();
                break;
            case 3:
                rdelete();
                break;
            case 4:
                rdisplay();
                break;
            case 5:
                break;
            default:
                printColoredText("\nInvalid choice",red);
        }
    } while (ch != 5);
}

void rdisplay() {
    const char* red = "\033[1;31m";  // Red color
    const char* green = "\033[1;32m";  // Green color
    const char* blue = "\033[1;34m";  // Blue color
    const char* yellow = "\033[1;33m";  // Yellow color
    const char* white = "\033[1;37m";  // White color
    
    fp = fopen("reserve.txt", "r");
    if (fp == NULL) {
        printColoredText("\nError opening file!",red);
        return;
    }

    while (fread(&re, sizeof(struct reservation), 1, fp) == 1) {
        printf("\nReservation ID: %d\nBus ID: %d\nPassenger ID: %d\nDate: %d\nNumber of seats: %d\n", re.r_id, re.b_id, re.p_id, re.r_date, re.r_seats);
    }

    fclose(fp);
    getch();
}
void radd() {
    const char* red = "\033[1;31m";  // Red color
    const char* green = "\033[1;32m";  // Green color
    const char* blue = "\033[1;34m";  // Blue color
    const char* yellow = "\033[1;33m";  // Yellow color
    const char* white = "\033[1;37m";  // White color
    
    FILE *fp1;
    int f = 0;
    fp1 = fopen("bus.txt", "r+");
    fp = fopen("reserve.txt", "a+");
    if (fp == NULL || fp1 == NULL) {
        printColoredText("\nError opening file!",red);
        return;
    }

    printColoredText("\nEnter Reservation ID: ",yellow);
    scanf("%d", &re.r_id);
    printColoredText("\nEnter Bus ID: ",yellow);
    scanf("%d", &re.b_id);
    printColoredText("\nEnter Passenger ID: ",yellow);
    scanf("%d", &re.p_id);
    printColoredText("\nEnter date: ",yellow);
    scanf("%d", &re.r_date);
    printColoredText("\nEnter Number of seats available: ",yellow);
    scanf("%d", &re.r_seats);

    while (fread(&bus, sizeof(struct busf), 1, fp1) == 1 && f == 0) {
        if (re.b_id == bus.b_id) {
            if (re.r_seats <= bus.b_seats) { // Corrected condition
                fwrite(&re, sizeof(re), 1, fp);
                fseek(fp1, -sizeof(bus), SEEK_CUR);
                fwrite(&bus, sizeof(bus), 1, fp1);
                fclose(fp1);
                fclose(fp);
                printColoredText("\nRecord inserted successfully",green);
            } else {
                printColoredText("\nSeats not available",red);
                fclose(fp1);
                fclose(fp);
            }
            f = 1;
        }
    }
    if (f == 0) {
        printColoredText("\nInvalid Bus ID",red);
        fclose(fp1);
        fclose(fp);
    }

    getch();
}

void redit() {
    const char* red = "\033[1;31m";  // Red color
    const char* green = "\033[1;32m";  // Green color
    const char* blue = "\033[1;34m";  // Blue color
    const char* yellow = "\033[1;33m";  // Yellow color
    const char* white = "\033[1;37m";  // White color

    int c = 0, rec;
    FILE *fp1, *fp2, *temp_fp;
    fp = fopen("reserve.txt", "r");
    fp1 = fopen("tempit.txt", "w");
    fp2 = fopen("stmp.txt", "w");

    if (fp == NULL || fp1 == NULL || fp2 == NULL) {
        printColoredText("\nError opening file!",red);
        return;
    }

    printColoredText("\nEnter Bus ID: ",yellow);
    scanf("%d", &rec);

    while (fread(&re, sizeof(struct reservation), 1, fp) == 1) {
        if (re.b_id != rec) {
            fwrite(&re, sizeof(re), 1, fp2);
        } else {
            c++;
            printColoredText("\nEnter Reservation ID: ",yellow);
            scanf("%d", &re.r_id);
            printColoredText("\nEnter Passenger ID: ",yellow);
            scanf("%d", &re.p_id);
            printColoredText("\nEnter Reservation Date: ",yellow);
            scanf("%d", &re.r_date);
            printColoredText("Enter Number of Seats Available: ",yellow);
            scanf("%d", &re.r_seats);
            fwrite(&re, sizeof(re), 1, fp1);
        }
    }

    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    
    // Truncate the reserve.txt file
    temp_fp = fopen("reserve.txt", "w");
    if (temp_fp != NULL) fclose(temp_fp); // Close if opened successfully

    // Copy the contents from stmp.txt to reserve.txt
    fp1 = fopen("tempit.txt", "r");
    fp = fopen("reserve.txt", "a");
    while (fread(&re, sizeof(struct reservation), 1, fp1) == 1) {
        fwrite(&re, sizeof(re), 1, fp);
    }
    fclose(fp);
    fclose(fp1);

    // Remove temporary files
    remove("stmp.txt");
    remove("tempit.txt");

    if (c == 0) {
        printColoredText("\nNo records found",red);
    } else {
        printColoredText("\nRecord updated successfully",green);
    }

    getch();
}



void rdelete() {

     const char* red = "\033[1;31m";  // Red color
    const char* green = "\033[1;32m";  // Green color
    const char* blue = "\033[1;34m";  // Blue color
    const char* yellow = "\033[1;33m";  // Yellow color
    const char* white = "\033[1;37m";  // White color

    FILE *fp1;
    int f = 0, c = 0, rec;
    fp = fopen("reserve.txt", "r");
    if (fp == NULL) {
        printColoredText("\nError opening file!",red);
        return;
    }

    fp1 = fopen("tp.txt", "w"); // Changed mode to "w"
    if (fp1 == NULL) {
        printColoredText("\nError creating temporary file!",red);
        fclose(fp);
        return;
    }

    printColoredText("\nEnter the reservation id for deletion: ",yellow);
    scanf("%d", &rec);

    while (fread(&re, sizeof(struct reservation), 1, fp) == 1) {
        if (re.r_id != rec) {
            fwrite(&re, sizeof(re), 1, fp1);
            c++;
        } else {
            f = 1;
            printColoredText("\nRecord deleted successfully",green);
        }
    }

    if (f == 0) {
        printColoredText("\nNo records found",red);
    }

    fclose(fp);
    fclose(fp1);
    
    remove("reserve.txt");
    rename("tp.txt", "reserve.txt");

    if (c == 0) {
        remove("reserve.txt");
    }

    getch();
}




















