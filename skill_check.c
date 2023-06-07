#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int generated_number = 0;
char user_input = '\0';
int number_to_achieve;

// Thread function for generating numbers
void* number_generator(void* arg) {
    while (1) {
        generated_number = rand() % 10; // Generate a random number from 0 to 9
        printf("Number to achieve: %d\n", number_to_achieve);
        printf("Random number: %d\n", generated_number);
        sleep(2); // Sleep for 2 seconds
        system("cls");
    }
    return NULL;
}

// Thread function for reading user input
void* input_reader(void* arg) {
    srand(time(NULL));
    number_to_achieve = rand() % (10 - 1 + 1) + 1;

    while (1) {
        scanf(" %c", &user_input); // Read a character from the user

        if (generated_number == number_to_achieve && user_input == 'c') {
            printf("Gamer\n");
        } else {
            printf("Unlucky\n");
        }
    }
    return NULL;
}

int main() {
    pthread_t generator_thread, reader_thread;

    // Create the number generator thread
    if (pthread_create(&generator_thread, NULL, number_generator, NULL) != 0) {
        fprintf(stderr, "Failed to create number generator thread\n");
        return 1;
    }

    // Create the input reader thread
    if (pthread_create(&reader_thread, NULL, input_reader, NULL) != 0) {
        fprintf(stderr, "Failed to create input reader thread\n");
        return 1;
    }

    // Wait for the threads to finish (which will never happen in this case)
    pthread_join(generator_thread, NULL);
    pthread_join(reader_thread, NULL);

    return 0;
}
