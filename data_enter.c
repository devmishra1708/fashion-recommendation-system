#include <stdio.h>
#include <stdbool.h>

// Define a structure for clothing attributes for men
struct MenClothing {
    int productId;
    int type;  // 1: shirt, 2: t-shirt, 3: pants, 4: trousers
    bool isRed;
    bool isBlue;
    bool isGreen;
    bool isBlack;
    bool isWhite;
    bool isGray;
    bool isYellow;
    bool isPurple;
    bool isOrange;
    bool isTextured;
    bool isVibrant;  // true if vibrant, false if muted
    int design;      // 0 for no design/solid, 1 to 9 for various levels of design
    float price;
    char url[100];
};

int main() {
    // Declare a structure variable
    struct MenClothing clothing;

    // Initialize product ID to 1
    int nextProductId = 1;

    // Continuous loop for input
    while (1) {
        // Generate a new product ID for each iteration
        clothing.productId = nextProductId++;

        // Get input for attributes
        printf("Enter product type (1: shirt, 2: t-shirt, 3: pants, 4: trousers): ");
        scanf("%d", &clothing.type);

        printf("Enter URL: ");
        scanf("%s", clothing.url);

        // Initialize color flags to zero
        clothing.isRed = false;
        clothing.isBlue = false;
        clothing.isGreen = false;
        clothing.isBlack = false;
        clothing.isWhite = false;
        clothing.isGray = false;
        clothing.isYellow = false;
        clothing.isPurple = false;
        clothing.isOrange = false;

        printf("Enter available colors (1 for Yes, 0 for No):\n");
        printf("Red: ");
        scanf("%d", &clothing.isRed);
        printf("Blue: ");
        scanf("%d", &clothing.isBlue);
        printf("Green: ");
        scanf("%d", &clothing.isGreen);
        printf("Black: ");
        scanf("%d", &clothing.isBlack);
        printf("White: ");
        scanf("%d", &clothing.isWhite);
        printf("Gray: ");
        scanf("%d", &clothing.isGray);
        printf("Yellow: ");
        scanf("%d", &clothing.isYellow);
        printf("Purple: ");
        scanf("%d", &clothing.isPurple);
        printf("Orange: ");
        scanf("%d", &clothing.isOrange);

        // Determine vibrancy/muted based on user input for colors
        clothing.isVibrant = (clothing.isRed || clothing.isBlue || clothing.isGreen ||
                              clothing.isYellow || clothing.isPurple || clothing.isOrange);

        // Get input for other attributes
        printf("Is the fabric textured? (1 for Yes, 0 for No): ");
        scanf("%d", &clothing.isTextured);

        printf("Enter design level (0 for no design/solid, 1 to 9 for various levels of design): ");
        scanf("%d", &clothing.design);

        printf("Enter price: ");
        scanf("%f", &clothing.price);

        // Write data to CSV file
        FILE *file = fopen("data.csv", "a");  // "a" for append mode
        if (file != NULL) {
            fprintf(file, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%.2f,%s\n",
                    clothing.productId, clothing.type,
                    clothing.isRed, clothing.isBlue, clothing.isGreen,
                    clothing.isBlack, clothing.isWhite, clothing.isGray,
                    clothing.isYellow, clothing.isPurple, clothing.isOrange,
                    clothing.isTextured, clothing.isVibrant, clothing.design,
                    clothing.price, clothing.url);

            fclose(file);
            printf("Data for product ID %d has been written to data.csv.\n", clothing.productId);
        } else {
            printf("Error opening file for writing.\n");
        }

        // Ask if the user wants to add another product
        char choice;
        printf("Do you want to add another product? (y/n): ");
        scanf(" %c", &choice);  // Note the space before %c to consume the newline character

        if (choice != 'y' && choice != 'Y') {
            break;  // Exit the loop if the user does not want to add another product
        }
    }

    return 0;
}
