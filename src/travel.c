#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AVG_SPEED 60

void input_data(FILE *file);
void mission_impossible();
void fck();

struct cities {
    char name[51];
    int coordinates_x;
    int coordinates_y;
    int stop;
};

int main(void) {
    FILE *file;
    char path[501];
    fgets(path, 500, stdin);
    if (path[strlen(path) - 1] == '\n') path[strlen(path) - 1] = '\0';
    // printf("%s\n",path);
    file = fopen(path, "r");
    if (file == NULL) fck();
    input_data(file);
    fclose(file);
    exit(EXIT_SUCCESS);
}

void input_data(FILE *file) {
    int cities_count = 0;
    int full_time = 0;
    int current_driving_time = 0;
    int time_between_cities = 0;
    double current_distance = 0;
    struct cities *city = malloc((cities_count + 1) * sizeof(struct cities));
    while (!feof(file)) {
        fscanf(file, "%s %d %d", city[cities_count].name, &city[cities_count].coordinates_x,
               &city[cities_count].coordinates_y);
        city[cities_count].stop = 0;
        if (strcmp(city[cities_count].name, "\0")) {
            cities_count++;
            city = realloc(city, (cities_count + 1) * sizeof(struct cities));
        }
    }
    for (int i = 0; i < cities_count; i++) {
        // printf("%s %d %d\n", city[i].name, city[i].coordinates_x, city[i].coordinates_y);
        if (i == 0)
            city[i].stop = 1;
        else {
            current_distance = abs(city[i].coordinates_x - city[i - 1].coordinates_x) +
                               abs(city[i].coordinates_y - city[i - 1].coordinates_y);
            time_between_cities = ceil(current_distance / AVG_SPEED);
        }
        if (time_between_cities > 8) mission_impossible();
        if (current_driving_time + time_between_cities >= 8) {
            full_time += 8 + time_between_cities;  // + current_driving_time
            current_driving_time = time_between_cities;
            city[i - 1].stop = 1;
        } else {
            current_driving_time += time_between_cities;
            full_time += time_between_cities;
        }
        // printf("distance = %lf, current_driving_time = %d, time = %d, fulltime = %d\n", current_distance,
        // current_driving_time, time_between_cities, full_time);
    }
    for (int i = 0; i < cities_count; i++) {
        if (city[i].stop == 1) printf("%s\n", city[i].name);
    }
    printf("%s\n%d", city[cities_count - 1].name, full_time);
    free(city);
}

void mission_impossible() {
    printf("Travel is impossible!");
    // fclose(file);
    exit(EXIT_SUCCESS);
}

void fck() {
    fprintf(stderr, "Puck you, Verter!");
    exit(EXIT_FAILURE);
}