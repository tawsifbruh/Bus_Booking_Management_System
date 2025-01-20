#include <stdio.h>
#include <string.h>

int main() {
    int digit, direction, bus_type, num_tickets, matrix[10][4], del_row, del_col, ticket_price = 0;
    int date, month, time_choice, payment_choice;
    char name[100], phone[20];
    int num = 1;

    printf("Welcome to Venture Express\n");

    printf("\nAvailable Destinations with Ticket Prices:\n");
    printf("1. Dhaka to Barisal     - 500 BDT\n");
    printf("2. Dhaka to Chittagong  - 800 BDT\n");
    printf("3. Dhaka to Rajshahi    - 900 BDT\n");
    printf("4. Dhaka to Khulna      - 600 BDT\n");
    printf("5. Dhaka to Sylhet      - 700 BDT\n");
    printf("6. Dhaka to Rangpur     - 1000 BDT\n");
    printf("7. Dhaka to Mymensingh  - 400 BDT\n");

    printf("\nSelect your destination route number: ");
    scanf("%d", &digit);
    getchar();

    char *destination;
    switch (digit) {
        case 1: ticket_price = 500; destination = "Barisal"; break;
        case 2: ticket_price = 800; destination = "Chittagong"; break;
        case 3: ticket_price = 900; destination = "Rajshahi"; break;
        case 4: ticket_price = 600; destination = "Khulna"; break;
        case 5: ticket_price = 700; destination = "Sylhet"; break;
        case 6: ticket_price = 1000; destination = "Rangpur"; break;
        case 7: ticket_price = 400; destination = "Mymensingh"; break;
        default:
            printf("Invalid choice\n");
            return 0;
    }

    printf("\nSelect your route:\n");
    printf("1. Dhaka to %s\n", destination);
    printf("2. %s to Dhaka\n", destination);
    scanf("%d", &direction);
    getchar();

    if (direction != 1 && direction != 2) {
        printf("Invalid route choice\n");
        return 0;
    }

    printf("\nEnter your travel date (DD MM): ");
    scanf("%d %d", &date, &month);
    getchar();
    if (month < 1 || month > 12 || date < 1 || date > 31) {
        printf("Invalid date or month entered. Exiting.\n");
        return 0;
    }

    printf("\nSelect Bus Type:\n(1) AC Bus\n(2) Non-AC Bus\n");
    scanf("%d", &bus_type);
    getchar();

    if (bus_type == 1) ticket_price += 200; // Additional cost for AC
    else if (bus_type != 2) {
        printf("Invalid bus type. Exiting.\n");
        return 0;
    }

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 4; j++)
            matrix[i][j] = num++;

    printf("\nBus seats\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }

    printf("\nEnter number of tickets you want to book: ");
    scanf("%d", &num_tickets);
    getchar();

    if (num_tickets < 1 || num_tickets > 40) {
        printf("Invalid number of tickets. Exiting.\n");
        return 0;
    }

    for (int i = 0; i < num_tickets; i++) {
        printf("\nEnter row and column to choose your seat for ticket %d: ", i + 1);
        scanf("%d %d", &del_row, &del_col);
        getchar();

        if (del_row < 1 || del_row > 10 || del_col < 1 || del_col > 4 || matrix[del_row - 1][del_col - 1] == 0) {
            printf("\nError: Invalid or already booked seat.\n");
            i--;
        } else {
            printf("Booking seat %d at row %d, column %d\n", matrix[del_row - 1][del_col - 1], del_row, del_col);
            matrix[del_row - 1][del_col - 1] = 0;
        }
    }

    printf("\nSelect your bus schedule time:\n");
    printf("1. 6:00 PM\n2. 10:00 PM\n3. 2:00 AM\n4. 6:00 AM\n5. 10:00 AM\n6. 12:00 PM\n");
    scanf("%d", &time_choice);
    getchar();

    char *time_schedule;
    switch (time_choice) {
        case 1: time_schedule = "6:00 PM"; break;
        case 2: time_schedule = "10:00 PM"; break;
        case 3: time_schedule = "2:00 AM"; break;
        case 4: time_schedule = "6:00 AM"; break;
        case 5: time_schedule = "10:00 AM"; break;
        case 6: time_schedule = "12:00 PM"; break;
        default:
            printf("Invalid time choice\n");
            return 0;
    }

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n"); // Remove trailing newline

    printf("Enter your phone number: ");
    fgets(phone, sizeof(phone), stdin);
    strtok(phone, "\n"); // Remove trailing newline

    printf("\nTicket Price: %d Taka (BDT)\n", ticket_price * num_tickets);

    printf("\nChoose your payment method:\n(1) Bkash\n(2) Nagad\n(3) Rocket\n");
    scanf("%d", &payment_choice);
    getchar();

    switch (payment_choice) {
        case 1: printf("You selected Bkash. Please send the amount to 01767679650.\n"); break;
        case 2: printf("You selected Nagad. Please send the amount to 01923456789.\n"); break;
        case 3: printf("You selected Rocket. Please send the amount to 01612345678.\n"); break;
        default:
            printf("Invalid payment method.\n");
            return 0;
    }

    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("\n\n");
    printf("   Congrats, You have booked your ticket! \n");
    printf("\n");
    printf("Name     : %s\n", name);
    printf("Mobile   : %s\n", phone);
    printf("Route    : %s to %s\n", direction == 1 ? "Dhaka" : destination, direction == 1 ? destination : "Dhaka");
    printf("Date     : %d %s\n", date, months[month - 1]);
    printf("Time     : %s\n", time_schedule);
    printf("\nThanks for traveling with Venture Express!\n");

    FILE *file = fopen("booking_data.txt", "a");
    if (file == NULL) {
        printf("\nError: Unable to open file for saving data.\n");
    } else {
        fprintf(file, "Name     : %s\n", name);
        fprintf(file, "Mobile   : %s\n", phone);
        fprintf(file, "Route    : %s to %s\n", direction == 1 ? "Dhaka" : destination, direction == 1 ? destination : "Dhaka");
        fprintf(file, "Date     : %d %s\n", date, months[month - 1]);
        fprintf(file, "Time     : %s\n", time_schedule);
        fprintf(file, "Total Price: %d Taka (BDT)\n", ticket_price * num_tickets);
        fprintf(file, "--------------------------------------\n");
        fclose(file);
        printf("\nYour booking details have been saved successfully.\n");
    }

    return 0;
}

