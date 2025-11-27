#include <stdio.h>
#include <string.h>

int main() {

    char domestic[100][100] = {"Bandung"};
    char international[100][100] = {"Kuala Lumpur"};
    int domesticCount = 1, internationalCount = 1, i;

    char domesticPassenger[100][100];
    int domesticPassengerCount = 0;

    char internationalPassenger[100][100];
    char passportList[100][100];
    int internationalPassengerCount = 0;

    while (1) {
        printf("Domestic Flight\n==========================\n");
        for(i = 0; i < domesticCount; i++){
            printf("%d. From: Jakarta    To: %s\n", i+1, domestic[i]);
        }

        printf("\nInternational Flight\n==========================\n");
        for(i = 0; i < internationalCount; i++){
            printf("%d. From: Jakarta    To: %s\n", i+1, international[i]);
        }

        printf("\nMenu:\n");
        printf("==========================\n");
        printf("1. Create New Flight\n");
        printf("2. Manage Booking\n");
        printf("3. See Passenger\n");
        printf("4. Exit\n");
        printf("Choice: ");

        int menu;
        scanf("%d", &menu);
        getchar();

        if(menu == 1) {
            char city[100];
            int valid = 0;

            do {
            	printf("Create new Flight\n");
            	printf("==========================\n");
                printf("Enter Flight Destination [Bandung / Bali / Medan / Kuala Lumpur / Singapore / Bangkok] : ");
                scanf("%[^\n]", city);
                getchar();

                if(strcmp(city, "Bali") == 0 || strcmp(city, "Bandung") == 0 || strcmp(city, "Medan") == 0 ||
                   strcmp(city, "Kuala Lumpur") == 0 || strcmp(city, "Singapore") == 0 || strcmp(city, "Bangkok") == 0) {
                    valid = 1;
                } else {
                    printf("Invalid Destination!\n");
                }
            } while(!valid);

            int duplicate = 0;
            for(i = 0; i < domesticCount; i++){
                if(strcmp(city, domestic[i]) == 0) duplicate = 1;
            }
            for(i = 0; i < internationalCount; i++){
                if(strcmp(city, international[i]) == 0) duplicate = 1;
            }
            if(duplicate){
                printf("There are already Flight from Jakarta to Bandung\n");
                continue;
            }

            if(strcmp(city, "Bali") == 0 || strcmp(city, "Bandung") == 0 || strcmp(city, "Medan") == 0){
                strcpy(domestic[domesticCount++], city);
                printf("Success Add Flight from Jakarta to %s\n", city);
            }
            else {
                strcpy(international[internationalCount++], city);
                printf("Success Add Flight from Jakarta to %s\n", city);
            }
        }
        else if(menu == 2){
            char name[100];
            char city[100];

            int len;
            do {
                printf("Passenger name [3..20]: ");
                scanf("%[^\n]", name);
                getchar();

                len = strlen(name);
                if(len < 3 || len > 20) printf("Invalid name length!\n");

            } while(len < 3 || len > 20);
            int valid = 0;
            do {
                printf("Enter Destination [Bandung / Bali / Medan / Kuala Lumpur / Singapore / Bangkok]: ");
                scanf("%[^\n]", city);
                getchar();

                if(strcmp(city, "Bali")==0 || strcmp(city, "Bandung")==0 || strcmp(city, "Medan")==0 ||
                   strcmp(city, "Kuala Lumpur")==0 || strcmp(city,"Singapore")==0 || strcmp(city, "Bangkok")==0)
                    valid = 1;
                else
                    printf("Invalid Destination!\n");

            } while(!valid);

            if(strcmp(city, "Bali") == 0 || strcmp(city, "Bandung") == 0 || strcmp(city, "Medan") == 0){
                strcpy(domesticPassenger[domesticPassengerCount++], name);
                printf("Success Add Passenger\n");
            }
            else {
                char passport[100];
                int passlen;

                do {
                    printf("Passport Number [6]: ");
                    scanf("%[^\n]", passport);
                    getchar();
                    passlen = strlen(passport);

                    if(passlen != 6) printf("Passport must be 6 characters!\n");

                } while(passlen != 6);

                strcpy(internationalPassenger[internationalPassengerCount], name);
                strcpy(passportList[internationalPassengerCount], passport);
                internationalPassengerCount++;

                printf("Success Add Passenger\n");
            }
        }
        else if(menu == 3){
            printf("\n=== Passenger List ===\n");

            printf("\nDomestic Passenger:\n");
            if(domesticPassengerCount == 0)
                printf("No Data\n");
            else
                for(i = 0; i < domesticPassengerCount; i++)
                    printf("%d. %s\n", i+1, domesticPassenger[i]);

            printf("\nInternational Passenger:\n");
            if(internationalPassengerCount == 0)
                printf("No Data\n");
            else
                for(i = 0; i < internationalPassengerCount; i++)
                    printf("%d. %s | Passport: %s\n",
                           i+1, internationalPassenger[i], passportList[i]);
        }
        else if(menu == 4){
            break;
        }

    }

    return 0;
}

