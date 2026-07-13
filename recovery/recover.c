#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

// Function to check if the current block is the start of a JPEG
bool is_jpeg_start(uint8_t buffer[BLOCK_SIZE]) {
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] <= 0xef);
}

int main(int argc, char *argv[]) {
    // Accept a single command-line argument
    if (argc != 2) {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card image
    FILE *card = fopen(argv[1], "r");
    if (card == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    // Buffer to hold each 512-byte block from the image
    uint8_t buffer[BLOCK_SIZE];

    // JPEG file counter
    int file_count = 0;

    // File pointer for writing JPEGs
    FILE *img = NULL;

    // Loop over the file, reading 512-byte blocks
    while (fread(buffer, 1, BLOCK_SIZE, card) == BLOCK_SIZE) {
        // Check if the current block is the start of a JPEG
        if (is_jpeg_start(buffer)) {
            // If we're already writing a JPEG, close the current file
            if (img != NULL) {
                fclose(img);
            }

            // Create a new file with the current file count as the filename
            char filename[8];  // e.g., "000.jpg"
            sprintf(filename, "%03d.jpg", file_count);
            img = fopen(filename, "w");
            if (img == NULL) {
                printf("Error: Could not create file %s\n", filename);
                fclose(card);
                return 1;
            }

            // Increment the JPEG file counter
            file_count++;
        }

        // If we're currently writing a JPEG file, write the current block to it
        if (img != NULL) {
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }

    // Close the last file and the card image
    if (img != NULL) {
        fclose(img);
    }
    fclose(card);

    return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        