#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for clothing attributes for men
struct MenClothing {
    int productId;
    int type;
    char url[100];
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
    bool isVibrant;
    int design;
    float price;
};

// Define a structure for user preferences
struct UserPreferences {
    int type;
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
    int design;
};

// Function to check if the given clothing matches the user's preferences
bool isMatch(struct MenClothing *clothing, struct UserPreferences *userPreferences) {
    // Check if the type of clothing matches the user's preference
    if (clothing->type != userPreferences->type) {
        printf("test failed due to type\n");
        return false;
    }

    // Check if the clothing has any color that the user likes
    bool hasPreferredColor = (
        (userPreferences->isRed && clothing->isRed) ||
        (userPreferences->isBlue && clothing->isBlue) ||
        (userPreferences->isGreen && clothing->isGreen) ||
        (userPreferences->isBlack && clothing->isBlack) ||
        (userPreferences->isWhite && clothing->isWhite) ||
        (userPreferences->isGray && clothing->isGray) ||
        (userPreferences->isYellow && clothing->isYellow) ||
        (userPreferences->isPurple && clothing->isPurple) ||
        (userPreferences->isOrange && clothing->isOrange)
    );

    // Check if the clothing has any color that the user likes
    if (!hasPreferredColor) {
        printf("test failed due to color\n");
        return false;
    }

    // Check if the fabric texture of the clothing matches the user's preference
    if (clothing->isTextured != userPreferences->isTextured) {
        printf("test failed due to texture\n");
        return false;
    }

    // Check if the design level of the clothing matches the user's preference
    if (clothing->design != userPreferences->design) {
        return false;
    }

    // If any of these checks fail, the function returns false, indicating that the clothing does not match the user's preferences.
    // If all checks pass, the function returns true, indicating that the clothing is a match for the user's preferences.
    return true;
}

// Function to save user preferences to a file
void saveUserPreferences(struct UserPreferences *userPreferences) {
    FILE *file = fopen("user_preference.csv", "a");  // "a" for append mode
    if (file != NULL) {
        fprintf(file, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
                userPreferences->type, userPreferences->isRed, userPreferences->isBlue,
                userPreferences->isGreen, userPreferences->isBlack, userPreferences->isWhite,
                userPreferences->isGray, userPreferences->isYellow, userPreferences->isPurple,
                userPreferences->isOrange, userPreferences->isTextured, userPreferences->design);

        fclose(file);
        printf("User preferences have been saved to user_preference.csv.\n");
    } else {
        printf("Error opening file for writing user preferences.\n");
    }
}

int main() {
    // Declare a structure variable for user preferences
    struct UserPreferences userPreferences;

    // Get input for user preferences
    printf("Enter your preferences:\n");
    printf("Type (1: shirt, 2: t-shirt, 3: pants, 4: trousers): ");
    scanf("%d", &userPreferences.type);

    printf("Red (1 for Yes, 0 for No): ");
    scanf("%d", &userPreferences.isRed);
    printf("Blue (1 for Yes, 0 for No): ");
    scanf("%d", &userPreferences.isBlue);
    printf("Green (1 for Yes, 0 for No): ");
    scanf("%d", &userPreferences.isGreen);
    printf("Black (1 for Yes, 0 for No): ");
    scanf("%d", &userPreferences.isBlack);
    printf("White (1 for Yes, 0 for No): ");
    scanf("%d", &userPreferences.isWhite);
    printf("Gray (1 for Yes, 0 for No): ");
    scanf("%d", &userPreferences.isGray);
    printf("Yellow (1 for Yes, 0 for No): ");
    scanf("%d", &userPreferences.isYellow);
    printf("Purple (1 for Yes, 0 for No): ");
    scanf("%d", &userPreferences.isPurple);
    printf("Orange (1 for Yes, 0 for No): ");
    scanf("%d", &userPreferences.isOrange);

    printf("Is the fabric textured? (1 for Yes, 0 for No): ");
    scanf("%d", &userPreferences.isTextured);

    printf("Enter design level \n(0 for no design/solid, 1 to 9 for various levels of design): ");
    scanf("%d", &userPreferences.design);

    // Save user preferences to a file
    saveUserPreferences(&userPreferences);

    // Read data from data.csv and show matches
    FILE *file = fopen("data.csv", "r");  // "r" for read mode
    if (file != NULL) {
        struct MenClothing clothing;

        printf("\nMatching Clothing:\n");

        // Read data from the file and check for matches
        while (fscanf(file, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%f,%s\n",
                &clothing.productId, &clothing.type,
                &clothing.isRed, &clothing.isBlue, &clothing.isGreen,
                &clothing.isBlack, &clothing.isWhite, &clothing.isGray,
                &clothing.isYellow, &clothing.isPurple, &clothing.isOrange,
                &clothing.isTextured, &clothing.isVibrant, &clothing.design,
                &clothing.price, clothing.url) != EOF) {

            if (isMatch(&clothing, &userPreferences)) {
                printf("Product ID: %d, URL: %s\n", clothing.productId, clothing.url);
            }
        }

        fclose(file);
    } else {
        printf("Error opening file for reading.\n");
    }

    return 0;
}
