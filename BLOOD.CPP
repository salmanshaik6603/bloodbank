//#include <stdio.h>
#include <string.h>

#define MAX_DONORS 100
#define MAX_RECIPIENTS 100

// Blood donor structure
struct Donor {
    int donor_id;
    char name[50];
    char blood_type[5];
    int age;
};

// Blood recipient structure
struct Recipient {
    int recipient_id;
    char name[50];
    char blood_type[5];
    int age;
};

// Blood bank inventory structure
struct BloodInventory {
    char blood_type[5];
    int quantity;
};

struct Donor donors[MAX_DONORS];
struct Recipient recipients[MAX_RECIPIENTS];
struct BloodInventory inventory[8];  // Example: 8 blood types

int donor_count = 0, recipient_count = 0;

// Function prototypes
void addDonor();
void addRecipient();
void displayDonors();
void displayRecipients();
void displayInventory();
void updateInventory();
void searchDonorByBloodType(char bloodType[5]);

int main() {
    int choice;
    
    // Initialize inventory
    strcpy(inventory[0].blood_type, "O+");
    strcpy(inventory[1].blood_type, "O-");
    strcpy(inventory[2].blood_type, "A+");
    strcpy(inventory[3].blood_type, "A-");
    strcpy(inventory[4].blood_type, "B+");
    strcpy(inventory[5].blood_type, "B-");
    strcpy(inventory[6].blood_type, "AB+");
    strcpy(inventory[7].blood_type, "AB-");
    
    for (int i = 0; i < 8; i++) {
        inventory[i].quantity = 0;  // Start with 0 quantity
    }

    while(1) {
        printf("\nBlood Bank Management System\n");
        printf("1. Add Donor\n");
        printf("2. Add Recipient\n");
        printf("3. Display Donors\n");
        printf("4. Display Recipients\n");
        printf("5. Display Inventory\n");
        printf("6. Update Inventory\n");
        printf("7. Search Donor by Blood Type\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addDonor();
                break;
            case 2:
                addRecipient();
                break;
            case 3:
                displayDonors();
                break;
            case 4:
                displayRecipients();
                break;
            case 5:
                displayInventory();
                break;
            case 6:
                updateInventory();
                break;
            case 7:
                {
                    char bloodType[5];
                    printf("Enter blood type to search (e.g., O+, A-): ");
                    scanf("%s", bloodType);
                    searchDonorByBloodType(bloodType);
                }
                break;
            case 8:
                printf("Exiting the system.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

void addDonor() {
    if(donor_count >= MAX_DONORS) {
        printf("Donor list is full.\n");
        return;
    }
    
    struct Donor new_donor;
    printf("Enter donor ID: ");
    scanf("%d", &new_donor.donor_id);
    printf("Enter donor name: ");
    scanf(" %[^\n]%*c", new_donor.name);  // To handle spaces in name
    printf("Enter blood type (e.g., O+, A-, etc.): ");
    scanf("%s", new_donor.blood_type);
    printf("Enter donor age: ");
    scanf("%d", &new_donor.age);

    donors[donor_count++] = new_donor;
    printf("Donor added successfully.\n");
}

void addRecipient() {
    if(recipient_count >= MAX_RECIPIENTS) {
        printf("Recipient list is full.\n");
        return;
    }
    
    struct Recipient new_recipient;
    printf("Enter recipient ID: ");
    scanf("%d", &new_recipient.recipient_id);
    printf("Enter recipient name: ");
    scanf(" %[^\n]%*c", new_recipient.name);  // To handle spaces in name
    printf("Enter blood type (e.g., O+, A-, etc.): ");
    scanf("%s", new_recipient.blood_type);
    printf("Enter recipient age: ");
    scanf("%d", &new_recipient.age);

    recipients[recipient_count++] = new_recipient;
    printf("Recipient added successfully.\n");
}

void displayDonors() {
    if(donor_count == 0) {
        printf("No donors available.\n");
        return;
    }

    printf("\nDonor List:\n");
    for(int i = 0; i < donor_count; i++) {
        printf("Donor ID: %d, Name: %s, Blood Type: %s, Age: %d\n",
                donors[i].donor_id, donors[i].name, donors[i].blood_type, donors[i].age);
    }
}

void displayRecipients() {
    if(recipient_count == 0) {
        printf("No recipients available.\n");
        return;
    }

    printf("\nRecipient List:\n");
    for(int i = 0; i < recipient_count; i++) {
        printf("Recipient ID: %d, Name: %s, Blood Type: %s, Age: %d\n",
                recipients[i].recipient_id, recipients[i].name, recipients[i].blood_type, recipients[i].age);
    }
}

void displayInventory() {
    printf("\nBlood Inventory:\n");
    for(int i = 0; i < 8; i++) {
        printf("Blood Type: %s, Quantity: %d\n", inventory[i].blood_type, inventory[i].quantity);
    }
}

void updateInventory() {
    char bloodType[5];
    int quantity;
    printf("Enter blood type to update (e.g., O+, A-): ");
    scanf("%s", bloodType);
    printf("Enter quantity to add/remove: ");
    scanf("%d", &quantity);
    
    for(int i = 0; i < 8; i++) {
        if(strcmp(inventory[i].blood_type, bloodType) == 0) {
            inventory[i].quantity += quantity;
            printf("Inventory updated successfully.\n");
            return;
        }
    }
    printf("Invalid blood type.\n");
}

void searchDonorByBloodType(char bloodType[5]) {
    int found = 0;
    for(int i = 0; i < donor_count; i++) {
        if(strcmp(donors[i].blood_type, bloodType) == 0) {
            printf("Donor ID: %d, Name: %s, Blood Type: %s, Age: %d\n",
                    donors[i].donor_id, donors[i].name, donors[i].blood_type, donors[i].age);
            found = 1;
        }
    }
    if(!found) {
        printf("No donor found with blood type %s.\n", bloodType);
    }
}
